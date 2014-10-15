#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <math.h>
#include "answer05.h"

//*************************************************************************//
//ACKNOWLEDGEMENT: Many parts of this code have been copied and have been  //
//                 changed according to the need of the Tester from their  //
//                 original source which is as follows:                    //
//                 Book Title : Intermediate C Programming                 //
//                 Author     : Yung Hsiang Lu                             //
//                 Part       : Part II , Recursion                        //
//                 Page #     : Section 12.4 (pp. 206-212),                //
//                              Section 13.4 (p. 221),                     //
//                              Chapter 14 (pp. 234-277)                   //
//*************************************************************************//



//*************************************************************************//
//                             PRINT PARTITIONs
//*************************************************************************//
void printPartition(int * arr, int length)
{
    int ind;
    printf("= ");
    for (ind=0;ind<length-1;ind++)
    {
        printf("%d + ", arr[ind]);
    }
    printf("%d\n", arr[length - 1]);
}
//*************************************************************************//
//                             PARTITION ALL
//*************************************************************************//
void func1(int * arr, int ind, int left)
{
    int val;
    if (left == 0)
    {
        printPartition(arr, ind);
        return;
    }
    for(val = 1; val <= left; val ++)
    {
        arr[ind] = val;
        func1(arr, ind + 1, left - val);
    }
}
// FUNCTION 1
void partitionAll(int value)
{
    int * arr;
    arr = malloc(sizeof(int) * value);
    func1(arr, 0, value);
    free(arr);
}
//*************************************************************************//
//                             PARTITION INCREASING
//*************************************************************************//
void func2(int * arr, int ind, int left)
{
    int val;
    if (left == 0)
    {
        printPartition(arr, ind);
        return;
    }
    int min = 1;
    if(ind !=0)
    {
        min = arr[ind - 1] + 1;
    }
    for(val = min; val <= left; val ++)
    {
        arr[ind] = val;
        func2(arr, ind + 1, left - val);
    }
}
// FUNCTION 2
void partitionIncreasing(int value)
{
    int * arr;
    arr = malloc(sizeof(int) * value);
    func2(arr, 0, value);
    free(arr);
}
//*************************************************************************//
//                             PARTITION DECREASING
//*************************************************************************//
void func3(int * arr, int ind, int left)
{
    int val;
    if (left == 0)
    {
        printPartition(arr, ind);
        return;
    }
    int max = left;
    if(ind !=0)
    {
        max = arr[ind - 1] - 1;
    }
    for(val = max; val > 0; val --)
    {
        arr[ind] = val;
        func3(arr, ind + 1, left - val);
    }
}
// FUNCTION 3
void partitionDecreasing(int value)
{
    int * arr;
    arr = malloc(sizeof(int) * value);
    func3(arr, 0, value);
    free(arr);
}
//*************************************************************************//
//                             PARTITION ODD
//*************************************************************************//
void func4(int * arr, int ind, int left)
{
    int val;
    if (left == 0)
    {
        printPartition(arr, ind);
        return;
    }
    for(val = 1; val <= left; val ++)// odd numbers only
    {
        if(val % 2 == 1)
        {
            arr[ind] = val;
            func4(arr, ind + 1, left - val);
        }
    }
}

// FUNCTION 4
void partitionOdd(int value)
{
    int * arr;
    arr = malloc(sizeof(int) * value);
    func4(arr, 0, value);
    free(arr);
}
//*************************************************************************//
//                             PARTITION EVEN
//*************************************************************************//
void func5(int * arr, int ind, int left)
{
    int val;
    if (left == 0)
    {
        printPartition(arr, ind);
        return;
    }
    for(val = 1; val <= left; val ++)// even numbers only
    {
        if(val % 2 == 0)
        {
            arr[ind] = val;
            func5(arr, ind + 1, left - val);
        }
    }
}


// FUNCTION 5
void partitionEven(int value)
{
    int * arr;
    arr = malloc(sizeof(int) * value);
    func5(arr, 0, value);
    free(arr);
}
//*************************************************************************//
//                             PARTITION ODD AND EVEN
//*************************************************************************//
void func6(int * arr, int ind, int left)
{
    int val;
    if (left == 0)
    {
        printPartition(arr, ind);
        return;
    }
    for(val = 1; val <= left; val ++)
    {
        int valid = 0;
        if (ind == 0) // no restriction for the first number
        {
            valid = 1;
        } else
        {
            valid = (arr[ind - 1] % 2) != (val % 2);
        }
        if (valid == 1)
        {
            arr[ind] = val;
            func6(arr, ind + 1, left - val);
        }
    }
}
// FUNCTION 6
void partitionOddAndEven(int value)
{
    int * arr;
    arr = malloc(sizeof(int) * value);
    func6(arr, 0, value);
    free(arr);
}
//*************************************************************************//
//                             PARTITION PRIME
//*************************************************************************//
int checkprime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 0;
    }
    int i = 0;
    for(i=3;i < (n/2); i+=2)
    {
        if(n%i == 0 && n != i)
        {
            return 0;
        }
    }
    return 1;
}

void func7(int * arr, int ind, int left)
{
    int val;
    if (left == 0)
    {
        printPartition(arr, ind);
        return;
    }
    for(val = 1; val <= left; val ++)
    {
        if(checkprime(val))
        {
            arr[ind] = val;
            func7(arr, ind + 1, left - val);
        }
    }
}

// FUNCTION 7
void partitionPrime(int value)
{
    int * arr;
    arr = malloc(sizeof(int) * value);
    func7(arr, 0, value);
    free(arr);
}
//*************************************************************************//
//                                 THE END
//*************************************************************************//