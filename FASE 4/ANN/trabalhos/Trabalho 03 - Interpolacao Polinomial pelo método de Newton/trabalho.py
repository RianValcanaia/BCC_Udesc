from sympy import symbols, lambdify, simplify
import matplotlib.pyplot as plt
import numpy as np

def plot_dispersao(pontos, polinomio, valor):
    # separa os valores de xi e yi
    xs = [p[0] for p in pontos]
    ys = [p[1] for p in pontos]

    # encontra o xmax e xmin e adiciona uma margem de 10% em cada lado
    xmin, xmax = min(xs), max(xs)
    margem = (xmax - xmin) * 0.1
    xmin -= margem
    xmax += margem

    # vetor de pontos entre xmin e xmax com 20 pontos para ficar mais suave a curva
    x_plot = np.linspace(xmin, xmax, len(pontos)*20)
    y_plot = polinomio(x_plot)

    
    plt.figure(figsize=(8, 5))  # cria o gráfico de tamanho 8x5 pol
    plt.plot(x_plot, y_plot, label='Polinômio interpolador', color='blue')  # desenha a curva em azul ligando os pontos (x_plot_i,y_plot_i)
    plt.scatter(xs, ys, color='red', label='Pontos dados')  # marca os pontos dados de vermelho

    if valor is not None:  # marca o ponto do valor estimado sobre a curva
        y_valor = polinomio(valor)
        plt.scatter([valor], [y_valor], color='green', marker='o', s=80, label=f'Ponto estimado ({valor:.2f}, {y_valor:.3f})')

    plt.title('Interpolação Polinomial de Newton')  # titulo o gráfico
    plt.xlabel('x')  # legenda reta x
    plt.ylabel('y')  # legenda reta y
    plt.grid(True)  # ativa a grade de fundo facilitando a visualização
    plt.legend()  # exibe a legenda determinada por label
    plt.tight_layout()  # ajusta automaticamente os espaços(margens, rótulos, legendas)
    plt.show()  # mostra

def diferencas_divididas(pontos):
    tam = len(pontos)  # tamanho do vetor pontos
    dd = [[0 for _ in range(tam)] for _ in range(tam)]  # cria a matriz triangular e inicia com zeros

    for i in range(tam):
        dd[i][0] = pontos[i][1]  # na coluna 0 da diferenças divididas adiciona f(xi), de ordem 0

    # percorre a matriz triangular fazendo as diferenças divididas
    for j in range(1, tam):  # j percorre [1,tam), pois a coluna 0 já está preenchida
        for i in range (tam - j):  # i percorre [0, tam -j)
            num = dd[i+1][j-1] - dd[i][j-1]  # j-1 pois j tá indexado em 1
            den = pontos[i+j][0] - pontos[i][0]
            dd[i][j] = num/den
    
    return dd  # retorna a matriz de diferenças divididas

def selecionar_pontos_proximos(valor, pontos, grau):
    dist_e_ponto = []  # cria um vetor vazio

    # para cada ponto (xi,yi) em pontos calcula a distância e armazena em dist_e_ponto (distância,(xi,yi)) 
    for ponto in pontos:
        distancia = abs(ponto[0] - valor)  # distancia é xi - valor
        dist_e_ponto.append((distancia, ponto)) 
    
    dist_e_ponto.sort(key=lambda x:x[0])  # ordena pela chave distância

    pontos_proximos = [p[1] for p in dist_e_ponto[:grau+1]]  # pega os grau+1 pontos com distância menor

    pontos_proximos.sort(key=lambda p:p[0])  # ordena os pontos pela chave xi

    return pontos_proximos  # retorna o vetor de tupla de pontos

def polinomio_newton(valor, pontos, grau):
    global x  # utiliza nesse escopo a variável x declarada no global
    tam = len(pontos)

    pontos_proximos = selecionar_pontos_proximos(valor, pontos, grau)  # seleciona os pontos proximos do valor 
    dd = diferencas_divididas(pontos_proximos)  # faz a diferença dividida dos pontos próximos

    coef = [dd[0][j] for j in range(grau + 1)]  
    pol = coef[0] # inicia o polinômio com o valor
    termo = 1

    # Calcula Pn(x) = a0 + a1(x-x0)+a2(x-x0)(x-x1)+...+an(x-x0)(x-x1)...(x-xn-1) 
    for i in range(grau):  # i percorre [1,grau)
        termo *= (x - pontos_proximos[i][0])  # (x-x0),(x-x0)(x-x1),(x-x0)(x-x1)(x-x2)...
        pol += coef[i+1] * termo  # ai(x-x0)...(x-xn-1)
    
    return pol  # retorna o polinomio 

def estimativa_erro(valor, pontos, dd, erro_max):
    print("============ Estimativa de erro ============\n")
    tam = len(pontos)

    melhor_grau = -1  # inicia o melhor_grau

    for grau in range(1, tam-1):  # i percorre [1, tam-2]
        pontos_proximos = selecionar_pontos_proximos(valor, pontos, grau)  # seleciona os pontos proximo ao valor

        print(f"|E{grau}(x)| = |", end='')

        produto = 1
        for i in range(grau+1):  # i percorre [0,grau]
            print(f"({valor} - {pontos_proximos[i][0]})", end='')
            produto *= (valor-pontos_proximos[i][0])
        
        dd_max = max(abs(dd[i][grau+1]) for i in range(tam - grau))  # encontra a maior distância dividida de ordem grau+1, na coluna grau+1, i percorre [0,tam-grau)

        erro_estimado = abs(produto * dd_max)  
        print("| * {:.6f}".format(dd_max), end='')
        print(" = {:.6f}".format(erro_estimado))
    
        if erro_estimado < erro_max and melhor_grau == -1:  # evita que entre mais de uma vez na condição, pois queremos o menor grau com melhor erro
            melhor_grau = grau
    
    if melhor_grau == -1: melhor_grau = tam-1  # caso não encontrar uma estimativa melhor que erro_max então melhor_grau = tam-1

    return melhor_grau

def printaDD(dd):
    # printa a matriz de diferenças divididas
    print("============ Tabela Diferenças Divididas ============\n")
    for i in range(0,len(dd)): print(f"    Ordem {i} ", end='')  
    print()
    for i in range(len(dd)+1):
        for j in range (len(dd) -i):
            if dd[i][j] < 0: print("| {:.6f} ".format(dd[i][j]), end='')
            else: print("|  {:.6f} ".format(dd[i][j]), end='')
        print()


# ======= main =======
x = symbols('x')  
pontos = [(0, -2.78), (0.5, -2.241), (1, -1.65), (1.5, -0.594), (2, 1.34), (2.5, 4.564)]  # pontos conhecidos
valor = 1.23  # valor que queremos encontrar
erro_max = 10**-3  # erro max para considerar na estimativa de erro

dd = diferencas_divididas(pontos)  # diferenças divididas
printaDD(dd)
melhor_grau = estimativa_erro(valor, pontos, dd, erro_max)  # encontra o melhor grau, tq estimativa de erro < erro_max
pol_expr = simplify(polinomio_newton(valor, pontos, melhor_grau))  # cria o polinômio de grau = melhor_grau
pol = lambdify(x, pol_expr) # lambdifica a expressão


print("\n============ Resultados ============\n")
print(f"Melhor polinômio = P{melhor_grau}(x)")
print(f"P{melhor_grau}(x) = {pol_expr}")
print(f"f({valor}) ≈ P{melhor_grau}({valor}) ≈ {pol(valor)}\n\n") 
plot_dispersao(pontos, pol, valor)