//
// Created by mario on 2024/10/3.
//

#ifndef VERTEX_H
#define VERTEX_H

#include "vertex.def.h"
#include "vertex.status.h"

extern VertexOpStatus TriVertices2DYSort(Vertex2D vertices[3]);

extern VertexOpStatus TriVertices2DXSort(Vertex2D vertices[3]);

extern VertexOpStatus TriVertices2DTransform(Vertex2D vertices[3], Vertex2DTransform* trans_type);

#endif //VERTEX_H
