#include <string>
#include <iostream>

#include "ConcreteComponent.h"
#include "ConcreteDecorators.h"

int main() {
    IComponent* component = new ConcreteComponent1();
    std::cout << component->do_something() << std::endl;

    component = new ParenthesisDecorator(component);
    std::cout << component->do_something() << std::endl;

    component = new CurlyBrackDecorator(component);
    std::cout << component->do_something() << std::endl;


    std::cout << "---------------------------------------\n";

    component = new ConcreteComponent2();
    std::cout << component->do_something() << std::endl;

    component = new SquareBrackDecorator(component);
    std::cout << component->do_something() << std::endl;

    component = new SquareBrackDecorator(component);
    std::cout << component->do_something() << std::endl;
    
    component = new SquareBrackDecorator(component);
    std::cout << component->do_something() << std::endl;



    std::cout << "---------------------------------------\n";

    component = new ConcreteComponent3();
    std::cout << component->do_something() << std::endl;

    component = new ParenthesisDecorator(component);
    std::cout << component->do_something() << std::endl;

    component = new CurlyBrackDecorator(component);
    std::cout << component->do_something() << std::endl;

    component = new SquareBrackDecorator(component);
    std::cout << component->do_something() << std::endl;


    delete(component);
    return 0;
}