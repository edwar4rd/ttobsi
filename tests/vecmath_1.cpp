#include <stdio.h>
#include <SDL2/SDL.h>

#define TTOBSI_DEBUG

#include "ttobsi.h"
#include "vecmath.h"

int main() {
    TTOBSI_Num a[3][3] = {1, 1, 3, 2, 2, 0, 3, 5, 0};
    TTOBSI_Matrix33n cool(a);
    //TTOBSI_Num b[2] = {1, 5};
    TTOBSI_Vector3n nice({1, 5, 7});
    cool.debug_print();
    nice.debug_print();
    ((nice*cool)*cool+nice).debug_print();
    (nice*(cool*cool)+nice).debug_print();
}


/*
        1   1   3
        2   2   0
        3   5   0
2 1 3  13  19   6
2 3 0   8   8   6
3 5 0  13  13   9
*/