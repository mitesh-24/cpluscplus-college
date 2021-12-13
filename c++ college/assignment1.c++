#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct stud
{
    int rollno;
    string name = "dummy";
    float sgpa;
};

class studentdata
{
public:
    stud student[20], temp;
    int n;
    string key;

    void get_details()
    {
        cout << "Enter No of Students : ";
        cin >> n;
        cout << endl;
        for (int i1 = 0; i1 < n; ++i1)
        {
            cout << "Enter Name of student : ";
            cin >> student[i1].name;
            cout << "Enter Roll No : ";
            cin >> student[i1].rollno;
            cout << "Enter Sgpa: ";
            cin >> student[i1].sgpa;
            cout << endl;
        }
    }
    void rollcall()
    {
        for (int p = 1; p < n; p++)
        {
            for (int i2 = 0; i2 < (n - 1 - p); i2++)
            {
                if (student[i2].rollno > student[i2 + 1].rollno)
                {
                    temp = student[i2];
                    student[i2] = student[i2 + 1];
                    student[i2 + 1] = temp;
                }
            }
        }
        cout << "Roll No" << setw(20) << "Name \n";
        cout << "==========================" << endl;
        for (int i3 = 0; i3 < n; i3++)
        {
            cout << student[i3].rollno << setw(20) << student[i3].name << endl;
        }
    }
    void alpha()
    {
        for (int i2 = 0; i2 < n; i2++)
        {
            temp = student[i2];
            key = student[i2].name;
            int j = i2 - 1;
            while (j >= 0 && student[j].name > key)
            {
                student[j + 1] = student[j];
                j = j - 1;
            }
            student[j + 1] = temp;
        }
        cout << "Sr.No" << setw(15) << "Name" << endl;
        cout << "===================================" << endl;
        for (int i2 = 0; i2 < n; i2++)
        {
            cout << i2 + 1 << "." << setw(20) << student[i2].name << endl;
        }
    }
    int partition(int s, int e)
    {
        int pivot = student[e].sgpa;
        int pi = s;
        for (int i2 = s; i2 < e; i2++)
        {
            if (student[i2].sgpa >= pivot)
            {
                temp = student[i2];
                student[i2] = student[pi];
                student[pi] = temp;
                pi++;
            }
        }
        temp = student[e];
        student[e] = student[pi];
        student[pi] = temp;
        return pi;
    }
    void quick(int s, int e)
    {
        if (s < e)
        {
            int p = partition(s, e);

            quick(s, (p - 1));
            quick((p + 1), e);
        }
    }
    void display()
    {
        cout << "Sr.no" << setw(19) << "Name" << setw(15) << "sgpa" << endl;
        for (int i2 = 0; i2 < n; i2++)
        {
            cout << i2 + 1 << "," << setw(15) << student[i2].name << setw(15) << student[i2].sgpa << endl;
        }
    }

    void search()
    {
        int flag = 0;
        int sgp;
        cout << "Enter the number that you want to search : ";
        cin >> sgp;
        int tr = 0;
        for (int i3 = 0; i3 < n; i3++)
        {
            if (student[i3].sgpa == sgp)
            {
                if (tr == 0)
                {
                    cout << "Roll No" << setw(10) << "Name" << endl;
                }
                cout << student[i3].rollno << setw(10) << student[i3].name << endl;
                flag = 1;
                tr++;
            }
        }
        if (flag == 1)
        {
            cout << tr << " results found " << endl;
        }
        if (flag == 0)
        {
            cout << "No results found" << endl;
        }
    }
    void binarysearch()
    {
        int ten, first, last, middle;
        string str;
        cout << "Enter the Name that you want to search : ";
        cin >> str;
        for (int i4 = 0; i4 < n; i4++)
        {
            for (int h = 0; h < n; h++)
            {
                if (student[h + 1].name < student[h].name)
                {
                    temp = student[h];
                    student[h] = student[h + 1];
                    student[h + 1] = temp;
                }
            }
        }
        ten = 0;
        first = 0;
        last = n - 1;
        float d2;
        middle = (first + last) / 2;
        while (first <= last)
        {
            if (student[middle].name == str)
            {
                ten++;
                cout << "Name" << setw(15) << "Roll No " << endl;
                cout << "------------------------------------\n";
                cout << student[middle].name << setw(10) << student[middle].rollno << "\n";
                d2 = student[middle].rollno;
                break;
            }
            else
            {
                if (student[middle].name < str)
                {
                    first = middle + 1;
                    middle = (first + last) / 2;
                }
                else if (str < student[middle].name)
                {
                    last = middle - 1;
                    middle = (first + last) / 2;
                }
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (student[k].name == str && student[k].rollno != d2)
            {
                cout << student[k].name << setw(10) << student[k].rollno << endl;
                ten++;
            }
        }
        if (ten == 0)
        {
            cout << "No searches found .";
        }
    }
};

int main()
{
    studentdata s;
    int sa;
    s.get_details();
    do
    {
        cout << "Enter your choice number : \n"
             << endl
             << "\t1. To display Roll wise List \n " << endl
             << "\t2. To display Name of Students alphabetically \n ";
        cout << "\t3. To display Rank list \n ";
        cout << "\t4. To Search Student by sgpa \n";
        cout << "\t5. To Search Student by Name \n";
        cout << "Enter 0 to exit \n";
        cin >> sa;
        switch (sa)
        {
        case 0:
            break;
        case 1:
        {
            cout << "roll number wise list " << endl;
            s.rollcall();
            break;
        }
        case 2:
        {
            cout << "List of Students " << endl;
            s.alpha();
            break;
        }
        case 3:
        {
            cout << "Rank wise list " << endl;
            s.quick(0, 14);
            s.display();
            break;
        }
        case 4:
        {
            cout << "Search Student by sgpa " << endl;
            s.search();
            break;
        }
        case 5:
        {
            cout << "Search Student by Name " << endl;
            s.binarysearch();
            break;
        }
        default:
        {
            cout << "wrong choice ";
            break;
        }
        }
    } while (sa != 0);

    return 0;
}
