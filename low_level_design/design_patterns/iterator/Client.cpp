#include <iostream>

#include "ConcreteAggregates.h"

void deleteLinkedList(LLAggregate* head) { 
    LLAggregate* cur = head;
    while(cur) {
        LLAggregate* next = cur->next;
        delete cur;
        cur = next;
    }
}

void deleteTree(BTAggregate* root) {
    if(root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}


int main() {
    std::cout << "-------- LinkedList Collection --------\n";

    LLAggregate* head = new LLAggregate(1);
    head->next = new LLAggregate(2);
    head->next->next = new LLAggregate(3);
    head->next->next->next = new LLAggregate(4);

    Iterator<int>* llIterator = head->createIterator();

    while(llIterator->hasNext()) {
        std::cout << llIterator->next() << " ";
    }

    std::cout << "\n\n";

    std::cout << "-------- BinaryTree Collection --------\n";

    BTAggregate* root = new BTAggregate(1);

    root->left = new BTAggregate(2);
    root->right = new BTAggregate(3);

    root->left->left = new BTAggregate(4);
    root->left->right = new BTAggregate(5);

    root->right->left = new BTAggregate(6);
    root->right->right = new BTAggregate(7);

    std::cout << "Preorder: ";

    Iterator<int>* preorder = root->createIterator();

    while(preorder->hasNext()) {
        std::cout << preorder->next() << " ";
    }

    std::cout << "\n";

    std::cout << "Level Order: ";

    Iterator<int>* levelorder = root->createLevelOrderIterator();

    while(levelorder->hasNext()) {
        std::cout << levelorder->next() << " ";
    }

    std::cout << "\n";


    // Cleanup

    delete(head);
    deleteTree(root);

    delete(llIterator);
    delete(preorder);
    delete(levelorder);
    return 0;
}