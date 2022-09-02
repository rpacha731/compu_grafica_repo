
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GLfloat puntos[2][2];
GLfloat colorcito[3]; // RGB
int cont = 0;

void iniciar(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);   // Pinta el fondo de blanco
    glMatrixMode(GL_PROJECTION);        // Selecciona el modo de proyección
    glLoadIdentity();                   // Inicializa la matriz de proyección en la matriz identidad
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Establece el viewport (ventana de dibujo)
}

void dibujar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Pinta el punto de color rojo
    glPointSize(3.0);            // Tamaño del punto

    glBegin(GL_POINTS); // Inicia el dibujo de puntos
    glVertex2f(puntos[0][0], puntos[0][1]);

    glEnd(); // Finaliza el dibujo de puntos

    // array de coordenadas de los puntos

    if (cont == 3)
        cont = 0;

        glFlush();

        glPointSize(1.0);
        glColor3f(colorcito[0], colorcito[1], colorcito[2]);

        float x, y, dx, dy, m;
        float x1 = puntos[0][0];
        float y1 = puntos[0][1];
        float x2 = puntos[1][0];
        float y2 = puntos[1][1];

        dx = x2 - x1;
        dy = y2 - y1;

        m = dy / dx;

        x = puntos[0][0];
        y = puntos[0][1];

        glBegin(GL_POINTS);

        // while (x < x2) {
        //     glVertex2f(x, y1);
        //     glVertex2f(x, y2);
        //     glVertex2f(x1, y);
        //     glVertex2f(x2, y);
        //     x++;
        //     y++;
        // }

        // dibujar desde el punto x1, y1 un rectangulo de ancho dx y alto dy
        
        if ((x1 < x2 && y1 < y2) || (x1 < x2 && y1 > y2)) {
            while (x < x2) {
                glVertex2f(x, y1);
                glVertex2f(x, y2);
                glVertex2f(x1, y);
                glVertex2f(x2, y);
                x++;
                y = y1 + m * (x - x1);
            }
        } else if ((x1 > x2 && y1 > y2) || (x1 > x2 && y1 < y2)) {
            while (x > x2) {
                glVertex2f(x, y1);
                glVertex2f(x, y2);
                glVertex2f(x1, y);
                glVertex2f(x2, y);
                x--;
                y = y1 + m * (x - x1);
            }
        }

        glEnd();
    

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        puntos[cont][0] = x;
        puntos[cont][1] = abs(480 - y);
        cont++;
        dibujar();
    }
}

void mousePassiveMotion(int x, int y)
{
    puntos[1][0] = x;
    puntos[1][1] = abs(480 - y);
    dibujar();
}

void keyboard(unsigned char key, int x, int y)
{
    printf("%c\n", key);
    switch (key)
    {
    case 'a':
        colorcito[0] = 0;
        colorcito[1] = 0;
        colorcito[2] = 255;
        break;
    case 'v':
        colorcito[0] = 0;
        colorcito[1] = 255;
        colorcito[2] = 0;
        break;
    case 'r':
        colorcito[0] = 255;
        colorcito[1] = 0;
        colorcito[2] = 0;
        break;
    }
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Inicializa la librería GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Inicializa el modo de visualización (un solo buffer, con color)
    glutInitWindowSize(640, 480);                // Inicializa el tamaño de la ventana de dibujo
    glutInitWindowPosition(100, 150);            // Inicializa la posición de la ventana de dibujo
    glutCreateWindow("CG Ejemplo");              // Crea la ventana de dibujo
    glutDisplayFunc(dibujar);                    // Establece la función de dibujo
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mousePassiveMotion);
    iniciar();      // Inicializa el contenido de la ventana de dibujo
    glutMainLoop(); // Inicia el bucle de eventos
}
