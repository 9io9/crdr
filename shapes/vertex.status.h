//
// Created by mario on 2024/10/3.
//

#ifndef VERTEX_STATUS_H
#define VERTEX_STATUS_H

typedef enum VertexOpStatus {
#define VOP(n) VertexOp ## n
    VOP(Success) = 0,
    VOP(FCheckError),
    VOP(VCheckError),
    VOP(VSort2Same),
#undef VOP
}VertexOpStatus;

#define EVOP(e) VertexOp ## e ## Error
#define SVOP(stat) VertexOp ## stat

#endif //VERTEX_STATUS_H
