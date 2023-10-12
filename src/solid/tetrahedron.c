#include "tetrahedron.h"
#include "../util/bindvbo.h"

static const GLfloat tetrahedronDefinition[TETRAHEDRON_TRIANGLE_COUNT * TETRAHEDRON_VERTEX_PER_TRIANGLE_COUNT * 6] =
{
    0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f,
    1.0f, -1.0f, 1.0f, 0.0f, 0.5f, 1.0f,
    -1.0f, -1.0f, 1.0f, 0.0f, 0.5f, 1.0f,

    0.0f, 1.0f, 0.0f, -1.0f, 0.25f, -0.5f,
    -1.0f, -1.0f, 1.0f, -1.0f, 0.25f, -0.5f,
    0.0f, -1.0f, -1.0f, -1.0f, 0.25f, -0.5f,

    0.0f, 1.0f, 0.0f, 1.0f, 1.0f, -0.5f,
    0.0f, -1.0f, -1.0f, 1.0f, 1.0f, -0.5f,
    1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -0.5f,

    1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f,
    -1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
};

static GLuint tetrahedronVBO = 0; //  Tetrahedron VBO

/**
 * Draws the tetrahedron using VBO.
 *
 * @param scale
 *   The scale of the tetrahedron.
 */
void drawTetrahedron(const GLfloat scale)
{
    bindVBO(&tetrahedronVBO, tetrahedronDefinition, sizeof(tetrahedronDefinition));
    // Assigns the vertex array.
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid *)0);
    glEnableClientState(GL_VERTEX_ARRAY);
    // Assigns the normal array.
    glNormalPointer(GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)12);
    glEnableClientState(GL_NORMAL_ARRAY);
    // Draws solid at scale.
    glPushMatrix();
    glScalef(scale, scale, scale);
    glDrawArrays(GL_TRIANGLES, 0, TETRAHEDRON_TRIANGLE_COUNT * TETRAHEDRON_VERTEX_PER_TRIANGLE_COUNT);
    glPopMatrix();
    // Clears the vertex and normal arrays.
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    // Releases the VBO.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
