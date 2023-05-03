#include<iostream>
using namespace std;

struct TBTNode
{
   TBTNode *Leftchild;
   int Leftthread;
   char data;
   int Rightthread;
   TBTNode *Rightchild;
};

class TBT
{
    private:
        TBTNode *root,*head,*curr;
    public:
        TBT(){root=head=NULL;}
        void create();
        TBTNode *getnode();
        void InOrder();
        void PreOrder();
        TBTNode *leftmost();
        TBTNode *rightmost();
};

TBTNode *TBT::getnode()
{
    TBTNode *temp;
    temp= new TBTNode;
    temp->Leftchild=temp->Rightchild=temp;
    temp->Leftthread=temp->Rightthread=1;
    cout<<"Enter data:";
    cin>>temp->data;
    return temp;
}
void TBT::create()
{
   //head or dummy
   head=new TBTNode;
   head->Leftchild=head->Rightchild=head;
   head->Leftthread=head->Rightthread=1;

   char choice;
   TBTNode *temp;
   do
   {
     temp=getnode();
     if(root==NULL)
     {
         root=temp;
         head->Leftchild=root;
         head->Leftthread=0;
         root->Leftchild=head->Rightchild=head;
     }
     else
     {
         curr=root;
         while(curr)
         {
             if(curr->data>temp->data)
             {
                 //left
                 if(curr->Leftthread==1)
                 {
                     temp->Leftchild=curr->Leftchild;
                     curr->Leftchild=temp;
                     curr->Leftthread=0;
                     temp->Rightchild=curr;
                     break;
                 }
                 else
                    curr=curr->Leftchild;
             }
             if(curr->data<temp->data)
             {
                 //Right
                 if(curr->Rightthread==1)
                 {
                     temp->Rightchild=curr->Rightchild;
                     curr->Rightchild=temp;
                     curr->Rightthread=0;
                     temp->Leftchild=curr;
                     break;
                 }
                 else
                    curr=curr->Rightchild;
             }
         }
     }
     cout<<"want to insert any more node Y/N ?";
     cin>>choice;
   }while((choice=='Y')||(choice=='y'));
}

void TBT::InOrder()
{
    TBTNode *curr=root;
    int flag=0;
    do
    {
        if((curr->Leftthread!=1)||(flag==0))
          curr=curr->Leftchild;
        else
        {
            cout<<curr->data;
            flag=curr->Rightthread;
            curr->Rightchild;
        }
    }while(curr!=head);
}

void TBT::PreOrder()
{
    TBTNode *curr=root;
    int flag=0;
    do
    {
        if(flag==0)
          cout<<curr->data;
        if((curr->Leftthread!=1)||(flag==0))
          curr=curr->Leftchild;
        else
        {
            flag=curr->Rightthread;
            curr->Rightchild;
        }
    }while(curr!=head);
}

TBTNode *TBT::leftmost()
{
    while(curr->Leftthread!=1)
      curr=curr->Leftchild;
    return curr;
}

TBTNode *TBT::rightmost()
{
    while(curr->Rightthread!=1)
      curr=curr->Rightchild;
    return curr;
}

int main()
{
    TBT t;
    int choice;
    char s;
    do
    {
    cout<<"\n1.create\n2.InOrder Traversal\nEnter the choice:";
    cin>>choice;
    switch(choice)
    {
     case 1:t.create();
            cout<<" TBT is Created."<<endl;
             break;
     case 2:cout<<"InOrder Traversal"<<endl;
            t.InOrder();
            break;
    default:
            cout<<"Wrong Choice";
            break;
    }
    cout<<"\n Do you want to continue(Y/N)=>";
    cin>>s;
   }while(s=='Y'||s=='y');
}