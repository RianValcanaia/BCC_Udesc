import heapq

def printa(mapa):
    print("Caminho no labirinto:")
    for i in range(len(mapa)):
        for j in range(len(mapa[0])):
            if mapa[i][j] == 2 and (mapa[i][j-1]==2 or mapa[i][j+1]==2):
                print("-", end="")
            elif mapa[i][j] == 2 and (mapa[i-1][j]==2 or mapa[i+1][j]==2):
                print("|", end="")
            elif mapa[i][j] == 0:
                print(" ", end="")
            else:
                print("#", end="")
        print()

def heuristica(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def A_star(mapa, inicio, fim):
    '''
        O algoritmo A* utiliza uma heurística para encontrar o caminho mais curto, 
        ele utiliza a formula: f(n) = g(n) + h(n)
            onde:
            f(n) = custo total estimado do caminho através do nó n
            g(n) = custo do caminho do nó inicial até o nó n
            h(n) = custo estimado do nó n até o nó final (heurística)

        sendo assim o próximo nó a ser explorado é aquele com o menor valor de f(n)
    '''
    linhas, colunas = len(mapa), len(mapa[0])
    movimentos = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    open_set = []  # guarda a tupla: (prioridade, posição)

    heapq.heappush(open_set, (0 + heuristica(inicio, fim), inicio))
    veio_de = {}  # para reconstruir o caminho
    custo_g = {inicio: 0}  # custo do inicio ate o no

    while open_set:
        _, atual = heapq.heappop(open_set)  # pega o no com menor prioridade

        if atual == fim:  # verifica se chegou ao destino
            caminho = []
            while atual in veio_de:
                caminho.append(atual)
                atual = veio_de[atual]
            caminho.append(inicio)
            caminho.reverse()
            return caminho
        
        for dx, dy in movimentos:  # percorre os 4 vizinhos
            vizinho = (atual[0] + dx, atual[1] + dy)
            if 0 <= vizinho[0] < linhas and 0 <= vizinho[1] < colunas:
                if mapa[vizinho[0]][vizinho[1]] == 1:  # se for parede ignora
                    continue

                novo_custo = custo_g[atual] + 1  # custo do atual para o vizinho
                
                if vizinho not in custo_g or novo_custo < custo_g[vizinho]:
                    custo_g[vizinho] = novo_custo
                    prioridade = novo_custo + heuristica(vizinho, fim)
                    heapq.heappush(open_set, (prioridade, vizinho))
                    veio_de[vizinho] = atual
    return None  
    
if __name__ == "__main__":
    mapa = [
        [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,],
        [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,],
        [1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,],
        [1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,],
        [1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,],
        [1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,],
        [1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,],
        [1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,],
        [1,0,1,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,],
        [1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,],
        [1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,],
        [1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,],
        [1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,],
        [1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,],
        [1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,],
        [1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,],
        [1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,],
        [1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,],
        [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,],
        [1,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,],
        [1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,],
        [1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,1,],
        [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,],
        [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,]
    ]

    inicio = (1,1)
    fim = (len(mapa)-2, len(mapa[0])-2)

    caminho = A_star(mapa, inicio, fim)

    if caminho:
        print("Caminho encontrado:")
        for passo in caminho:
            mapa[passo[0]][passo[1]] = 2
        printa(mapa)
    else:
        print("Nenhum caminho possível.")