#include<iostream>

using namespace std;

void input(int a[], int &size)
{
    cin>>size;
    for(int i=0; i<size; i++)
        cin>>a[i];
}

void swap (int &a, int &b)
{
    int t=a;
    a=b;
    b=t;
}

int partition(int a[], int i, int j)
{
    int m=i;
    int p=a[i];
    int k=i+1;
    for( k=i+1;k<=j;k++)
        if(a[k]<p) 
        {
            m++;
            swap(a[m], a[k]);
        }
    swap(a[i], a[m]);
    return i;
}
void quickSort(int a[],int i, int j)
{
	if(i<j)
	{
		int piIdx=partition(a,i,j);
		quickSort(a,i,piIdx-1);
		quickSort(a,piIdx+1,j);
	}
}
int main()
{
    int a[100], size;
    input(a, size);
    quickSort(a,0,size-1);
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    return 0;
}
