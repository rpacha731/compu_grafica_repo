
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GLfloat puntos[3][2];
int cont = 0;

void iniciar(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);   // Pinta el fondo de blanco
    glMatrixMode(GL_PROJECTION);    // Selecciona el modo de proyección
    glLoadIdentity();            // Inicializa la matriz de proyección en la matriz identidad
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Establece el viewport (ventana de dibujo)
}

void dibujar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); // Pinta el punto de color rojo
    glPointSize(5.0);               // Tamaño del punto

    glBegin(GL_POINTS);       // Inicia el dibujo de puntos
        for (int i = 0; i < cont; i++)
        {
            printf("dibujando %f %f\n", puntos[i][0], puntos[i][1]);
            glVertex2f(puntos[i][0], puntos[i][1]);
        }
    
    glEnd();                  // Finaliza el dibujo de puntos

    // array de coordenadas de los puntos
    if (cont == 3) {
        glFlush();

    glPointSize(2.0);
     glBegin(GL_POINTS);       // Inicia el dibujo de puntos
        for (int i = 0; i < cont; i++)
        {
            glVertex2f(puntos[i][0], puntos[i][1]);
        }
    
    glEnd();
    GLfloat puntoK[2] = {100.0, 50.0};

    glBegin(GL_POINTS);

    for (int i = 0; i < 50000; i++) {
        // selecciona un punto al azar
        int punto = rand() % 3;
        // if (punto == 0 && i == 0)
        //     punto = 1;
        
        GLfloat x = puntos[punto][0];
        GLfloat y = puntos[punto][1];

        puntoK[0] = (puntoK[0] + x) / 2;
        puntoK[1] = (puntoK[1] + y) / 2;

        glVertex2f(puntoK[0], puntoK[1]);
    }
    glEnd();
    }
    

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        printf("%d\n", cont);
        printf("%d %d\n", x, y);
        puntos[cont][0] = x;
        puntos[cont][1] = y;
        cont ++;
        dibujar();
    }
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);      // Inicializa la librería GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Inicializa el modo de visualización (un solo buffer, con color)
    glutInitWindowSize(640, 480);   // Inicializa el tamaño de la ventana de dibujo
    glutInitWindowPosition(100, 150);   // Inicializa la posición de la ventana de dibujo
    glutCreateWindow("CG Ejemplo");  // Crea la ventana de dibujo
    glutDisplayFunc(dibujar);   // Establece la función de dibujo
    glutMouseFunc(mouse);
    iniciar();              // Inicializa el contenido de la ventana de dibujo
    glutMainLoop();     // Inicia el bucle de eventos
}
