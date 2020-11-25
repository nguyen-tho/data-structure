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
// độ phức tạp O(n^2)
void shakerSort(int arr[], int size)
{
    int l=0, r=size-1, k=0;
    while (l < r)// xét mảng
	{
		for (int i = l; i < r; i++)// lượt đi
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		}
		r = k;
		for (int i = r; i > l; i--)// lượt về
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		}
		l = k;
	}
}
void output(int arr[], int size)
{
    shakerSort(arr, size);
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
