#include<iostream>
using namespace std;
#define MAX 20

struct TreeNode
{
   TreeNode *Leftchild;
   char data;
   TreeNode *Rightchild;
};

int Isoperand(char ch)
{
    if((ch>='A' && ch <='Z')||(ch>='a' && ch <='z')||(ch>='0' && ch <='9'))
        return 1;
    else
        return 0;

}

int Isoperator(char ch)
{
    if((ch=='$')||(ch=='^')||(ch=='/')||(ch=='*')||(ch=='+')||(ch=='-')||(ch=='%'))
        return 1;
    else
        return 0;

}

class ExpresionTree
{
private:
    TreeNode *root;
public:

    ExpresionTree()
    {
        root=NULL;
    }
     //Declaration of Stack
     TreeNode *Stack[MAX];
     int top=-1;

    void create(char prefix[MAX]);

    void Inorder_rec();
    void Inorder_rec(TreeNode *);

    void Preorder_rec();
    void Preorder_rec(TreeNode *);

    void Postorder_rec();
    void Postorder_rec(TreeNode *);

    void Inorder(TreeNode *);
    void Inorder();

    void Preorder(TreeNode *);
    void Preorder();

    //void Postorder(TreeNode *);
    //void Postorder();


};


void ExpresionTree::create(char prefix[MAX])
{

      TreeNode *temp;
     char ch;

    int i,len;

    //Length of Prefix Expression
    for(i=0;prefix[i]!='\0';i++);

    len=i-1;
    //Scan the Prefix Expression from Right to Left
     for(i=len;i>=0;i--)
     {
        ch=prefix[i];
        temp= new(TreeNode);
        temp->Leftchild=NULL;
        temp->data=ch;
        temp->Rightchild=NULL;

        if(Isoperand(ch))
        {
            //Push new address of new node on stack
            Stack[++top]=temp;
        }
        else if(Isoperator(ch))
        {
            temp->Leftchild=Stack[top--];
            temp->Rightchild=Stack[top--];
            Stack[++top]=temp;
        }
     }
     root=Stack[top--];
     cout<<"Tree is Created.";
     cout<<"\nroot is = "<<root->data<<endl;
}
void ExpresionTree::Inorder_rec()
{
  if(root)
   Inorder_rec(root);
  else
   {
    cout<<"Tree is Empty";
   }
}
void ExpresionTree::Inorder_rec(TreeNode *root)
{
    if(root)
    {
       Inorder_rec(root->Leftchild);
       cout<<root->data;
       Inorder_rec(root->Rightchild);
    }
}
void ExpresionTree::Preorder_rec()
{
  if (root)
        Preorder_rec(root);
  else
   cout<<"Tree is Empty";
}
void ExpresionTree::Preorder_rec(TreeNode *root)
{
    if(root)
    {
       cout<<root->data;
       Preorder_rec(root->Leftchild);
       Preorder_rec(root->Rightchild);
    }
}
void ExpresionTree::Postorder_rec()
{
  if (root)
        Postorder_rec(root);
  else
   cout<<"Tree is Empty";
}
void ExpresionTree::Postorder_rec(TreeNode *root)
{
    if(root)
    {
       Postorder_rec(root->Leftchild);
       Postorder_rec(root->Rightchild);
       cout<<root->data;
    }
}
void ExpresionTree::Inorder()
{
  if (root)
        Inorder(root);
  else
   cout<<"Tree is Empty";
}
void ExpresionTree::Inorder(TreeNode *root)
{
  TreeNode *pt;
  pt=root;
  while(1)
  {
      while(pt!=NULL)
      {
          Stack[++top]=pt;
          pt=(pt->Leftchild);
      }
      if(top==-1)
        break;
      pt=Stack[top--];
      cout<<pt->data;
      pt=(pt->Rightchild);
  }
}
void ExpresionTree::Preorder()
{
  if (root)
        Preorder(root);
  else
   cout<<"Tree is Empty";
}
void ExpresionTree::Preorder(TreeNode *root)
{
  TreeNode *pt;
  pt=root;
  while(1)
  {
      while(pt!=NULL)
      {
          cout<<pt->data;
          Stack[++top]=pt;
          pt=(pt->Leftchild);
      }
      if(top==-1)
        break;
      pt=Stack[top--];

      pt=(pt->Rightchild);
  }
}

int main()
{
    int choice;
    char s;
    ExpresionTree et;
    char prefix[MAX]="-+A/BC*ED";

   do{
    cout<<"\n1.create\n2.InOrderRecursive\n3.PreOrderRecursive\n4.PostOrderRecursive\n5.InOrder\n6.PreOrder\n7.PostOrder\nEnter the choice:";
    cin>>choice;
    switch(choice)
    {
     case 1:et.create(prefix);
             break;
     case 2:cout<<"Inorder Recursive :"<<endl;
            et.Inorder_rec();
            break;
     case 3:cout<<"Preorder Recursive :"<<endl;
           et.Preorder_rec();
           break;
     case 4:cout<<"Postorder Recursive :"<<endl;
            et.Postorder_rec();
            break;
     case 5:cout<<"Inorder :"<<endl;
            et.Inorder();
            break;
     case 6:cout<<"Preorder :"<<endl;
            et.Preorder();
            break;
     //case 7:et.Postorder();
            //break;
     default:
        {
            cout<<"Wrong Choice";
            break;
        }
    }
    cout<<"\n Do you want to continue(Y/N)=>";
    cin>>s;
   }
    while(s=='Y'||s=='y');
        return 0;
}
