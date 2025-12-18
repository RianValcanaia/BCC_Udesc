import sys
import os   # para variáveis de ambiente

# Define o backend gráfico do Qt para X11 (XCB) no Linux,
os.environ["QT_QPA_PLATFORM"] = "xcb"

# Importando classes necessárias do PyQt6, responsável por eventos, janelas e widgets
from PyQt6.QtWidgets import QApplication
from ui.window import JanelaPrincipal 

if __name__ == "__main__":
    app = QApplication(sys.argv)  # passa argumentos da linha de comando para a aplicação Qt, para mouse e teclado 
    
    # cria a janela principal
    janela = JanelaPrincipal()
    janela.show()
    
    # loop de eventos para pegar eventos do SO
    sys.exit(app.exec())