; Definicao da classe
.class public mdc
.super java/lang/Object

; Construtor padrao
.method public <init>()V
    aload_0
    invokespecial java/lang/Object/<init>()V
    return
.end method

; Metodo estatico mdc_calc(II)I
; Parametros:
;   - int a (local var 0)
;   - int b (local var 1)
;   - int r (local var 2)
.method public static mdc_calc(II)I
    .limit stack 2
    .limit locals 3

    Loop:
        iload_1
        ifeq Fim

        iload_0     ; Carrega a na pilha
        iload_1     ; Carrega b na pilha
        irem        ; Calcula o resto da divisao 
        istore_2    ; Armazena o resultado em r

        iload_1     ; Carrega b na pilha
        istore_0    ; Armazena em a (variavel local 0)

        iload_2     ; Carrega r na pilha
        istore_1    ; Armazena em b (variavel local 1)

        goto Loop   ; Volta para o inicio do loop

    Fim:
        iload_0     ; Carrega 'a' para a pilha.
        ireturn     ; Retorna o valor inteiro no topo da pilha
.end method

.method public static main([Ljava/lang/String;)V
    .limit stack 4  
    .limit locals 4 

    ; Cria um novo Scanner para ler a entrada do sistema
    new java/util/Scanner
    dup
    getstatic java/lang/System/in Ljava/io/InputStream;
    invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V
    astore_1 ; Armazena Scanner na variavel local 1

    ; Le a
    aload_1 ; Carrega o Scanner
    invokevirtual java/util/Scanner/nextLine()Ljava/lang/String;
    invokestatic java/lang/Integer/parseInt(Ljava/lang/String;)I
    istore_2 ; Armazena a na variavel local 2

    ; Le b
    aload_1 ; Carrega o Scanner
    invokevirtual java/util/Scanner/nextLine()Ljava/lang/String;
    invokestatic java/lang/Integer/parseInt(Ljava/lang/String;)I
    istore_3 ; Armazena b na variavel local 3

    getstatic java/lang/System/out Ljava/io/PrintStream;
    iload_2 ; Carrega a
    iload_3 ; Carrega b
    invokestatic mdc/mdc_calc(II)I ; Chama o metodo mdc
    invokevirtual java/io/PrintStream/println(I)V ; Imprime o resultado

    return
.end method