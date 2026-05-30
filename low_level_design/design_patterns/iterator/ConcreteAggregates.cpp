#include "ConcreteAggregates.h"
#include "ConcreteIterators.h"

LLAggregate::LLAggregate(int val) : data(val), next(nullptr) {}

BTAggregate::BTAggregate(int val) : data(val), left(nullptr), right(nullptr) {}

Iterator<int>* LLAggregate::createIterator() {
    return new LLIterator(this);
}

Iterator<int>* BTAggregate::createIterator() {
    return new BTPreorderIterator(this);
}

Iterator<int>* BTAggregate::createLevelOrderIterator() {
    return new BTLevelOrderIterator(this);
}