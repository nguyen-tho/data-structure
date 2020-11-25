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

void insertionSort(int arr[],int size)
{
    int i, j, key;
    for( i=0; i<size;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void insertionSort2(int arr[],int size)
{
    int j;
    for(int i=0; i<size; i++)
    {
        j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    
}

void output(int arr[], int size)
{
    insertionSort(arr, size);
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