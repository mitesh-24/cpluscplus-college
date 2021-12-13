#include <iostream>
using namespace std;
#define SIZE 15

class Student
{
public:
    int roll_no;
    char name[20];
    float SGPA;
};

void read_data(Student list[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter roll no, name and SGPA : ";
        cin >> list[i].roll_no >> list[i].name >> list[i].SGPA;
    }
}
void display_data(Student list[SIZE])
{
    cout << "\n\nRollno\tName\tSGPA\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\n"
             << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].SGPA;
    }
}

void displayTop(Student list[80])
{
    cout << "\n\nRollno\tName\tSGPA\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\n"
             << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].SGPA;
    }
}
void bubbleSort(Student list[SIZE])
{
    Student temp;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < (SIZE - 1 - i); j++)
        {
            if (list[j].roll_no > list[j + 1].roll_no)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void insertSort(Student list[SIZE])
{
    int j;
    Student temp;
    for (int i = 1; i < SIZE; i++)
    {
        temp = list[i];
        j = i - 1;
        while (j >= 0 && list[j].name > temp.name)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = temp;
    }
}
void quickSort(Student list[SIZE], int first, int last)
{
    int pivot, i, j;
    Student temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
    }
    while (i < j)
    {
        while (list[i].SGPA >= list[pivot].SGPA && i < last)
        {
            i++;
        }
        while (list[j].SGPA < list[pivot].SGPA)
        {
            j--;
        }
        if (i < j)
        {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    temp = list[pivot];
    list[pivot] = list[j];
    list[j] = temp;
    quickSort(list, first, j - 1);
    quickSort(list, j + 1, last);
}
void search(Student list[SIZE])
{
    float SGPA;
    cout << "\nEnter SGPA : ";
    cin >> SGPA;
    cout << "\n\nRollno\tName\tSGPA\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (SGPA == list[i].SGPA)
        {
            cout << "\n"
                 << list[i].roll_no << "\t" << list[i].name << "\t" << list[i].SGPA;
        }
    }
}
void binarysearch(Student list[SIZE])
{

    char search[80];
    cout << "\nEnter name of student you want to search : ";
    cin >> search;

    int low = 0;
    int high = SIZE - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (list[mid].name == search)
        {
            cout << "\n"
                 << list[mid].roll_no << "\t" << list[mid].name << "\t" << list[mid].SGPA;
            break;
        }
        else if (search > list[mid].name)
        {
            low = mid + 1;
        }
        else if (search < list[mid].name)
        {
            high = mid - 1;
        }
    }
    cout << search << "Not found in the list";
}
int main()
{
    int ch, i;
    Student data[20];
    read_data(data);
    while (true)
    {
        cout << "\n 1 : Bubble Sort";
        cout << "\n 2 : Insertion Sort";
        cout << "\n 3 : Quick Sort";
        cout << "\n 4 : Search";
        cout << "\n 5 : Binary Search";
        cin >> ch;

        switch (ch)
        {
        case 1:
            bubbleSort(data);
            display_data(data);
            break;

        case 2:
            insertSort(data);
            display_data(data);
            break;

        case 3:
            quickSort(data, 0, SIZE - 1);
            displayTop(data);
            break;

        case 4:
            search(data);
            break;

        case 5:
            binarysearch(data);
            break;

        default:
            cout << "Invalid Choice...";
        }
    }

    return 0;
}