#include "bindvbo.h"

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
void bindVBO(GLuint* p, const GLfloat a[], const int n)
{
    if (*p)
        glBindBuffer(GL_ARRAY_BUFFER, *p); // Tells OpenGL to use the buffer `p` refers to.
    else
    {
        // Initializes `p` with a newly-created buffer name.
        glGenBuffers(1, p);
        // Tells OpenGL to use the buffer `p` refers to.
        glBindBuffer(GL_ARRAY_BUFFER, *p);
        // Copies the `n` number of bytes from `a` into the buffer.
        glBufferData(GL_ARRAY_BUFFER, n, a, GL_STATIC_DRAW);
    }
}
