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

void exchangeSort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
            if(arr[i]<arr[j])
                swap(arr[i],arr[j]);
    }
}
void output(int arr[], int size)
{
    exchangeSort(arr, size);
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