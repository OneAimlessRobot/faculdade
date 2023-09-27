/*******
 *  print vars memory addresses
 *  FCT/UNL
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

const char strC[]= "Memory map of a process\n\n";

char strV[]= "Architecture sizes:";

int globalVar;
int globalVarInit= 1;

int main(int argc, char *argv[]) {
    int x = 3;

    printf("%s", strC);
    printf("%s\nint %zu, long %zu, long long %zu, pointer %zu\n", 
        strV, sizeof (int), sizeof (long), sizeof (long long), sizeof (void*) );

    printf("location of the code      (main):  %p (hex)  %zu (dec)\n", 
        main, (uintptr_t)main);

    printf("location of a (string) constant :  %p (hex)  %zu (dec)\n", 
        strC, (uintptr_t)strC);

    printf("location of a (string) variable :  %p (hex)  %zu (dec)\n", 
        strV, (uintptr_t)strV);

    printf("loc. of a global initialized var:  %p (hex)  %zu (dec)\n", 
        &globalVarInit, (uintptr_t)&globalVarInit);

    printf("loc. of a global non-init'ed var:  %p (hex)  %zu (dec)\n", 
        &globalVar, (uintptr_t)&globalVar);

    char *ptr = malloc(100000000L);
    printf("location of the top of the heap :  %p (hex) %zu (dec)\n", 
        ptr, (uintptr_t)ptr);

    printf("location of the top of the stack:  %p (hex) %zu (dec)\n", 
        &x, (uintptr_t)&x);

    printf("\npress ENTER to exit.\n");
    getchar();

    return 0;
}
