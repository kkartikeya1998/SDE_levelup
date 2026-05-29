#include <stdexcept>

#include "Object.h"

class SimpleObjectBuilder{
private:
    Object obj;

public:
    SimpleObjectBuilder& with_p1(const std::string& val) {
        obj.p1 = val;
        return *this; 
    }

    SimpleObjectBuilder& with_p2(const std::string& val) {
        obj.p2 = val;
        return *this;
    }

    SimpleObjectBuilder& with_p3(int val) {
        obj.p3 = val;
        return *this; 
    }

    SimpleObjectBuilder& with_p4(int val) {
        obj.p4 = val;
        return *this;
    }

    Object build() {
        if(obj.p1.empty()) {
            throw std::runtime_error(
                "[Simple Object Builder] Missing critical attribute: p1!\n"
            );
        }
        return obj;
    }
    
};