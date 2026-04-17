#define NN_IMPLEMENTATION
#include "nn.h"
#include<time.h>

int main (void)
{
    srand(time(0));
    Mat m = mat_alloc(2,2);
    mat_fill(m,31);

    Mat n = mat_alloc(2,2);
    mat_fill(n,69);
    printf("---------------------------\n");
    mat_sum(m,n);
    mat_print(m);
    return 0;
}