#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int roll_no;
    char name[30];
    char division[5];
    char address[50];

public:
    void accept();
    void display();
    int getRollNo() { return roll_no; }
};

void Student::accept() {
    cout << "\nEnter Roll Number: ";
    cin >> roll_no;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Address: ";
    cin.ignore();
    cin.getline(address, 50);
}

void Student::display() {
    cout << "\n" << roll_no << "\t" << name << "\t" << division << "\t" << address;
}

void create() {
    Student s;
    int n;
    ofstream out("students.dat", ios::binary);
    cout << "Enter number of records to be added: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        s.accept();
        out.write((char*)&s, sizeof(s));
    }

    out.close();
}

void search() {
    int roll_no, found = 0;
    cout << "Enter Roll Number to search: ";
    cin >> roll_no;

    ifstream infile("students.dat", ios::binary);
    Student s;

    while (infile.read((char*)&s, sizeof(s))) {
        if (s.getRollNo() == roll_no) {
            cout << "\nRecord Found!";
            s.display();
            found = 1;
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }

    infile.close();
}

void display() {
    ifstream infile("students.dat", ios::binary);
    Student s;

    cout << "\nRoll No\tName\t\tDivision\tAddress\n";
    while (infile.read((char*)&s, sizeof(s))) {
        s.display();
    }

    infile.close();
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Database\n";
        cout << "2. Display All Records\n";
        cout << "3. Search a Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);

    return 0;
}
