#include <iostream>

using namespace std;

void input(int a[], int &n)
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
}

// tìm kiếm nhị phân không đệ quy
int binarySearch(int a[], int n, int x)
{
    int left=0;
    int right=n-1;
    int middle;
    while(left<=right)
    {
       middle =(left+right)/2;
       if(x==a[middle]) return middle;
       else 
        if(x<a[middle]) right=middle-1;
        else left=middle+1; 
    }
    return -1;
}

// tìm kiếm nhị phân dùng đệ quy
int binarySearch2(int a[], int left, int right, int x)
{
    if(left > right) return -1;
    int middle=(left+right)/2;
    if(x==a[middle]) return middle;
    else
        if(x<a[middle]) return binarySearch2(a,left,middle-1,x);
        else return binarySearch2(a,middle+1,right,x);
}


int main()
{
    int a[100],n,x;
    input(a,n);
    cin>>x;
    cout<< binarySearch(a,n,x);
   //cout<<binarySearch2(a,0,n-1,x);
    return 0;

}
