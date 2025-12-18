"""
Cria primitivas 2D no espaço 3D usando PyVista.
Primitivas suportadas: Quadrado, Círculo e Triângulo.
Permite definir o tamanho e o plano de desenho (XY, XZ, YZ).
"""

import pyvista as pv
import numpy as np

# Helper para definir a direção normal baseada no plano
def _obter_direcao(plano):
    if plano == 'xz':
        return (0, 1, 0)
    elif plano == 'yz':
        return (1, 0, 0) 
    else:
        return (0, 0, 1)
    
# --- Funções para criar as primitivas ---

def criar_quadrado(tamanho=1.0, plano='xy'):
    return pv.Plane(
        center=(0,0,0), 
        direction=_obter_direcao(plano), 
        i_size=tamanho, 
        j_size=tamanho, 
        i_resolution=1, 
        j_resolution=1
    )

def criar_circulo(tamanho=1.0, plano='xy'):
    radius = tamanho / 2.0
    
    malha = pv.Circle(radius=radius, resolution=60)
    
    if plano == 'xz':
        malha.rotate_x(90, inplace=True)
    elif plano == 'yz':
        malha.rotate_y(-90, inplace=True)
        
    return malha

def criar_triangulo(tamanho=1.0, plano='xy'):
    s = tamanho / 2.0 

    if plano == 'xy':
        pts = np.array([
            [0.0,  s, 0.0],  
            [-s,  -s, 0.0],  
            [ s,  -s, 0.0]   
        ])
        
    elif plano == 'xz':
        pts = np.array([
            [0.0, 0.0,  s],  
            [-s,  0.0, -s], 
            [ s,  0.0, -s]
        ])
        
    elif plano == 'yz':
        pts = np.array([
            [0.0,  s, 0.0],  
            [0.0, -s, -s], 
            [0.0, -s,  s]
        ])

    malha = pv.PolyData(pts).delaunay_2d()
    return malha