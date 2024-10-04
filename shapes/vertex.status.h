//
// Created by mario on 2024/10/3.
//

#ifndef VERTEX_STATUS_H
#define VERTEX_STATUS_H

typedef enum TriVertexSortStatus {
#define TRIVSORT(n) TriVSort ## n
    TRIVSORT(Success) = 0,
    TRIVSORT(VertexError),
    TRIVSORT(VertexFlatBottom)
#undef TRIVSORT
}TriVertexSortStatus;

#define TRIVSORT_ERR(e) TriVSort ## e ## Error
#define TRIVSORT_STAT(stat) TriVSort ## stat
#define TRIVSORT_SUC TriVSort ## Success

#endif //VERTEX_STATUS_H
