#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class String
{
    char content[100];
    int q =1;
    public:
    String()
    {
        *content = '\0';
    }
 
    String(char str[])
    {
        strcpy(content, str);
 
    }
 
    String(const String & s)
    {
        strcpy(content, s.content);
    }    
 
    String(int x)
    {
        for(int i = 0; i < x; i++)
        {
            content[i] = ' ';
 
        }
        content[x] - '\0';
    }
 
    char get(int i)  
    {
        return content[i];
    }
 
    char operator [](int i)
    {
        return content[i];
    }
 
    String & operator + (const String & str)
    {   
        String result;
        strcat(result.content, content);
        strcat(result.content, str.content);
        return result;
    }
 
    String & operator - (const String & str)
    {
        String result;
        int t = 0;
        int s_ind, e_ind;
        for(int i = 0; i < strlen(content) || i == strlen(content); i++)
        {
            if(str.content[t] == content[i] && t==0)
            {
                s_ind = i;
                t++;
            }
 
            else if(t!=0 && str.content[t] == content[i] && str.content[t] != '\0')
            {
                t++;
            }
 
 
            else if(str.content[t] == '\0' && t == strlen(str.content)) 
            {
                e_ind = i;
                break;
            }
 
 
        }
        t=0;
        if(e_ind!=0)
        {
        	for(int i = 0; i < s_ind; i++)
            {
                result.content[i] = content[i];
                t++;
            }
 
            for (int i = e_ind; content[i]!='\0' ; i++)
            {
 
                result.content[t] = content[i];
                t++;
 
            }
            result.content[t] = '\0';
            return result;
 
    	}
    	else
    	{
    		cout<<"The Substring was not found in the string\n";
    		result.content[0] = '\0';
    		return result;
		}
    }
 int operator - (int a)
 {
    q= a +1;
    return q;
 }
    bool operator ! ()
    {
        if(this->content[0] == '\0')
        {
            return true;
        }
        else
        return false;
    }
 
    String& operator = ( const String &str )
    {
        for (int i = 0; str.content[i] != '\0'; i++)
        {
            content[i] = str.content[i];
        }
 
    }
 
    bool operator == (const String& str)
    {
 
        for (int i = 0; str.content[i] != '\0'; i++)
        {
            if(content[i] == str.content[i])
                continue;
 
            else
                return false;                
        }
        return true;
 
    }
 
    int operator () (const char p)
    {
        for (int i = 0; content[i] != '\0'; i++)
        {
            if(content[i] == p)
                return i;               
        }
       cout<<"Character not found\n";
    }
 
    String operator *(int a)
    {   
        String result;
        for(int i=0; i<= a; i++)
        {
            strcat(result.content,content);
        }
        return result;
    }
 
    String length ()
    {
        return strlen(content);
    }
 
    ~String()
    {
 
    }
 
    friend ostream & operator << (ostream& o, const String s)
    {
        o << "Content: " <<  s.content;
        return o;
    }
 
    friend istream & operator >> (istream& in, String s)
    {   
        char t[200];
        cout<<"Enter the content of the string: ";
        in >> t;
        strcpy(s.content, t);
        return in;
    }
 
};

int main()
{
   system("Color 0B");


    // Test default constructor
    String s1;
    cout << "s1 = " << s1 << endl;

    // Test constructor with char array parameter
    String s2("hello");
    cout << "s2 = " << s2 << endl;

    // Test copy constructor
    String s3(s2);
    cout << "s3 = " << s3 << endl;

    // Test move constructor
    String s4(String("world"));
    cout << "s4 = " << s4 << endl;

    // Test assignment operator
    s1 = s2;
    cout << "s1 = " << s1 << endl;

    // Test move assignment operator
    s3 = String("new string");
    cout << "s3 = " << s3 << endl;


    // Test + operator
    String s5 = s2 + "!";
    cout << "s5 = " << s5 << endl;


    // Test == operator
    bool equal = (s2 == s3);
    cout << "s2 == s3: " << equal << endl;

    // Test != operator
    if (!s2 == true)
    {
        cout << "s2 is empty\n";
    }
    else
    {
        cout<<"s2 is not empty\n";
    }

    // Test [] operator
    cout << "s2[1] = " << s2[1] << endl;

    // Test << operator
    cout << "Enter a string: ";
    String s6;
    cin >> s6;
    cout << "s6 = " << s6 << endl;

    // Test >> operator
    String s7;
    cout<<"d\n";
    cin >> s7;
    cout << "s7 = " << s7 << endl;

    // Test * operator
    String s8 = s2 * 3;
    string qw = s2.multiply(3);
    cout << "s8 = " << s8 << endl;

    // Test - operator
    String s9 = s2 - "l";
    cout << "s9 = " << s9 << endl;

   
    int a= s2 - 3;
    cout<<a;


return 0;
}
