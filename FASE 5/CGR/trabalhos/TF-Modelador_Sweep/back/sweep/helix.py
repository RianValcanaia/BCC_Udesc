"""
Módulo para aplicar Sweep Helicoidal em primitivas 2D.
Função principal:
- cria uma extrusão rotacional helicoidal (como uma mola) a partir de uma primitiva 2D.
"""

def aplicar_sweep_helix(malha_2d, raio_caminho=2.0, voltas=3, altura=4.0):
    """
    Args:
        malha_2d (pv.PolyData): mesh 2D a ser extrudada.
        raio_caminho (float): distância do eixo Z (raio da trajetória).
        voltas (float): número de voltas da hélice.
        altura (float): altura total da hélice.

    Returns:
        pv.PolyData: mesh 3D resultante da extrusão helicoidal.
    """
    
    nova_malha = malha_2d.copy()
    nova_malha.translate([raio_caminho, 0, 0], inplace=True)
    
    angulo_total = 360 * voltas
    
    # capping ativa as tampas superior e inferior
    return nova_malha.extrude_rotate(
        resolution=120, 
        angle=angulo_total, 
        translation=altura, 
        capping=True
    )