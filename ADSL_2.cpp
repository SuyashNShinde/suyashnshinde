#include<iostream>
#include<string.h>
using namespace std;
#define MAX 20

struct TreeNode
{
   TreeNode *Leftchild;
   char keyword[MAX],meaning[MAX];
   TreeNode *Rightchild;
};

class BST
{
private:
    TreeNode *root;
public:
    BST(){root=NULL;}
    void create();
    void Ascending_Order();
    void Ascending_Order(TreeNode *);
    void Insert(TreeNode *,TreeNode *);
    void Search(TreeNode *,TreeNode *);
};
void BST::Insert(TreeNode *root,TreeNode *temp)
{
    if(strcmp(root->keyword,temp->keyword)<0)
    {
        //Traverse Left
        if(root->Leftchild==NULL)
        {
          root->Leftchild=temp;
          return;
        }
        else
          Insert(root->Leftchild,temp);
    }
    else if(strcmp(root->keyword,temp->keyword)>0)
    {
        //Traverse Right
        if(root->Rightchild==NULL)
        {
          root->Rightchild=temp;
          return;
        }
        else
        Insert(root->Rightchild,temp);
    }
}


void BST::create()
{
  TreeNode *temp;
 // string keyword[MAX],meaning[MAX];
  char choice;
  do{
  temp= new(TreeNode);
  temp->Leftchild=NULL;
  cout<<"Enter keyword :";
  cin>>temp->keyword;
  cout<<"Enter meaning :";
  cin>>temp->meaning;
  temp->Rightchild=NULL;

      if(root==NULL)
        root=temp;
      else
        Insert(root,temp);

      cout<<"want to insert any more node Y/N ?";
      cin>>choice;

  }while((choice=='Y')||(choice=='y'));
}
void BST::Ascending_Order()
{
    cout<<"keyword"<<"  "<<"meaning"<<endl;
        if(root)
        Ascending_Order(root);
    else
        cout<<"Tree is Empty";
}
void BST::Ascending_Order(TreeNode *root)
{
    if(root)
    {
      Ascending_Order(root->Leftchild);
      cout<<root->keyword<<" "<<root->meaning<<endl;
      Ascending_Order(root->Rightchild);
    }
}


int main()
{
    int choice;
    char s;
    BST b;

    do{
    cout<<"\n1.create\n2.Ascending_Order\nEnter the choice:";
    cin>>choice;
    switch(choice)
    {
     case 1:b.create();
            cout<<" BST is Created."<<endl;
             break;
     case 2:cout<<"Ascending_Order"<<endl;
            b.Ascending_Order();
            break;
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
}