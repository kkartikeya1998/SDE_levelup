#pragma once

#include <iostream>

class SubsystemComponent1 {
public:

    bool component_1_precondition() {
        std::cout << "[Subsystem Component 1] Checking preconditions...\n";
        return true;
    }

    void component_1_operation(){
        std:: cout << "[Subsystem Component 1] Performing operation 1...\n";
    }
};

class SubsystemComponent2 {
public:
    bool component_1_precondition() {
        std::cout << "[Subsystem Component 2] Checking preconditions...\n";
        return true;
    }

    void component_2_operation() {
        std::cout << "[Subsystem Component 2] Performing operation 2...\n";
    }

    bool component_2_postcondition() {
        std::cout << "[Subsystem Component 2] Checking postconditions...\n";
        return true;
    }
};

class SubsystemComponent3 {
public: 
    void  component_3_operation() {
        std::cout << "[Subsystem Component 3] Performing operation 3...\n";
    }
}; 


class SubsystemComponent4 {
public:
    void component_4_operation() {
        std::cout << "[Subsystem Component 4] Performing operation 4...\n";
    }

    bool component_4_postcondition() {
        std::cout << "[Subsystem Component 4] Checking postconditions...\n";
        return true;
    }
};

