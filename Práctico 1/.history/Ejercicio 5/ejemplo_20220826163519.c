
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

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
    glPointSize(1.0);            // Tamaño del punto

    // leer archivo de puntos 'dino.dat'
    FILE *archivo = fopen("dino.dat", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    int n;
    // Estructura del archivo
    // cantidad de polilíneas total
    // cantidad de puntos por polilínea
    // x1 y1
    // x2 y2
    // ...
    // xn yn
    // cantidad de puntos por polilínea
    // x1 y1
    // x2 y2
    fscanf(archivo, "%d", &n);  // Cantidad de polilineas
    printf("%d\n", n);


    while (!feof(archivo))
    {
        for (int j = 0; j < n; j++)
        {
            int m;      // Cantidad de puntos por polilinea
            fscanf(archivo, "%d", &m);
            glBegin(GL_LINE_STRIP);
            for (int i = 0; i < m; i++)
            {
                GLint x, y;
                fscanf(archivo, "%d %d", &x, &y);
                glVertex2f(x, y);

            }
            glEnd();
        }
    }

    fclose(archivo);
    

    glFlush();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Inicializa la librería GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Inicializa el modo de visualización (un solo buffer, con color)
    glutInitWindowSize(640, 480);                // Inicializa el tamaño de la ventana de dibujo
    glutInitWindowPosition(100, 150);            // Inicializa la posición de la ventana de dibujo
    glutCreateWindow("CG Ejemplo");              // Crea la ventana de dibujo
    glutDisplayFunc(dibujar);                    // Establece la función de dibujo
    iniciar();                                   // Inicializa el contenido de la ventana de dibujo
    glutMainLoop();                              // Inicia el bucle de eventos
}
