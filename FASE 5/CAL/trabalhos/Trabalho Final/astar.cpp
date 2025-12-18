// Matheus Azevedo de Sá e Rian Vulcanai, novembro de 2025
// g++ astar.cpp -o astar.out && ./astar.out


/*
    Implementação do algoritmo A* para um grafo ponderado com arestas direcionadas.
    Encontra o caminho mais curto entre dois aeroportos.
    Basea-se no banco de dados de aeroportos e rotas do OpenFlights (disponível em https://openflights.org/data).
    Consome:
        airports_processed.csv (coordenadas dos aeroportos, usadas na heurística do A*)
        edges.csv (arestas que representam rotas de voo e servem para montar o grafo em memória)
*/
#include <bits/stdc++.h>
#include<chrono>
using namespace std;

// Mapa: IATA -> (lat, lon)
unordered_map<string, pair<double,double>> airport_coords; // mais rápido que map

// Grafo: IATA -> lista de (destino, peso)
unordered_map<string, vector<pair<string,double>>> graph; // Dado um aeroposrto (vértice), o mapa retorna uma lista de vizinhos (arestas): vértice (IATA), peso (distância)


// Carregar airports_processed.csv
void load_airports(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir " << filename << endl;
        exit(1);
    }

    string line;
    getline(file, line); // descartar cabeçalho

    while (getline(file, line)) {
        stringstream ss(line);
        string iata, lat_s, lon_s;

        getline(ss, iata, ',');
        getline(ss, lat_s, ',');
        getline(ss, lon_s, ',');

        double lat = stod(lat_s);
        double lon = stod(lon_s);

        airport_coords[iata] = {lat, lon};
    }
}

// Carregar edges.csv
void load_edges(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir " << filename << endl;
        exit(1);
    }

    string line;
    getline(file, line); // cabeçalho

    while (getline(file, line)) {
        stringstream ss(line);
        string src, dst, w_s;

        getline(ss, src, ',');
        getline(ss, dst, ',');
        getline(ss, w_s, ',');

        double w = stod(w_s);

        graph[src].push_back({dst, w});
    }
}

// Calcula distância geodésica entre dois aeroportos (usado na heurística) usando a fórmula de Haversine
double haversine(double lat1, double lon1, double lat2, double lon2) { 
    const double R = 6371.0; // raio médio da Terra em km
    
    // Converte para radianos
    auto deg2rad = [](double x){ return x * M_PI / 180.0; }; 

    lat1 = deg2rad(lat1);
    lon1 = deg2rad(lon1);
    lat2 = deg2rad(lat2);
    lon2 = deg2rad(lon2);

    // Diferenças em radianos
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Parâmetro Angular a = sen²(dlat/2) + cos(lat1) * cos(lat2) * sen²(dlon/2)
    double a = sin(dlat/2)*sin(dlat/2) + cos(lat1)*cos(lat2)*sin(dlon/2)*sin(dlon/2);

    // Ângulo Central c = 2 * arcsen(sqrt(a))
    double c = 2 * asin(sqrt(a));

    // Distância d = R * c
    return R * c;
}

/* ------------------------------------------------------
    Heurística do A*: distância geodésica
--------------------------------------------------------- */
double heuristic(const string &a, const string &b) {
    auto [lat1, lon1] = airport_coords[a];
    auto [lat2, lon2] = airport_coords[b];
    return haversine(lat1, lon1, lat2, lon2);
}


// A* 
vector<string> astar(const string &start, const string &goal) {
    /* 
    f(n) = g(n) + h(n)

    g(n): É o custo real do caminho do nó inicial (start) até o nó atual n.
    h(n): É a função heurística, que estima o custo do caminho mais curto do nó atual n até o nó objetivo (goal).
    f(n): É o custo total estimado do caminho que passa pelo nó n (do início ao fim). 

    O A* sempre expande o nó com o menor valor de f(n).
    */

    // Verificar se o aeroporto existe
    if (!airport_coords.count(start) || !airport_coords.count(goal)) return {};

    // Priority queue (min-heap)
    priority_queue<pair<double,string>, vector<pair<double,string>>, greater<pair<double,string>>> pq;

    unordered_map<string, double> g; // custo do início até n
    unordered_map<string, string> parent; // usado para fazer a reconstrução do caminho

    // Inicialização
    g[start] = 0.0; // A distância do início até o início é zero
    pq.push({ heuristic(start, goal), start }); // Jogo o ponto inicial na fila com a distância até o fim sendo estimada pela heurística

    // A* laço de repetição
    while (!pq.empty()) {
        auto [f, current] = pq.top();
        pq.pop();

        // Encontrou o destino
        if (current == goal) { // Reconstrói o caminho
            vector<string> path;
            string node = goal;

            while (node != start) {
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        // Expandir vizinhos
        for (auto &[neighbor, weight] : graph[current]) {
            double tentative_g = g[current] + weight;

            if (!g.count(neighbor) || tentative_g < g[neighbor]) {
                g[neighbor] = tentative_g;
                double h = heuristic(neighbor, goal);
                double f_new = tentative_g + h;

                parent[neighbor] = current;
                pq.push({f_new, neighbor});
            }
        }
    }

    // Sem caminho
    return {};
}

int main() {
    //cout << "Carregando airports_processed.csv" << endl;
    load_airports("airports_processed.csv");

    //cout << "Carregando edges.csv" << endl;
    load_edges("edges.csv");

    //cout << "Sistema pronto para consultas" << endl;
    cout << "Digite dois códigos IATA (ex: GRU LAX)" << endl;

    while (true) {
        //cout << "Digite dois códigos IATA (ex: GRU LAX)" << endl;
        cout << "\nConsulta: ";
        string a, b;
        cin >> a >> b;

        // Normalizar para maiúsculas
        for (auto &c : a) c = toupper(c);
        for (auto &c : b) c = toupper(c);

        // Verificar existência
        if (!airport_coords.count(a)) {
            cout << "Aeroporto " << a << " não encontrado." << endl;
            continue;
        }
        if (!airport_coords.count(b)) {
            cout << "Aeroporto " << b << " não encontrado." << endl;
            continue;
        }

        // Checar voo direto
        bool direto = false;
        for (auto &[dst, w] : graph[a]) {
            if (dst == b) {
                cout << "Existe voo direto entre " << a << " e " << b << "!" << endl;
                cout << "Distância: " << w << " km" << endl;
                direto = true;
                break;
            }
        }

        if (direto) continue;

        // Rodar A*
        cout << "Calculando A*..." << endl;
        
        auto start_time = chrono::high_resolution_clock::now();

        auto path = astar(a, b);

        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end_time - start_time;

        cout << fixed << setprecision(6);
        cout << "Tempo de processamento: " << elapsed.count() << " segundos\n";

        if (path.empty()) {
            cout << "Não existe caminho entre " << a << " e " << b << "." << endl;
        } else {
            cout << "Caminho encontrado:" << endl;

            double total = 0.0;

            for (int i = 0; i < (int)path.size()-1; i++) {
                string u = path[i];
                string v = path[i+1];

                double w = 0;
                for (auto &[dst, peso] : graph[u]) {
                    if (dst == v) {
                        w = peso;
                        break;
                    }
                }

                cout << "   " << u << " -> " << v << "  (" << w << " km)" << endl;
                total += w;
            }

            cout << "Distância total: " << total << " km" << endl;
        }
    }

    return 0;
}
