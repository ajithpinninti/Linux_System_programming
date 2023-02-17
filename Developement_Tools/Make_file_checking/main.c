#include "stdlib.h"
#include "a.h"


extern void function_two();
extern void function_three();

int main(){
    function_three();
    function_two();
    exit(EXIT_SUCCESS);
}