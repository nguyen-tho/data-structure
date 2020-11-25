# include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;// con trỏ chỉ tới dữ liệu node
};

void initNode(Node *head, int n)
{
    head->data=n;
    head->next=NULL;
}

//add last
/*
void addNode(Node *head,int n)
{
    Node *cur= head;
    while(cur->next != NULL)
    {
        cur= cur->next;
    }
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=NULL;
    cur->next=newNode;
}
*/
void addNode(Node *head, int n)
{
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=NULL;

    Node *cur =head;
    while(cur)
    {
        if(cur->next==NULL)
        {
            cur->next=newNode;
            return;
        }
        cur = cur->next;
    }   
}

//add first
void addFirst(Node **head, int n)//** là con trỏ trỏ tới con trỏ
{
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=*head;
    *head=newNode; 
}

Node *searchNode(Node *head, int n)
{
    Node *cur=head;
    while (cur)
    {
        if(cur->data==n) return cur;
        cur=cur->next;
    }
    cout<< "No Node"<<n<<" in list.\n";
}

// hàm xoá node khi có delVal sẽ xoá và trả về true ngược lại là false
bool deleteNode(Node **head,Node *delVal)
{
    Node *cur=*head;
    if(delVal==*head)
    {
        *head=cur->next;
        delete delVal;
        return true;
    }
    while(cur)
    {
        if(cur->next==delVal)
        {
            cur->next=delVal->next;
            delete delVal;
            return false;
        }
        cur=cur->next;
    }
    return false;
}

void reverse(Node **head)
{
    Node *par= *head;
    Node *me= par->next;
    Node *chil=me->next;
    par->next=NULL;
    while(chil)
    {
        me->next=par;
        me->next=chil;
        chil->next=me;
        me=chil;
    }
    me->next=par;
    me=*head;
}
void reverseList(Node*& n)  {
    if(n == NULL)
        return;

    Node *current = NULL;
    Node *previous = NULL;

    while(n != NULL)    {
        current = n;
        n = n->next;
        current->next = previous;
        previous = current;
    }
    n = current;
}

void copyList(Node *l1, Node **l2)
{
    if(l1!=NULL)
    {
        *l2=new Node;
        (*l2)->data=l1->data;
        (*l2)->next=NULL;
        copyList(l1->next, &(*l2)->next);
    }   
}

void copylist(Node *l1,Node **l2)
{
    if(l1==NULL)
        (*l2)==NULL;
    else
        while(l1)
        {
            *l2=new Node;
            (*l2)->data=l1->data;
            (*l2)->next=NULL;
            l1=l1->next;
        }
}

void writeList(Node *list)
{
    Node *p= list;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void deleteList(Node **l)
{
    Node *t;
    while (*l)
    {
        t=*l;
        *l=t->next;
        delete t;
    }  
}

bool compareList(Node *l1, Node *l2)
{
    bool flag;
    if(l1==NULL && l2==NULL)
        flag=true;
    else
    {
        if(l1==NULL || l2==NULL)
            flag=false;
        else
        {
            if(l1->data !=l2->data)
                flag=false;
            else 
                compareList(l1->next, l2->next);
        }

    }
   return flag; 
}



/*
bool comparelist(Node *l1, Node *l2)
{
    bool flag;
    if(l1==NULL && l2==NULL)
        flag=true;
    else
    {
         while()   
    }
    
}
*/
int main()
{
    int n,x;
    cout << "Nhap vao n: ";
    cin>>n;
    cout << "Nhap vao x: ";
    cin>>x;
    Node *head=new Node;
    initNode(head,x);
    for(int i=1;i<n;i++)
    {
        cin>>x;
        addNode(head,x);
    }
    writeList(head);
    cout << endl;
/*
    int k;
    cin>>k;
    addFirst(&head, k);
    writeList(head);
    cout<<"\n";

    int f;
    cout<< "Nhap phan tu can tim: ";
    cin>> f;
    cout<< searchNode(head,f);
    cout<<"\n";
*/


    int a;
    cout<< "Nhap phan tu can xoa: ";
    cin>>a;
    Node *delVal=searchNode(head,a);
    deleteNode(&head, delVal);
    writeList(head);

   /* reverse(&head);
    writeList(head);


    Node *l2=new Node;
    copylist(head, &l2);
    cout<<"danh sach da sao chep: ";
    writeList(head);
    cout<<"\n";
*/
    /*addNode(l2,30);
    cout<<"Danh sach moi: ";
    writeList(l2);
    cout<<"\n";
    if(compareList(head,l2))
        cout<<"Hai danh sach giong nhau";
    else
    {
        cout<<"Hai danh khong giong nhau";
    }
    cout<<"\n";*/
/*
    deleteList(&l2);
    cout<<"Danh sach da xoa: ";
    writeList(l2);
    cout<<"\n";*/
    return 0;
}
