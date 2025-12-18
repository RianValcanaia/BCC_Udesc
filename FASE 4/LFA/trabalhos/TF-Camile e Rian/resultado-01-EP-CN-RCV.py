class Pilha:
    def __init__(self):
        self.itens = ['#']

    def empilhar(self, item):
        self.itens.append(item)

    def desempilhar(self):
        if not self.vazia():
            return self.itens.pop()
        return None

    def vazia(self):
        return len(self.itens) == 0

    def mostrar(self):
        itens_formatados = []
        for item in reversed(self.itens):  # Topo à esquerda
            if isinstance(item, tuple):
                if item[0] == 'h':
                    itens_formatados.append(f"h({item[1]},{item[2]}→{item[3]})")
                elif item[0] == 'p':
                    itens_formatados.append(f"p({item[1]}→{item[2]})")
            else:
                itens_formatados.append(str(item))
        return str(itens_formatados)


class AutomatoPilha:
    def __init__(self, n_discos, origem='A', destino='C'):
        self.estado_atual = "q0"  # uso de somente um estado
        self.n_discos = n_discos
        self.pilha = Pilha()
        self.torres = {
            'A': list(range(n_discos, 0, -1)),
            'B': [],
            'C': []
        }

        self.movimentos = 0
        self.passos_internos = 0

        if self.n_discos == 1:
            self.pilha.empilhar(('p', origem, destino))
            
        elif self.n_discos > 1:
            self.pilha.empilhar(('h', self.n_discos, origem, destino))

    def _obter_torre_auxiliar(self, origem, destino):
        return ({'A', 'B', 'C'} - {origem, destino}).pop()

    def _imprimir_passo(self, tipo_transicao, simbolo_consumido, disco=None):
        passo_total = self.movimentos + self.passos_internos
        print(f"\n--- Passo {passo_total} ---")

        tipo, *args = simbolo_consumido
        simbolo_str = f"h({args[0]},{args[1]}→{args[2]})" if tipo == 'h' else f"p({args[0]}→{args[1]})"

        if tipo_transicao == "inicial":
            n, origem, destino = args
            self.passos_internos += 1
            print(f"Transição: δ(q₀, ε, #) → 〈q₀, {simbolo_str}〉")
            if self.n_discos == 1:
                print(f"Transição: δ(q₀, ε, h(1,A→C) → 〈q₀, p({origem}→{destino})〉")
        elif tipo_transicao == "expandir":
            self.passos_internos += 1
            n, origem, destino = args
            auxiliar = self._obter_torre_auxiliar(origem, destino)
            derivacao = f"h({n-1},{origem}→{auxiliar})p({origem}→{destino})h({n-1},{auxiliar}→{destino})"
            print(f"Transição: δ(q₀, ε, {simbolo_str}) → 〈q₀, {derivacao}〉")
        elif tipo_transicao == "simplificar":
            self.passos_internos += 1
            n, origem, destino = args
            print(f"Transição: δ(q₀, ε, {simbolo_str} → 〈q₀, p({origem}→{destino})〉")
        elif tipo_transicao == "mover":
            self.movimentos += 1
            print(f"Ação: Mover disco {disco} de {args[0]} para {args[1]}")
            print(f"Transição: δ(q₀, ε, {simbolo_str}) → 〈q₀, ε〉")

        pilha_str = self.pilha.mostrar()
        print("Pilha (topo à esquerda):", pilha_str if pilha_str != '[]' else "vazia")

        print("Estado das Torres:")
        for pino in ['A', 'B', 'C']:
            discos = ' '.join(str(d) for d in self.torres[pino])
            print(f"  Pino {pino}: | {discos}")

    def executar(self):
        self._imprimir_passo("inicial", ('h', self.n_discos, 'A', 'C'))

        while not self.pilha.vazia():
            simbolo_topo = self.pilha.desempilhar()

            if simbolo_topo == '#':
                continue

            tipo, *args = simbolo_topo

            if tipo == 'h':
                n, origem, destino = args

                if n == 1:
                    self.pilha.empilhar(('p', origem, destino))
                    self._imprimir_passo("simplificar", simbolo_topo)
                else:
                    auxiliar = self._obter_torre_auxiliar(origem, destino)
                    self.pilha.empilhar(('h', n - 1, auxiliar, destino))
                    self.pilha.empilhar(('p', origem, destino))
                    self.pilha.empilhar(('h', n - 1, origem, auxiliar))
                    self._imprimir_passo("expandir", simbolo_topo)

            elif tipo == 'p':
                origem, destino = args

                if not self.torres[origem]:
                    print("ERRO: Tentativa de mover de torre vazia!")
                    break

                disco = self.torres[origem].pop()
                self.torres[destino].append(disco)
                self._imprimir_passo("mover", simbolo_topo, disco)

        print("\n--- Simulação Concluída ---")
        print(f"Número total de movimentos de disco: {self.movimentos}")


if __name__ == "__main__":
    print("--- Iniciando Simulação com Autômato com Pilha ---\n")
    try:
        numero_discos = int(input("Digite o número de discos: "))
        if numero_discos < 1:
            print("O número de discos deve ser pelo menos 1.")
        else:
            automato = AutomatoPilha(numero_discos, origem='A', destino='C')
            automato.executar()
    except ValueError:
        print("Entrada inválida. Por favor, digite um número inteiro.")
