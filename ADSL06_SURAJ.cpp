#include <iostream>
#define Max 20
#define infi 999
using namespace std;
class ShortestPath
{
private:
    int A[Max][Max];
    int NoOfvertices;

public:
    ShortestPath()
    {
        cout << "ENTER NO OF VERTICES: " << endl;
        cin >> NoOfvertices;
        for (int i = 0; i < NoOfvertices; i++)
        {
            for (int j = 0; j < NoOfvertices; j++)
            {
                if (i != j)
                {
                    A[i][j] = infi;
                }
                else
                {
                    A[i][j] = 0;
                }
            }
        }
    }
    void Display_Graph()
    {
        cout << "YOUR GRAPH IS AS FOLLOWS: " << endl;
        for (int i = 0; i < NoOfvertices; i++)
        {
            for (int j = 0; j < NoOfvertices; j++)
            {
                cout << A[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void Create_Graph()
    {
        char r;
        int w;
        for (int i = 0; i < NoOfvertices; i++)
        {
            for (int j = 0; j < NoOfvertices; j++)
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
                        cout << "ENTER THE WEIGHT: " << endl;
                        cin >> A[i][j];
                    }
                }
            }
        }
    }
    int findmin(int distance[], bool visited[])
    {
        int minv = -1;
        for (int i = 0; i < NoOfvertices; i++)
        {
            if (visited[i] == false && (minv == -1 || distance[i] < distance[minv]))
            {
                minv = i;
            }
        }
        return minv;
    }
    void shortestPath()
    {
        int distance[NoOfvertices];
        bool visited[NoOfvertices];
        for (int i = 0; i < NoOfvertices; i++)
        {
            visited[i] = false;
            distance[i] = infi;
        }
        cout << "ENTER STARTING VERTEX: " << endl;
    }
}

;
int main()
{
    ShortestPath s;
    int n;
    cout << " 1.CREATE " << endl;
    cout << " 2.DISPLAY " << endl;
    cout << " 3.SHORTEST PATH " << endl;
    do
    {
        cout << "ENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            s.Create_Graph();
            break;
        case 2:
            s.Display_Graph();
            break;
        case 3:
            s.shortestPath();
            break;
        default:
            break;
        }

    } while (n != 4);
}