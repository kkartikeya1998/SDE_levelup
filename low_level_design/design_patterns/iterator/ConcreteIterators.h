#pragma once

#include <stack>
#include <queue>


#include "Iterator.h"
#include "ConcreteAggregates.h"

class LLIterator : public Iterator<int> {
private:
    LLAggregate* cur;

public:
    LLIterator(LLAggregate* head) : cur(head) {}

    bool hasNext() override {
        return cur != nullptr;
    }

    int next() override {
        int val = cur->data;
        cur = cur->next;
        return val;
    }
};

class BTPreorderIterator : public Iterator<int> {
private:
    std::stack<BTAggregate*> st;

public:
    BTPreorderIterator(BTAggregate* root) {
        if(root) st.push(root);
    }

    bool hasNext() override {
        return !st.empty();    
    }

    int next() override {
        BTAggregate* node = st.top();
        st.pop();

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
        
        return node->data;
    }
};


class BTLevelOrderIterator : public Iterator<int> {
private:
    std::queue<BTAggregate*> q;

public:
    BTLevelOrderIterator(BTAggregate* root) {
        if(root) q.push(root);
    }

    bool hasNext() override {
        return !q.empty();
    }

    int next() override {
        BTAggregate* node = q.front();
        q.pop();

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);

        return node->data;
    }
};