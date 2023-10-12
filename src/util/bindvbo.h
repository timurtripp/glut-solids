#include "glincludes.h"

/**
 * Creates a new buffer and assigns its name to `p`,
 * initializing it with the contents of array `a`.
 *
 * @param p
 *   The pointer to assign.
 * @param a
 *   The array to place in the VBO if p isn't yet initialized.
 * @param n
 *   The size (in bytes) of a.
 */
void bindVBO(GLuint* p, const GLfloat a[], const int n);
