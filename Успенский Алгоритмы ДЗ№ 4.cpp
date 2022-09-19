#include <stdio.h>
#include <stdlib.h>

int binRecursive(int num) {
    if (num > 0) {
        printf("\n %d  \n", num % 2);
        return binRecursive(num / 2);
    }
    else {
        return 0;
    }
}

int  aDegreeIterativeB(int a, int b) {
    int degree = 1;
    while (b > 0) {
        degree = degree * a;
        b =b - 1;
    }
    return degree;
}

int  aDegreeRecursiveB(int a, int b) {
     if (b > 0) {
        return a* aDegreeRecursiveB( a, (b-1));
    }
    else {
        return 1;
    }
}


int  aDegreeRecursiveParityB(int a, int b) {
    if (b == 0) {
        return 1;
    }
    else if (b == 1) {
        return a;
    }
    else if ((b % 2) == 0) {
        return (a*a) * aDegreeRecursiveB(a, (b/2));
    }
    else if ((b % 2) == 1) {
        return (a * a) * aDegreeRecursiveB(a, ((b-1) / 2) );
    }
    else  {
        return 1;
    }
}

int routes(int x, int y) {
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0 ^ y == 0)
        return 1;
    else
        return routes(x, y - 1) + routes(x - 1, y);
}




int main(const int argc, const char** argv)
{
    printf("%d \n", binRecursive(10));
    printf("%d \n", aDegreeIterativeB(2,4));
    printf("%d \n", aDegreeRecursiveB(2, 4));
    printf("%d \n", aDegreeRecursiveParityB(2, 4));
    printf("%d \n", aDegreeRecursiveParityB(2, 3));
    printf("%d \n", aDegreeRecursiveParityB(2, 1));
    printf("%d \n", aDegreeRecursiveParityB(2, 0));

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            printf("%5d", routes(x, y));
        }
        printf("\n");
    }

    return 0;
}