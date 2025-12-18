//gcc castelo.c -lglut -lGL -lGLU -lSOIL -lm -o castelo && ./castelo

#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "SOIL/SOIL.h"

// variaveis globais pra camera
float cameraX = 0.0f;
float cameraY = 5.0f;
float cameraZ = 15.0f;

// Objeto quádrico para desenhar
GLUquadricObj *quadric;

unsigned int textureID, textureID_sky, textureID_grass;

// Funcao para redefinir a visualizacao quando a janela eh redimensionada
void changeSize(int w, int h) {
    // Previne uma divisão por zero se a janela for muito pequena
    if (h == 0) h = 1;
    float ratio = 1.0 * w / h;

    // Redefine a matriz de projeção
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Define a viewport para a janela inteira
    glViewport(0, 0, w, h);

    // Define a projeção de perspectiva
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Volta para a matriz de visualização do modelo
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT:
            cameraX -= 0.3f; // Move a camera para a esquerda
            break;
        case GLUT_KEY_RIGHT:
            cameraX += 0.3f; // Move a camera para a direita
            break;
        case GLUT_KEY_UP:
            cameraZ -= 0.3f; // Move a camera para frente
            break;
        case GLUT_KEY_DOWN:
            cameraZ += 0.3f; // Move a camera para tras
            break;
    }

    // Pede ao GLUT para redesenhar a cena com a nova posicao da camera
    glutPostRedisplay();
}

// Funcao de callback para teclas normais
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) // Tecla ESC
        exit(0);
}

void desenhaEixos() {
    glLineWidth(2.0f); // Define a largura das linhas
    glBegin(GL_LINES);

    // Eixo X (vermelho)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 0.0f, 0.0f);

    // Eixo Y (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);

    // Eixo Z (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    
    glEnd();
}

// A função de inicialização
void init() {
    // Cria o objeto quádrico
    quadric = gluNewQuadric();
    
    // Configura o estilo de desenho (solido) e as normais (suaves)
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    
    // Habilita o teste de profundidade
    glEnable(GL_DEPTH_TEST);

    // Habilita o sistema de iluminacao
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // Define as propriedades da luz
    GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    // Define a posicao da luz
    GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    // Permite que a cor do material seja definida por glColor
    glEnable(GL_COLOR_MATERIAL);
    
    // Configura o mapeamento de textura em quadricas
    gluQuadricTexture(quadric, GL_TRUE);
    
    // Habilita o recurso de mapeamento de textura 2D
    glEnable(GL_TEXTURE_2D);
    
    // Carrega e configura a textura das torres
    textureID = SOIL_load_OGL_texture(
        "texturaTorres.jpg", 
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    if (textureID == 0) {
        printf("Erro ao carregar a textura das torres: %s\n", SOIL_last_result());
    }
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Carrega e configura a textura do ceu
    textureID_sky = SOIL_load_OGL_texture(
        "texturaCeu.jpg", 
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    if (textureID_sky == 0) {
        printf("Erro ao carregar a textura do ceu: %s\n", SOIL_last_result());
    }
    glBindTexture(GL_TEXTURE_2D, textureID_sky);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Carrega e configura a textura da grama
    textureID_grass = SOIL_load_OGL_texture(
        "texturaGrama.jpg", 
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    if (textureID_grass == 0) {
        printf("Erro ao carregar a textura da grama: %s\n", SOIL_last_result());
    }
    glBindTexture(GL_TEXTURE_2D, textureID_grass);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
}

void drawTexturedCube() {
    // Face frontal
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
    glEnd();
    
    // Face traseira
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
    glEnd();
    
    // Face superior
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
    glEnd();
    
    // Face inferior
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
    glEnd();
    
    // Face direita
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
    glEnd();
    
    // Face esquerda
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);
    glEnd();
}

// A função de renderização que desenha a cena
void renderScene(void) {
    // Limpa o buffer de cor e o de profundidade
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // --- 1. DESENHA O PLANO DE FUNDO ---
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING); // Desabilita a iluminacao para o ceu
    glDisable(GL_COLOR_MATERIAL); // Desabilita a cor do material

    // Ativa a textura do ceu
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_sky);

    // Define a cor do material para branco para nao escurecer a textura
    glColor3f(1.0f, 1.0f, 1.0f);
    
    // Configura a matriz para o ceu
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluPerspective(45.0f, 1.0, 0.1f, 100.0f);
    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();
        
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, -100.0f, -50.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f( 100.0f, -100.0f, -50.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f( 100.0f,  100.0f, -50.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f,  100.0f, -50.0f);
        glEnd();
        
    glPopMatrix();

    // chao

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_grass);

    glPushMatrix();
        glTranslatef(7.5f, 0.0f, 7.5f);
        glScalef(100.0f, 0.0f, 100.0f);
        drawTexturedCube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    
    // --- 2. DESENHA O CASTELO E OS OBJETOS DA CENA ---
    // Habilita novamente as configuracoes para o castelo
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    
    // Restaura a matriz de visualizacao para desenhar o castelo
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Posiciona a camera
    gluLookAt(
        cameraX, cameraY, cameraZ,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );
    
    // Ativa a textura das torres
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // 3. Posiciona a camera
    gluLookAt(
        cameraX, cameraY, cameraZ,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );

    desenhaEixos();


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    //TORRES

    // Define a cor para o próximo objeto a ser desenhado
    glColor3f(0.45f, 0.45f, 0.45f); // cinza

    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f); 
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.5, 1.5, 5.0, 15, 15); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(15.0f, 0.0f, 0.0f);
        glRotatef(-90.f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.5, 1.5, 5.0, 15, 15);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(15.0f, 0.0f, 15.0f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.5, 1.5, 5.0, 15, 15);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 15.0f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.5, 1.5, 5.0, 15, 15);
    glPopMatrix();
    
    //TELHADOS

    glColor3f(0.5f, 0.2f, 0.1f); // marrom

    glPushMatrix();
        glTranslatef(0.0f, 5.0f, 0.0f); 
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
        gluCylinder(quadric, 1.5, 0.0, 1.5, 15, 15); // cilindro com o raio do topo sendo zero, virando um cone
    glPopMatrix();

    glPushMatrix();
        glTranslated(15.0f, 5.0f, 0.0f);
        glRotatef(-90.f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.5, 0.0, 1.5, 15, 15);
    glPopMatrix();

    glPushMatrix();
        glTranslated(15.0f, 5.0f, 15.0f);
        glRotatef(-90.f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.5, 0.0, 1.5, 15, 15);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0f, 5.0f, 15.0f);
        glRotatef(-90.f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.5, 0.0, 1.5, 15, 15);
    glPopMatrix();

    // PAREDES

    glColor3f(0.255f,0.255f, 0.255f); // cinza

    glPushMatrix();
      // escala e depois translacao
      glTranslatef(7.0f, 1.75f, 0.0f); // Move para a posicao correta (meio da altura)
      glScalef(14.0f, 3.5f, 0.5f); // Escala para criar um paralelepipedo (largo, alto, fino)
      drawTexturedCube(); // Desenha um cubo de tamanho 1.0
    glPopMatrix();

    // parede da torre ate a entrada (esquerda)
    glPushMatrix();
        glTranslatef(3.0f, 1.75f, 15.0f);
        glScalef(6.0f, 3.5f, 0.5f);
        drawTexturedCube();
    glPopMatrix();

    // parede da torre ate a entrada (direita)
    glPushMatrix();
        glTranslatef(12.0f, 1.75f, 15.0f);
        glScalef(6.0f, 3.5f, 0.5f);
        drawTexturedCube();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 1.75f, 7.0f);
        glScalef(0.5f, 3.5f, 14.0f);
        drawTexturedCube();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(15.0f, 1.75f, 7.0f);
        glScalef(0.5f, 3.5f, 14.0f);
        drawTexturedCube();
    glPopMatrix();

    //ENTRADA

    glColor3f(0.45f, 0.45f, 0.45f); // cinza

    glPushMatrix();
        glTranslatef(6.5f, 2.0f, 14.0f);
        glScalef(1.0f, 4.0f, 3.0f);
        drawTexturedCube();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(8.5f, 2.0f, 14.0f);
        glScalef(1.0f, 4.0f, 3.0f);
        drawTexturedCube();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(7.5f, 4.5f, 14.0f);
        glScalef(3.0f, 1.0f, 3.0f);
        drawTexturedCube();
    glPopMatrix();

    // TORRE DO MEIO

    glColor3f(0.45f, 0.45f, 0.45f); // cinza

    glPushMatrix();
        glTranslated(7.5f, 0.0f, 7.5f);
        glRotatef(-90.f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadric, 1.0, 1.0, 7.5, 30, 30);
    glPopMatrix();

    // TETO TORRE DO MEIO

    glColor3f(0.5f, 0.2f, 0.1f); // marrom

    glPushMatrix();
        glTranslatef(7.5f, 7.5f, 7.5f); 
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
        gluCylinder(quadric, 1.0, 0.0, 1.5, 15, 15); 
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);


    // Troca os buffers (exibe o que foi desenhado)
    glutSwapBuffers();
}

// A função principal do programa
int main(int argc, char** argv) {
    // Inicializa o GLUT
    glutInit(&argc, argv);
    
    // Define o modo de exibição (buffer duplo e profundidade)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // Define o tamanho e a posição da janela
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    
    // Cria a janela
    glutCreateWindow("Castelo de Quadricas");
    
    // Chama a função de inicialização
    init();

    // Registra as funções de callback
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(specialKeys);

    // Entra no loop principal de eventos do GLUT
    glutMainLoop();
    
    // Libera a memória alocada para o objeto quádrico
    gluDeleteQuadric(quadric);
    
    return 0;
}