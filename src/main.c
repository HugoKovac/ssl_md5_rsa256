#include <stdio.h>
#include "my_library.h"

int main() {
    int a = 5, b = 3;
    printf("Add: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtract: %d - %d = %d\n", a, b, subtract(a, b));
    return 0;
}
