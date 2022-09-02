
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void iniciar(void) {

    glClearColor(1.0, 1.0, 1.0, 0.0);   // Pinta el fondo de blanco
    glMatrixMode(GL_PROJECTION);        // Selecciona el modo de proyección con la matriz de proyección
    glLoadIdentity();                   // Inicializa la matriz de proyección en la matriz identidad
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Establece la ventana de dibujo, actua como zoom tambien (?)

}

void dibujar(void) {

    glClear(GL_COLOR_BUFFER_BIT);   // Limpio la pantalla
    glColor3f(0.0f, 0.0f, 0.0f);    // Cambio de color a negro para lo que se pintará
    glPointSize(1.0);               // Tamaño del punto a pintar

    FILE *archivo = fopen("dino.dat", "r");     // Abro el archivo en modo lectura

    if (archivo == NULL) {      // Si no puedo abrir el archivo, error del programa
        printf("Error al abrir el archivo\n");
        exit(1);
    }

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

    int n;      // n = Total de polilineas de todo el dinosaurio
    fscanf(archivo, "%d", &n);

    while (!feof(archivo)) {    // Mientras que no se termine el archivo

        for (int j = 0; j < n; j++) {       // Recorro todas las polilíneas del dinosaurio
            
            int m;                          // m = Cantidad de puntos de la polilínea actual
            fscanf(archivo, "%d", &m);      // Leo la cantidad de puntos de la polilínea actual

            glBegin(GL_LINE_STRIP);         // Inicio el dibujado de la polilínea actual

            for (int i = 0; i < m; i++) {  // Recorro todos los puntos de la polilínea actual
                GLint x, y;
                fscanf(archivo, "%d %d", &x, &y);   // Leo los puntos de la polilínea actual del archivo
                glVertex2f(x, y);         // Pinto el punto actual para la polilínea actual
            }

            glEnd();                     // Finalizo el dibujado de la polilínea actual
        }

    }

    fclose(archivo);             // Cierro el archivo
    
    glFlush();                 // Limpio el buffer de dibujo
}

void main(int argc, char **argv) {

    glutInit(&argc, argv);                       // Inicializa la librería GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Inicializa el modo de visualización (un solo buffer, con color)
    glutInitWindowSize(640, 480);                // Inicializa el tamaño de la ventana de dibujo
    glutInitWindowPosition(100, 150);            // Inicializa la posición de la ventana de dibujo
    glutCreateWindow("Ejercicio 5 - Leonel Pacha :)");              // Crea la ventana de dibujo
    glutDisplayFunc(dibujar);                    // Establece la función de dibujo
    iniciar();                                   // Inicializa el contenido de la ventana de dibujo
    glutMainLoop();                              // Inicia el bucle de eventos

}
