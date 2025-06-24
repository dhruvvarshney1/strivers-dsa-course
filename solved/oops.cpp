# include <iostream>

using namespace std;

class teacher {
    private:
        double salary;
    public:
        string name;
        string dept;
        string subject;

        // Custom Constructors
        teacher() {
            cout << "Initialize Teacher Object" << endl;
        }

        teacher(string n, double s, string sub, string d = "Computer Science") {
            this -> name = n; //this is used to signify it belongs to the object
            salary = s;
            subject = sub;
            dept = d;
        }

        void depChange(string newDep) {
            dept = newDep;
        }
        // Setter Function
        void setSalary(int newSalary) {
            salary = newSalary;
        }
        // Getter Function
        double getSalary() {
            return salary;
        }

        void getinfo() {
            cout << "Name: " << name << endl;
            cout << "Salary: " << getSalary() << endl;
            cout << "Department: " << dept << endl;
            cout << "Subject: " << subject << endl;
        }      
};

// class student {
// public:
//     string name;
//     double *gpa_ptr;
//     // Shallow copy constructor
//     student(string name, double gpa) {
//         this -> name = name;
//         gpa_ptr = new double;
//         *gpa_ptr = gpa;
//     }

//     // Deep copy constructor
//     student(student &s) {
//         name = s.name;
//         gpa_ptr = new double;
//         *gpa_ptr = *s.gpa_ptr;
//     }

//     // Destructor
//     ~student() {
//         delete gpa_ptr;
//     }
//     void getInfo() {
//         cout << "Name: " << name << endl;
//         cout << "GPA: " << *gpa_ptr << endl;
//     }
// };

class person {
public:
    person() {
        cout << "Person object created" << endl;
    }
    string name;
    int age;

    person(string n, int a) {
        name = n;
        age = a;
        cout << "Person object created" << endl;
    }
};

// class student : public person {
// public:
//     int roll;
//     student() {
//         cout << "Derived Student object created" << endl;
//     }
//     student(string name, int a, int n) : person(name, a) {
//         roll = n;
//         cout << "Derived Student object created" << endl;
//     }
//     void getinfo() {
//         cout << "Name: " << name << endl;
//         cout << "Age: " << age << endl;
//         cout << "Roll: " << roll << endl;
//     }
// };

// class gradstudent : public student {
// public:
//     string reseaerch_area;
// };
class student {
public:
    string name;
    
    student() {
        cout << "Non - parameterized constructor" << endl;
    }

    student(string name) {
        cout << "Parametrized Constructor" << endl;
    }
};

class print {
public:
    // Function Overloading
    void show(int x) {
        cout << x << endl;
    }
    void show(double x) {
        cout << x << endl;
    }
    void show(string x) {
        cout << x << endl;
    }
    void show(char x) {
        cout << x << endl;
    }
};

class shape{// Abstract Class
    virtual void draw() = 0;// Pure abstract class
};


int main() {
}
