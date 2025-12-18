"""
Controller da aplicação 3D.
Responsável por:
1. Gerenciar a forma 2D selecionada (Quadrado, Triângulo, Círculo).
2. Gerenciar o tipo de sweep aplicado (Linear, Revolve, Helix, interpolation).
3. Armazenar e atualizar parâmetros de cada primitiva e sweep.
4. Atualizar a cena 3D no plotter do PyVistaQt.
"""

import pyvista as pv
from back import primitives
from back.sweep import linear, revolve, helix, interpolation

class Controller:
    # Inicializacao
    def __init__(self, plotter):
        self.plotter = plotter
        
        self.forma_selecionada = None    # forma 2D selecionada
        self.tipo_sweep = None     # tipo de sweep selecionado
        self.ator_atual = None     # ator atual na cena
        
        # parâmetros da primitiva
        self.tamanho_primitiva = 0.5
        self.plano_primitiva = 'xy'

        # parâmetros sweep: linear
        self.altura_linear = 5.0
        self.eixo_linear = 'z'

        # parâmetros sweep: revolve
        self.raio_revolve = 2.0 

        # parâmetros sweep: helix
        self.raio_helix = 2.0
        self.voltas_helix = 3.0
        self.altura_helix = 5.0

        # parâmetros sweep: interpolação 
        self.altura_interp = 5.0
        self.forma_final_interp = 'circulo'
        self.tamanho_final_interp = 1.0

    # --- Setters primitiva ---
    def set_tamanho_primitiva(self, valor):
        self.tamanho_primitiva = valor
        if self.forma_selecionada: self.atualizar_cena()

    def set_plano_primitiva(self, valor):
        self.plano_primitiva = valor[:2].lower()
        if self.forma_selecionada: self.atualizar_cena()

    # --- Setters linear ---
    def set_altura_linear(self, valor):
        self.altura_linear = valor
        if self.tipo_sweep == 'linear': self.atualizar_cena()

    def set_eixo_linear(self, valor):
        self.eixo_linear = valor.lower()
        if self.tipo_sweep == 'linear': self.atualizar_cena()

    # --- Setters revolve ---
    def set_raio_revolve(self, valor):
        self.raio_revolve = valor
        if self.tipo_sweep == 'revolve': self.atualizar_cena()

    # --- Setters helix ---
    def set_raio_helix(self, valor):
        self.raio_helix = valor
        if self.tipo_sweep == 'helix': self.atualizar_cena()

    def set_voltas_helix(self, valor):
        self.voltas_helix = valor
        if self.tipo_sweep == 'helix': self.atualizar_cena()

    def set_altura_helix(self, valor):
        self.altura_helix = valor
        if self.tipo_sweep == 'helix': self.atualizar_cena()

    # --- Setters selecao ---
    def set_forma(self, forma_key, state):
        if state:
            self.forma_selecionada = forma_key
            self.atualizar_cena()

    def set_tipo_sweep(self, tipo_sweep_key, state):
        if state:
            self.tipo_sweep = tipo_sweep_key
            self.atualizar_cena()

    # setter interpolacao
    def set_altura_interp(self, valor):
        self.altura_interp = valor
        if self.tipo_sweep == 'interp': self.atualizar_cena()

    def set_forma_final_interp(self, valor):
        self.forma_final_interp = valor
        if self.tipo_sweep == 'interp': self.atualizar_cena()
        
    def set_tamanho_final_interp(self, valor):
        self.tamanho_final_interp = valor
        if self.tipo_sweep == 'interp': self.atualizar_cena()

    # Atualiza a cena 3D
    def atualizar_cena(self):
        # Remove ator atual
        if self.ator_atual:
            self.plotter.remove_actor(self.ator_atual)
            self.ator_atual = None

        # Verifica se há forma selecionada, por garantia
        if not self.forma_selecionada:
            return

        # Gera primitiva
        malha_2d = None
        if self.forma_selecionada == 'quadrado':
            malha_2d = primitives.criar_quadrado(tamanho=self.tamanho_primitiva, plano=self.plano_primitiva)
        elif self.forma_selecionada == 'circulo':
            malha_2d = primitives.criar_circulo(tamanho=self.tamanho_primitiva, plano=self.plano_primitiva)
        elif self.forma_selecionada == 'triangulo':
            malha_2d = primitives.criar_triangulo(tamanho=self.tamanho_primitiva, plano=self.plano_primitiva)
        
        # Verifica se a primitiva foi criada, por garantia
        if malha_2d is None:
            return

        # Gera 3D
        malha_final = None
        
        # Sem sweep, apenas a primitiva 2D
        if self.tipo_sweep is None:
            self.ator_atual = self.plotter.add_mesh(
                malha_2d, color='lightblue', show_edges=True, line_width=2
            )
        else:
            if self.tipo_sweep == 'linear':
                malha_final = linear.aplicar_sweep_linear(
                    malha_2d, altura=self.altura_linear, eixo=self.eixo_linear
                )
            elif self.tipo_sweep == 'revolve':
                # Passando parâmetro de raio
                malha_final = revolve.aplicar_sweep_revolve(
                    malha_2d, raio_caminho=self.raio_revolve
                )
            elif self.tipo_sweep == 'helix':
                # Passando todos os parâmetros da mola
                malha_final = helix.aplicar_sweep_helix(
                    malha_2d, 
                    raio_caminho=self.raio_helix, 
                    voltas=self.voltas_helix, 
                    altura=self.altura_helix
                )
            elif self.tipo_sweep == 'interp': 
                malha_final = interpolation.aplicar_interpolacao(
                    malha_2d,
                    forma_alvo=self.forma_final_interp,
                    altura=self.altura_interp,
                    tamanho_alvo=self.tamanho_final_interp
                )
                
            # Adiciona a malha final à cena
            if malha_final:
                self.ator_atual = self.plotter.add_mesh(
                    malha_final, 
                    color='lightblue', 
                    lighting=True,
                    line_width=1
                )