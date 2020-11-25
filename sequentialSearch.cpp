#include <iostream>

using namespace std;

void input(int a[],int &n)
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
}

int linearSearch(int a[], int n, int x)
{
    for(int i=0; i<n; i++)
        if(a[i]==x) return i;
    return -1;
}

// độ phức tạp (O(2n)) vì phải so sánh 2 lần (a[i] với x và i với n)
int linearSearch2(int a[], int n, int x)
{
    int i=0;
    while((a[i]!=x) && (i<n) )
    {
        i++;
    }
    return i;
}
// độ phức tạp(O(n+1)) vì tạo thêm 1 phần tử a[n]
int linearSearch3(int a[], int n, int x)
{
    int i=0;
    a[n]=x;//guard
    while((a[i]!=x))
    {
        i++;
    }
    return i;
}


int linearSearch4(int a[], int n, int x)
{
    int i=0;
    a[n]=x; //cũng dùng kĩ thuật guard chỉ khác ver 3 là khi không tìm ra x sẽ trả về -1
    while(x!=a[i])
    {
        i++;
        if(i<n) return i;
    }
    return -1;
}
int main()
{
    int a[100],n,x;
    input(a,n);
    cin>>x;
    cout<< linearSearch(a,n,x);
    return 0;
}