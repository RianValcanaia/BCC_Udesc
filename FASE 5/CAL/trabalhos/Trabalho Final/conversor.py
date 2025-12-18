# Matheus Azevedo de Sá e Rian Vulcanai, novembro de 2025
# python3 conversor.py

"""
    Lê os arquivos airports.csv e routes.csv do dataset OpenFlights, disponível em https://openflights.org/data
    Produz dois arquivos para consumo posterior no a.cpp:
        1. airports_processed.csv
            - Tabela que associa o código de um aeroporto às duas coordenadas (latitude, longitude)
        2. edges.csv
            - Lista de arestas direcionadas com pesos representando a distância geográfica (em km) entre dois aeroportos, usada para criar um grafo


    # SOBRE O BANCO DE DADOS (Fonte: OpenFlights)

    # airports.csv

        Airport ID  Unique OpenFlights identifier for this airport.
        Name    Name of airport. May or may not contain the City name.
        City    Main city served by airport. May be spelled differently from Name.
        Country     Country or territory where airport is located. See Countries to cross-reference to ISO 3166-1 codes.
        IATA    3-letter IATA code. Null if not assigned/unknown.
        ICAO    4-letter ICAO code.
        Null if not assigned.
        Latitude    Decimal degrees, usually to six significant digits. Negative is South, positive is North.
        Longitude   Decimal degrees, usually to six significant digits. Negative is West, positive is East.
        Altitude    In feet.
        Timezone    Hours offset from UTC. Fractional hours are expressed as decimals, eg. India is 5.5.
        DST     Daylight savings time. One of E (Europe), A (US/Canada), S (South America), O (Australia), Z (New Zealand), N (None) or U (Unknown). See also: Help: Time
        Tz database timezone    Timezone in "tz" (Olson) format, eg. "America/Los_Angeles".
        Type    Type of the airport. Value "airport" for air terminals, "station" for train stations, "port" for ferry terminals and "unknown" if not known. In airports.csv, only type=airport is included.
        Source  Source of this data. "OurAirports" for data sourced from OurAirports, "Legacy" for old data not matched to OurAirports (mostly DAFIF), "User" for unverified user contributions. In airports.csv, only source=OurAirports is included.

        The data is UTF-8 encoded.

        Note: Rules for daylight savings time change from year to year and from country to country. The current data is an approximation for 2009, built on a country level. Most airports in DST-less regions in countries that generally observe DST (eg. AL, HI in the USA, NT, QL in Australia, parts of Canada) are marked incorrectly.
        
        Sample entries:

        507,"London Heathrow Airport","London","United Kingdom","LHR","EGLL",51.4706,-0.461941,83,0,"E","Europe/London","airport","OurAirports"
        26,"Kugaaruk Airport","Pelly Bay","Canada","YBB","CYBB",68.534401,-89.808098,56,-7,"A","America/Edmonton","airport","OurAirports"
        3127,"Pokhara Airport","Pokhara","Nepal","PKR","VNPK",28.200899124145508,83.98210144042969,2712,5.75,"N","Asia/Katmandu","airport","OurAirports"
        8810,"Hamburg Hbf","Hamburg","Germany","ZMB",N,53.552776,10.006683,30,1,"E","Europe/Berlin","station","User"


    # routes.csv (Dados até 2014)

        Airline     2-letter (IATA) or 3-letter (ICAO) code of the airline.
        Airline ID  Unique OpenFlights identifier for airline (see Airline).
        Source airport  3-letter (IATA) or 4-letter (ICAO) code of the source airport.
        Source airport ID   Unique OpenFlights identifier for source airport (see Airport)
        Destination airport     3-letter (IATA) or 4-letter (ICAO) code of the destination airport.
        Destination airport ID  Unique OpenFlights identifier for destination airport (see Airport)
        Codeshare   "Y" if this flight is a codeshare (that is, not operated by Airline, but another carrier), empty otherwise.
        Stops   Number of stops on this flight ("0" for direct)
        Equipment   3-letter codes for plane type(s) generally used on this flight, separated by spaces

        The data is UTF-8 encoded. The special value N' is used for "NULL" to indicate that no value is available, and is understood automatically by MySQL if imported.
        Notes:

            Routes are directional: if an airline operates services from A to B and from B to A, both A-B and B-A are listed separately.
            Routes where one carrier operates both its own and codeshare flights are listed only once.

        Sample entries

        BA,1355,SIN,3316,LHR,507,,0,744 777
        BA,1355,SIN,3316,MEL,3339,Y,0,744
        TOM,5013,ACE,1055,BFS,465,,0,320
"""


import csv
import math

def haversine(lat1, lon1, lat2, lon2): # Calcular distância geodésica entre duas coordenadas
    """
    Calcula a distância entre dois pontos (lat1, lon1) e (lat2, lon2) usando a fórmula de Haversine, que calcula a menor distância entre dois pontos na superfície de uma esfera.
    A Terra é aproximada como esfera, o que é uma precisão suficiente para voos.
    Retorna a distância em quilômetros (float).
    """
    R = 6371.0  # raio médio da Terra em km

    # Converter graus para radianos
    lat1, lon1, lat2, lon2 = map(math.radians, [lat1, lon1, lat2, lon2])
    # Diferenças em radianos
    dlat = lat2 - lat1
    dlon = lon2 - lon1

    # Parâmetro Angular a = sen²(dlat/2) + cos(lat1) * cos(lat2) * sen²(dlon/2)
    a = (math.sin(dlat / 2) ** 2 
        +
        math.cos(lat1) * math.cos(lat2) * math.sin(dlon / 2) ** 2)

    # Ângulo Central c = 2 * arcsen(sqrt(a))
    c = 2 * math.asin(math.sqrt(a))

    # Distância d = R * c
    return R * c


def main():

    # Entrada
    airports_file = "airports.csv"
    routes_file = "routes.csv"

    # Saída
    airports_out = "airports_processed.csv"
    edges_out = "edges.csv"

    # 1) Lê airports.csv e constrói a tabela IATA -> coords ---------------------------------------------------------------------------
    airports = {}  # dicionário: { "IATA": (lat, lon) }

    print("Lendo airports.csv")

    with open(airports_file, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        for row in reader:
            # row = [AirportID, Name, City, Country, IATA, ICAO, Latitude, Longitude, ...]
            if len(row) < 8:
                continue  # linha malformada

            iata = row[4].strip()
            lat = row[6].strip()
            lon = row[7].strip()

            # ignorar aeroportos sem código IATA válido
            if iata == "\\N" or iata == "" or len(iata) != 3:
                continue

            try: # evita alguns erros da formatação da tabela
                lat = float(lat)
                lon = float(lon)
            except ValueError:
                # Coordenadas inválidas
                continue

            airports[iata] = (lat, lon)

    print(f"Total de aeroportos válidos lidos: {len(airports)}")

    # Salvar airports_processed.csv
    print("Gerando airports_processed.csv") 
    with open(airports_out, "w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["IATA", "lat", "lon"])  # cabeçalho

        for iata, (lat, lon) in airports.items():
            writer.writerow([iata, lat, lon])

           

    # 2) Lê routes.csv e calcula pesos das arestas
    print("Lendo routes.csv e calculando arestas")

    edges = []  # (source, dest, distance_km)

    with open(routes_file, "r", encoding="utf-8") as f:
        reader = csv.reader(f)

        for row in reader:
            # row = [Airline, AirlineID, SourceAirport, SourceAirportID, DestAirport, DestAirportID, Codeshare, Stops, Equipment]

            if len(row) < 5:
                continue

            source = row[2].strip()
            dest = row[4].strip()

            # Garantir que ambos aeroportos existem na tabela pois alguns podem ter sido eliminados no processo de filtragem anterior
            if source not in airports or dest not in airports:
                continue

            lat1, lon1 = airports[source] # pega do dicionário
            lat2, lon2 = airports[dest]

            # Calcular peso da aresta
            dist = haversine(lat1, lon1, lat2, lon2)

            edges.append((source, dest, dist))

    print(f"Total de arestas válidas geradas: {len(edges)}")

    # Salvar edges.csv
    print("Gerando edges.csv")
    with open(edges_out, "w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["source", "destination", "weight_km"])  # cabeçalho

        for s, d, w in edges:
            writer.writerow([s, d, f"{w:.6f}"])

    

    print("\nProcesso finalizada com sucesso")
    print(f"Arquivos gerados: {airports_out}, {edges_out}")

# EXECUTAR PROGRAM
if __name__ == "__main__":
    main()