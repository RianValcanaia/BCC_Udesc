"""
Módulo para aplicar Sweep Linear em primitivas 2D.
Função principal:
- extrude a primitiva 2D ao longo de um eixo formando um objeto 3D.
"""

def aplicar_sweep_linear(malha_2d, altura=2.0, eixo='z'):
    """
    Realiza uma extrusão linear.
    Args:
        malha_2d: O objeto pyvista 2D.
        altura (float): A altura/comprimento da extrusão.
        axis (str): 'x', 'y' ou 'z'.
    Returns:
        O objeto pyvista 3D resultante.
    """
    vetor = [0, 0, 0]
    
    if eixo == 'x':
        vetor = [altura, 0, 0]
    elif eixo == 'y':
        vetor = [0, altura, 0]
    else: # padrão z
        vetor = [0, 0, altura]

    # capping ativa as tampas superior e inferior
    return malha_2d.extrude(vetor, capping=True)