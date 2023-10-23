#include "icosahedron.h"
#include "../util/bindvbo.h"

static const GLfloat icosahedronDefinition[ICOSAHEDRON_TRIANGLE_COUNT * ICOSAHEDRON_VERTEX_PER_TRIANGLE_COUNT * 6] =
{
                1.0f,             0.0f,             0.0f,  0.760845213037948f,  0.470228201835026f,  0.341640786498800f,
     0.447213590145f,  0.894427180290f,             0.0f,  0.760845213037948f,  0.470228201835026f,  0.341640786498800f,
     0.447213590145f,  0.276393204927f,  0.850650787354f,  0.760845213037948f,  0.470228201835026f,  0.341640786498800f,

                1.0f,             0.0f,             0.0f,  0.760845213036861f, -0.179611190632978f,  0.552786404500000f,
     0.447213590145f,  0.276393204927f,  0.850650787354f,  0.760845213036861f, -0.179611190632978f,  0.552786404500000f,
     0.447213590145f, -0.723606824875f,  0.525731086731f,  0.760845213036861f, -0.179611190632978f,  0.552786404500000f,

                1.0f,             0.0f,             0.0f,  0.760845213033849f, -0.581234022404097f,                0.0f,
     0.447213590145f, -0.723606824875f,  0.525731086731f,  0.760845213033849f, -0.581234022404097f,                0.0f,
     0.447213590145f, -0.723606824875f, -0.525731086731f,  0.760845213033849f, -0.581234022404097f,                0.0f,

                1.0f,             0.0f,             0.0f,  0.760845213036861f, -0.179611190632978f, -0.552786404500000f,
     0.447213590145f, -0.723606824875f, -0.525731086731f,  0.760845213036861f, -0.179611190632978f, -0.552786404500000f,
     0.447213590145f,  0.276393204927f, -0.850650787354f,  0.760845213036861f, -0.179611190632978f, -0.552786404500000f,

                1.0f,             0.0f,             0.0f,  0.760845213037948f,  0.470228201835026f, -0.341640786498800f,
     0.447213590145f,  0.276393204927f, -0.850650787354f,  0.760845213037948f,  0.470228201835026f, -0.341640786498800f,
     0.447213590145f,  0.894427180290f,             0.0f,  0.760845213037948f,  0.470228201835026f, -0.341640786498800f,

     0.447213590145f,  0.894427180290f,             0.0f,  0.179611190628666f,  0.760845213037948f,  0.552786404498399f,
    -0.447213590145f,  0.723606824875f,  0.525731086731f,  0.179611190628666f,  0.760845213037948f,  0.552786404498399f,
     0.447213590145f,  0.276393204927f,  0.850650787354f,  0.179611190628666f,  0.760845213037948f,  0.552786404498399f,

     0.447213590145f,  0.276393204927f,  0.850650787354f,  0.179611190634277f, -0.290617011204044f,  0.894427191000000f,
    -0.447213590145f, -0.276393204927f,  0.850650787354f,  0.179611190634277f, -0.290617011204044f,  0.894427191000000f,
     0.447213590145f, -0.723606824875f,  0.525731086731f,  0.179611190634277f, -0.290617011204044f,  0.894427191000000f,

     0.447213590145f, -0.723606824875f,  0.525731086731f,  0.179611190633958f, -0.940456403667806f,                0.0f,
    -0.447213590145f, -0.894427180290f,             0.0f,  0.179611190633958f, -0.940456403667806f,                0.0f,
     0.447213590145f, -0.723606824875f, -0.525731086731f,  0.179611190633958f, -0.940456403667806f,                0.0f,

     0.447213590145f, -0.723606824875f, -0.525731086731f,  0.179611190634278f, -0.290617011204044f, -0.894427191000000f,
    -0.447213590145f, -0.276393204927f, -0.850650787354f,  0.179611190634278f, -0.290617011204044f, -0.894427191000000f,
     0.447213590145f,  0.276393204927f, -0.850650787354f,  0.179611190634278f, -0.290617011204044f, -0.894427191000000f,

     0.447213590145f,  0.276393204927f, -0.850650787354f,  0.179611190628666f,  0.760845213037948f, -0.552786404498399f,
    -0.447213590145f,  0.723606824875f, -0.525731086731f,  0.179611190628666f,  0.760845213037948f, -0.552786404498399f,
     0.447213590145f,  0.894427180290f,             0.0f,  0.179611190628666f,  0.760845213037948f, -0.552786404498399f,

     0.447213590145f,  0.894427180290f,             0.0f, -0.179611190633958f,  0.940456403667806f,                0.0f,
    -0.447213590145f,  0.723606824875f, -0.525731086731f, -0.179611190633958f,  0.940456403667806f,                0.0f,
    -0.447213590145f,  0.723606824875f,  0.525731086731f, -0.179611190633958f,  0.940456403667806f,                0.0f,

     0.447213590145f,  0.276393204927f,  0.850650787354f, -0.179611190634277f,  0.290617011204044f,  0.894427191000000f,
    -0.447213590145f,  0.723606824875f,  0.525731086731f, -0.179611190634277f,  0.290617011204044f,  0.894427191000000f,
    -0.447213590145f, -0.276393204927f,  0.850650787354f, -0.179611190634277f,  0.290617011204044f,  0.894427191000000f,

     0.447213590145f, -0.723606824875f,  0.525731086731f, -0.179611190628666f, -0.760845213037948f,  0.552786404498399f,
    -0.447213590145f, -0.276393204927f,  0.850650787354f, -0.179611190628666f, -0.760845213037948f,  0.552786404498399f,
    -0.447213590145f, -0.894427180290f,             0.0f, -0.179611190628666f, -0.760845213037948f,  0.552786404498399f,

     0.447213590145f, -0.723606824875f, -0.525731086731f, -0.179611190628666f, -0.760845213037948f, -0.552786404498399f,
    -0.447213590145f, -0.894427180290f,             0.0f, -0.179611190628666f, -0.760845213037948f, -0.552786404498399f,
    -0.447213590145f, -0.276393204927f, -0.850650787354f, -0.179611190628666f, -0.760845213037948f, -0.552786404498399f,

     0.447213590145f,  0.276393204927f, -0.850650787354f, -0.179611190634277f,  0.290617011204044f, -0.894427191000000f,
    -0.447213590145f, -0.276393204927f, -0.850650787354f, -0.179611190634277f,  0.290617011204044f, -0.894427191000000f,
    -0.447213590145f,  0.723606824875f, -0.525731086731f, -0.179611190634277f,  0.290617011204044f, -0.894427191000000f,

    -           1.0f,             0.0f,             0.0f, -0.760845213036861f,  0.179611190632978f, -0.552786404500000f,
    -0.447213590145f,  0.723606824875f, -0.525731086731f, -0.760845213036861f,  0.179611190632978f, -0.552786404500000f,
    -0.447213590145f, -0.276393204927f, -0.850650787354f, -0.760845213036861f,  0.179611190632978f, -0.552786404500000f,

    -           1.0f,             0.0f,             0.0f, -0.760845213033849f,  0.581234022404097f,                0.0f,
    -0.447213590145f,  0.723606824875f,  0.525731086731f, -0.760845213033849f,  0.581234022404097f,                0.0f,
    -0.447213590145f,  0.723606824875f, -0.525731086731f, -0.760845213033849f,  0.581234022404097f,                0.0f,

    -           1.0f,             0.0f,             0.0f, -0.760845213036861f,  0.179611190632978f,  0.552786404500000f,
    -0.447213590145f, -0.276393204927f,  0.850650787354f, -0.760845213036861f,  0.179611190632978f,  0.552786404500000f,
    -0.447213590145f,  0.723606824875f,  0.525731086731f, -0.760845213036861f,  0.179611190632978f,  0.552786404500000f,

    -           1.0f,             0.0f,             0.0f, -0.760845213037948f, -0.470228201835026f,  0.341640786498800f,
    -0.447213590145f, -0.894427180290f,             0.0f, -0.760845213037948f, -0.470228201835026f,  0.341640786498800f,
    -0.447213590145f, -0.276393204927f,  0.850650787354f, -0.760845213037948f, -0.470228201835026f,  0.341640786498800f,

    -           1.0f,             0.0f,             0.0f, -0.760845213037948f, -0.470228201835026f, -0.341640786498800f,
    -0.447213590145f, -0.276393204927f, -0.850650787354f, -0.760845213037948f, -0.470228201835026f, -0.341640786498800f,
    -0.447213590145f, -0.894427180290f,             0.0f, -0.760845213037948f, -0.470228201835026f, -0.341640786498800f
};

static GLuint icosahedronVBO = 0; //  Icosahedron VBO

/**
 * Draws the icosahedron using VBO.
 *
 * @param scale
 *   The scale of the icosahedron.
 */
void drawIcosahedron(const GLfloat scale)
{
    bindVBO(&icosahedronVBO, icosahedronDefinition, sizeof(icosahedronDefinition));
    // Assigns the vertex array.
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableClientState(GL_VERTEX_ARRAY);
    // Assigns the normal array.
    glNormalPointer(GL_FLOAT, 6 * sizeof(GLfloat), (GLvoid*)12);
    glEnableClientState(GL_NORMAL_ARRAY);
    // Draws solid at scale.
    glPushMatrix();
    glScalef(scale, scale, scale);
    glDrawArrays(GL_TRIANGLES, 0, ICOSAHEDRON_TRIANGLE_COUNT * ICOSAHEDRON_VERTEX_PER_TRIANGLE_COUNT);
    glPopMatrix();
    // Clears the vertex and normal arrays.
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    // Releases the VBO.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
