#include <iostream>
#include <string>

#include "Adaptee.h"
#include "TargetAdapter.h"

int main() {
    Adaptee adaptee;

    adaptee.set_adapter(new ConcreteAdapter1());
    std::cout << "Adapter1->Name: " << adaptee.get_name() << ", "
              << "City: " << adaptee.get_city() << std::endl;

    
    adaptee.set_adapter(new ConcreteAdapter2());
    std::cout << "Adapter1->Name: " << adaptee.get_name() << ", "
              << "City: " << adaptee.get_city() << std::endl;

    
    adaptee.set_adapter(new ConcreteAdapter3());
    std::cout << "Adapter1->Name: " << adaptee.get_name() << ", "
              << "City: " << adaptee.get_city() << std::endl;

    
    adaptee.set_adapter(new ConcreteAdapter4());
    std::cout << "Adapter1->Name: " << adaptee.get_name() << ", "
              << "City: " << adaptee.get_city() << std::endl;

    return 0;
}
