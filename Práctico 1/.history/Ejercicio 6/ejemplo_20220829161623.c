
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GLfloat puntos[3][2];
GLfloat colorcito[3] = {0.0, 0.0, 0.0}; // RGB
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
    glColor3f(colorcito[0], colorcito[1], colorcito[2]);
    glPointSize(5.0);            // Tamaño del punto

    glBegin(GL_LINE_STRIP); // Inicia el dibujo de puntos
    for (int i = 0; i < cont; i++)
        glVertex2f(puntos[i][0], puntos[i][1]);
    

    glEnd(); // Finaliza el dibujo de puntos

    // array de coordenadas de los puntos
    // if (cont == 3)
    // {
    //     cont = 0;
    //     glFlush();

    //     glPointSize(1.0);
    //     glColor3f(colorcito[0], colorcito[1], colorcito[2]);
    //     glBegin(GL_POINTS); // Inicia el dibujo de puntos
    //     for (int i = 0; i < cont; i++)
    //     {
    //         glVertex2f(puntos[i][0], puntos[i][1]);
    //     }

    //     glEnd();
    //     GLfloat puntoK[2] = {puntos[0][0], puntos[0][1]};

    //     glBegin(GL_POINTS);

    //     for (int i = 0; i < 50000; i++)
    //     {
    //         // selecciona un punto al azar
    //         int punto = rand() % 3;
    //         // if (punto == 0 && i == 0)
    //         //     punto = 1;

    //         GLfloat x = puntos[punto][0];
    //         GLfloat y = puntos[punto][1];

    //         puntoK[0] = (puntoK[0] + x) / 2;
    //         puntoK[1] = (puntoK[1] + y) / 2;

    //         glVertex2f(puntoK[0], puntoK[1]);
    //     }
    //     glEnd();
    // }

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
    case 'z':
        cont --;
        dibujar();
        break;
    // caso tecla 'esc'
    case 27:
        printf("preionaste ESC\n");
        break;
    }
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
    iniciar();      // Inicializa el contenido de la ventana de dibujo
    glutMainLoop(); // Inicia el bucle de eventos
}
