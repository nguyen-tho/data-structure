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

void selectionSort(int arr[], int size)
{
    int i,j, minIdx;
    for( i=0; i<size-1;i++)
    {
        minIdx=i; //gán minIdx=i để xét vị trí nhỏ nhất
        for(j=i+1; j<size; j++)
            if(arr[j]<arr[minIdx]) 
                minIdx=j;
        swap(arr[minIdx], arr[i]);
    }
}

void selectionSort2(int arr[], int size)
{
    int i,j, minIdx;
    for( i=0; i<size-1;i++)
    {
        minIdx=i; //gán minIdx=i để xét vị trí nhỏ nhất
        for(j=i+1; j<size; j++)
            if(arr[j]<arr[minIdx]) 
                minIdx=j;
        if(minIdx!=i)
            swap(arr[minIdx], arr[i]);// sẽ không đổi chỗ nếu i=minIdx
    }
}
void output(int arr[], int size)
{
    selectionSort(arr, size);
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
