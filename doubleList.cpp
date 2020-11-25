#include <iostream>

using namespace std;

// khai báo cấu trúc danh sách liên kết đôi
struct node
{
    int data;
    node *next;
    node *prev;
};

// khởi tạo

void initNode(node *head)
{
    head=NULL;
}
// tạo 1 nút
void createNode(node *head, int x)
{
    head->data = x;
    head->next = NULL;
    head->prev = NULL;
}

// chèn cuối
void addLast(node *l, int x)
{     
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(l==NULL)
        l=temp;
    else
    {
    node *cur = l;
    while (cur)
    {
        if (cur->next == NULL)
        {
            cur->next = temp;
            return;
        }
        cur=cur->next;
    }
    }
}

// chèn đầu
void addFirst(node **head, int x)
{
    node *newNode = new node;
    newNode->data = x;
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

// tìm kiếm nút
node *searchNode(node *head, int x)
{
    node *cur = head;
    while (cur)
    {
        if (cur->data == x)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

// xoá 1 nút
bool deleteNode(node **head, node *ptrDel)
{
    if(*head == NULL)
        return false;
    else
    {
        node *cur= *head;
    if(cur==ptrDel)
    {
        cur=cur->next;
        delete ptrDel;
        return true;
    } 
    while (cur)
    {
        if(cur->next==ptrDel)
        {
            cur->next = ptrDel->next;
            delete ptrDel;
            return false;
        }
        cur=cur->next;
    }
    return false;
        
    }
    
    
}

// xoá cả list
void deletelist(node **l)
{
    node *temp;
    while (*l)
    {
        temp=*l;
        *l = temp->next;
        (temp)->prev = NULL;
        delete temp;
    }
}

// copy list
void copyList(node *l1, node **l2)
{
    if(l1==NULL)
        *l2 = NULL;
    else
    {
        *l2=new node;
        (*l2)->data=l1->data;
        (*l2)->next=NULL;
        copyList(l1->next, &(*l2)->next);
    }   
}

/*
void copylist(node *l1,node **l2)
{
    if(l1==NULL)
        (*l2)==NULL;
    else
        while(l1)
        {
            *l2=new node;
            (*l2)->data=l1->data;
            (*l2)->next=NULL;
            l1=l1->next;
        }
}
*/

// đảo ngược list
void reverse(node **head)
{
    node *prv=NULL;
    node *cur=*head;
    node *nxt;
    while(cur)
    {
        nxt=cur->next;
        cur->next=prv;
        prv=cur;
        cur=nxt;
    }
    *head=prv;
}

// so sánh list
bool compareList(node *l1, node *l2)
{
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data != l2->data)
            return false;
        l1=l1->next;
        l2=l2->next;
    }
    return (l1==NULL && l2==NULL);
}

//xuất list
void display(node *list)
{
    node *p= list;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    cout<<"====================================================================================\n";
    int n, x;
    cout<< "Nhap so phan tu cua list: ";cin>> n;
    cout<< "Nhap cac phan tu cua list: ";cin>> x;

    //khởi tạo
    node *head=new node;
    createNode(head, x);
    //chèn cuối danh sách
    for(int i=1; i<n; i++)
    {
        cin>>x;
        addLast(head, x);
    }

    //liệt kê danh sách ban đầu
    cout<<"Danh sach ban dau: ";
    display(head);
    cout<<"\n";
/*
    //chèn thêm 1 nút vào đầu
    cout<<"Nhap nut can them vao dau danh sach: "; cin>> x;
    addFirst(&head, x);
    cout<<"Danh sach sau khi chen: ";
    display(head);
    cout<<"\n";

    //tìm 1 nút (xuất địa chỉ)
    cout<<"Nhap phan tu can tim: "; cin>> x;
    if(searchNode(head, x) !=  NULL)
        cout<<"Da tim thay. Dia chi cua nut can tim: "<<searchNode(head,x)<<"\n";
    else
        cout<<"Khong tim thay\n";
*/
    //xoá 1 phần tử  trong list
    cout<<"Nhap phan tu can xoa: ";cin>>x;
    node *PtrDel=searchNode(head,x);
    if(PtrDel != NULL)
    {
        deleteNode(&head, PtrDel);
        cout<<"Danh sach sau khi xoa: ";
        display(head);
    }
    else
    {
        cout<<"Danh sach sau khi xoa: ";
        display(head);
    }
    cout<<"\n";

/*
    node *l2=new node;
    copyList(head, &l2);
    cout<<"Danh sach copy: ";
    display(l2);
    cout<<"\n";

    int n2, x2;
    cout<< "Nhap so phan tu cua list: ";cin>> n2;
    cout<< "Nhap cac phan tu cua list: ";cin>>x2;
    node *l3=new node;
    createNode(l3, x2);
    for(int i=1; i<n; i++)
    {
        cin>>x2;
        addLast(l3, x2);
    }

    if(compareList(head, l3))
        cout<<"Danh sach giong nhau\n";
    else
        cout<<"Danh sach khong giong nhau\n";

    cout<<"Danh sach dao nguoc: ";
    reverse(&head);
    display(head);
    cout<<"\n";

    deletelist(&l2);
    cout<<"Danh sach da xoa";
    display(l2);*/
    return 0;
}
