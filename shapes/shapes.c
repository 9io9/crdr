//
// Created by mario on 2024/10/3.
//

#include <windows.h>
#ifdef ENABLE_PRINT
#include <stdio.h>
#else
#define fprintf(...)
#endif
#include <math.h>

#include "vertex.h"

#include "shapes.status.h"

RenderPaintStatus RenderPaintPure2DTriangle(Vertex2D vertexs[3], COLORREF color, HDC hdc, int max_width, int max_height) {
    switch (TriVertices2DYSort(vertexs)) {
        case SVOP(VSort2Same): {
            if (vertexs[2].y > max_height || vertexs[0].y < 0) {
                return RDRPAINT_SUC;
            }

            float dx_31 = vertexs[0].x -  vertexs[2].x;
            float dx_32 = vertexs[1].x - vertexs[2].x;
            float dy_312 = vertexs[1].y - vertexs[2].y;

            float k31 = dx_31 / dy_312;
            float k32 = dx_32 / dy_312;

            fprintf(stdout, "k31: %f, k32: %f\n", k31, k32);

            int dy = 0;

            while (vertexs[2].y + dy <= min(vertexs[0].y, max_height)) {

                dx_31 = dy * k31;
                dx_32 = dy * k32;

                fprintf(stdout, "y: %f, dx_31: %f, dx_32: %f\n", vertexs[2].y + dy, dx_31, dx_32);

                int start_x = min(nearbyintf(vertexs[2].x + dx_31), nearbyintf(vertexs[2].x + dx_32));
                int end_x = max(nearbyintf(vertexs[2].x + dx_31), nearbyintf(vertexs[2].x + dx_32));

                if (end_x >= 0 || start_x < max_width) {
                    start_x = max(0, start_x);
                    end_x = min(end_x, max_width);

                    fprintf(stdout, "startX: %d, endX: %d\n", start_x, end_x);

                    while (start_x <= end_x) {
                        SetPixel(hdc, start_x, vertexs[2].y + dy, color);
                        start_x += 1;
                    }
                }

                dy += 1;
            }

            return RDRPAINT_SUC;
        }
        case SVOP(Success): {
            if (vertexs[2].y > max_height || vertexs[0].y < 0) {
                return RDRPAINT_SUC;
            }

            float dx_31 = vertexs[0].x -  vertexs[2].x;
            float dx_32 = vertexs[1].x - vertexs[2].x;
            float dx_12 = vertexs[1].x - vertexs[0].x;
            float dy_31 = vertexs[0].y - vertexs[2].y;
            float dy_32 = vertexs[1].y - vertexs[2].y;
            float dy_12 = vertexs[1].y - vertexs[0].y;

            float k31 = dx_31 / dy_31;
            float k32 = dx_32 / dy_32;
            float k12 = dx_12 / dy_12;


            fprintf(stdout, "k31: %f, k32: %f, k12: %f\n", k31, k32, k12);

            int dy = 0;

            while (vertexs[2].y + dy < min(vertexs[1].y, max_height)) {

                dx_31 = dy * k31;
                dx_32 = dy * k32;

                fprintf(stdout, "y: %f, dx_31: %f, dx_32: %f\n", vertexs[2].y + dy, dx_31, dx_32);

                int start_x = min(nearbyintf(vertexs[2].x + dx_31), nearbyintf(vertexs[2].x + dx_32));
                int end_x = max(nearbyintf(vertexs[2].x + dx_31), nearbyintf(vertexs[2].x + dx_32));

                if (end_x >= 0 || start_x <= max_width) {
                    start_x = max(0, start_x);
                    end_x = min(end_x, max_width);

                    fprintf(stdout, "startX: %d, endX: %d\n", start_x, end_x);

                    while (start_x <= end_x) {
                        SetPixel(hdc, start_x, vertexs[2].y + dy, color);
                        start_x += 1;
                    }
                }

                dy += 1;
            }

            int offset31 = dy + 1;
            dy = 0;

            while (vertexs[1].y + dy <= min(vertexs[0].y, max_height)) {

                dx_31 = (offset31 + dy) * k31;
                dx_12 = dy * k12;

                fprintf(stdout, "y: %f, dx_31: %f, dx_12: %f\n", vertexs[1].y + dy, dx_31 - offset31 * k31, dx_12);

                int start_x = min(nearbyintf(vertexs[2].x + dx_31), nearbyintf(vertexs[1].x +  dx_12));
                int end_x = max(nearbyintf(vertexs[2].x + dx_31), nearbyintf(vertexs[1].x +  dx_12));

                if (end_x >= 0 || start_x <= max_width) {
                    start_x = max(0, start_x);
                    end_x = min(end_x, max_width);

                    fprintf(stdout, "startX: %d, endX: %d\n", start_x, end_x);

                    while (start_x <= end_x) {
                        SetPixel(hdc, start_x, vertexs[1].y + dy, color);
                        start_x += 1;
                    }
                }

                dy += 1;
            }

            return RDRPAINT_SUC;
        }
        default:
            return RDRPAINT_ERR(TriVertexs);
    }
}