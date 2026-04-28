#pragma once

#include <string>

#include "IComponent.h"


class ConcreteComponent1 : public IComponent {
public:
    std::string do_something() const override {
        return "[Component1] doing something...";
    }
};


class ConcreteComponent2 : public IComponent {
public:
    std::string do_something() const override {
        return "[Component2] doing something...";
    }
};


class ConcreteComponent3 : public IComponent {
public:
    std::string do_something() const override {
        return "[Component3] doing something...";
    }
};



