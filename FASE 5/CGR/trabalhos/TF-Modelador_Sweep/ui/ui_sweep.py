"""
Define o widget "Sweep" do painel lateral da aplicação 3D.
Funcionalidades principais:
1. Permite escolher o tipo de Sweep: Linear, Revolução ou Helicoidal.
2. Cada tipo tem seu próprio painel de parâmetros com controles interativos.
3. Os valores dos controles são enviados para o Controller que gerencia a lógica 3D.
4. Gerencia visibilidade dos painéis de parâmetros ao selecionar diferentes tipos de Sweep.
"""

from PyQt6.QtWidgets import (QWidget, QVBoxLayout, QLabel, QPushButton, 
                             QButtonGroup, QDoubleSpinBox, QComboBox, QFrame)

# Estilos reutilizáveis para QDoubleSpinBox (nao funcionando)
icone_mais = "url(data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAyNCAyNCIgZmlsbD0id2hpdGUiPjxwYXRoIGQ9Ik0xOSAxM2gtNnY2aC0ydi02SDV2LTJoNlY1aDJ2Nmg2djJ6Ii8+PC9zdmc+)"
icone_menos = "url(data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAyNCAyNCIgZmlsbD0id2hpdGUiPjxwYXRoIGQ9Ik0xOSAxM0g1di0yaDE0djJ6Ii8+PC9zdmc+)"

SPIN_STYLE = f"""
    QDoubleSpinBox {{
        background-color: #606060; color: white; padding: 4px;
        border-radius: 4px; border: 1px solid #404040; font-size: 12px;
    }}
    QDoubleSpinBox::up-button, QDoubleSpinBox::down-button {{
        background-color: #757575; width: 24px; border-left: 1px solid #404040; border-radius: 0px;
    }}
    QDoubleSpinBox::up-button {{ border-top-right-radius: 4px; }}
    QDoubleSpinBox::down-button {{ border-bottom-right-radius: 4px; }}
    QDoubleSpinBox::up-button:hover, QDoubleSpinBox::down-button:hover {{ background-color: #909090; }}
    QDoubleSpinBox::up-arrow {{ image: {icone_mais}; width: 12px; height: 12px; }}
    QDoubleSpinBox::down-arrow {{ image: {icone_menos}; width: 12px; height: 12px; }}
"""

class WidgetSweep(QWidget):
    # Inicializacao
    def __init__(self, controller):
        super().__init__()
        self.controller = controller
        self.init_ui()

    # Inicializacao da interface
    def init_ui(self):
        # Layout Principal
        layout_principal = QVBoxLayout()
        layout_principal.setContentsMargins(0, 0, 0, 0)
        self.setLayout(layout_principal)

        # Título
        lbl_titulo = QLabel("Diretriz (Sweep)")
        lbl_titulo.setStyleSheet("font-weight: bold; font-size: 14px; color: #CDDC39; margin-bottom: 10px;")
        layout_principal.addWidget(lbl_titulo)

        # Botões de Seleção do Tipo de Sweep
        self.grupo_botoes = QButtonGroup(self)
        self.grupo_botoes.setExclusive(True)

        # Adiciona os botões
        self.adicionar_botao("Linear", "linear", layout_principal)
        self.adicionar_botao("Revolução", "revolve", layout_principal)
        self.adicionar_botao("Helicoidal", "helix", layout_principal)
        self.adicionar_botao("Interpolação", "interp", layout_principal)

        # Cria os painéis de parâmetros
        # Painel Linear
        self.painel_linear = self.criar_painel_linear()
        layout_principal.addWidget(self.painel_linear)
        self.painel_linear.hide()

        # Painel Revolução
        self.painel_revolve = self.criar_painel_revolve()
        layout_principal.addWidget(self.painel_revolve)
        self.painel_revolve.hide()
        
        # Painel Helicoidal
        self.painel_helix = self.criar_painel_helix()
        layout_principal.addWidget(self.painel_helix)
        self.painel_helix.hide()

        # Painel Interpolação
        self.painel_interp = self.criar_painel_interp() # <--- NOVO PAINEL
        layout_principal.addWidget(self.painel_interp)
        self.painel_interp.hide()

        # Espaço Flexível no Final 
        layout_principal.addStretch() 

    # Logica para selecao do tipo de Sweep
    def clicar_botao_tipo(self, key):
        self.controller.set_tipo_sweep(key, True)
        
        # Esconde todos primeiro
        self.painel_linear.hide()
        self.painel_revolve.hide()
        self.painel_helix.hide()
        self.painel_interp.hide()

        # Mostra o correspondente
        if key == 'linear':
            self.painel_linear.show()
        elif key == 'revolve':
            self.painel_revolve.show()
        elif key == 'helix':
            self.painel_helix.show()
        elif key == 'interp':
            self.painel_interp.show()

    # Painel de parametros Linear
    def criar_painel_linear(self):
        # Criacao do Frame
        painel = QFrame()
        painel.setStyleSheet("background-color: #454545; border-radius: 5px; margin-top: 10px;")
        layout = QVBoxLayout()
        painel.setLayout(layout)

        # Adiciona os widgets
        layout.addWidget(self.criar_label("Parâmetros Linear:"))
        
        # Altura
        layout.addWidget(self.criar_label("Altura:"))
        spin = QDoubleSpinBox()
        spin.setRange(0.1, 100.0); spin.setValue(5.0); spin.setSingleStep(0.5)
        spin.setStyleSheet(SPIN_STYLE)
        spin.valueChanged.connect(self.controller.set_altura_linear)
        layout.addWidget(spin)
        
        # Eixo de Extrusao
        layout.addWidget(self.criar_label("Eixo de Extrusão:"))
        combo = QComboBox()
        combo.addItems(["Z", "X", "Y"])
        combo.setStyleSheet("background-color: #606060; color: white; padding: 2px;")
        combo.currentTextChanged.connect(lambda t: self.controller.set_eixo_linear(t[0]))
        layout.addWidget(combo)
        return painel

    # Painel de parametros Revolucao
    def criar_painel_revolve(self):
        # Criacao do Frame
        painel = QFrame()
        painel.setStyleSheet("background-color: #454545; border-radius: 5px; margin-top: 10px;")
        layout = QVBoxLayout()
        painel.setLayout(layout)
        
        # Adiciona os widgets
        layout.addWidget(self.criar_label("Parâmetros Revolução:"))

        # Raio do Caminho
        layout.addWidget(self.criar_label("Raio do Caminho:"))
        spin = QDoubleSpinBox()
        spin.setRange(0.0, 50.0); spin.setValue(2.0); spin.setSingleStep(0.1)
        spin.setStyleSheet(SPIN_STYLE)
        spin.valueChanged.connect(self.controller.set_raio_revolve)
        layout.addWidget(spin)
        return painel

    # Painel de parametros Helicoidal
    def criar_painel_helix(self):
        # Criacao do Frame
        painel = QFrame()
        painel.setStyleSheet("background-color: #454545; border-radius: 5px; margin-top: 10px;")
        layout = QVBoxLayout()
        painel.setLayout(layout)

        # Adiciona os widgets
        layout.addWidget(self.criar_label("Parâmetros Helicoidal:"))

        # Raio da Mola
        layout.addWidget(self.criar_label("Raio da Mola:"))
        spin_r = QDoubleSpinBox()
        spin_r.setRange(0.1, 50.0); spin_r.setValue(2.0); spin_r.setSingleStep(0.1)
        spin_r.setStyleSheet(SPIN_STYLE)
        spin_r.valueChanged.connect(self.controller.set_raio_helix)
        layout.addWidget(spin_r)

        # Numero de Voltas
        layout.addWidget(self.criar_label("Número de Voltas:"))
        spin_t = QDoubleSpinBox()
        spin_t.setRange(0.5, 50.0); spin_t.setValue(3.0); spin_t.setSingleStep(0.5)
        spin_t.setStyleSheet(SPIN_STYLE)
        spin_t.valueChanged.connect(self.controller.set_voltas_helix)
        layout.addWidget(spin_t)

        # Altura Total
        layout.addWidget(self.criar_label("Altura Total:"))
        spin_h = QDoubleSpinBox()
        spin_h.setRange(0.1, 100.0); spin_h.setValue(5.0); spin_h.setSingleStep(0.5)
        spin_h.setStyleSheet(SPIN_STYLE)
        spin_h.valueChanged.connect(self.controller.set_altura_helix)
        layout.addWidget(spin_h)
        return painel

    # Painel de param interpolação
    def criar_painel_interp(self):
        painel = QFrame()
        painel.setStyleSheet("background-color: #454545; border-radius: 5px; margin-top: 10px;")
        layout = QVBoxLayout()
        painel.setLayout(layout)

        layout.addWidget(self.criar_label("Parâmetros Interpolação:"))

        # Altura
        layout.addWidget(self.criar_label("Altura:"))
        spin_h = QDoubleSpinBox()
        spin_h.setRange(0.1, 100.0); spin_h.setValue(5.0); spin_h.setSingleStep(0.5)
        spin_h.setStyleSheet(SPIN_STYLE)
        spin_h.valueChanged.connect(self.controller.set_altura_interp)
        layout.addWidget(spin_h)

        # Forma Alvo
        layout.addWidget(self.criar_label("Forma Final (Topo):"))
        combo = QComboBox()
        combo.addItems(["Círculo", "Quadrado", "Triângulo"])
        combo.setStyleSheet("background-color: #606060; color: white; padding: 2px;")
        
        # Mapa de nomes para chaves
        def converter_combo(texto):
            mapa = {"Círculo": "circulo", "Quadrado": "quadrado", "Triângulo": "triangulo"}
            self.controller.set_forma_final_interp(mapa[texto])
            
        combo.currentTextChanged.connect(converter_combo)
        layout.addWidget(combo)

        # Tamanho do Topo
        layout.addWidget(self.criar_label("Tamanho Final:"))
        spin_t = QDoubleSpinBox()
        spin_t.setRange(0.1, 50.0); spin_t.setValue(1.0); spin_t.setSingleStep(0.1)
        spin_t.setStyleSheet(SPIN_STYLE)
        spin_t.valueChanged.connect(self.controller.set_tamanho_final_interp)
        layout.addWidget(spin_t)

        return painel

    # Helper para criar labels
    def criar_label(self, text):
        label = QLabel(text)
        if "Parâmetros" in text:
            label.setStyleSheet("color: #ddd; font-size: 11px; font-weight: bold;")
        return label

    # Helper para adicionar botões
    def adicionar_botao(self, text, key, layout):
        botao = QPushButton(text)
        botao.setCheckable(True)
        botao.setFixedHeight(40)
        botao.setStyleSheet("""
            QPushButton {
                background-color: #505050; border-radius: 5px; border: 1px solid #303030;
            }
            QPushButton:hover { background-color: #606060; }
            QPushButton:checked { 
                background-color: #CDDC39; color: black; font-weight: bold; border: 1px solid #F0F4C3;
            }
        """)
        botao.clicked.connect(lambda: self.clicar_botao_tipo(key))
        self.grupo_botoes.addButton(botao)
        layout.addWidget(botao)