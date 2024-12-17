#include <iostream>
#include <string.h>
using namespace std;

typedef struct student {
    int roll_num;
    char name[20];
    float sgpa;
} STUD;

void create(STUD s[], int n);
void display(STUD s[], int n);
void insertionSort(STUD s[], int n);

int main() {
    STUD s[20];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    create(s, n);
    insertionSort(s, n);

    cout << "\nList of Students sorted in ascending order (by Name):\n";
    display(s, n);

    return 0;
}

void create(STUD s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter roll number: ";
        cin >> s[i].roll_num;
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter SGPA: ";
        cin >> s[i].sgpa;
    }
}

void display(STUD s[], int n) {
    cout << "\nRoll Number\tName\tSGPA";
    for (int i = 0; i < n; i++) {
        cout << "\n" << s[i].roll_num << "\t\t" << s[i].name << "\t" << s[i].sgpa;
    }
    cout << "\n";
}

void insertionSort(STUD s[], int n) {
    for (int i = 1; i < n; i++) {
        STUD key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}
