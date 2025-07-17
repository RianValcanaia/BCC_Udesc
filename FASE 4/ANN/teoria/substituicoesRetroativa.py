def substituicoes_retroativas(A, b): # funcao da substituicao retroativa
    n = len(A)  # tamanho da matriz(numero de variaveis)
    x = n * [0] # inicializando o vetor solucao
    for i in range(n-1,-1,-1):  # criando um looping que percorre as equações de baixo para cima
        S = 0
        for j in range(i+1,n): 
            S = S + A[i][j]*x[j]  # calcula a soma dos termos das variaveis
        x[i] = (b[i]-S)/A[i][i]  # calcula o valor do x[i] isolando a variavel da equacao
    return x

A = [(2, 3, -1), 
     (0,-2,-1), 
     (0,0,5)]

b = [5,-7,15]

x = substituicoes_retroativas(A, b)
print(x)

