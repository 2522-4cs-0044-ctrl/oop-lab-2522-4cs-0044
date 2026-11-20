#include <iostream>
using namespace std;
class Assessment {
public:
    virtual void calculateMarks() = 0;
};
class Quiz : public Assessment {
private:
    int marks;
public:
    Quiz(int m) {
        marks = m;
    }
void calculateMarks() {
        cout << "Quiz Marks: " << marks << endl;
    }
int getMarks() {
        return marks;
    }
};
class Assignment : public Assessment {
private:
    int marks;
public:
    Assignment(int m) {
        marks = m;
    }
void calculateMarks() {
        cout << "Assignment Marks: " << marks << endl;
    }
int getMarks() {
        return marks;
    }
};
class Marks {
private:
    int value;
public:
    Marks(int v = 0) {
        value = v;
    }
    Marks operator+(Marks other) {
        return Marks(value + other.value);
    }
    int getValue() {
        return value;
    }
};
int main() {
    Quiz q(15);
    Assignment a(25);
    q.calculateMarks();
    a.calculateMarks();
    Marks m1(q.getMarks());
    Marks m2(a.getMarks());
    Marks total = m1 + m2;
    cout << "Total Assessment Marks: " << total.getValue() << endl;
    return 0;
}