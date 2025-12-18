"""
Define a janela principal da aplicação PyQt6 para modelagem 3D.
1. Cria a janela principal (`MainWindow`) com título, tamanho e estilo global.
2. Configura o layout principal com dois painéis: lateral (menu) e direito (3D + barra superior).
3. Inicializa a área de visualização 3D usando PyVista.
4. Adiciona widgets de controle no painel lateral (Primitives e Sweep).
5. Cria animação para abrir/fechar o painel lateral ao clicar no botão de menu.
"""

from PyQt6.QtWidgets import (QMainWindow, QWidget, QHBoxLayout, 
                             QVBoxLayout, QFrame, QPushButton)
from PyQt6.QtCore import QPropertyAnimation, QEasingCurve, Qt
from pyvistaqt import QtInteractor

from back.controller import Controller
from ui.ui_primitives import WidgetPrimitivas
from ui.ui_sweep import WidgetSweep


def setup_viewport(plotter):
    """
    Configura a viewport 3D da aplicação usando PyVistaQt.
    Funções principais:
    1. Define o fundo da área 3D.
    2. Adiciona eixos de canto para referência visual.
    3. Ajusta a câmera para uma visão isométrica inicial.
    4. Aplica zoom padrão.
    """
    plotter.set_background("#202020") 

    plotter.add_axes(
        interactive=False,  # eixos fixos
        line_width=3,  # espessura das linhas
        labels_off=False,  # mostra os rótulos dos eixos
        viewport=(0.0, 0.8, 0.2, 1.0)  # posicao no canto superior esquerdo
    )

    # camera em posicao isometrica
    plotter.view_isometric()

    # posicao da camera
    plotter.camera_position = [(5,5,5), (0, 0, 0), (0, 0, 1)]

class JanelaPrincipal(QMainWindow):
    def __init__(self):
        # cria janela e define tamanho e rótulo
        super().__init__()
        self.setWindowTitle("Modelador 3D - Sweep de Primitivas 2D")
        self.resize(1200, 800)
        
        # Estilo Global
        self.setStyleSheet("""
            QMainWindow { background-color: #2b2b2b; }
            QWidget { color: #ffffff; font-family: Segoe UI, Arial; }
            QFrame { border: none; }
            /* Estilo do Botão de Menu */
            QPushButton#menuBtn {
                background-color: transparent;
                border: none;
                font-size: 20px;
                color: #aaaaaa;
            }
            QPushButton#menuBtn:hover { color: white; background-color: #3a3a3a; border-radius: 5px; }
        """)

        # ====== Layout Principal ======
        widget_central = QWidget()
        self.setCentralWidget(widget_central)
        layout_principal = QHBoxLayout()
        layout_principal.setContentsMargins(0, 0, 0, 0)  # sem margens
        layout_principal.setSpacing(0)  # sem espaçamento
        widget_central.setLayout(layout_principal)

        # ====== Painel lateral  ======
        self.painel_lateral = QFrame()
        self.painel_lateral.setStyleSheet("background-color: #3c3f41; border-right: 1px solid #1e1e1e;")
        
        self.largura_lateral = 280
        self.painel_lateral.setMaximumWidth(self.largura_lateral)
        self.painel_lateral.setMinimumWidth(0)
        
        layout_lateral = QVBoxLayout()
        layout_lateral.setContentsMargins(20, 30, 20, 30)  # margens internas
        layout_lateral.setSpacing(20)
        self.painel_lateral.setLayout(layout_lateral)
        
        layout_principal.addWidget(self.painel_lateral)

        # ====== Painel direito (3D + Barra Superior) ======
        painel_direito = QWidget()
        layout_direito = QVBoxLayout()
        layout_direito.setContentsMargins(0, 0, 0, 0)
        layout_direito.setSpacing(0)
        painel_direito.setLayout(layout_direito)
        
        layout_principal.addWidget(painel_direito)

        # Barra Superior para o Botão
        barra_superior = QFrame()
        barra_superior.setFixedHeight(40)  # altura fixa
        barra_superior.setStyleSheet("background-color: #2b2b2b; border-bottom: 1px solid #3a3a3a;")
        barra_superior_layout = QHBoxLayout()
        barra_superior_layout.setContentsMargins(10, 0, 10, 0) 
        barra_superior.setLayout(barra_superior_layout)

        # ====== Botão Hambúrguer ======
        self.botao_menu = QPushButton("☰")
        self.botao_menu.setObjectName("menuBtn")
        self.botao_menu.setFixedSize(40, 30)
        self.botao_menu.setCursor(Qt.CursorShape.PointingHandCursor)
        self.botao_menu.clicked.connect(self.toggle_sidebar)  # funcao atribuida ao clique
        
        barra_superior_layout.addWidget(self.botao_menu)
        barra_superior_layout.addStretch() # empurra o botao para a esquerda

        layout_direito.addWidget(barra_superior)

        # ====== Área 3D (PyVista) ======
        self.plotter = QtInteractor(self)  # usa openGL via PyVistaQt
        setup_viewport(self.plotter) 
        layout_direito.addWidget(self.plotter.interactor)

        # ====== Lógica e Conteúdo do Painel Lateral ======
        self.controller = Controller(self.plotter)

        # ====== Adiciona os Widgets no Painel Lateral ======
        menu_primitivas = WidgetPrimitivas(self.controller)
        menu_sweep = WidgetSweep(self.controller)

        layout_lateral.addWidget(menu_primitivas)
        
        line = QFrame()
        line.setFrameShape(QFrame.Shape.HLine)
        line.setStyleSheet("background-color: #505050;")
        layout_lateral.addWidget(line)
        
        layout_lateral.addWidget(menu_sweep)
        layout_lateral.addStretch()

        # Configuração da Animação
        self.animacao_painel = QPropertyAnimation(self.painel_lateral, b"maximumWidth")
        self.animacao_painel.setEasingCurve(QEasingCurve.Type.InOutQuart)
        self.animacao_painel.setDuration(500)

    # Função para Alternar o Painel Lateral
    def toggle_sidebar(self):
        largura_atual = self.painel_lateral.width()
        
        if largura_atual == 0:
            nova_largura = self.largura_lateral
            self.botao_menu.setText("☰") 
        else:
            nova_largura = 0
            self.botao_menu.setText("➤")

        self.animacao_painel.setStartValue(largura_atual)
        self.animacao_painel.setEndValue(nova_largura)
        self.animacao_painel.start()