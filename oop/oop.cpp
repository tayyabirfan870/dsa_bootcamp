#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person(){
        cout<<" base class constructor called \n";
    }
    ~Person(){
        cout<<"base class destructor called\n";
    }
};
class Student : public Person{
    public:
    int rollnum;
    Student(){
        cout<<"derived class constructor called\n";
    }
    void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"age "<<age<<endl;
        cout<<"rollnum "<<rollnum<<endl;

    }
    ~Student(){
        cout<<"derived class destructor called\n";
    }
};
int main(){
    Student s1;
    s1.name="tayyab ";
    s1.age=11;
    s1.rollnum=28;
s1.getinfo();
    return 0;
}

































/*
#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;
    public:
    string name;
    string department;
    string subject;
    void changeDept(string newdept){
        department=newdept;
    }
    int getsalary(){
        return salary;
    }
    void setsalary(int s){
        salary=s;
    }
    Teacher(){
        department="computer science ";
    }
};
int main(){
    Teacher t1;
    Teacher t2;
    t1.name="tayyab";
    t1.subject="c++";
    // cout<<t1.name<<endl;
    // t1.setsalary(122.0);
    // cout<<t1.getsalary();
    cout<<t1.department<<endl;
    return 0;
}

*/

// parameterize constructor

/*

#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;
    public:
    string name;
    string department;
    string subject;
    // parameterize constructor
    Teacher(string n,string s, string d, double sal){

        department=d;
        salary =sal;
        subject=s;
        name=n;
    }
    void getinfo(){
        cout<<name<<" "<<subject<<endl;
    }
};
int main(){
    Teacher t1("tayyab","computer","software",1100.0);
    t1.getinfo();

    return 0;
}

*/
/// this pointer 

/*
#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;
    public:
    string name;
    string department;
    string subject;
    Teacher(string name,string subject, string department, double salary){
        //this pointer
        this->department=department;
         this->salary =salary;
         this->subject=subject;
         this->name=name;
    }
    void getinfo(){
        cout<<name<<" "<<subject<<endl;
    }
};
int main(){
    Teacher t1("tayyab","computer","software",1100.0);
    t1.getinfo();

    return 0;
}

*/

// default copy constructor
/*
#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;
    public:
    string name;
    string department;
    string subject;
    Teacher(string name,string subject, string department, double salary){
        //this pointer
        this->department=department;
         this->salary =salary;
         this->subject=subject;
         this->name=name;
    }
    void getinfo(){
        cout<<name<<" "<<subject<<endl;
    }
};
int main(){
    Teacher t1("tayyab","computer","software",1100.0);
    Teacher t2(t1);
    t2.getinfo();
    return 0;
}

*/

// customize copy constructor
/*
#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;
    public:
    string name;
    string department;
    string subject;
    Teacher(string name,string subject, string department, double salary){
        //this pointer
        this->department=department;
         this->salary =salary;
         this->subject=subject;
         this->name=name;
    }
    //customize constructor
    Teacher(Teacher &orgObj){
        cout<<"customize construstor called "<<endl;
        this->department=orgObj.department;
        this->name=orgObj.name;
        this->salary=orgObj.salary;
        this->subject=orgObj.subject;
    }
    void getinfo(){
        cout<<name<<" "<<subject<<endl;
    }
};
int main(){
    Teacher t1("tayyab","computer","software",1100.0);
    Teacher t2(t1);
    t2.getinfo();
    return 0;
}
*/

// shallow copy issue
/*

#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    double *cgpaptr;
    Student(string name, double cgpa){
        this->name=name;
        cgpaptr= new double;
        *cgpaptr=cgpa;
    }
    Student(Student &obj){
        //shallow copy
        this->name=obj.name;
        this->cgpaptr=obj.cgpaptr;
    }
    void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"cgpa "<<*(cgpaptr)<<endl;
    }
};
int main(){
Student s1("tayyab", 3.01);
Student s2(s1);
s1.getinfo();
*(s2.cgpaptr)=4.0;
s1.getinfo();
    return 0;
}*/


// deep copy

/*
#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    double *cgpaptr;
    Student(string name, double cgpa){
        this->name=name;
        cgpaptr= new double;
        *cgpaptr=cgpa;
    }
    Student(Student &obj){
        //deep copy
        this->name=obj.name;
        cgpaptr= new double;
        *(cgpaptr)=*(obj.cgpaptr);
    }
    void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"cgpa "<<*(cgpaptr)<<endl;
    }
};
int main(){
Student s1("tayyab", 3.01);
Student s2(s1);
s1.getinfo();
*(s2.cgpaptr)=4.0;
s1.getinfo();
s2.name="muaz";
s2.getinfo();
    return 0;
} */


// destructor
/*

#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    double *cgpaptr;
    Student(string name, double cgpa){
        this->name=name;
        cgpaptr= new double;
        *cgpaptr=cgpa;
    }
    void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"cgpa "<<*(cgpaptr)<<endl;
    }
    ~Student(){
        cout<<"i deleting everything ";
        delete cgpaptr;
    }
};
int main(){
Student s1("tayyab", 3.01);
s1.getinfo();
    return 0;
}


*/


// inheritance
/*

#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person(){
        cout<<" base class constructor called \n";
    }
    ~Person(){
        cout<<"base class destructor called\n";
    }
};
class Student : public Person{
    public:
    int rollnum;
    Student(){
        cout<<"derived class constructor called\n";
    }
    void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"age "<<age<<endl;
        cout<<"rollnum "<<rollnum<<endl;

    }
    ~Student(){
        cout<<"derived class destructor called\n";
    }
};
int main(){
    Student s1;
    s1.name="tayyab ";
    s1.age=11;
    s1.rollnum=28;
s1.getinfo();
    return 0;
}
*/

// constructor 
/*
#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person(string name,int age){
        this->age=age;
        this->name=name;
    }

};
class Student : public Person{
    public:
    int rollnum;
    Student(string name, int age, int rollnum) : Person(name,age){
        this->rollnum=rollnum;
    }
    void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"age "<<age<<endl;
        cout<<"rollnum "<<rollnum<<endl;

    }
};
int main(){
    Student s1("tayyab",22,33);
    s1.name="muaz";
s1.getinfo();
    return 0;
}
*/

//multi-level  inheritance

/*
#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
};
class Student : public Person{
    public:
    int rollnum;
    void getinfo(){
        cout<<"name "<<name<<endl;
        cout<<"age "<<age<<endl;
        cout<<"rollnum "<<rollnum<<endl;

    }
};

// drived class
class Gradstudent : public Student{
    public:
    string reasearchArea;
};
int main(){
    Gradstudent s1;
    s1.name="tayyab";
    s1.reasearchArea="oop";
    cout<<s1.name<<endl;
    cout<<s1.reasearchArea<<endl;
    return 0;
}
*/
// #include<iostream>
// using namespace std;
// class Person{
//     public:
//     string name;
//     int age;
// };
// class Student : public Person{
//     public:
//     int rollnum;
//     void getinfo(){
//         cout<<"name "<<name<<endl;
//         cout<<"age "<<age<<endl;
//         cout<<"rollnum "<<rollnum<<endl;

//     }
// };

// // drived class
// class Gradstudent : public Student{
//     public:
//     string reasearchArea;
// };
// int main(){
//     Gradstudent s1;
//     Gradstudent s2;
//     s1.name="tayyab";
//     s1.reasearchArea="oop";
//     cout<<s1.name<<endl;
//     cout<<s1.reasearchArea<<endl;
//     return 0;
// }

