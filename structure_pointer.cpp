#include<iostream>
#include<string>
using namespace std;

struct Person{
    string name;
    int age;
    double salary;
};

int main()
{
    Person p1;




    cout<<"Enter details of person"<<endl;
    cin>>p1.name;
    cin>>p1.age;
    cin>>p1.salary;

    cout<<"Details of persons as follows"<<endl;
    cout << "name:- " <<p1.name << endl;
    cout << "age:- " << p1.age << endl;
    cout << "salary:- " << p1.salary << endl;

    //  USING POINTERS

    Person *ptr = &p1;

    cout<<"Enter details of person"<<endl;
    cin>>ptr->name;
    cin>>ptr->age;
    cin>>ptr->salary;

    cout<<"Details of persons as follows"<<endl;
    cout << "name:- " <<ptr->name << endl;
    cout << "age:- " << ptr->age << endl;
    cout << "salary:- " << ptr->salary << endl;

    return 0;
}

