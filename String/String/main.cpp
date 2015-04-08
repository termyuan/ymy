//
//  main.cpp
//  String
//
//  Created by sxwt11 on 15-1-22.
//  Copyright (c) 2015年 sxwt11. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class String
{
private:
    char * rep;
    int len;
public:
    String();
    String(char* s);
    String(const String & );
    ~String();
    const String& operator=(const String&);
    const String& operator+=(const String&);
    const char& at(int) const;
    char& at(int);
    const char& operator[](int)const;
    char& operator[](int);
    int length();
    friend bool operator==(const String&,const String&);
    friend String operator+(const String&,const String&);
    friend bool operator<(const String&,const String&);
    friend ostream& operator<<(ostream&,const String& );

};

String::String()
{
    rep = new char[1];
    strcpy(rep, "");
    len = 0;
}

String::String(char* s)
{
    if(!s)
    {
        rep = new char[1];
        strcpy(rep, "");
        len = 1;
    }
    else
    {
        rep = new char[strlen(s)+1];
        strcpy(rep, s);
        len = strlen(s);
    }
    
}

String::String(const String& s)
{
    len = s.len;
    rep = new char[strlen(s.rep)+1];
    strcpy(rep, s.rep);

}

String::~String()
{
    delete []rep;
    rep = NULL;
}
const String& String::operator=(const String& s)
{
 if(this != &s)
 {
     delete []rep;
     rep = new char[len+1];
     strcpy(rep, s.rep);
 
 }
    return *this;
}

const String& String::operator+=(const String& s)
{
    char *tmp = rep;
    len += s.len;
    rep = new char[len+1];
    strcpy(rep,tmp);
    strcat(rep,s.rep );
    delete []tmp;
    return *this;
    
}

const char& String::operator[](int index)const
{
    return rep[index];
}

char& String::operator[](int index)
{
    return rep[index];
}

const char& String::at(int index) const
{
    if(index<0||index>=len)
    {
     throw "yuejie";
    }
    return rep[index];
}

char& String::at(int index)
{
    if(index<0||index>=len)
    {
        throw "yuejie";
    }
    return rep[index];
}

int String::length()
{
    return len;
}

bool operator==(const String& s1,const String& s2)
{
 if(strcmp(s1.rep,s2.rep)==0)
 {
     return true;
 }
    return false;

}

String operator+(const String& s1,const String& s2)
{
    int len = s1.len + s2.len;
    char* tmp = new char[len+1];
    strcpy(tmp, s1.rep);
    strcat(tmp, s2.rep);
    String s(tmp);
    delete []tmp;
    return s;

}

bool operator<(const String& s1,const String& s2)
{
    if(strcmp(s1.rep, s2.rep))
    {
    
        return true;
    }
    return false;
}

ostream& operator<<(ostream& out,const String& s)
{
    out<<s.rep<<endl;
    return out;
}

int main(int argc, const char * argv[])
{

    String s1("hi");
    String s2("hello");
    String s3 = s1+s2;
    cout<<(s1+=s2);
    cout<<s3;
    cout<<s1+s2;
    return 0;
}

