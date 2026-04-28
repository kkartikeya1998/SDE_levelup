#pragma once

#include <string>

class IAdapter {
public:
    virtual ~IAdapter() = default;
    virtual std::string get_name() = 0;
    virtual std::string get_city() = 0;
};