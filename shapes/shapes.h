//
// Created by mario on 2024/10/3.
//

#ifndef SHAPES_H
#define SHAPES_H

#include "vertex.h"
#include "shapes.status.h"

extern RenderPaintStatus RenderPaintPure2DTriangle(Vertex2D vertexs[3], COLORREF color, HDC hdc, int max_width, int max_height);

#endif //SHAPES_H
