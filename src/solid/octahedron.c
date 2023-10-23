#include "octahedron.h"
#include "../util/bindvbo.h"

static const GLfloat octahedronDefinition[OCTAHEDRON_TRIANGLE_COUNT * OCTAHEDRON_VERTEX_PER_TRIANGLE_COUNT * 6] =
{
    0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,
    -1.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,

    0.0f, 1.0f, 0.0f,  -1.0f, 1.0f, 0.0f,
    -1.0f, 0.0f, 1.0f,  -1.0f, 1.0f, 0.0f,
    -1.0f, 0.0f, -1.0f,  -1.0f, 1.0f, 0.0f,

    0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,
    1.0f, 0.0f, -1.0f,  1.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 1.0f,  1.0f, 1.0f, 0.0f,

    0.0f, 1.0f, 0.0f,  0.0f, 1.0f, -1.0f,
    1.0f, 0.0f, -1.0f,  0.0f, 1.0f, -1.0f,
    -1.0f, 0.0f, -1.0f,  0.0f, 1.0f, -1.0f,

    0.0f, -1.0f, 0.0f,  0.0f, -1.0f, 1.0f,
    1.0f, 0.0f, 1.0f,  0.0f, -1.0f, 1.0f,
    -1.0f, 0.0f, 1.0f,  0.0f, -1.0f, 1.0f,

    0.0f, -1.0f, 0.0f,  -1.0f, -1.0f, 0.0f,
    -1.0f, 0.0f, 1.0f,  -1.0f, -1.0f, 0.0f,
    -1.0f, 0.0f, -1.0f,  -1.0f, -1.0f, 0.0f,

    0.0f, -1.0f, 0.0f,  1.0f, -1.0f, 0.0f,
    1.0f, 0.0f, -1.0f,  1.0f, -1.0f, 0.0f,
    1.0f, 0.0f, 1.0f,   1.0f, -1.0f, 0.0f,

    0.0f, -1.0f, 0.0f,  0.0f, -1.0f, -1.0f,
    1.0f, 0.0f, -1.0f,  0.0f, -1.0f, -1.0f,
    -1.0f, 0.0f, -1.0f,  0.0f, -1.0f, -1.0f
};

static GLuint octahedronVBO = 0; //  Octahedron VBO

/**
 * Draws the octahedron using VBO.
 *
 * @param scale
 *   The scale of the octahedron.
 */
void drawOctahedron(const GLfloat scale)
{
    bindVBO(&octahedronVBO, octahedronDefinition, sizeof(octahedronDefinition));
    // Assigns the vertex array.
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableClientState(GL_VERTEX_ARRAY);
    // Assigns the normal array.
    glNormalPointer(GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)12);
    glEnableClientState(GL_NORMAL_ARRAY);
    // Draws solid at scale.
    glPushMatrix();
    glScalef(scale, scale, scale);
    glDrawArrays(GL_TRIANGLES, 0, OCTAHEDRON_TRIANGLE_COUNT * OCTAHEDRON_VERTEX_PER_TRIANGLE_COUNT);
    glPopMatrix();
    // Clears the vertex and normal arrays.
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    // Releases the VBO.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
