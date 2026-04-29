#pragma once

#include "SubsystemComponent.h"

class Facade {
private:
    SubsystemComponent1* s_cmp1;
    SubsystemComponent2* s_cmp2;
    SubsystemComponent3* s_cmp3;
    SubsystemComponent4* s_cmp4;

public:
    Facade() {
        s_cmp1 = new SubsystemComponent1();
        s_cmp2 = new SubsystemComponent2();
        s_cmp3 = new SubsystemComponent3();
        s_cmp4 = new SubsystemComponent4();
    }

    ~Facade() {
        if(s_cmp1) delete(s_cmp1);
        if(s_cmp2) delete(s_cmp2);
        if(s_cmp3) delete(s_cmp3);
        if(s_cmp4) delete(s_cmp4);
    }

    void perform_operation() {
        if(!s_cmp1->component_1_precondition()) return;
        if(!s_cmp2->component_1_precondition()) return;
        
        s_cmp1->component_1_operation();
        s_cmp2->component_2_operation();
        s_cmp3->component_3_operation();
        s_cmp4->component_4_operation();
        
        if(!s_cmp2->component_2_postcondition()) return;
        if(!s_cmp4->component_4_postcondition()) return;    

        std::cout << "Operation performed successfully!\n";
    }
};