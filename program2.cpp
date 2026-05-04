#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    string fullName;
    string group;
    double averageGrade;

public:
    Student() : fullName(""), group(""), averageGrade(0.0) {}

    void setData(string name, string grp, double grade) {
        fullName = name;
        group = grp;
        averageGrade = grade;
    }

    double getGrade() const {
        return averageGrade;
    }

    void input() {
        cout << "ФИО студента: ";
        cin >> ws;
        getline(cin, fullName);
        cout << "Группа: ";
        getline(cin, group);
        cout << "Средний балл: ";
        cin >> averageGrade;
    }

    void printRow() const {
        cout << left << setw(25) << fullName
            << setw(10) << group
            << setw(10) << averageGrade << endl;
    }
};

int main() {
    const int MAX_STUDENTS = 50;
    Student students[MAX_STUDENTS];
    int n;

    cout << "Введите количество студентов для анализа: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nСтудент №" << i + 1 << ":" << endl;
        students[i].input();
    }

    cout << "\nСписок студентов-отличников (балл > 4.5):" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << left << setw(25) << "ФИО" << setw(10) << "Группа" << setw(10) << "Балл" << endl;
    cout << "---------------------------------------------------" << endl;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].getGrade() > 4.5) {
            students[i].printRow();
            found = true;
        }
    }

    if (!found) {
        cout << "Студенты с таким баллом не найдены." << endl;
    }
}