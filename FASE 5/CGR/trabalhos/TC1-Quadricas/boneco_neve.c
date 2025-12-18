#include <GL/glut.h>

/*
    Para rodar:
    gcc boneco_neve.c -o boneco -lGL -lGLU -lglut && ./boneco
*/

// Mostras os eixos para nao se perder
void desenharEixos() {
    glBegin(GL_LINES);  // define o tipo de primitiva grafica que sera construido

    // Eixo X (vermelho)
    glColor3f(1.0f, 0.0f, 0.0f);  // define a cor 
    glVertex3f(0.0f, 0.0f, 0.0f);  // ponto inicial
    glVertex3f(10.0f, 0.0f, 0.0f);  // ponto final (10 unidades no eixo x)

    // Eixo Y (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);

    // Eixo Z (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);

    glEnd();  // finaliza o bloco de desenho
}

/*
=============================================================
====         FUNCOES DE ROTACAO USANDO O MOUSE            ===
=============================================================
*/

// Angulos de rotacao e estado do mouse
float anguloX = 0.0f;
float anguloY = 0.0f;
int mouseX, mouseY;
int botaoPressionado = 0;

// Redimensionamento da janela
void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);  // area da janela
    glMatrixMode(GL_PROJECTION);  // muda para matriz de projecao (camera)
    glLoadIdentity();  // reseta a matriz
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // perspectiva: 60 graus de abertura, proporcaoo largura/altura, clipping entre 1 e 20
    glMatrixMode(GL_MODELVIEW);  // volta para a matriz de modelagem
}

// Funcao chamada ao pressionar/soltar botao do mouse
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            botaoPressionado = 1;
            mouseX = x;
            mouseY = y;
        } else {
            botaoPressionado = 0;
        }
    }
}

// Funcao chamada ao mover o mouse com botao pressionado
void motion(int x, int y) {
    if (botaoPressionado) {
        int dx = x - mouseX;
        int dy = y - mouseY;

        anguloX += dy * 0.5f; // rodacao vertical
        if (anguloX > 80) anguloX = 80;   // limite superior
        if (anguloX < 10) anguloX = 10; // limite inferior para nao atravessar chao

        anguloY += dx * 0.5f; // rotacao horizontal
        mouseX = x;
        mouseY = y;
        glutPostRedisplay();
    }
}

/*
===========================================================
====         FUNCOES PARA DESENHAR O BONECO             ===
===========================================================
*/
GLUquadric *quad;

void chapeu() {
    // Aba do chapeu 
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);           
        glTranslatef(0.0f, 2.5f, 0.0f);       
        glRotatef(-90, 1.0f, 0.0f, 0.0f);      
        gluDisk(quad, 0.0, 0.5, 30, 1);       
    glPopMatrix();

    // Coroa do chapeu
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);           
        glTranslatef(0.0f, 2.5f, 0.0f);      
        glRotatef(-90, 1.0f, 0.0f, 0.0f);      
        gluCylinder(quad, 0.299f ,0.299f, 0.5, 20, 20);    
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);           
        glTranslatef(0.0f, 3, 0.0f);       
        glRotatef(-90, 1.0f, 0.0f, 0.0f);      
        gluDisk(quad, 0.0, 0.3, 30, 1);       
    glPopMatrix();
}

void cabeca(){
    // cabeca
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(0.0f, 2.2f, 0.0f); 
        gluSphere(quad, 0.4, 30, 30);   
    glPopMatrix();

    // olhos
    glPushMatrix();
        glColor3f(0.0f,0.0f,0.0f);

        // olho direito
        glTranslatef(0.15f, 2.3f, 0.33f);
        gluSphere(quad, 0.05, 20, 20);

        // olho esquerdo
        glTranslatef(-0.3f, 0.0f, 0.0f);
        gluSphere(quad, 0.05, 20, 20);
    glPopMatrix();

    // Nariz 
    glPushMatrix();
        glColor3f(1.0f, 0.5f, 0.0f);      
        glTranslatef(0.0f, 2.2f, 0.38f); 
       // glRotatef(-90, 1.0f, 0.0f, 0.0f);
        glutSolidCone(0.07f, 0.2f, 20, 20);
    glPopMatrix();
}

void bracos(){
    glPushMatrix();
        glColor3f(0.7, 0.3, 0.2);
        glTranslatef(0.5, 1.5f, 0.0f);
        glRotatef(30, 0, 0, 1);
        glRotatef(90, 0, 1, 0);
        gluCylinder(quad, 0.05, 0.02, 1.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.7, 0.3, 0.2);
        glTranslatef(-0.5, 1.5f, 0.0f);
        glRotatef(-30, 0, 0, 1);
        glRotatef(-90, 0, 1, 0);
        gluCylinder(quad, 0.05, 0.02, 1.0, 20, 20);
    glPopMatrix();

}

void botoes() {
    glColor3f(0.0f, 0.0f, 0.0f);

    // Botao 1 
    glPushMatrix();
        glTranslatef(0.0f, 1.75f, 0.5f);
        gluSphere(quad, 0.05, 20, 20);
    glPopMatrix();

    // Botao 2 
    glPushMatrix();
        glTranslatef(0.0f, 1.5f, 0.6f);
        gluSphere(quad, 0.05, 20, 20);
    glPopMatrix();

    // Botao 3 
    glPushMatrix();
        glTranslatef(0.0f, 1.25f, 0.6f);
        gluSphere(quad, 0.05, 20, 20);
    glPopMatrix();
}

void corpo(){
    // bola do meio
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(0, 1.4, 0);       
        gluSphere(quad, 0.6 , 30, 30);  
    glPopMatrix();
}

void pes(){
    // bola de baixo
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(0, 0.5 , 0);
        gluSphere(quad, 0.8, 30, 30); 
    glPopMatrix();
}

void desenharChao() {
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f); 
        glTranslatef(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex3f(-30.0f, 0.0f, -30.0f);
            glVertex3f( 30.0f, 0.0f, -30.0f);
            glVertex3f( 30.0f, 0.0f,  30.0f);
            glVertex3f(-30.0f, 0.0f,  30.0f);
        glEnd();
    glPopMatrix();
}

void desenharCenario() {
    // chao
    desenharChao();

    // pseudosol
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 0.0f); 
        glTranslatef(-3.0f, 5.0f, -5.0f);
        glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // limpa tela e z-buffer
    glLoadIdentity(); 
    glTranslatef(0.0f, -2.0f, -7.0f);  // move a camera 

    // Rotacao interativa
    glRotatef(anguloX, 1.0f, 0.0f, 0.0f);  // gira em torno do eixo x
    glRotatef(anguloY, 0.0f, 1.0f, 0.0f);  // gira em torno do eixo y
    
    //desenharEixos();  
    desenharCenario();
    chapeu();
    cabeca();
    bracos();
    botoes();
    corpo();
    pes();

    glutSwapBuffers();  // troca os buffers (double buffer)
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);  // inicializa a glut 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // modo de exibicao (2 buffers, cor RGB, profundidade)
    glutInitWindowSize(600, 600);  // tamanho da janela
    glutCreateWindow("Boneco de Neve 3D");  // cria a janela

    glEnable(GL_DEPTH_TEST);  // ativa o teste de profundidade
    glClearColor(0.0f, 0.98f,1, 1);

    quad = gluNewQuadric();  // cria objeto quadric (formas geometricas basicas)
    gluQuadricNormals(quad, GLU_SMOOTH);  // normais suaves para iluminacao (ainda nao usado)

    // registra as funcoess de callback
    glutDisplayFunc(display);
    glutReshapeFunc(redimensiona);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();  // entra no loop principal 
    gluDeleteQuadric(quad);  // libera memoria
    return 0;
}
