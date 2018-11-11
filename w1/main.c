#include "stdio.h"
#include "math.h"

/*
 * h(Q)(x) = Q0 + Q1x
 * */

float X[4] = {1,2,4,0};
float Y[4] = {0.5,1,2,0};

float h(float Q[2], float x)
{
    return Q[0] + Q[1] *x;
}

float mesure(float Q[2])
{
    int i = 0;
    float m =0;

    for(i=0;i<4;i++) {
        m += (h(Q,X[i]) - Y[i])*(h(Q,X[i]) - Y[i]);
    }

    return m; 
}


int main(int argc,char **argv)
{
    float Q[2];

    Q[0] = 1, Q[1] = 1;
    printf("(1,1) mesure: %f \r\n",mesure(Q));

    Q[0] = 0.5, Q[1] = 0.5;
    printf("(0.5,0.5) mesure: %f \r\n",mesure(Q));


    Q[0] = 1, Q[1] = 0.5;
    printf("(1,0.5) mesure: %f \r\n",mesure(Q));


    Q[0] = 0, Q[1] = 0.5;
    printf("(0,0.5) mesure: %f \r\n",mesure(Q));

    Q[0] = 0.5, Q[1] = 0;
    printf("(0.5,0) mesure: %f \r\n",mesure(Q));

    return 0;
}
