#pragma once

#include "Iterator.h"

template <typename T>
class Aggregate{
public:
    virtual ~Aggregate() = default;
    virtual Iterator<T>* createIterator() = 0;
};