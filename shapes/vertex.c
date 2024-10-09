//
// Created by mario on 2024/10/3.
//

#include "vertex.def.h"
#include "vertex.status.h"

VertexOpStatus TriVertices2DYSort(Vertex2D vertices[3]) {
    if (vertices[0].y == vertices[1].y && vertices[1].y == vertices[2].y) {
        return EVOP(VCheck);
    }

    if (vertices[0].x == vertices[1].x && vertices[1].x == vertices[2].x) {
        return EVOP(VCheck);
    }

    if (vertices[0].y == vertices[1].y && vertices[0].x == vertices[1].x) {
        return EVOP(VCheck);
    }

    if (vertices[1].y == vertices[2].y && vertices[1].x == vertices[2].x) {
        return EVOP(VCheck);
    }

    if (vertices[0].y == vertices[2].y && vertices[0].x == vertices[2].x) {
        return EVOP(VCheck);
    }

    for (int sort_id = 0; sort_id < 2; ++sort_id) {
        for (int vid = 0; vid < 2 - sort_id; ++vid) {
            if (vertices[vid].y < vertices[vid + 1].y) {
                Vertex2D vertex_buf = vertices[vid];
                vertices[vid] = vertices[vid + 1];
                vertices[vid + 1] = vertex_buf;
            }
        }
    }

    if (vertices[0].y == vertices[1].y) {
        return SVOP(VSort2Same);
    }

    return SVOP(Success);
}

VertexOpStatus TriVertices2DXSort(Vertex2D vertices[3]) {
    if (vertices[0].y == vertices[1].y && vertices[1].y == vertices[2].y) {
        return EVOP(VCheck);
    }

    if (vertices[0].x == vertices[1].x && vertices[1].x == vertices[2].x) {
        return EVOP(VCheck);
    }

    if (vertices[0].y == vertices[1].y && vertices[0].x == vertices[1].x) {
        return EVOP(VCheck);
    }

    if (vertices[1].y == vertices[2].y && vertices[1].x == vertices[2].x) {
        return EVOP(VCheck);
    }

    if (vertices[0].y == vertices[2].y && vertices[0].x == vertices[2].x) {
        return EVOP(VCheck);
    }

    for (int sort_id = 0; sort_id < 2; ++sort_id) {
        for (int vid = 0; vid < 2 - sort_id; ++vid) {
            if (vertices[vid].x < vertices[vid + 1].x) {
                Vertex2D vertex_buf = vertices[vid];
                vertices[vid] = vertices[vid + 1];
                vertices[vid + 1] = vertex_buf;
            }
        }
    }

    if (vertices[0].x == vertices[1].x) {
        return SVOP(VSort2Same);
    }

    return SVOP(Success);
}

static __inline__ __w2cview(float* a, float world_min, float world_rng) {
    *a = (*a - world_min) / world_rng * 2 - 1;
}

static __inline__ __cview2s(float* a, float screen_center_xoy) {
    *a = *a * screen_center_xoy + screen_center_xoy;
}

VertexOpStatus TriVertices2DTransform(Vertex2D vertices[3], Vertex2DTransform* trans) {
    switch (trans->trans_type) {
        case World2Screen:
            float world_x_rng = trans->trans_arg.w2s.world_x_max - trans->trans_arg.w2s.world_x_min;
            float world_y_rng = trans->trans_arg.w2s.world_y_max - trans->trans_arg.w2s.world_y_min;

            float screen_center_x = trans->trans_arg.w2s.screen_width / 2;
            float screen_center_y = trans->trans_arg.w2s.screen_height / 2;

            for (int vid = 0; vid < 3; ++vid) {
                __w2cview(&vertices[vid].x, trans->trans_arg.w2s.world_x_min, world_x_rng);
                __cview2s(&vertices[vid].x, screen_center_x);
                __w2cview(&vertices[vid].y, trans->trans_arg.w2s.world_y_min, world_y_rng);
                __cview2s(&vertices[vid].y, screen_center_y);
            }
            break;
        default:
            return EVOP(FCheck);
    }

    return SVOP(Success);
}