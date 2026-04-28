#pragma once

#include <string>

#include "IDecorator.h"

class ParenthesisDecorator : public IDecorator {

public:
    ParenthesisDecorator(IComponent* c) : IDecorator(c) {} 

    std::string do_something() const override {
        return "(" + this->wrapped_component->do_something() + ")";
    }
};


class CurlyBrackDecorator : public IDecorator {

public:
    CurlyBrackDecorator(IComponent* c) : IDecorator(c) {} 

    std::string do_something() const override {
        return "{" + this->wrapped_component->do_something() + "}";
    }
};


class SquareBrackDecorator : public IDecorator {

public:
    SquareBrackDecorator(IComponent* c) : IDecorator(c) {} 

    std::string do_something() const override {
        return "[" + this->wrapped_component->do_something() + "]";
    }
};