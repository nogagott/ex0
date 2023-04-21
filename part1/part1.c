//
// Created by Noga on 21/04/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


int input_size_r();
int* get_num(int input_size);
bool is_exponent_of_two(int x);
int calculate_exponent_of_two(int x);


int main ()
{
    int input_size = input_size_r();
    if (input_size < 1)
    {
        printf("Invalid size\n");
        return 0;
    }
    int* num = get_num(input_size);
    if( num == NULL)
    {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i<= input_size; i++)
    {
        int x = num[i];
        if (is_exponent_of_two(x))
        {
          int exp = calculate_exponent_of_two(x);
          printf("The number %d is a power of 2: %d = 2^%d\n", x, x, exp);
          sum += exp;
        }
    }
    free(num);

    printf("Total exponent sum is %d\n", sum);

    return 0;
}


int input_size_r()
{
    int input_size = 0;
    printf("Enter size of input:\n");
    scanf("%d", &input_size);
    return input_size;
}

int* get_num(int input_size)
{
    printf("Enter numbers:\n");
    int* num = malloc(input_size * sizeof(*num));
    if (num == NULL) {
        return NULL;
    }
    for (int i = 0; i < input_size; i++)
    {
         if(scanf("%d", &num[i]) != 1)
         {
             printf("Invalid number\n") ;
             return NULL;
         }
    }
    return num;
}

int calculate_exponent_of_two(int x)
{
    assert(x >= 1);
    int exp = 0;
    while(x % 2 == 0)
    {
        x /= 2;
        exp++;
    }
    return exp;
}

bool is_exponent_of_two(int x)
{
    if (x < 1)
    {
        return false;
    }

    return (x & (x-1)) == 0;
}