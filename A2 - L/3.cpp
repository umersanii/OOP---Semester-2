#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Phone
{   private:
    int p_no;
    public:
    Phone()
    {
        p_no = 0;
    }
    Phone(int xno)
    {
        p_no = xno;
    }
};

class Person 
{   
    protected:
    Phone pn; // Aggreagation relationship
    string name;
    int age;
    string address;

    public:
    Person()
    {
        pn = 0;
        this->name = '\0';
        this->age = 0;
        this->address = '\0';
    }
    Person(string name, int age, string address, int xpn)
    {   
        pn = xpn;
        this->name = name;
        this->age = age;
        this->address = address;
    }
};

class Student : public Person
{
    int student_id;
    string * courses;
    int no_courses;
    public:
    Student()
    {
        this->student_id = 0;
        this->courses = NULL;
        this->no_courses = 0;
    }
    Student(string name, int age, string address, int student_id, string * courses, int no_courses)
    {this->name = name;
        this->age = age;
        this->address = address;
        this->student_id = student_id;
        this->no_courses = no_courses;
        this->courses = new string[this->no_courses];
        for (int i = 0; i < no_courses; i++)
        {
            this->courses[i] = courses[i];
        }   

    }
    ~Student()
    {
        delete[] courses;
    }

    friend ostream & operator << (ostream& o,const Student& s)
    {
        o<<"The name of the student: "<<s.name<<endl;
        o<<"The age of the student: "<<s.age<<endl;
        o<<"The id of the student: "<<s.student_id<<endl;
        o<<"The courses of the student: "<<endl;
        for (int i = 0; i < s.no_courses; i++)
        {
            o<<s.courses[i]<<endl;
        }
     return o;   
    }
    
};

class Professor : public Person
{
    int years_xp;
    string * subject_taught;
    int no_subject_taught;

    public:
    Professor()
    {
        this->years_xp = 0;
        this->subject_taught = NULL;
        this->no_subject_taught = 0;
    }
    Professor(string name, int age, string address, int years_xp, string * subject_taught, int no_subject_taught)
    {   
        this->name = name;
        this->age = age;
        this->address = address;
        this->years_xp = years_xp;
        this->no_subject_taught = no_subject_taught;
        this->subject_taught = new string[this->no_subject_taught];
        for (int i = 0; i < no_subject_taught; i++)
        {
            this->subject_taught[i] = subject_taught[i];
        }            
    }
    ~Professor()
    {
        delete[] subject_taught;
    }    

    friend ostream & operator << (ostream& o, const Professor& s)
    {
        o<<"The name of the professor: "<<s.name<<"\n";
        o<<"The age of the professor: "<<s.age<<"\n";
        o<<"The Experience of the professor: "<<s.years_xp<<"\n";
        o<<"The subjects taught by the professor: "<<"\n";
        for (int i = 0; i < s.no_subject_taught; i++)
        {
            o<<s.subject_taught[i]<<"\n";
        }                    
        return o;
    }
};

int main()
{
   system("Color 0B");
    int n1,n2;
    int x, age, y;
    string name, address;
    
    cout << "Enter the number of students: ";
    cin >> n1;
    Student * students = new Student[n1];
    cout<<"\n";
   for (int i = 0; i < n1; i++)
   {   cout<<"Enter the Name of Student "<<i+1<<": ";
       cin>>name;
       cout<<"\nEnter the Age of Student "<<i+1<<": ";
       cin>>age;
       cout<<"\nEnter the Address of Student "<<i+1<<": ";
       cin.ignore();
		getline(cin, address);
       cout<<"\nEnter the ID of the Student"<<i+1<<": ";
       cin>>x;
       cout<<"\nEnter the Number of courses taken by the Student: ";
       cin>>y;
       string *temp = new string[y];
       cout<<"\nEnter the Subjects taken by the Student\n ";
       for (int i = 0; i < y; i++)
       {
           cout<<"Course No "<<i+1<<": ";
           cin>>temp[i];
       }
       students[i] = Student(name, age, address, x, temp, y);
       delete[]temp;
   }
    cout<<"************************-------------------**************************";
    cout<<endl<<"Enter the number of Professors: ";
    cin>>n2;
    Professor * pros = new Professor[n2];
    cout<<"\n";
    for (int i = 0; i < n2; i++)
    {  
        cout<<"Enter the Name of Professor "<<i+1<<": ";
        cin>>name;
        cout<<"\nEnter the Age of Professor "<<i+1<<": ";
        cin>>age;
        cout<<"\nEnter the Address of Professor "<<i+1<<": ";
        cin.ignore();
        getline(cin, address);
        cout<<"\nEnter the Age of Experience of the Professor"<<i+1<<": ";
        cin>>x;
        cout<<"\nEnter the Number of Courses taught by the Professor: ";
        cin>>y;
        string *temp = new string[y];
        cout<<"\nEnter the Subjects taught by the Professor\n ";
        for (int i = 0; i < y; i++)
        {
            cout<<"Course No "<<i+1<<": ";
            cin>>temp[i];
        }
        pros[i] = Professor(name, age, address, x, temp, y);
        delete[]temp;
    }

   for (int i = 0; i < n1; i++)
   {
       cout<<students[i];
       cout<<"\n";
   }
    cout<<"\n";
    for (int i = 0; i < n2; i++)
    {
        cout<<pros[i];
        cout<<"\n";
    }        


    delete [] students;
	  delete [] pros;
return 0;
}

