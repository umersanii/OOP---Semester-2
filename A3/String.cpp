#include <iostream>
#include "String.h"
#include <string>

using namespace std;

    String::String()
    {
        *content = '\0';
    }

    String::String(char str[])
    {
        strcpy_s(content, str);

    }

    String::String(const String& s)
    {
        strcpy_s(content, s.content);
    }

    String::String(int x)
    {
        for (int i = 0; i < x; i++)
        {
            content[i] = ' ';

        }
        content[x] - '\0';
    }

    char String::get(int i)
    {
        return content[i];
    }

    char String::operator [](int i)
    {
        return content[i];
    }

    String& String::operator + (const String& str)
    {
        String result;
        strcat_s(result.content, content);
        strcat_s(result.content, str.content);
        return result;
    }

    String& String::operator - (const String& str)
    {
        String result;
        int t = 0;
        int s_ind, e_ind;
        for (int i = 0; i < strlen(content) || i == strlen(content); i++)
        {
            if (str.content[t] == content[i] && t == 0)
            {
                s_ind = i;
                t++;
            }

            else if (t != 0 && str.content[t] == content[i] && str.content[t] != '\0')
            {
                t++;
            }


            else if (str.content[t] == '\0' && t == strlen(str.content))
            {
                e_ind = i;
                break;
            }


        }
        t = 0;
        if (e_ind != 0)
        {
            for (int i = 0; i < s_ind; i++)
            {
                result.content[i] = content[i];
                t++;
            }

            for (int i = e_ind; content[i] != '\0'; i++)
            {

                result.content[t] = content[i];
                t++;

            }
            result.content[t] = '\0';
            return result;

        }
        else
        {
            cout << "The Substring was not found in the string\n";
            result.content[0] = '\0';
            return result;
        }
    }

    bool String::operator ! ()
    {
        if (this->content[0] == '\0')
        {
            return true;
        }
        else
            return false;
    }

    String& String::operator = (const String& str)
    {
        for (int i = 0; str.content[i] != '\0'; i++)
        {
            content[i] = str.content[i];
        }

    }

    bool String::operator == (const String& str)
    {

        for (int i = 0; str.content[i] != '\0'; i++)
        {
            if (content[i] == str.content[i])
                continue;

            else
                return false;
        }
        return true;

    }

    int String::operator () (const char p)
    {
        for (int i = 0; content[i] != '\0'; i++)
        {
            if (content[i] == p)
                return i;
        }
        cout << "Character not found\n";
    }

    String String::operator *(int a)
    {
        String result;
        for (int i = 0; i <= a; i++)
        {
            strcat_s(result.content, content);
        }
        return result;
    }

    String String::length()
    {
        return strlen(content);
    }

    String::~String()
    {

    }

    ostream& operator << (ostream& o, const String s)
    {
        o << "Content: " << s.content;
        return o;
    }

    istream& operator >> (istream& in, String s)
    {
        char t[200];
        cout << "Enter the content of the string: ";
        in >> t;
        strcpy_s(s.content, t);
        return in;
    }

