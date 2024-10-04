//
// Created by mario on 2024/10/3.
//

#ifndef SHAPES_STATUS_H
#define SHAPES_STATUS_H

typedef enum RenderPaintStatus {
#define RDRPAINT(n) RenderPaint ## n
    RDRPAINT(Success) = 0,
    RDRPAINT(FuncArgError),
    RDRPAINT(TriVertexsError),
#undef RDRPAINT
}RenderPaintStatus;

#define RDRPAINT_SUC RenderPaintSuccess
#define RDRPAINT_ERR(e) RenderPaint ## e ## Error
#define RDRPAINT_STAT(stat) RenderPaint ## stat

#endif //SHAPES_STATUS_H
