#include <string.h>

#include "TargetAdapter.h"
#include "IAdapter.h"


class Adaptee {
private:
    IAdapter* adapter;

public:
    void set_adapter(IAdapter* new_adapter) {
        adapter = new_adapter;
    }

    std::string get_name() {
        if(adapter == nullptr) return "";
        return adapter->get_name();
    }

    std::string get_city() {
        if(adapter == nullptr) return "";
        return adapter->get_city();
    }
};