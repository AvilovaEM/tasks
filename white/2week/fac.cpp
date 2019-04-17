#include<iostream>

int Factorial(int n)
{
    if(n < 2) return 1;

    int f = 1;

    for(int i = 2; i < n+1; i++)
        f *= i;

    return f;
}
