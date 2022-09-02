
#include <GL/glu.h>
#include <GL/glut.h>

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
        glVertex2f(100.0, 50.0);  // Dibuja el punto (100,50)
        glVertex2f(100.0, 130.0); // Dibuja el punto (100,130)
        glVertex2f(150.0, 130.0); // Dibuja el punto (130,130)
    glEnd();                  // Finaliza el dibujo de puntos
    glFlush();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);      // Inicializa la librería GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Inicializa el modo de visualización (un solo buffer, con color)
    glutInitWindowSize(640, 480);   // Inicializa el tamaño de la ventana de dibujo
    glutInitWindowPosition(100, 150);   // Inicializa la posición de la ventana de dibujo
    glutCreateWindow("CG Ejemplo");  // Crea la ventana de dibujo
    glutDisplayFunc(dibujar);   // Establece la función de dibujo
    iniciar();              // Inicializa el contenido de la ventana de dibujo
    glutMainLoop();     // Inicia el bucle de eventos
}
