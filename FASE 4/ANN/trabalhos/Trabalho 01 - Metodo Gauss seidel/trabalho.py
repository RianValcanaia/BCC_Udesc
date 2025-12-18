# descobrindo a precisao necessaria
def casas_precisao(criterio):
    expoente = 0  # vamos achar o expoente, que no caso a precisão é expoente+1 se não for especificado a precisão
    temp = criterio
    while (temp < 1):  # enquando o criterio_parada < 1 
        temp *= 10  # multiplicamos por 10
        expoente += 1  # acrescentamos em expoente
    
    return expoente + 1  # precisão = expoente + 1

# Calculo Gauss-seidel
def ajusta_convergencia(A, b):  # funcao que ajusta a matriz para atingir critério de convergência
    for i in range(len(A)):  # for -> percorre linhas da matriz
        soma = 0  # inicia variavel de soma
        melhor_linha = i  # melhor linha que atende ao criterio de convergência
        
        for j in range(len(A[i])):  # for -> percorre cada elemento da linha i
            if i != j:  # não soma o valor na posicao i, pois é o pivo da linha
                soma += abs(A[i][j])  # soma o absoluto da posicao i,j
       
        if abs(A[i][i]) < soma:  # se o absoluto do pivo for menor que a soma da linha exceto o pivo, buscamos outra linha que atenda ao critério de convergência na posiçãoo i
            melhor_criterio = abs(A[i][i]) - soma  # definimos um melhor critêrio visando a diferenca da soma com o pivo 
           
            for k in range (i+1, len(A)):  # for -> percorre da linha i+1
                soma_k = 0  # iniciamos um variavel de soma
                
                for j in range (len(A[k])):  # for -> percorre cada elemento da linha k
                    if i != j:  # não queremos na o elemento da posicao i, pois estamos procurando uma linha substitua para a linha i 
                        soma_k += abs(A[k][j])  # soma o absoluto 
                
                criterio_k = abs(A[k][i]) - soma_k  # criterio a ser analizado para a troca de linhas

                if criterio_k > melhor_criterio:  # se o criterio_k for maior que o melhor_criterio, melhor_criterio = criterio_k
                    melhor_criterio = criterio_k  
                    melhor_linha = k  # guarda a linha k para depois fazer o swap

        if melhor_linha != i:  # se achamos uma linha melhor fazemos o swap
            A[i], A[melhor_linha] = A[melhor_linha], A[i]  # troca linhas da matriz A
            b[i], b[melhor_linha] = b[melhor_linha], b[i]  # traca elementos do vetor dos termos independentes 

# Calculo de arredondamento segundo norma (Pode ser usado a funcao round() no lugar dessa)
def arredondamento(numero, casas_decimais):
    fator = 10 ** casas_decimais  # 10^casas_decimais
    numero = numero * fator  # multiplica por 10^(casas_decimais)

    parte_inteira = int(numero)  # pega a parte inteira do numero 
    parte_decimal = numero - parte_inteira  # pega a parte decimal do numero

    if parte_decimal == 0.5:  # se a parte decimal for igual a 5
        if parte_inteira % 2 != 0:  # neste caso se a parte_inteira for impar acrescentamos 1 unidade para o proximo par
            parte_inteira += 1
    elif parte_decimal > 0.5: # se a parte decimal for maior que 0.5 acresentamos na parte_inteira 1 unidade
        parte_inteira += 1

    return parte_inteira / fator  # devolvemos a parte inteira sem a parte decimal, dividito pelo fator inicial

# Cálculo Gauss-Seidel
def gauss_seidel(A, b, x_inicial, criterio_parada, precisao):
    x_resultado = x_inicial.copy()  # inicia o vetor resultado com uma copia do x_inicial
    primeira_iteracao = True  # para iterar pela primeira vez

    while primeira_iteracao or (diferenca_maior > criterio_parada):
        primeira_iteracao = False  # Falso após a primeira iteracao
        diferenca_maior = 0  # inicia a diferencia maior pois usamos norma infinita

        for i, linha in enumerate(A):  # for -> percorre linha por linha na matriz
            soma = 0  # inicia a soma 

            for j, elemento in enumerate(linha):  # for -> percorre cada elemento da linha i
                if j != i:  # não usamos o elemento da linha i pois esse passa dividindo a soma
                    soma += elemento * x_resultado[j]  # pega o elemento da matriz * o meu valor do vetor resultado

            novo_valor = (b[i] - soma)/A[i][i]  # calcula novo valor subtraindo a soma do valor em b[i] e dividindo pelo elemento na pos i que ignoramos anteriormente
            novo_valor = arredondamento(novo_valor, precisao)  # ajustamos o valor arredondado
            diferenca = abs(x_resultado[i] - novo_valor)  # calculamos a diferenca para usar no critério de parada

            if diferenca > diferenca_maior:  # se a diferenca for maior que a diferenca maior então diferenca_maior = diferenca
                diferenca_maior = diferenca

            x_resultado[i] = novo_valor  # atualizamos o vetor resultado
    return x_resultado

# Vetor residuo
def qualidadeAjusteVetorResiduo(A, b, x_resultado): # A.x̄ - b -> vai usar a matriz A e multiplica com o vetor x_resultado, depois faz a diferença com o vetor b
    vetResiduo = [] # apenas a declaração do vetor
    for i in range (len(x_resultado)): # iterador das linhas
        soma = 0 # soma resultante da multiplicação de matrizes
        for j in range(len(A[i])): # iterador das colunas, poderia iterar utilizando o mesmo parâmetro do iterador das linhas (o tamanho do vetor resultado, que sempre terá como tamanho a quantidade de linhas da matriz A, se não não tem como fazer o produto matricial), mas ao utilizar o tamanho da linha é possível incluir matrizes nao quadradas na solução. Esse foi um problema que percebi nos testes.
            soma += A[i][j] * x_resultado[j] # produto matricial
        residuo = soma - b[i] # quando termino de iterar todos as colunas da matriz e eu ja tenho o resultado da primeira linha da matriz resultante, eu tiro a diferença com a linha respectiva do vetor de termos independentes.
        vetResiduo.append(residuo) # no final apenas adiciona o residuo no fim do vetor residuo, o método .append() faz exatamente isso
    return vetResiduo


# Main:
## Matriz dos coeficientes
A = [[7,1,-1,4],
     [1,-5,1,-2],
     [1, 0, 3,-1],
     [3, 1, -3, 8]] 

## Vetor dos termos independetes
b = [-10, 2, 11,-24] 

## Criterio de parada
criterio_parada = 0.0005

## Vetor inicial
x_inicial = [-0.3, 1.3, 2.8,-2.3]

precisao = casas_precisao(criterio_parada)  # Defini o numero de casas de precisão
ajusta_convergencia(A, b)  # Ajusta linhas da matriz dos coeficientes e vetor dos termos independentes

x_resultado = gauss_seidel(A, b, x_inicial, criterio_parada, precisao)  # chama a função gauss_seidel

## printa resultado
print("x̄ =")
for valor in x_resultado:
    print(f"{valor:.{precisao}f}")

vetResiduo = qualidadeAjusteVetorResiduo(A, b, x_resultado) # chama a função do vetor residuo

## printa vetor resíduo
print("\nVetor Residuo:")
for valor in vetResiduo: # printar o vetor residuo
    print(f"{valor:.{precisao}f}") # .{precisao}f indica que é para formatar o print com numero de precisao de casas após a virgula