#pragma once

#include <string>

#include "IComponent.h"


class IDecorator : public IComponent {
protected:
    IComponent* wrapped_component;    
public:
    IDecorator(IComponent * component) {
        this->wrapped_component = component;
    }

    ~IDecorator() {
        delete(wrapped_component);
    }
};