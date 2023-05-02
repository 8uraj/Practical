#include <iostream>
#include <string.h>
#define MAX 10

using namespace std;

struct TreeNode
{
    TreeNode *lchild;
    int lthread;
    int data;
    int rthread;
    TreeNode *rchild;
};

class TBT
{

private:
    TreeNode *root, *head;

public:
    TBT()
    {
        root = head = NULL;
    }
    TreeNode *getnode();
    void create();

    void inorder();
};

TreeNode *TBT::getnode()
{

    TreeNode *temp;
    temp = new TreeNode;
    temp->lchild = temp->rchild = temp;

    temp->lthread = temp->rthread = 1;
    cout << "ENTER DATA" << endl;
    cin >> temp->data;
    return temp;
}

void TBT::create()
{
    TreeNode *temp, *curr;
    char ch;

    head = new TreeNode;

    head->lchild = head->rchild = head;
    head->lthread = head->rthread = 1;

    do
    {

        temp = getnode();

        if (root == NULL)
        {
            root = temp;
            head->lthread = 0;
            root->lchild = head;
            root->rchild = head;
        }

        else
        {

            curr = root;
            while (1)
            {

                if (curr->data > temp->data)
                {

                    if (curr->lthread == 1)
                    {
                        temp->lchild = curr->lchild;
                        curr->lchild = temp;
                        curr->lthread = 0;
                        temp->rchild = curr;
                        break;
                    }
                    else
                    {
                        curr = curr->lchild;
                    }
                }
                else if (curr->data < temp->data)
                {

                    if (curr->rthread == 1)
                    {

                        temp->rchild = curr->rchild;
                        curr->rchild = temp;
                        curr->rthread = 0;
                        temp->lchild = curr;
                        break;
                    }

                    else
                    {
                        curr = curr->rchild;
                    }
                }
            }
        }
        cout << "DO YOU WANT TO CONTINUE: ";
        cin >> ch;
    }

    while (ch == 'Y' || ch == 'y');
}

void TBT::inorder()
{

    TreeNode *curr = root;
    int flag = 0;

    do
    {
        if ((curr->lthread != 1) && (flag == 0))
        {

            curr = curr->lchild;
        }
        else
        {
            cout << curr->data << " ";
            flag = curr->rthread;
            curr = curr->rchild;
        }
    } while (curr != head);
}

int main()
{

    TBT t1;
    cout << "1.CREATE " << endl;
    cout << "2.INORDER DISPLAY " << endl;
    cout << "3.EXIT " << endl;
    int n;
    do
    {
        cout << "\nENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            t1.create();
            break;
        case 2:
            t1.inorder();
        default:
            break;
        }
    } while (n != 3);
}
