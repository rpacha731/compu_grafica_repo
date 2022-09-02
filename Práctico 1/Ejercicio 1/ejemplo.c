
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
    glClear(GL_COLOR_BUFFER_BIT);   // Inicializa el buffer de color
    glFlush();                   // Limpia el buffer de color
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
