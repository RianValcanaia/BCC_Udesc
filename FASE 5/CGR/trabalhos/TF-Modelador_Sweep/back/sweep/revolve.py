"""
Módulo para aplicar Sweep de Revolução em primitivas 2D.
Função principal:
- gira a primitiva 2D em torno do eixo Z formando um objeto 3D.
"""

def aplicar_sweep_revolve(malha_2d, raio_caminho=2.0):
    """
    Args:
        malha_2d (pv.PolyData): mesh 2D a ser revolvido.
        raio_caminho (float): distância do eixo Z (raio da trajetória).
    Returns:
        pv.PolyData: mesh 3D resultante da revolução.
    """

    nova_malha = malha_2d.copy()
    nova_malha.translate([raio_caminho, 0, 0], inplace=True)
    # capping ativa as tampas superior e inferior
    return nova_malha.extrude_rotate(resolution=60, angle=360, capping=True)