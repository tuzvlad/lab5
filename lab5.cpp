#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StudentDatabase {
protected:
    string lastName;
    string firstName;
    string homeAddress;
    string phoneNumber;
    string dateOfBirth;

public:
    
    StudentDatabase() {}
    StudentDatabase(string lName, string fName, string address, string phone, string dob)
        : lastName(lName), firstName(fName), homeAddress(address), phoneNumber(phone), dateOfBirth(dob) {}

    virtual void display() {
        setlocale(LC_CTYPE, "ukr");
        cout << "Прiзвище: " << lastName << endl;
        cout << "Iм'я: " << firstName << endl;
        cout << "Домашня адреса: " << homeAddress << endl;
        cout << "Номер телефону: " << phoneNumber << endl;
        cout << "Дата народження: " << dateOfBirth << endl;
    }

    virtual ~StudentDatabase() {}
};

class SpecializedStudentDatabase : public StudentDatabase {
private:
    string department;
    int studentID;

public:
    
    SpecializedStudentDatabase(string lName, string fName, string address, string phone, string dob, string dept, int id)
        : StudentDatabase(lName, fName, address, phone, dob), department(dept), studentID(id) {}

    void display() override {
        StudentDatabase::display(); 
        setlocale(LC_CTYPE, "ukr");
        cout << "Спецiальнiсть: " << department << endl;
        cout << "Студентський квиток: " << studentID << endl;
    }
};

int main() {
    
    StudentDatabase student1("Туз", "Владислав", "вулю Руська 33", "0986550874", "01/05/2004");
    setlocale(LC_CTYPE, "ukr");
    cout << "Студент 1:\n";
    student1.display();
    cout << endl;

    SpecializedStudentDatabase student2("Остапчук", "Олег", "вул. Збаразька 41", "0734668745", "05/09/2000", "Комп'ютернi науки", 11456789);
    cout << "Студент 2:\n";
    student2.display();
    cout << endl;

    return 0;
}