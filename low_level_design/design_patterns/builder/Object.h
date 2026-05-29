#pragma once 

#include <iostream>
#include <string>

class Object {
private:
    std::string p1 = "";
    std::string p2 = "";
    int p3 = 0;
    int p4 = 0;

    Object() {}
public:
    friend class SimpleObjectBuilder;

    void run() {
        std::cout << "[Object] Running method with the object[" << this << "]\n";
        std::cout << "\t Param1 : " << p1 << std::endl;

        if(!p2.empty()) std::cout << "\t Param2 : " << p2 << std::endl;
        std::cout << "\t Param3 : " << p3 << std::endl;
        std::cout << "\t Param4 : " << p4 << std::endl;
        
    }
};