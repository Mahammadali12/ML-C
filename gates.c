#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


float or_train [][3]={
    {0,0,0},
    {1,0,1},
    {0,1,1},
    {1,1,1}
};

float and_train [][3]={
    {0,0,0},
    {1,0,0},
    {0,1,0},
    {1,1,1}
};

float nand_train [][3]={
    {0,0,1},
    {1,0,1},
    {0,1,1},
    {1,1,0}
};


typedef float sample[3];
sample *train = nand_train;
const float TRAIN_COUNT = 4;

float random_float()
{
    return (float)rand()/(float)RAND_MAX;
}

float sigmoidf(float x)
{
    return 1.f/(1 + expf(-x));
}


float cost(float w1,float w2,float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < TRAIN_COUNT; i++)
    {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = sigmoidf(x1*w1 + x2*w2 + b);

        float d = y - train[i][2];
        result += d*d  ;

    }

    result /= TRAIN_COUNT;
    return result;

}

int main()
{
    srand(time(0));

    float w1 = random_float();
    float w2 = random_float();
    float b  = random_float();
    
    float eps = 1e-2;
    float rate = 1e-3 ;
        float c;
    for (size_t i = 0; i < 1e+6; i++)
    {
        c = cost(w1,w2,b);
        // printf("w1 = %f w2 = %f b = %f c = %f\n",w1,w2,b,c);
        // printf("%f\n",c);

        float dw1 = (cost(w1 + eps,w2,b) - c)/eps;
        float dw2 = (cost(w1,w2 + eps,b) - c)/eps;
        float db  = (cost(w1,w2,b + eps) - c)/eps;

        w1 -= rate*dw1;
        w2 -= rate*dw2;
        b -= rate*db;
    }
    // printf("w1 = %f w2 = %f b = %f c = %f\n",w1,w2,b,c);

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            printf("%zu | %zu | %f\n",i,j,sigmoidf(i*w1 +j*w2 + b));
        }
        
    }
    // printf("------------------------------\n");
    // printf("w = %f b = %f\n",w,b);
    return 0;
}