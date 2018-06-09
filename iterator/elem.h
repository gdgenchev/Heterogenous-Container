//
// Created by georg on 1/3/2018.
//

#ifndef HETEROGENEOUS_CONTAINER_ELEM_H
#define HETEROGENEOUS_CONTAINER_ELEM_H

template <typename T>
struct elem {
    T inf;
    elem<T>* next;
};
#endif //HETEROGENEOUS_CONTAINER_ELEM_H
