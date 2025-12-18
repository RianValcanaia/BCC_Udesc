"""
Módulo para aplicar Sweep de Interpolação (Loft/Morphing).
CORREÇÃO FINAL:
1. Ordenação angular (evita torção).
2. Capping (Tampas): Fecha o sólido em cima e embaixo.
3. Suavização: Recalcula normais para evitar listras pretas na renderização.
"""
import pyvista as pv
import numpy as np

def _gerar_contorno_ordenado(malha, n_pontos=2000):
    """
    Gera um contorno reamostrado e ordenado por ângulo.
    Isso evita que a malha fique torcida.
    """
    # 1. Extrair arestas
    arestas = malha.extract_feature_edges(boundary_edges=True, feature_edges=False, manifold_edges=False)
    if arestas.n_points == 0: arestas = malha
    
    pontos_brutos = arestas.points
    if len(pontos_brutos) < 3:
        return pv.Circle(resolution=n_pontos).points

    # 2. Centroide e Ângulos
    centro = np.mean(pontos_brutos, axis=0)
    dx = pontos_brutos[:, 0] - centro[0]
    dy = pontos_brutos[:, 1] - centro[1]
    angulos = np.arctan2(dy, dx)
    
    # 3. Ordenar (Anti-horário)
    ordem = np.argsort(angulos)
    pontos_ordenados = pontos_brutos[ordem]
    pontos_ordenados = np.vstack([pontos_ordenados, pontos_ordenados[0]]) # Fecha loop
    
    # 4. Reamostragem Uniforme
    dists = np.linalg.norm(np.diff(pontos_ordenados, axis=0), axis=1)
    cum_dist = np.insert(np.cumsum(dists), 0, 0)
    total_dist = cum_dist[-1]
    
    novas_posicoes = np.linspace(0, total_dist, n_pontos + 1)[:-1]
    
    novos_pontos = np.zeros((n_pontos, 3))
    for i in range(3):
        novos_pontos[:, i] = np.interp(novas_posicoes, cum_dist, pontos_ordenados[:, i])

    # 5. Rotação de Fase (Alinhar o ponto 0 com o eixo X)
    angulos_finais = np.arctan2(novos_pontos[:, 1], novos_pontos[:, 0])
    idx_inicio = np.argmin(np.abs(angulos_finais))
    pontos_alinhados = np.roll(novos_pontos, -idx_inicio, axis=0)
    
    return pontos_alinhados

def _criar_tampa(pontos):
    """
    Cria uma face preenchida a partir de uma lista de pontos ordenados.
    """
    # Cria o objeto PolyData apenas com os pontos
    tampa = pv.PolyData(pontos)
    
    # Define a face manualmente: [número_de_pontos, p0, p1, p2, ...]
    n_pts = len(pontos)
    face = [n_pts] + list(range(n_pts))
    tampa.faces = face
    
    # Triangula para garantir renderização correta
    return tampa.triangulate()

def aplicar_interpolacao(malha_base, forma_alvo='circulo', altura=5.0, tamanho_alvo=1.0):
    n_resolucao = 2000
    
    # --- 1. Gerar Pontos Ordenados ---
    pontos_base = _gerar_contorno_ordenado(malha_base, n_resolucao)
    
    if forma_alvo == 'quadrado':
        temp = pv.Plane(i_size=tamanho_alvo, j_size=tamanho_alvo, i_resolution=1, j_resolution=1)
        pontos_topo = _gerar_contorno_ordenado(temp, n_resolucao)
    elif forma_alvo == 'triangulo':
        s = tamanho_alvo / 2.0
        pts = np.array([[0, s, 0], [-s, -s, 0], [s, -s, 0]])
        temp = pv.PolyData(pts).delaunay_2d()
        pontos_topo = _gerar_contorno_ordenado(temp, n_resolucao)
    else: # Circulo
        radius = tamanho_alvo / 2.0
        temp = pv.Circle(radius=radius, resolution=n_resolucao)
        pontos_topo = _gerar_contorno_ordenado(temp, n_resolucao)

    # Elevar o Topo
    pontos_topo[:, 2] += altura
    
    # --- 2. Criar Paredes Laterais ---
    todos_pontos = np.vstack((pontos_base, pontos_topo))
    grid = pv.StructuredGrid()
    grid.points = todos_pontos
    grid.dimensions = [n_resolucao, 2, 1]
    paredes = grid.extract_surface().triangulate()
    
    # --- 3. Criar e Unir Tampas (Capping) ---
    tampa_base = _criar_tampa(pontos_base)
    tampa_topo = _criar_tampa(pontos_topo)
    
    # O comando merge junta as geometrias em um único objeto
    solido = paredes.merge([tampa_base, tampa_topo])
    
    # --- 4. Limpeza e Suavização Final ---
    # clean: remove pontos duplicados na costura das tampas
    # compute_normals: calcula iluminação suave para o sólido inteiro
    solido = solido.clean().compute_normals(auto_orient_normals=True)
    
    return solido