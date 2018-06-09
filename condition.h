//
// Created by georg on 1/2/2018.
//

#ifndef HETEROGENEOUS_CONTAINER_CONDITION_H
#define HETEROGENEOUS_CONTAINER_CONDITION_H

template <typename T>
using Condition = bool (*)(T const&);

#endif //HETEROGENEOUS_CONTAINER_CONDITION_H
