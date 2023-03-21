#include<iostream>
using namespace std;
#define MAX 50

class Shortest_path
{
    private:
    int G[MAX][MAX];
    int noofvertices;

    public:
        Shortest_path();
        void Create_Graph();
        void Display_Graph();

};
Shortest_path::Shortest_path()
{
    cout<<"Enter No of Vertices";
    cin>>noofvertices;

    for(int i=0;i<noofvertices;i++)
    {
        for(int j=-0;j<noofvertices;j++)
        {
            if(i==j)
                G[i][j]=0;
            else
                G[i][j]=-999;
        }
    }
}
void Shortest_path::Display_Graph()
{
    for(int i=0;i<noofvertices;i++)
    {
        for(int j=0;j<noofvertices;j++){
            cout<<G[i][j]<<"\t";
        }
    cout<<endl;
    }
}


void Shortest_path::Create_Graph()
{
    char ch;


    for(int i=0;i<noofvertices;i++)
    {
        for(int j=0;j<noofvertices;j++){
            if(i==j)
            {
                continue;
            }
            cout<<"Whether"<<i<<" "<<j<<" are adjacent vertex or not? Y/N";
            cin>>ch;
            if(ch=='Y'||ch=='y')
            {
                cout<<"Enter weight ";
                cin>>G[i][j];
            }
        }
    }
}



int main() {
    Shortest_path g;
    g.Display_Graph();
    g.Create_Graph();
    g.Display_Graph();

}
