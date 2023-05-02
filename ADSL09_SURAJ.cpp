#include <iostream>
#include <fstream>
using namespace std;
#define MAX 20

class MYFILE
{
private:
    struct rec
    {
        int rno;
        char name[MAX];
    };
    struct index
    {
        int key, recloc;
    };

public:
    MYFILE();
    void create();
    void display_master();
    void append();
    void modify();
    void searchi(int *, int *, int);
    void search();
    void Delete();
    int countrec();
    void sort();
    void writei();
    void display_index();

    bool BoolSearch(int rno)
    {
        ifstream fs;
        rec r;
        int i, lb = 0, ub = 0;
        int flag = 0;
        searchi(&lb, &ub, rno);
        fs.open("master.dat", ios::binary | ios::in);
        for (i = lb; i <= ub; i++)
        {
            fs.seekg(i * sizeof(r), ios::beg);
            fs.read((char *)&r, sizeof(r));
            if (r.rno == rno)
            {
                flag = 1;
                fs.close();
                break;
            }
        }
        if (i > ub)
        {
            fs.close();
        }
        if (flag == 1)
        {
            return true;
        }
        return false;
        // return(-1);
        fs.close();
    }
};

MYFILE::MYFILE()
{
}

int MYFILE::countrec()
{
    rec r;
    ifstream fs;
    int count = 0;
    fs.open("master.dat", ios::binary | ios::in);
    while (fs.read((char *)&r, sizeof(r)))
        count++;
    fs.close();
    return (count);
}

void MYFILE::sort()
{
    int i, j;
    int count;
    fstream fs;
    rec r, m;
    fs.open("master.dat", ios::binary | ios::in | ios::out);
    count = countrec();

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            fs.seekg((j) * sizeof(r), ios::beg);
            fs.read((char *)&r, sizeof(r));
            // fs.seekg((j+1)*sizeof(m),ios::beg);
            fs.read((char *)&m, sizeof(m));

            if (r.rno > m.rno)
            {
                fs.seekg((j) * sizeof(r), ios::beg);
                fs.write((char *)&m, sizeof(m));
                fs.seekg((j + 1) * sizeof(m), ios::beg);
                fs.write((char *)&r, sizeof(r));
            }
        }
    }
    fs.close();
}

void MYFILE::writei()
{
    ifstream fs1;
    ofstream fs2;
    rec r;
    index m;
    int rno, count = 0;
    char ch;

    fs1.open("master.dat", ios::binary | ios::in);
    fs2.open("index.dat", ios::binary | ios::out);
    while (fs1.read((char *)&r, sizeof(r)))
    {
        count++;
        if (count % 5 == 0)
        {
            m.key = r.rno;
            m.recloc = count - 1;
            fs2.write((char *)&m, sizeof(m));
        }
    }
    fs2.close();
    fs1.close();
}
void MYFILE::create()
{
    ofstream fs;
    rec r;
    char ch;
    fs.open("master.dat", ios::binary | ios::out);
    do
    {
        cout << "\nEnter rollno and name of a student";
        cin >> r.rno;
        cin >> r.name;
        fs.write((char *)&r, sizeof(r));
        cout << "\nWould u like to add any more record y/n";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    fs.close();
    sort();
    writei();
}
void MYFILE::append()
{

    ofstream fs;
    rec r;
    char ch;
    fs.open("master.dat", ios::binary | ios::app);
    do
    {
        cout << "\nEnter rollno and name of a student";
        cin >> r.rno;
        cin >> r.name;
        fs.write((char *)&r, sizeof(r));
        cout << "\nWould u like to add any more record y/n";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
    fs.close();
    sort();
    writei();
}
void MYFILE::searchi(int *lb, int *ub, int roll)
{
    index r;
    int i, flag = 0;
    ifstream fs;
    fs.open("index.dat", ios::binary | ios::in);
    // fs.seekg(sizeof(r),ios::beg);
    *lb = 0;
    while (fs.read((char *)&r, sizeof(r)))
    {

        if (r.key > roll)
        {

            *ub = r.recloc;
            flag = 1;
            break;
        }
        else
            *lb = r.recloc;
    }
    if (flag == 0)
        *ub = countrec();
    fs.close();
}
void MYFILE::search()
{
    ifstream fs;
    rec r;
    int i, rno, lb = 0, ub = 0;
    char ch;
    cout << "Enter a roll no of a record to be searched";
    cin >> rno;
    searchi(&lb, &ub, rno);
    fs.open("master.dat", ios::binary | ios::in);
    for (i = lb; i <= ub; i++)
    {
        fs.seekg(i * sizeof(r), ios::beg);
        fs.read((char *)&r, sizeof(r));
        if (r.rno == rno)
        {
            printf("\nRecord Found");
            cout << "\n"
                 << r.rno << "\t" << r.name;
            fs.close();
            break;
        }
    }
    if (i > ub)
    {
        cout << "\nRecord not found";
        fs.close();
    }
    // return(-1);
    fs.close();
}
void MYFILE::Delete()
{

    ifstream fs1;
    ofstream fs2;
    rec r, m;
    int rno;
    char ch;

    fs1.open("master.dat", ios::binary | ios::in);
    fs2.open("temp.dat", ios::binary | ios::out);
    cout << "\nEnter a roll no of a record to be Deleted";
    cin >> m.rno;
    while (fs1.read((char *)&r, sizeof(r)))
    {
        if (r.rno != m.rno)
        {
            fs2.write((char *)&r, sizeof(r));
        }
    }
    cout << "\nRecord Deleted successfully!!";
    fs2.close();
    fs1.close();
    remove("master.dat");
    rename("temp.dat", "master.dat");
    sort();
    writei();
}

void MYFILE::modify()
{

    fstream fs;
    rec r, m;
    int rno, flag = 0, pos = 0;

    fs.open("master.dat", ios::binary | ios::in | ios::out);
    cout << "\nEnter a roll no of a record to be modified";
    cin >> m.rno;
    if (BoolSearch(m.rno))
    {
        while (fs.read((char *)&r, sizeof(r)))
        {
            pos++;
            if (r.rno == m.rno)
            {
                cout << "\nRecord Found!!";
                cout << "\nEnter modified rollno and name of a student";
                cin >> m.rno;
                cin >> m.name;

                fs.seekg((pos - 1) * sizeof(r), ios::beg);
                fs.write((char *)&m, sizeof(m));
                flag = 1;
                break;
            }
        }
    }
    else
    {
        cout << "Record Not found";
    }
    fs.close();
    sort();
    writei();
}
void MYFILE::display_index()
{
    ifstream fs;
    index r;
    char ch;
    fs.open("index.dat", ios::binary | ios::in);
    cout << "\nKey\t\tPosition\n";
    while (fs.read((char *)&r, sizeof(r)))
    {
        cout << "\n"
             << r.key << "\t" << r.recloc;
    }
    fs.close();
}
void MYFILE::display_master()
{
    ifstream fs;
    rec r;
    char ch;
    fs.open("master.dat", ios::binary | ios::in);
    cout << "\nRollno\t\tname\n";
    while (fs.read((char *)&r, sizeof(r)))
    {
        cout << "\n"
             << r.rno << "\t" << r.name;
    }
    fs.close();
}

int main()
{
    int choice;
    char ch;
    MYFILE file;
    while (1)
    {
        cout << "\n1.Create\n2.Append\n3.Modify\n4.Delete\n5.Search";
        cout << "\n6.Display Master File\n7.Display Index File\n8.exit";
        cout << "\nEnter your choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            file.create();
            break;
        case 2:
            file.append();
            break;
        case 3:
            file.modify();
            break;
        case 4:
            file.Delete();
            break;
        case 5:
            file.search();
            break;
        case 6:
            file.display_master();
            break;
        case 7:
            file.display_index();
            break;
        case 8:
            return (0);
        }
    }
}
