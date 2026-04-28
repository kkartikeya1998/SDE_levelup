#pragma once

#include <string>

class IComponent{
public:
    virtual ~IComponent() = default;
    virtual std::string do_something() const = 0;
};