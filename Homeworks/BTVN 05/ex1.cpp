#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

int countGoodMoralityStudent = 0;

class Student {
  private:
    char code[10];
    char fullName[30];
    char date[30];
    char sex[10];
    double averagePoint;
    char moralityRank[30];
  public:
    Student() {

    };

    Student(char code[], char fullName[], char date[], char sex[], double averagePoint, char moralityRank[]) {
      strcpy(this->code, code);
      strcpy(this->fullName, fullName);
      strcpy(this->date, date);
      strcpy(this->sex, sex);
      this->averagePoint = averagePoint;
      strcpy(this->moralityRank, moralityRank);
    }

    ~Student() {
      strcpy(this->code, "");
      strcpy(this->fullName, "");
      strcpy(this->date, "");
      strcpy(this->sex, "");
      this->averagePoint = 0;
      strcpy(this->moralityRank, "");
    }

    void setCode(char code[]) {
      strcpy(this->code, code);
    }

    char* getCode() {
      return this->code;
    }

    void setFullName(char fullName[]) {
      strcpy(this->fullName, fullName);
    }

    char* getFullName() {
      return this->fullName;
    }

    void setDate(char date[]) {
      strcpy(this->date, date);
    }

    char* getDate() {
      return this->date;
    }

    void setSex(char sex[]) {
      strcpy(this->sex, sex);
    }

    char* getSex() {
      return this->sex;
    }

    void setAveragePoint(double averagePoint) {
      this->averagePoint = averagePoint;
    }

    double getAveragePoint() {
      return this->averagePoint;
    }

    void setMoralityRank(char moralityRank[]) {
      strcpy(this->moralityRank, moralityRank);
    }

    char* getMoralityRank() {
      return this->moralityRank;
    }
};

void inputStudent(Student &student) {
  char tempStr[30];
  double tempDouble;
  cout << "\tCode: ";                   fflush(stdin);    gets(tempStr);    student.setCode(tempStr);
  cout << "\tFull name: ";              fflush(stdin);    gets(tempStr);    student.setFullName(tempStr);
  cout << "\tDate: ";                   fflush(stdin);    gets(tempStr);    student.setDate(tempStr);
  cout << "\tSex: ";                    fflush(stdin);    gets(tempStr);    student.setSex(tempStr);
  cout << "\tAverage point: ";          cin >> tempDouble;                  student.setAveragePoint(tempDouble);
  cout << "\tMorality Rank: ";          fflush(stdin);    gets(tempStr);    student.setMoralityRank(tempStr);
  if (strcmp(student.getMoralityRank(), "Good") == 0 || strcmp(student.getMoralityRank(), "good") == 0) {
    countGoodMoralityStudent += 1;
  }
}

void showStudent(Student student) {
  cout << setw(10) << student.getCode();
  cout << setw(20) << student.getFullName();
  cout << setw(20) << student.getDate();
  cout << setw(10) << student.getSex();
  cout << setw(20) << student.getAveragePoint();
  cout << setw(20) << student.getMoralityRank() << endl;
}

void title() {
  cout << setw(10) << "Code";
  cout << setw(20) << "Full name";
  cout << setw(20) << "Date";
  cout << setw(10) << "Sex";
  cout << setw(20) << "Average point";
  cout << setw(20) << "Morality rank" << endl;
}

void showGoodMoralityStudent(Student *students, int amount) {
  if (countGoodMoralityStudent != 0) {
    for(int i = 0; i < amount; i++) {
      if(strcmp(students[i].getMoralityRank(), "Good") == 0 || strcmp(students[i].getMoralityRank(), "good") == 0) {
        showStudent(students[i]);
      }
    }
  } else {
    cout << "No good morality student." << endl;
  }
}

main() {
  Student *students;
  int amountOfStudents;
  cout << "Enter amount of students: ";   cin >> amountOfStudents;
  students = new Student[amountOfStudents];
  for(int i = 0; i < amountOfStudents; i++) {
    cout << "Information of student " << i+1 << ":" << endl;
    inputStudent(students[i]);
  }
  cout << "--------------------------------------------------" << endl;
  cout << "LIST STUDENTS" << endl;
  title();
  for(int i = 0; i < amountOfStudents; i++) {
    showStudent(students[i]);
  }
  cout << "--------------------------------------------------" << endl;
  cout << "LIST GOOD MORALITY STUDENTS" << endl;
  showGoodMoralityStudent(students, amountOfStudents);
}
