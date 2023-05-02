// Represent a given graph using an adjacency list and perform DFS or BFS.
#include <iostream>
#define MAX 10
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int vertexNo;
    Node *next;
};
class Graph
{
private:
    Node *headArr[MAX];
    Node *head;
    int N;

public:
    Graph()
    {
        cout << "ENTER THE NUMBER OF VERTICES: " << endl;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            headArr[i] = NULL;
        }
    }
    void Create_Graph()
    {
        char r;
        Node *temp, *curr;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    cout << "WHETHER " << i << " & " << j << " ARE ADJACENT TO EACH OTHER: Y/N?";
                    cin >> r;
                    if ((r == 'y') || (r == 'Y'))
                    {
                        temp = new Node;
                        temp->vertexNo = j;
                        temp->next = NULL;
                        if (!headArr[i])
                        {
                            headArr[i] = temp;
                        }
                        else
                        {
                            curr = headArr[i];
                            while (curr->next)
                            {
                                curr = curr->next;
                            }
                            curr->next = temp;
                        }
                    }
                }
            }
        }
    }
    void Display_Graph()
    {
        Node *curr;
        cout << "ADJECENCY LIST FOR THE ENTERED GRAPH IS: " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << i << "-->";
            curr = headArr[i];
            if (curr)
            {
                while (curr)
                {
                    cout << curr->vertexNo << "-->";
                    curr = curr->next;
                }
                cout << "NULL" << endl;
            }
        }
    }
    void BFS()
    {
        int visited[MAX], Svertex, vertex;
        queue<int> q;
        Node *curr;
        for (int i = 0; i < N; i++)
        {
            visited[i] = 0;
        }

        cout << "ENTER A STARTING VERTEX FOR BFS: " << endl;
        cin >> Svertex;

        q.push(Svertex);
        visited[Svertex] = 1;
        cout << "BFS GRAPH DISPLAY IS: " << endl;
        do
        {
            vertex = q.front();
            q.pop();
            cout << vertex << " ";
            curr = headArr[vertex];
            while (curr)
            {
                if (visited[curr->vertexNo] == 0)
                {
                    q.push(curr->vertexNo);
                    visited[curr->vertexNo] = 1;
                }
                curr = curr->next;
            }
            if (q.empty())
            {
                break;
            }
        } while (1);
    }
    void DFS()
    {
        int visited[MAX], Svertex, vertex;
        stack<int> s;
        Node *curr;
        for (int i = 0; i < N; i++)
        {
            visited[i] = 0;
        }

        cout << "ENTER A STARTING VERTEX FOR BFS: " << endl;
        cin >> Svertex;

        s.push(Svertex);
        visited[Svertex] = 1;
        cout << "DFS GRAPH DISPLAY IS: " << endl;
        do
        {
            vertex = s.top();
            s.pop();
            cout << vertex << " ";
            curr = headArr[vertex];
            while (curr)
            {
                if (visited[curr->vertexNo] == 0)
                {
                    s.push(curr->vertexNo);
                    visited[curr->vertexNo] = 1;
                }
                curr = curr->next;
            }
            if (s.empty())
            {
                break;
            }
        } while (1);
    }
};
int main()
{
    Graph g;
    int n;
    cout << "1.CREATE GRAPH " << endl;
    cout << "2.DISPLAY GRAPH " << endl;
    cout << "3.BFS " << endl;
    cout << "4.DFS " << endl;
    cout << "5.EXIT " << endl;
    do
    {

        cout << "\nENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            g.Create_Graph();
            break;
        case 2:
            g.Display_Graph();
            break;
        case 3:
            g.BFS();
            break;
        case 4:
            g.DFS();
            break;
        default:
            break;
        }

    } while (n != 5);
}