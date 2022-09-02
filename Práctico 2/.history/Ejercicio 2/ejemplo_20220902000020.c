
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
    for (int i = 0; i < cont; i++)
        glVertex2f(puntos[i][0], puntos[i][1]);
    

    glEnd(); // Finaliza el dibujo de puntos

    // array de coordenadas de los puntos
    if (cont == 2)
    {
        cont = 0;
        glFlush();

        glPointSize(1.0);
        glColor3f(colorcito[0], colorcito[1], colorcito[2]);

        float x, y, dx, dy, m, d, incrE, incrNE;
        int pendiente = 0;

        dx = puntos[1][0] - puntos[0][0];
        dy = puntos[1][1] - puntos[0][1];

        m = dy / dx;

        printf("m: %f, dx: %f, dy: %f\n", m, dx, dy);
       
        incrE = 2 * dy;
        incrNE = 2 * (dy - dx);

        pendiente = (m > 0) ? 1 : -1;

        d = (2 * dy) - dx;

        x = puntos[0][0];
        y = puntos[0][1];

        glBegin(GL_POINTS);

        if (pendiente == 1)
        {
            while (x < puntos[1][0])
            {
                glVertex2f(x, y);
                if (d <= 0)
                {
                    d += incrE;
                    x++;
                    if (puntos[0][1] < puntos[1][1])
                        y += m;
                    else
                        y -= m;
                }
                else
                {
                    d += incrNE;
                    x++;
                    if (puntos[0][1] < puntos[1][1])
                        y += m;
                    else
                        y -= m;
                }
            }
        }
        else
        {
            while (x > puntos[1][0])
            {
                glVertex2f(x, y);
                if (d <= 0)
                {
                    d += incrE;
                    x--;
                    if (puntos[0][1] < puntos[1][1])
                        y += m;
                    else
                        y -= m;
                }
                else
                {
                    d += incrNE;
                    x--;
                    if (puntos[0][1] < puntos[1][1])
                        y += m;
                    else
                        y -= m;
                }
            }
        }


        glEnd();
        
    }

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
