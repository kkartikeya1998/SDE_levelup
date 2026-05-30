#pragma once

#include "Aggregate.h"

class LLAggregate : public Aggregate<int> {
public:
    int data;
    LLAggregate* next;

    LLAggregate(int val);
    Iterator<int>* createIterator() override;
};

class BTAggregate : public Aggregate<int> {
public:
    int data;
    BTAggregate* left;
    BTAggregate* right;

    BTAggregate(int val);
    Iterator<int>* createIterator() override;
    Iterator<int>* createLevelOrderIterator();
};