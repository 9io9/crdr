//
// Created by mario on 2024/10/3.
//

#ifndef VERTEX_DEF_H
#define VERTEX_DEF_H

typedef struct Vertex2D {
    float x, y;
}Vertex2D;

typedef struct Vertex3D {
    float x, y, z;
}Vertex3D;

typedef enum Vertex2DTransformType {
    World2Screen = 0,
    XYMove,
    DMove,
    Rotate,
    Scale,
}Vertex2DTransformType;

typedef struct Vertex2DTransform {
    Vertex2DTransformType trans_type;
    union TransArg {
        struct W2S {
            float world_x_max, world_x_min, world_y_max, world_y_min;
            int screen_width, screen_height;
        }w2s;
        struct XMov {
            float x, y;
        }xmov;
        struct DMov {
            Vertex2D dire;
            float dire_scale_rate;
        }dmov;
        struct Rot {
            float angle;
        }rot;
        struct Scal {
            float x_scale_rate;
            float y_scale_rate;
        }scal;
    }trans_arg;
}Vertex2DTransform;

#endif //VERTEX_DEF_H
