#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Student
{
public:
    string roll_no, name, division, address;

    Student(string r, string n, string d, string a)
    {
        roll_no = r;
        name = n;
        division = d;
        address = a;
    }
};

class Database
{
private:
    fstream db;
    ifstream idb;
    string filename;

public:
    Database(string f)
    {
        filename = f;
        createFile();
    }

    void createFile()
    {
        db.open(filename, fstream::app);

        if (!db)
        {
            cout << "Error while creating database";
        }
        cout << "Database created successfully";
        db.close();
    }

    void addStudent(Student st)
    {
        db.open(filename, fstream::app);
        db << st.roll_no << ","
           << st.name << ","
           << st.division << ","
           << st.address << "\n";
        cout << "Data successfully added\n";
        db.close();
    }

    void display()
    {
        idb.open(filename);
        string line;
        int i = 0;
        while (getline(idb, line))
        {
            i++;
            cout << "Student " << i << " details: ";
            cout << line << "\n";
        }
        idb.close();
    }

    void search(string key)
    {
        idb.open(filename);
        string line, ref;
        bool flag = false;
        // while (getline(idb, line))
        // {
        //     char *arr = &line[0];
        //     ref = line;
        //     char *ptr;
        //     ptr = strtok(arr, ",");
        //     while (ptr != NULL)
        //     {

        //         if (ptr == key)
        //         {
        //             flag = true;
        //             cout << "Student found with searched name\n"
        //                  << ref << "\n";
        //         }

        //         ptr = strtok(NULL, ",");
        //     }
        // }
        while (getline(idb, line))
        {
            if (line.find(key) != string::npos)
            {
                cout << "Student found with searched name \n"
                     << line << "\n";
                flag = true;
            }
        }
        if (flag == false)
            cout << "Student not found";
        idb.close();
    }

    void deleteStudent(string key)
    {
        idb.open(filename);
        string line;
        fstream newFile("new.txt", ios::out);
        while (getline(idb, line))
        {
            if (line.find(key) == string::npos)
            {
                newFile << line << "\n";
            }
        }
        newFile.close();

        newFile.open("new.txt", ios::in);
        db.open(filename, ios::out);
        while (getline(newFile, line))
        {
            db << line << "\n";
        }

        db.close();
        newFile.close();
        idb.close();
    }

    ~Database()
    {
        cout << "\n\nDatabase closed successfully";
        db.close();
    }
};

int main()
{
    Database database("data.txt");
    int ch = 0;

    while (ch != 5)
    {
        cout << "\n1.Add student 2.Display records 3.Search student 4.Delete student 5.Exit: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            string roll_no, name, division, address;
            cout << "Enter roll_no: ";
            cin >> roll_no;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter division: ";
            cin >> division;
            cout << "Enter address: ";
            cin >> address;

            Student st(roll_no, name, division, address);
            database.addStudent(st);

            break;
        }
        case 2:
        {
            database.display();
            break;
        }
        case 3:
        {
            string key;
            cout << "Enter student name: ";
            cin >> key;
            database.search(key);

            break;
        }
        case 4:
        {
            string key;
            cout << "Enter student name to delete: ";
            cin >> key;
            database.deleteStudent(key);
            break;
        }
        case 5:
        {

            break;
        }
        default:
            break;
        }
    }

    return 0;
}