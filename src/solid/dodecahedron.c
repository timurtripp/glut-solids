#include "dodecahedron.h"
#include "../util/bindvbo.h"

#define V_1 0.381966024637f
#define V_2 0.618034005165f
#define N_1 0.525731112119f
#define N_2 0.850650808354f

static const GLfloat dodecahedronDefinition[DODECAHEDRON_POLYGON_COUNT * DODECAHEDRON_VERTEX_PER_POLYGON_COUNT * 6] =
{
     0.0f,  1.0f,   V_1,  0.0f,  N_1,  N_2,
    - V_2,   V_2,   V_2,  0.0f,  N_1,  N_2,
    - V_1,  0.0f,  1.0f,  0.0f,  N_1,  N_2,
      V_1,  0.0f,  1.0f,  0.0f,  N_1,  N_2,
      V_2,   V_2,   V_2,  0.0f,  N_1,  N_2,

     0.0f,  1.0f, - V_1,  0.0f,  N_1, -N_2,
      V_2,   V_2, - V_2,  0.0f,  N_1, -N_2,
      V_1,  0.0f, -1.0f,  0.0f,  N_1, -N_2,
    - V_1,  0.0f, -1.0f,  0.0f,  N_1, -N_2,
    - V_2,   V_2, - V_2,  0.0f,  N_1, -N_2,

     0.0f, -1.0f,   V_1,  0.0f, -N_1,  N_2,
      V_2, - V_2,   V_2,  0.0f, -N_1,  N_2,
      V_1,  0.0f,  1.0f,  0.0f, -N_1,  N_2,
    - V_1,  0.0f,  1.0f,  0.0f, -N_1,  N_2,
    - V_2, - V_2,   V_2,  0.0f, -N_1,  N_2,

     0.0f, -1.0f, - V_1,  0.0f, -N_1, -N_2,
    - V_2, - V_2, - V_2,  0.0f, -N_1, -N_2,
    - V_1,  0.0f, -1.0f,  0.0f, -N_1, -N_2,
      V_1,  0.0f, -1.0f,  0.0f, -N_1, -N_2,
      V_2, - V_2, - V_2,  0.0f, -N_1, -N_2,

      V_1,  0.0f,  1.0f,  N_2,  0.0f,  N_1,
      V_2, - V_2,   V_2,  N_2,  0.0f,  N_1,
     1.0f, - V_1,  0.0f,  N_2,  0.0f,  N_1,
     1.0f,   V_1,  0.0f,  N_2,  0.0f,  N_1,
      V_2,   V_2,   V_2,  N_2,  0.0f,  N_1,

    - V_1,  0.0f,  1.0f, -N_2,  0.0f,  N_1,
    - V_2,   V_2,   V_2, -N_2,  0.0f,  N_1,
    -1.0f,   V_1,  0.0f, -N_2,  0.0f,  N_1,
    -1.0f, - V_1,  0.0f, -N_2,  0.0f,  N_1,
    - V_2, - V_2,   V_2, -N_2,  0.0f,  N_1,

      V_1,  0.0f, -1.0f,  N_2,  0.0f, -N_1,
      V_2,   V_2, - V_2,  N_2,  0.0f, -N_1,
     1.0f,   V_1,  0.0f,  N_2,  0.0f, -N_1,
     1.0f, - V_1,  0.0f,  N_2,  0.0f, -N_1,
      V_2, - V_2, - V_2,  N_2,  0.0f, -N_1,

    - V_1,  0.0f, -1.0f, -N_2,  0.0f, -N_1,
    - V_2, - V_2, - V_2, -N_2,  0.0f, -N_1,
    -1.0f, - V_1,  0.0f, -N_2,  0.0f, -N_1,
    -1.0f,   V_1,  0.0f, -N_2,  0.0f, -N_1,
    - V_2,   V_2, - V_2, -N_2,  0.0f, -N_1,

     1.0f,   V_1,  0.0f,  N_1,  N_2,  0.0f,
      V_2,   V_2, - V_2,  N_1,  N_2,  0.0f,
     0.0f,  1.0f, - V_1,  N_1,  N_2,  0.0f,
     0.0f,  1.0f,   V_1,  N_1,  N_2,  0.0f,
      V_2,   V_2,   V_2,  N_1,  N_2,  0.0f,

     1.0f, - V_1,  0.0f,  N_1, -N_2,  0.0f,
      V_2, - V_2,   V_2,  N_1, -N_2,  0.0f,
     0.0f, -1.0f,   V_1,  N_1, -N_2,  0.0f,
     0.0f, -1.0f, - V_1,  N_1, -N_2,  0.0f,
      V_2, - V_2, - V_2,  N_1, -N_2,  0.0f,

    -1.0f,   V_1,  0.0f, -N_1,  N_2,  0.0f,
    - V_2,   V_2,   V_2, -N_1,  N_2,  0.0f,
     0.0f,  1.0f,   V_1, -N_1,  N_2,  0.0f,
     0.0f,  1.0f, - V_1, -N_1,  N_2,  0.0f,
    - V_2,   V_2, - V_2, -N_1,  N_2,  0.0f,

    -1.0f, - V_1,  0.0f, -N_1, -N_2,  0.0f,
    - V_2, - V_2, - V_2, -N_1, -N_2,  0.0f,
     0.0f, -1.0f, - V_1, -N_1, -N_2,  0.0f,
     0.0f, -1.0f,   V_1, -N_1, -N_2,  0.0f,
    - V_2, - V_2,   V_2, -N_1, -N_2,  0.0f
};

static GLuint dodecahedronVBO = 0; //  Dodecahedron VBO

/**
 * Draws the dodecahedron using VBO.
 *
 * @param scale
 *   The scale of the dodecahedron.
 */
void drawDodecahedron(const GLfloat scale)
{
    bindVBO(&dodecahedronVBO, dodecahedronDefinition, sizeof(dodecahedronDefinition));
    // Assigns the vertex array.
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableClientState(GL_VERTEX_ARRAY);
    // Assigns the normal array.
    glNormalPointer(GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)12);
    glEnableClientState(GL_NORMAL_ARRAY);
    // Draws solid at scale.
    glPushMatrix();
    glScalef(scale, scale, scale);
    for (int i = 0; i < DODECAHEDRON_POLYGON_COUNT; i++)
        glDrawArrays(GL_POLYGON, DODECAHEDRON_VERTEX_PER_POLYGON_COUNT * i, DODECAHEDRON_VERTEX_PER_POLYGON_COUNT);
    glPopMatrix();
    // Clears the vertex and normal arrays.
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    // Releases the VBO.
    glBindBuffer(GL_ARRAY_BUFFER,  0);
}
