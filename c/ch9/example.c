#include "vector.h"
#include <stdio.h>

int main(void)
{
    int i;
    
    for (i=0; i<11; ++i) {
        push_back(i*2+7);
        printf("i: %d, size: %d, capacity: %d\n", i, get_size(), get_capacity());
    }

    while (get_size()) {
        i = pop_back();
        printf("i: %d, size: %d, capacity: %d\n", i, get_size(), get_capacity());
    }
}
