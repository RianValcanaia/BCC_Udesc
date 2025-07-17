def substituicoes_retroativas(A, b): # funcao da substituicao retroativa
    n = len(A)  # tamanho da matriz(numero de variaveis)
    x = n * [0] # inicializando o vetor solucao
    for i in range(n-1,-1,-1):  # criando um looping que percorre as equações de baixo para cima
        S = 0
        for j in range(i+1,n): 
            S = S + A[i][j]*x[j]  # calcula a soma dos termos das variaveis
        x[i] = (b[i]-S)/A[i][i]  # calcula o valor do x[i] isolando a variavel da equacao
    return x

def eliminacao_gauss(A, b): # funcao que resolve o sistema Ax=b por eliminacao de gauss
    n = len(A)
    # etapa 1: eliminacao para transformar a matriz a em triangular superior
    for k in range(0, n-1):  # percorre cada linha da matriz
        for i in range(k+1, n):  # percorre as linhas abaixo da linha pivo
            # calculando o multiplicador para eliminar o elemento A[i][k]
            m = - A[i][k] / A[k][k]  
            # atualizar os elementos da linha i apartir da coluna k+1
            for j in range(k, n):  
                A[i][j] = A[i][j] + m * A[k][j]
            # atualiza o vetor de termos independentes
            b[i] = b[i] + m * b[k]
    x = substituicoes_retroativas(A, b)
    return x

A1 = [[-2,3,1], [2,1,-4], [4,10,-6]]
b1 = [-5,-9,2]
x = eliminacao_gauss(A1, b1)
print(x)