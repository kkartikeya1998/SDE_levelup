#include "SimpleObjectBuilder.h"


int main() {
    Object obj1 = SimpleObjectBuilder()
                    .with_p1("First object")
                    .with_p2("Spicy")
                    .with_p3(5)
                    .with_p4(500)
                    .build();

    obj1.run();

    Object obj2 = SimpleObjectBuilder()
                    .with_p1("Second Object")
                    .build();
    obj2.run();

    return 0;
}