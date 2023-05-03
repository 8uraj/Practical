#include<iostream>
#include<string.h>
#define MAX 20
using namespace std;

struct TreeNode{
TreeNode*lchild;
char keyword[MAX],meaning[MAX];
TreeNode*rchild;
};
class BST
{
private:
    TreeNode *root;
public:
    BST(){
        root=NULL;
        }




void insert(TreeNode*curr,TreeNode*temp){
    while(1)
        {

            if(strcmp(curr->keyword,temp->keyword)>0)
            {
                if(curr->lchild==NULL)
                {
                    curr->lchild=temp;
                    break;
                }
            else
                curr=curr->lchild;
            }

            if(strcmp(curr->keyword,temp->keyword)<0)
            {
                if(curr->rchild==NULL)
                {
                    curr->rchild=temp;
                    break;
                }
            else
                curr=curr->rchild;
            }

        }

}
void display(TreeNode*root){
if(root==NULL){
    return;
}else{
display(root->lchild);
cout<<root->keyword<<" ";
cout<<root->meaning<<" ";
display(root->rchild);
}
}
void create()
{
    TreeNode*temp,*curr;
    char choice,c;
do{
        temp=new(TreeNode);
        temp->lchild=NULL;
        cout<<"Enter your Keyword: ";
        cin>>temp->keyword;
        cout<<"Enter Meaning: ";
        cin>>temp->meaning;
        temp->rchild=NULL;

    if(root==NULL)
            root=temp;

    else
    {
        insert(root,temp);
    }
    cout<<"\nDO YOU WANT TO DISPLAY: "<<endl;
    cin>>c;
    if(c=='y'){
        display(root);
    }
cout<<"\nDO YOU WANT TO CONTINUE: "<<endl;
cin>>choice;
}while(choice=='y');
}};

int main()
{
    BST obj;
    obj.create();

}




