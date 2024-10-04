//
// Created by mario on 2024/10/3.
//

#include "vertex.def.h"
#include "vertex.status.h"

TriVertexSortStatus TriVertexsYSort(Vertex2D vertexs[3]) {
    if (vertexs[0].y == vertexs[1].y && vertexs[1].y == vertexs[2].y) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[0].x == vertexs[1].x && vertexs[1].x == vertexs[2].x) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[0].y == vertexs[1].y && vertexs[0].x == vertexs[1].x) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[1].y == vertexs[2].y && vertexs[1].x == vertexs[2].x) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[0].y == vertexs[2].y && vertexs[0].x == vertexs[2].x) {
        return TRIVSORT_ERR(Vertex);
    }

    Vertex2D vertex_buf;

    for (int sort_id = 0; sort_id < 2; ++sort_id) {
        for (int vid = 0; vid < 2 - sort_id; ++vid) {
            if (vertexs[vid].y < vertexs[vid + 1].y) {
                vertex_buf = vertexs[vid];
                vertexs[vid] = vertexs[vid + 1];
                vertexs[vid + 1] = vertex_buf;
            }
        }
    }

    if (vertexs[0].y == vertexs[1].y) {
        return TRIVSORT_STAT(VertexFlatBottom);
    }

    return TRIVSORT_SUC;
}

TriVertexSortStatus TriVertexsXSort(Vertex2D vertexs[3]) {
    if (vertexs[0].y == vertexs[1].y && vertexs[1].y == vertexs[2].y) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[0].x == vertexs[1].x && vertexs[1].x == vertexs[2].x) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[0].y == vertexs[1].y && vertexs[0].x == vertexs[1].x) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[1].y == vertexs[2].y && vertexs[1].x == vertexs[2].x) {
        return TRIVSORT_ERR(Vertex);
    }

    if (vertexs[0].y == vertexs[2].y && vertexs[0].x == vertexs[2].x) {
        return TRIVSORT_ERR(Vertex);
    }

    Vertex2D vertex_buf;

    for (int sort_id = 0; sort_id < 2; ++sort_id) {
        for (int vid = 0; vid < 2 - sort_id; ++vid) {
            if (vertexs[vid].x < vertexs[vid + 1].x) {
                vertex_buf = vertexs[vid];
                vertexs[vid] = vertexs[vid + 1];
                vertexs[vid + 1] = vertex_buf;
            }
        }
    }

    if (vertexs[0].x == vertexs[1].x) {
        return TRIVSORT_STAT(VertexFlatBottom);
    }

    return TRIVSORT_SUC;
}