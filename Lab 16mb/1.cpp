#include <iostream>
#include <string>

using namespace std;

class Person 
{
public:
    virtual void readData() = 0;
    virtual void display() const = 0;
    virtual string getName() const = 0;
};

class Student : public Person 
{
private:
    string studentName;
    int rollNumber;
    int* subjectMarks;
    int numSubjects;

public:
    Student() : studentName(""), rollNumber(0), subjectMarks(nullptr), numSubjects(0) {}

    void readData() override 
	{
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, studentName);

        cout << "Enter student roll number: ";
        cin >> rollNumber;

        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        subjectMarks = new int[numSubjects];

        cout << "Enter marks for each subject:" << endl;
        for (int i = 0; i < numSubjects; i++) 
		{
            cout << "Subject " << i + 1 << ": ";
            cin >> subjectMarks[i];
        }
    }

    void display() const override 
	{
        cout << "Student Name: " << studentName << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: ";
        for (int i = 0; i < numSubjects; i++) 
		{
            cout << subjectMarks[i] << " ";
        }
        cout << endl;
    }

    string getName() const override 
	{
        return studentName;
    }

    ~Student() 
	{
        delete[] subjectMarks;
    }
};

class Teacher : public Person 
{
private:
    string teacherName;
    int employeeId;
    string department;
    int numSubjects;

public:
    Teacher() : teacherName(""), employeeId(0), department(""), numSubjects(0) {}

    void readData() override 
	{
        cout << "Enter teacher name: ";
        cin.ignore();
        getline(cin, teacherName);

        cout << "Enter employee ID: ";
        cin >> employeeId;

        cout << "Enter department: ";
        cin.ignore();
        getline(cin, department);

        cout << "Enter the number of subjects: ";
        cin >> numSubjects;
    }

    void display() const override 
	{
        cout << "Teacher Name: " << teacherName << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        cout << endl;
    }

    string getName() const override 
	{
        return teacherName;
    }
};

int main() 
{
    const int MAX_PERSONS = 100;
    Person* persons[MAX_PERSONS];
    int numPersons = 0;
    int choice;

    while (choice != 6)
	{
        cout << "----- Menu -----" << endl;
        cout << "1. Add a new student" << endl;
        cout << "2. Add a new teacher" << endl;
        cout << "3. Display details of all students" << endl;
        cout << "4. Display details of all teachers" << endl;
        cout << "5. Search for a student or teacher" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
		{
            if (numPersons < MAX_PERSONS) 
			{
                persons[numPersons] = new Student();
                persons[numPersons]->readData();
                numPersons++;
                cout << "New student added." << endl;
            } 
			else 
			{
                cout << "Maximum number of persons reached." << endl;
            }
		}
		else if (choice == 2) 
		{
			if (numPersons < MAX_PERSONS) 
			{
				persons[numPersons] = new Teacher();
				persons[numPersons]->readData();
				numPersons++;
				cout << "New teacher added." << endl;
			} 
			else 
			{
				cout << "Maximum number of persons reached." << endl;
			}
		}
		else if (choice == 3) 
		{
			cout << "Details of all students:" << endl;
			for (int i = 0; i < numPersons; i++) 
			{
				if (dynamic_cast<Student*>(persons[i])) 
				{
					persons[i]->display();
				}
			}
		}
		else if (choice == 4) 
		{
			cout << "Details of all teachers:" << endl;
			for (int i = 0; i < numPersons; i++) 
			{
				if (dynamic_cast<Teacher*>(persons[i])) 
					{
						persons[i]->display();
					}
			}
		} 
		else if (choice == 5) 
		{
		string searchName;
		cout << "Enter name to search: ";
		cin.ignore();
		getline(cin, searchName);
        bool found = false;
    		for (int i = 0; i < numPersons; i++) 
			{
        		if (persons[i]->getName() == searchName) 
				{
		            persons[i]->display();
		            found = true;
		            break;
        		}
   		 	}

		    if (!found) 
			{
		        cout << "Person not found." << endl;
		    }
    	}
		else if (choice == 6) 
		{
	        cout << "Exiting the program." << endl;
	    }
		else 
		{
	        cout << "Invalid choice. Please try again." << endl;
	    }

    	cout << endl;
}

for (int i = 0; i < numPersons; i++) 
{
    delete persons[i];
}

return 0;

}

