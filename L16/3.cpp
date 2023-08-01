#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Person
{
    string name;
    int YOB;
    public:
    Person()
    {
        name = "";
        YOB = 0;
    }
    Person(string xname, int xYOB)
    {
        name = xname;
        YOB = xYOB;
    }
    void set_name(string xname)
    {
        name = xname;
    }
    void set_YOB(int xYOB)
    {
        YOB = xYOB;
    }
    string get_name()
    {
        return name;
    }
    int get_YOB()
    {
        return YOB;
    }

};

class Student : public Person
{
    int SID;
    int enSem;
    public:
    Student()
    {
        SID = 0;
        enSem = 0;
    }
    Student(string xname, int xYOB, int xSID, int xenSem)
    {
        set_name(xname);
        set_YOB(xYOB);
        SID = xSID;
        enSem = xenSem;
    }
    int get_SID() 
    {
        return SID;
    }

    void set_SID(int sid) 
    {
        SID = sid;
    }

    int get_enSem() 
    {
        return enSem;
    }

    void set_enSem(int sem) 
    {
        enSem = sem;
    }
    void Display()
    {
        cout<<"Name: ";
        get_name();
        cout<<"\nYear Of Birth: ";
        get_YOB();
        cout<<"\nStudent ID: ";
        get_SID();
        cout<<"\nEnrollment Semester: ";
        get_enSem();
        cout<<"\n";
    } 
};

class Employee : public Person
{
    int EID;
    int enYear;
    string jobTitle;
    int CID;
    string courseTitle;
    public:
    Employee()
    {
        EID = 0;
        enYear = 0;
        jobTitle = " ";
        CID = 0;
        courseTitle = " ";
    }
    int get_EID() 
    { 
        return EID; 
    }
    void set_EID(int eid) 
    { 
        EID = eid; 
    }

    int get_enYear() 
    { 
        return enYear; 
    }
    void set_enYear(int year) 
    { 
        enYear = year; 
    }

    string get_jobTitle() 
    { 
        return jobTitle; 
    }
    void set_jobTitle(string title) 
    { 
        jobTitle = title; 
    }

    int get_CID() 
    { 
        return CID; 
    }
    void set_CID(int cid) 
    {
         CID = cid; 
    }

    string get_courseTitle() 
    { 
        return courseTitle; 
    }
    void set_courseTitle(string title) 
    { 
        courseTitle = title; 
    }
};

class Administration : public Employee
{
    public:
    Administration()
    {
        set_CID(0);
        set_EID(0);
        set_enYear(0);
        set_jobTitle(NULL);
        set_courseTitle(NULL);
    }
    Administration(int eid, int cid, int year, string title, string course)
    {
        set_EID(eid);
        set_CID(cid);
        set_enYear(year);
        set_jobTitle(title);
        set_courseTitle(course);
    }

    void setJobTitle(string t)
    {
        set_jobTitle(t);
    }
    string getJobTitle()
    {
        return get_jobTitle();
    }
    
};

class Academic : public Employee
{
    public:
    Academic()
    {
        set_CID(0);
        set_EID(0);
        set_enYear(0);
        set_jobTitle(NULL);
        set_courseTitle(NULL);
    }
    Academic(int eid, int cid, int year, string title, string course)
    {
        set_EID(eid);
        set_CID(cid);
        set_enYear(year);
        set_jobTitle(title);
        set_courseTitle(course);
    }

    void setCourseTitle(string s)
    {
        set_courseTitle(s);
    }
    string getCourseTitle()
    {
        return get_courseTitle();
    }

};

int main()
{
   system("Color 0B");
    Student student("Ali Ahmad", 2000, 1234, 1);
    student.Display();

    Administration admin(5678, 100, 2020, "Manager", "Business");
    cout << "Job Title: " << admin.getJobTitle() << endl;

    Academic academic(9012, 200, 2015, "Professor", "Computer Science");
    cout << "Course Title: " << academic.getCourseTitle() << endl;

return 0;
}