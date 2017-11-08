#include <malloc.h>
#include "FixedAllocator.h"
#include <iostream>
int main() {
    /*FixedAllocator obj;
    int *m = (int *)obj.Allocate(40);

    for (int i = 0; i < 10; i++) {
        m[i] = i;
        std::cout <<  m[i] << std::endl;
    }*/
   /* int *x = (int *)obj.Allocate(40);

    for (int i = 0; i < 10; i++) {
        x[i] = i;
        std::cout <<  x[i] << std::endl;
    }
    int *y = (int *)obj.Allocate(40);

    for (int i = 0; i < 10; i++) {
        y[i] = i;
        std::cout <<  y[i] << std::endl;
    }*/
    Chunk tmp;
    tmp.Init(10,20);
    int *x = (int*)tmp.Allocate(40);
    for (int i = 0; i < 10; i++) {
        //*x++ = i;
        x[i] = i;
        std::cout << x[i] << std::endl;
    }
    int *y = (int*)tmp.Allocate(40);
    for (int i = 0; i < 10; i++) {
        //*x++ = i;
        y[i] = i+10;
        std::cout << y[i] << std::endl;
    }
    /*
    Question 2
    char *x = (char *) malloc(sizeof(char)*20);
    std::cout << malloc_usable_size(x) << std::endl;
    char *y = x;
    for (int i = 0; i < 10; i++) {
        y++;
        *y =64;

        std::cout << *y << malloc_usable_size(y) << std::endl;
    }*/
    
   
    return 0;
}