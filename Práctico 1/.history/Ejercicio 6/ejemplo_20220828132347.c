
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Array de puntos de la polilinea
GLfloat* puntos[2] = {};

void iniciar(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);   // Pinta el fondo de blanco
    glMatrixMode(GL_PROJECTION);    // Selecciona el modo de proyección
    glLoadIdentity();            // Inicializa la matriz de proyección en la matriz identidad
    gluOrtho2D(0.0, 4.0, 0.0, 4.0); // Establece el viewport (ventana de dibujo)
}

void dibujarLineas(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Pinta el punto de color rojo
    glPointSize(0.5);               // Tamaño del punto
    glBegin(GL_LINE_STRIP);
    glVertex2i(0, 2);
    glVertex2i(4, 2);
    glEnd();

    glPointSize(1.0);

    glColor3f(1.0f, 0.0f, 0.0f); // Pinta el punto de color rojo

    glBegin(GL_POINTS);       // Inicia el dibujo de puntos
        
    for (float i = 0; i < 4; i = i + 0.005)
    {
        GLfloat x = i;
        GLfloat y = pow(M_E, -x) * cos(2 * M_PI * x);
        y = y + 2;
        glVertex2f(x, y);
    }



    glEnd();                  // Finaliza el dibujo de puntos

    glFlush();
}


void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // añadir un punto a la polilinea
        printf("tamaño del array: %d\n", sizeof(puntos));

        printf("x = %d, y = %d\n", x, y);
    }
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);      // Inicializa la librería GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Inicializa el modo de visualización (un solo buffer, con color)
    glutInitWindowSize(640, 480);   // Inicializa el tamaño de la ventana de dibujo
    glutInitWindowPosition(100, 150);   // Inicializa la posición de la ventana de dibujo
    glutCreateWindow("CG Ejemplo");  // Crea la ventana de dibujo
    // glutDisplayFunc(dibujar);   // Establece la función de dibujo
    glutMouseFunc(mouse);
    iniciar();              // Inicializa el contenido de la ventana de dibujo
    glutMainLoop();     // Inicia el bucle de eventos
}
