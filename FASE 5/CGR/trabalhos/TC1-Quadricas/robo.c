#include <GL/glut.h>
/*
    Para compilar e rodar:
    gcc robo.c -o robo -lGL -lGLU -lglut && ./robo
*/

// Variaveis globais para controle da camera com o mouse
float anguloX_camera = 20.0f;
float anguloY_camera = 0.0f;
int mouseX_anterior, mouseY_anterior;
int botaoPressionado = 0;

// Ponteiro para o objeto quadrico
GLUquadric *quad;

// Variaveis para articulacao 
float anguloOmbroDireito = 0.0f;
float anguloCotoveloDireito = 0.0f;
float anguloQuadrilDireito = 0.0f;
float anguloJoelhoDireito = 0.0f;

float anguloOmbroEsquerdo = 0.0f;
float anguloCotoveloEsquerdo = 0.0f;
float anguloQuadrilEsquerdo = 0.0f;
float anguloJoelhoEsquerdo = 0.0f;

/*
=============================================================
====         FUNCOES DE CONTROLE DA CAMERA (MOUSE)        ===
=============================================================
*/

// funcao chamada ao redimensionar a janela
void redimensiona(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Funcao para eventos de clique do mouse
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            botaoPressionado = 1;
            mouseX_anterior = x;
            mouseY_anterior = y;
        } else {
            botaoPressionado = 0;
        }
    }
}

// Funcao para eventos de movimento do mouse
void motion(int x, int y) {
    if (botaoPressionado) {
        anguloY_camera += (x - mouseX_anterior) * 0.5f;
        anguloX_camera += (y - mouseY_anterior) * 0.5f;

        // Limita a rotacao vertical para nao virar de cabeca para baixo
        if (anguloX_camera > 80.0f) anguloX_camera = 80.0f;
        if (anguloX_camera < 0.0f) anguloX_camera = 0.0f;

        mouseX_anterior = x;
        mouseY_anterior = y;
        glutPostRedisplay();
    }
}

// Funcao para eventos de teclado
void teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Mover ombro direito para cima
            anguloOmbroDireito += 5.0f;
            break;
        case 's': // Mover ombro direito para baixo
            anguloOmbroDireito -= 5.0f;
            break;
        case 'a': // Dobrar cotovelo direito
            anguloCotoveloDireito += 5.0f;
            if (anguloCotoveloDireito > 120.0f) anguloCotoveloDireito = 120.0f;
            break;
        case 'd': // Esticar cotovelo direito
            anguloCotoveloDireito -= 5.0f;
            if (anguloCotoveloDireito < 0.0f) anguloCotoveloDireito = 0.0f;
            break;
        case 'q': // Mover quadril direito para frente
            anguloQuadrilDireito += 5.0f;
            if (anguloQuadrilDireito > 45.0f) anguloQuadrilDireito = 45.0f;
            break;
        case 'e': // Mover quadril direito para tras
            anguloQuadrilDireito -= 5.0f;
            if (anguloQuadrilDireito < -45.0f) anguloQuadrilDireito = -45.0f;
            break;
        case 'z': // Dobrar joelho direito
            anguloJoelhoDireito += 5.0f;
            if (anguloJoelhoDireito > 90.0f) anguloJoelhoDireito = 90.0f;
            break;
        case 'c': // Esticar joelho direito
            anguloJoelhoDireito -= 5.0f;
            if (anguloJoelhoDireito < 0.0f) anguloJoelhoDireito = 0.0f;
            break;


        case 'i': // Mover ombro esquerdo para cima
            anguloOmbroEsquerdo += 5.0f;
            break;
        case 'k': // Mover ombro esquerdo para baixo
            anguloOmbroEsquerdo -= 5.0f;
            break;
        case 'j': // Dobrar cotovelo esquerdo
            anguloCotoveloEsquerdo += 5.0f;
            if (anguloCotoveloEsquerdo > 120.0f) anguloCotoveloEsquerdo = 120.0f;
            break;
        case 'l': // Esticar cotovelo esquerdo
            anguloCotoveloEsquerdo -= 5.0f;
            if (anguloCotoveloEsquerdo < 0.0f) anguloCotoveloEsquerdo = 0.0f;
            break;
        case 'u': // Mover quadril esquerdo para frente
            anguloQuadrilEsquerdo += 5.0f;
            if (anguloQuadrilEsquerdo > 45.0f) anguloQuadrilEsquerdo = 45.0f;
            break;
        case 'o': // Mover quadril esquerdo para tras
            anguloQuadrilEsquerdo -= 5.0f;
            if (anguloQuadrilEsquerdo < -45.0f) anguloQuadrilEsquerdo = -45.0f;
            break;
        case 'm': // Dobrar joelho esquerdo
            anguloJoelhoEsquerdo += 5.0f;
            if (anguloJoelhoEsquerdo > 90.0f) anguloJoelhoEsquerdo = 90.0f;
            break;
        case '.': // Esticar joelho esquerdo
            anguloJoelhoEsquerdo -= 5.0f;
            if (anguloJoelhoEsquerdo < 0.0f) anguloJoelhoEsquerdo = 0.0f;
            break;
            

        case 27: // Tecla ESC para sair
            exit(0);
            break;
    }
    glutPostRedisplay(); // Redesenha a tela para mostrar a mudanca
}

/*
===========================================================
====         FUNCOES PARA DESENHAR O ROBO BENDER        ===
===========================================================
*/

void eixos() {
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

void legenda() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    // Obtem o tamanho da janela para a legenda ser responsiva
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluOrtho2D(0, w, 0, h); // Muda para projeção 2D

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Desabilita recursos 3D para desenhar o texto 2D
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glColor3f(1.0f, 1.0f, 1.0f); // Cor do texto: branco

    const char *linhas[] = {
        "Controles do Robo:",
        "",
        "--- Braco Direito ---",
        "W/S: Ombro",
        "A/D: Cotovelo",
        "",
        "--- Perna Direita ---",
        "Q/E: Quadril",
        "Z/C: Joelho",
        "",
        "--- Braco Esquerdo ---",
        "I/K: Ombro",
        "J/L: Cotovelo",
        "",
        "--- Perna Esquerda ---",
        "U/O: Quadril",
        "M/. : Joelho",
        "",
        "Mouse: Rotacionar Câmera",
        "ESC: Sair"
    };

    int numLinhas = sizeof(linhas)/sizeof(char *);
    float x = 10;  // Posição X inicial (canto superior direito)
    float y = h - 25;   // Posição Y inicial
    float espacamento = 15.0f;

    for (int i = 0; i < numLinhas; i++) {
        glRasterPos2f(x, y - i * espacamento);
        const char *p = linhas[i];
        while (*p) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p);
            p++;
        }
    }

    // Restaura as matrizes e estados originais
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void cabeca() {
    glPushMatrix();
        glColor3f(0.5f, 0.6f, 0.7f); // Cor metalica 

        // Cabeca 
        glTranslatef(0.0f, 4.0f, 0.0f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
        gluCylinder(quad, 0.5, 0.5, 1.0, 30, 30); 
        gluDisk(quad, 0.0, 0.5, 30, 1); // Tampa inferior
        glPushMatrix();  // Tampa superior
            glTranslatef(0.0f, 0.0f, 1.0f);
            gluDisk(quad, 0.0, 0.5, 30, 1);
        glPopMatrix();

        // Antena
        glColor3f(0.3f, 0.3f, 0.3f); // Cinza escuro
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 1.0f); 
            gluCylinder(quad, 0.05, 0.05, 0.3, 10, 10);
            glTranslatef(0.0f, 0.0f, 0.3f); 
            gluSphere(quad, 0.08, 15, 15); 
        glPopMatrix();

        // Olhos
        glColor3f(0.9f, 0.9f, 0.1f); // Amarelo
        glPushMatrix();
            // Olho esquerdo
            glTranslatef(0.2f, -0.5f, 0.7f); 
            glScalef(0.2, 0.15, 0.1); 
            glutSolidCube(1.0);
        glPopMatrix();
        glPushMatrix();
            // Olho direito
            glTranslatef(-0.2f, -0.5f, 0.7f);
            glScalef(0.2, 0.15, 0.1);
            glutSolidCube(1.0);
        glPopMatrix();

        // Dentes
        glColor3f(0.8f, 0.8f, 0.8f); // Branco Acizentado
        glPushMatrix();
            glTranslatef(0.17f, -0.45f, 0.35); 
            glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); 
            gluCylinder(quad, 0.08, 0.08, 0.4, 10, 10);
        glPopMatrix();

    glPopMatrix();
}

void torso() {
    glPushMatrix();
        glColor3f(0.5f, 0.6f, 0.7f); // Cor metalica 

        // Corpo 
        glTranslatef(0.0f, 2.0f, 0.0f);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quad, 0.8, 0.8, 2.0, 30, 30); 
        gluDisk(quad, 0.0, 0.8, 30, 1); 
        
        glPushMatrix();  // Tampa superior do torso
            glTranslatef(0.0f, 0.0f, 2.0f);
            gluDisk(quad, 0.0, 0.8, 30, 1);
        glPopMatrix();        

    glPopMatrix();
}

void braco(int lado) {
    glPushMatrix();
        glColor3f(0.3f, 0.3f, 0.3f); // cinza escura

        glTranslatef(0.9f * lado, 3.4f, 0.0f);

        // Articulacao do ombro
        if (lado == -1) { 
            glRotatef(anguloOmbroDireito, 1.0f, 0.0f, 0.0f); // Rotacao para frente/tras (W/S)
        }else if(lado == 1){
            glRotatef(anguloOmbroEsquerdo, 1.0f, 0.0f, 0.0f); // Rotacao para frente/tras (i/k)
        }
        
        // Rotacao inicial para os bracos ficarem para os lados
        glRotatef(90.0f * lado, 0.0f, 1.0f, 0.0f);
        glRotatef(-15.0f, 0.0f, 0.0f, 1.0f); // Pequena queda no ombro

        // Ombro 
        gluSphere(quad, 0.25, 20, 20);

        // Braco superior 
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.1f); 
            for (int i = 0; i < 3; i++) {
                gluCylinder(quad, 0.15, 0.15, 0.3, 20, 20);
                glTranslatef(0.0f, 0.0f, 0.3f);
                gluDisk(quad, 0.0, 0.15, 20, 1);
            }
        glPopMatrix();

        // Posicao do cotovelo
        glTranslatef(0.0f, 0.0f, 1.0f); 

        // Cotovelo 
        gluSphere(quad, 0.2, 20, 20);

        // Articulacao do Cotovelo
        if (lado == -1) { 
            glRotatef(anguloCotoveloDireito, 1.0f, 0.0f, 0.0f); // Dobrar o cotovelo (A/D)
        }else if(lado == 1){
            glRotatef(anguloCotoveloEsquerdo, 1.0f, 0.0f, 0.0f); // Dobrar o cotovelo (J/L)
        }
        
        // Antebraco 
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.1f); 
            for (int i = 0; i < 3; i++) {
                gluCylinder(quad, 0.12, 0.12, 0.3, 20, 20);
                glTranslatef(0.0f, 0.0f, 0.3f);
                gluDisk(quad, 0.0, 0.12, 20, 1); 
            }
        glPopMatrix();

        // Mao 
        glTranslatef(0.0f, 0.0f, 1.0f); // Final do antebraco
        gluSphere(quad, 0.18, 20, 20); // Base da "mao"
        
        // Dedos
        glPushMatrix();
            glTranslatef(0.0f, 0.1f, 0.1f);
            glRotatef(-45.0f, 1.0f, 0.0f, 0.0f);
            gluCylinder(quad, 0.05, 0.05, 0.2, 10, 10);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0f, -0.1f, 0.1f);
            glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
            gluCylinder(quad, 0.05, 0.05, 0.2, 10, 10);
        glPopMatrix();

    glPopMatrix();
}

void perna(int lado) {
    glPushMatrix();
        glColor3f(0.3f, 0.3f, 0.3f); // Cinza escuro

        // Posicao do quadril 
        glTranslatef(0.4f * lado, 2.2f, 0.0f);

        // Quadril 
        gluSphere(quad, 0.28, 20, 20);

        // Articulacao quadril
        if (lado == -1) { 
            glRotatef(anguloQuadrilDireito, 1.0f, 0.0f, 0.0f); // Rotacao para frente/tras (Q/E)
        }else if(lado == 1) glRotatef(anguloQuadrilEsquerdo, 1.0f, 0.0f, 0.0f); // Rotacao para frente/tras (U/O)

        // Coxa 
        glPushMatrix();
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f); 
            for (int i = 0; i < 3; i++) {
                gluCylinder(quad, 0.22, 0.22, 0.35, 20, 20);
                glTranslatef(0.0f, 0.0f, 0.35f);
                gluDisk(quad, 0.0, 0.22, 20, 1); 
            }
        glPopMatrix();

        // Posicao do joelho
        glTranslatef(0.0f, -1.05f, 0.0f); 

        // Joelho 
        gluSphere(quad, 0.25, 20, 20);

        // Articulacao joelho
        if (lado == -1) { 
            glRotatef(anguloJoelhoDireito, 1.0f, 0.0f, 0.0f); // Dobrar o joelho (Z/C)
        }else if(lado == 1){
            glRotatef(anguloJoelhoEsquerdo, 1.0f, 0.0f, 0.0f); // Dobrar o joelho (M/.)
        }
        
        // Canela 
        glPushMatrix();
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            for (int i = 0; i < 3; i++) {
                gluCylinder(quad, 0.2, 0.2, 0.35, 20, 20);
                glTranslatef(0.0f, 0.0f, 0.35f);
                gluDisk(quad, 0.0, 0.2, 20, 1); 
            }
        glPopMatrix();
        
        // Pe
        glTranslatef(0.0f, -1.05f, 0.2f);
        glScalef(1.0, 0.4, 1.5); 
        glutSolidCube(0.5);

    glPopMatrix();
}

void chao() {
    glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f); 
        glBegin(GL_QUADS);
            glNormal3f(0.0, 1.0, 0.0); 
            glVertex3f(-50.0f, 0.0f, -50.0f);
            glVertex3f( 50.0f, 0.0f, -50.0f);
            glVertex3f( 50.0f, 0.0f,  50.0f);
            glVertex3f(-50.0f, 0.0f,  50.0f);
        glEnd();
    glPopMatrix();
}

// Funcao principal de desenho
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Posicionamento da camera
    glTranslatef(0.0f, -3.0f, -15.0f);

    // Rotaciona a cena com o mouse
    glRotatef(anguloX_camera, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloY_camera, 0.0f, 1.0f, 0.0f);

    // Desenha as partes do cenario e do robo
    //eixos();
    chao();
    
    cabeca();
    torso();
    braco(-1);  // Braco direito
    braco(1);   // Braco esquerdo
    perna(-1);  // Perna direita
    perna(1);   // Perna esquerda
    
    legenda();
    
    glutSwapBuffers();
}

void init() {
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f); // Cor de fundo 
    glEnable(GL_DEPTH_TEST); // Habilita teste de profundidade
    glEnable(GL_COLOR_MATERIAL); // Permite que a cor seja definida por glColor

    // Configuracao de iluminacao
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    // Fonte de luz direcional (simula sol)
    GLfloat light_pos[] = {2.0, 7.0, 5.0, 0.0}; // ultimo componente 0.0 para luz direcional
    GLfloat light_ambient[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    // Cria o objeto quadrico
    quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL); // Estilo preenchido
    gluQuadricNormals(quad, GLU_SMOOTH); // Normais para iluminacao suave
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bender da Shopee");

    init(); 

    // Registra as funcoes de callback
    glutDisplayFunc(display);
    glutReshapeFunc(redimensiona);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(teclado); // Para controle de articulacao

    glutMainLoop();

    gluDeleteQuadric(quad); // Libera a memoria do objeto quadrico
    return 0;
}