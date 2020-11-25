#include<iostream>

using namespace std;

struct node 
{
    int data;
    node *right;
    node *left;
};

node *create(int n)
{
    node *newNode= new node;
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *Node, int key)
{
    if(Node==NULL)
        return create(key);

    if(key< Node->data)
        Node->left=insert(Node->left, key);
    if(key> Node->data)
        Node->right=insert(Node->right, key);
    
    return Node;
}

void LNR(node *root)
{
    if(root!=NULL)
    {
        LNR(root->left);
        cout<<root->data <<" ";
        LNR(root->right);
    }
}

void RNL(node *root)
{
    if(root!=NULL)
    {
        RNL(root->right);
        cout<<root->data <<" ";
        RNL(root->left);
    }
}

void NLR(node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        NLR(root->left);
        NLR(root->right);

    }
}

void NRL(node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        NRL(root->right);
        NRL(root->left);
    }
}


node* search(node* root, int key) 
{ 
    
    if (root == NULL || root->data == key) 
       return root; 
     
    if (root->data < key) 
       return search(root->right, key); 
  
    return search(root->left, key);
}

void deadMan(node *&X, node *&Y) // NODE Y là node thế mạng cho node cần xóa - node này sẽ đảm nhận nhiệm vụ tìm ra node trái nhất(TÌM NODE TRÁI NHẤT CÂY CON PHẢI) hoặc phải nhất(TÌM NODE PHẢI NHẤT CỦA CÂY CON TRÁI)
{
    // CÁCH 1: TÌM NODE TRÁI NHẤT CỦA CÂY CON PHẢI
    // duyệt sang bên trái nhất
    if (Y->left != NULL)
    {
        deadMan(X, Y->left);// tìm ra node trái nhất ?
    }
    else // tìm ra được node trái nhất rồi nek..
    {
        X->data = Y->data; // cập nhật cái data của node cần xóa chính là data của node thế mạng
        X = Y; // cho node X(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node X
        Y = Y->right; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) với node con của node thế mạng  
    }
}
void DeleteNode(node *&t, int data) // data chính là giá trị của cái node cần xóa
{
    // nếu như cây đang rỗng
    if (t == NULL)
    {
        return; // kết thúc hàm
    }
    else
    {
        // nếu như data nhỏ hơn node gốc
        if (data < t->data)
        {
            DeleteNode(t->left, data); // duyệt sang nhánh trái của cây 
        }
        else if (data > t->data)
        {
            DeleteNode(t->right, data); // duyệt sang nhánh phải của cây 
        }
        else // data == t->data - đã tìm ra cái node cần xóa
        {
            node *X = t; // node X là node thế mạng - tí nữa chúng ta sẽ xóa nó
            // nếu như nhánh trái bằng NULL <=> đây là cây có 1 con chính là con phải
            if (t->left == NULL)
            {
                // duyệt sang phải của cái node cần xóa để cập nhật mối liên kết giữa node 
                // cha của node cần xóa với node con của node cần xóa
                t = t->right; 
            }
            else if (t->right == NULL)
            {
                // duyệt sang trái của cái node cần xóa để cập nhật mối liên kết giữa node 
                // cha của node cần xóa với node con của node cần xóa
                t = t->left;
            }
            else // node cần xóa là node có 2 con
            {
                // CÁCH 1: Tìm node trái nhất của cây con phải(cây con phải của cái node cần xóa)
                deadMan(X, t->right);
                // CÁCH 2: Tìm node phải nhất của cây con trái(cây con trái của cái node cần xóa)
                //DiTimNodeTheMang(X, t->pLeft);
            }
            delete X; // xóa node cần xóa
        }
    }
}


void destroyTree(node *&root)
{
    if(root)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

int main()
{
    node *root=NULL;
    int n, key;
    cout<<"Nhap so phan tu cua cay: \n"; cin>>n; 
    cout<<"Nhap phan tu goc cua cay: \n"; cin>>key;
    root=insert(root, key);

    cout<<"Nhap cac phan tu con lai: \n";
    for(int i=1; i<n;i++)
    {
        cin>> key;
        insert(root, key);
    }
    /*
    cout<<"Trat tu left - node - right: ";
    LNR(root);
    cout<<"\n";

    cout<<"Trat right - node - left: ";
    RNL(root);
    cout<<"\n";

    cout<<"Trat node - right - left: ";
    NRL(root);
    cout<<"\n";

    cout<<"Trat node - left - right: ";
    NLR(root);
    cout<<"\n";

    cout<<"Nhap phan tu can tim: "; cin>>key;
    if(search(root, key)!=NULL)
        cout<<"Da tim thay!\n";
    else
        cout<<"Khong tim thay!\n";
    */
    cout<<"Nhap phan tu can xoa: "; cin>>key;
    DeleteNode(root, key);
    LNR(root);
    
    return 0;
}