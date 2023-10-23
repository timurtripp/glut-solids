#include "cube.h"
#include "../util/bindvbo.h"

static const GLfloat cubeDefinition[CUBE_QUAD_COUNT * CUBE_VERTEX_PER_QUAD_COUNT * 6] =
{
    -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
     1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
     1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,

     1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
     1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,

     1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
     1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
     1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
     1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,

    -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
    -1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
    -1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
    -1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f,

    -1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
     1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
     1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,
    -1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,

    -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
     1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
     1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
    -1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f
};

static GLuint cubeVBO = 0; //  Cube VBO

/**
 * Draws the cube using VBO.
 *
 * @param scale
 *   The scale of the cube.
 */
void drawCube(const GLfloat scale)
{
    bindVBO(&cubeVBO, cubeDefinition, sizeof(cubeDefinition));
    // Assigns the vertex array.
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableClientState(GL_VERTEX_ARRAY);
    // Assigns the normal array.
    glNormalPointer(GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)12);
    glEnableClientState(GL_NORMAL_ARRAY);
    // Draws solid at scale.
    glPushMatrix();
    glScalef(scale, scale, scale);
    glDrawArrays(GL_QUADS, 0, CUBE_QUAD_COUNT * CUBE_VERTEX_PER_QUAD_COUNT);
    glPopMatrix();
    // Clears the vertex and normal arrays.
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    // Releases the VBO.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
