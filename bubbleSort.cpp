#include <iostream>

using namespace std;

void input(int arr[], int  &size)
{
    cin>> size;
    for(int i=0;i<size;i++)
        cin>> arr[i];
}

void swap (int &a, int &b)
{
    int t=a;
    a=b;
    b=t;
}
/*
void bubbleSort(int arr[], int size)
{
    int i,j;
    bool haveSwap=false;// cờ hiệu báo true khi đã swap 
    for(int i=0; i<size-1; i++)
    {
        haveSwap=false;
        for(int j=0; j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                haveSwap=true;
            }
            if (haveSwap=false)// khi mảng đã được xếp thì không hoán vị tiếp
                break;
        }
    }
}
*/
void bubbleSort2(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
         for(int j=size-10; j>i;j--)
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
    }   
}

void output(int arr[], int size)
{
    bubbleSort2(arr, size);
    for(int i=0; i<size;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[100], size;
    input(arr, size);
    output(arr, size);
    return 0;
}
