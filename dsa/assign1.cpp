#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

struct stud
{
    int roll_no;
    char name[15];
    float sgpa;
};

void create_db(stud studs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter record " << (i + 1) << ": ";
        cin >> studs[i].roll_no >> studs[i].name >> studs[i].sgpa;
    }
}

void display_db(stud studs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << studs[i].roll_no << setw(10) << studs[i].name << setw(10) << studs[i].sgpa << endl;
    }
}

void bubble_sort(stud studs[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (studs[j].roll_no > studs[j + 1].roll_no)
            {
                swap(studs[j], studs[j + 1]);
            }
        }
    }

    cout << "\nDatabase contents after sorting(bubble sort): \n";
    display_db(studs, n);
}

void insertion_sort(stud studs[], int n)
{
    stud key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = studs[i];
        j = i - 1;

        while (j >= 0 && strcmp(studs[j].name, key.name) > 0)
        {
            studs[j + 1] = studs[j];
            j = j - 1;
        }
        studs[j + 1] = key;
    }
}

// int partition(stud studs[], int start, int end)
// {
//     int pivot = studs[end].sgpa;
//     int i = start - 1;

//     for (int j = start; j < end; j++)
//     {
//         if (studs[j].sgpa >= pivot)
//         {
//             i++;
//             swap(studs[i], studs[j]);
//         }
//     }

//     swap(studs[i + 1], studs[end]);
//     return i + 1;
// }

int partition(stud studs[], int start, int end)
{
    int pivot = studs[start].sgpa;
    int i = start;
    int j = end;
    while (i < j)
    {
        while (i < end && studs[i].sgpa >= pivot)
            i++;
        while (j >= 0 && studs[j].sgpa < pivot)
            j--;
        if (i < j)
            swap(studs[i], studs[j]);
    }
    swap(studs[j], studs[start]);
    return j;
}

void quick_sort(stud studs[], int low, int high)
{
    if (low < high)
    {

        int p = partition(studs, low, high);

        quick_sort(studs, low, p - 1);
        quick_sort(studs, p + 1, high);
    }
}

void linear_search(stud studs[], int n)
{
    float s_sgpa = 0;
    cout << "\n\nEnter sgpa to search: ";
    cin >> s_sgpa;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (studs[i].sgpa == s_sgpa)
        {
            flag = true;
            cout << "Found student with roll no " << studs[i].roll_no << " having required sgpa" << endl;
        }
    }
    if (flag == false)
    {
        cout << "No student found with required sgpa";
    }
}

void binary_search(stud studs[], int n)
{
    char name[15];
    cout << "\n\nEnter name to search: ";
    cin >> name;
    bool flag = false;

    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (strcmp(studs[mid].name, name) == 0)
        {
            flag = true;
            cout << "Found student with roll no " << studs[mid].roll_no << " having required name" << endl;
            break;
        }
        else
        {
            if (strcmp(studs[mid].name, name) > 0)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }

    if (flag == false)
    {
        cout << "No student found with required name";
    }
}

int main()
{

    int n = 20;
    cout << "Enter number of records: ";
    cin >> n;

    if (n < 0 || n > 20)
    {
        cout << "Records should be between 1 and 20";
        return 0;
    }

    stud studs[n];
    create_db(studs, n);
    // stud studs[7] = {{14, "abc", 10}, {12, "som", 4}, {11, "adi", 2}, {13, "jsk", 1}, {17, "ggs", 5}, {19, "rsa", 6}, {13, "abs", 9}};

    cout << "\nDatabase contents: \n";
    display_db(studs, n);

    bubble_sort(studs, n);

    insertion_sort(studs, n);
    cout << "\nDatabase contents after sorting(insertion sort): \n";
    display_db(studs, n);

    cout << "\nDatabase contents after sorting(quick sort): \n";
    quick_sort(studs, 0, n - 1);
    display_db(studs, min(10, n));

    linear_search(studs, n);

    insertion_sort(studs, n);
    cout << "\nDatabase contents:\n";
    display_db(studs, n);
    binary_search(studs, n);

    return 0;
}