#ifdef USEGLEW
#include <GL/glew.h>
#endif
#ifdef USEFREEGLUT
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
