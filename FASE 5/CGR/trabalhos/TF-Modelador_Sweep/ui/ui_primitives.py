"""
Define o widget "Primitives" do painel lateral da aplicação 3D.
Funcionalidades principais:
1. Permite selecionar a forma 2D a ser usada: Quadrado, Triângulo ou Círculo.
2. Painel de parâmetros da forma:
   - Tamanho 
   - Plano de desenho (XY, XZ, YZ)
3. Os valores e seleções são enviados para o Controller que gerencia a lógica 3D.
4. O painel de parâmetros fica escondido inicialmente e é mostrado ao selecionar uma forma.
"""

from PyQt6.QtWidgets import (QWidget, QVBoxLayout, QLabel, QPushButton, 
                             QButtonGroup, QDoubleSpinBox, QComboBox, QFrame)

class WidgetPrimitivas(QWidget):
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
        lbl_titulo = QLabel("Primitiva (2D)")
        lbl_titulo.setStyleSheet("font-weight: bold; font-size: 14px; color: #4db8ff; margin-bottom: 10px;")
        layout_principal.addWidget(lbl_titulo)

        # Botões de Seleção da Forma
        self.grupo_botoes = QButtonGroup(self)
        self.grupo_botoes.setExclusive(True)

        # Adiciona os botões
        self.adicionar_botao("Quadrado", "quadrado", layout_principal)
        self.adicionar_botao("Triângulo", "triangulo", layout_principal)
        self.adicionar_botao("Círculo", "circulo", layout_principal)

        # Painel de Parâmetros da Forma
        self.painel_parametros = QFrame()
        self.painel_parametros.setStyleSheet("background-color: #454545; border-radius: 5px; margin-top: 10px;")
        layout_parametros = QVBoxLayout()
        self.painel_parametros.setLayout(layout_parametros)

        # Título do Painel de Parâmetros
        lbl_parametros = QLabel("Parâmetros da Forma:")
        lbl_parametros.setStyleSheet("color: #ddd; font-size: 11px; font-weight: bold;")
        layout_parametros.addWidget(lbl_parametros)

        # 1. Tamanho
        self.lbl_tamanho = QLabel("Tamanho:") 
        layout_parametros.addWidget(self.lbl_tamanho)
        
        # SpinBox para Tamanho
        self.spin_size = QDoubleSpinBox()
        self.spin_size.setRange(0.1, 50.0)
        self.spin_size.setValue(1.0)
        self.spin_size.setSingleStep(0.1)

        # Ícones SVG de + e - convertidos para Base64 (nao funcionando)
        icone_mais = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAAyElEQVR4Ae2VwQ2CMBBF/7rECwQwYg9UKoBS0NhDiIPICugHokW2YCiMzFxLpy0X58F3RDeBzJk5v1+z15Z1E3GRsEwiAFYgUX0A2mlnAWIwPwqYQP5nAMco3gGqAtYHFeT4BpztgD5gfE2iMtHoJt5EIgA4DLzknJtY4oEWYvX5PzJHAD0oMUSjFZgMZ8rjAf9qYCqrEc2d+wVwaYf4mUDBAh4xLqa8AOFJDBHeAF8tD0L9IQNcYjFnZk8bYBnqV1fx7mPu1GQf7+zNX4wK/ANrLRV6fVYyAAAAAElFTkSuQmCC"
        icone_menos = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAAZUlEQVR4Ae3RwQnAIBAEwJ9RE4TiIiLoyFX6kwAMpYeai+HLnhM3yIwG4OACfDsqAdPcpBgPdCOkmxAG8JiCjiGeIGCCF0I0IY4BjgCcgQmENOBjRhjgmMACnNDRRzH1L5vA2Gnf8P0z4A0o6kHUBWGBUAAAAASUVORK5CYII="

        self.spin_size.setStyleSheet(f"""
            QDoubleSpinBox {{
                background-color: #606060; 
                color: white; 
                padding: 4px;
                border-radius: 4px;
                border: 1px solid #404040;
                font-size: 12px;
            }}
            QDoubleSpinBox::up-button, QDoubleSpinBox::down-button {{
                background-color: #757575;
                width: 24px;
                border-left: 1px solid #404040;
                border-radius: 0px;
            }}
            QDoubleSpinBox::up-button {{ border-top-right-radius: 4px; }}
            QDoubleSpinBox::down-button {{ border-bottom-right-radius: 4px; }}
            
            QDoubleSpinBox::up-button:hover, QDoubleSpinBox::down-button:hover {{
                background-color: #909090;
            }}

            QDoubleSpinBox::up-arrow {{
                image: {icone_mais};
                width: 12px; height: 12px;
            }}
            QDoubleSpinBox::down-arrow {{
                image: {icone_menos};
                width: 12px; height: 12px;
            }}
        """)
        
        # Conecta o valor ao Controller
        self.spin_size.valueChanged.connect(self.controller.set_tamanho_primitiva)
        layout_parametros.addWidget(self.spin_size)

        # Plano de Desenho
        lbl_plano = QLabel("Plano de Desenho:")
        layout_parametros.addWidget(lbl_plano)
        
        # ComboBox para Plano
        self.combo_plano = QComboBox()
        self.combo_plano.addItems(["XY", "XZ", "YZ"])
        self.combo_plano.setStyleSheet("background-color: #606060; color: white; padding: 2px;")
        self.combo_plano.currentTextChanged.connect(self.controller.set_plano_primitiva)
        layout_parametros.addWidget(self.combo_plano)

        # Adiciona o Painel de Parâmetros ao Layout Principal
        layout_principal.addWidget(self.painel_parametros)
        self.painel_parametros.hide()

    # Handler para clique nos botões de forma
    def tratar_clique(self, key):
        # atualiza o controller
        self.controller.set_forma(key, True)

        # atualiza o painel de parâmetros
        self.painel_parametros.show()

        # atualiza o label do tamanho
        if key == 'circle':
            self.lbl_tamanho.setText("Diâmetro:")
        else:
            self.lbl_tamanho.setText("Tamanho (Lado):")

    # Helper para adicionar botões
    def adicionar_botao(self, text, key, layout):
        # cria um botão com estilo customizado
        botao = QPushButton(text)
        botao.setCheckable(True)
        botao.setFixedHeight(40)
        botao.setStyleSheet("""
            QPushButton {
                background-color: #505050; 
                border-radius: 5px;
                border: 1px solid #303030;
            }
            QPushButton:hover { background-color: #606060; }
            QPushButton:checked { 
                background-color: #00BCD4; 
                color: black; 
                font-weight: bold;
                border: 1px solid #80DEEA;
            }
        """)
        
        botao.clicked.connect(lambda: self.tratar_clique(key))
        
        self.grupo_botoes.addButton(botao)
        layout.addWidget(botao)