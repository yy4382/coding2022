#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct student{
    int id;
    int cls;
    string name;
    float s1;
    float s2;
    float s3;
    bool selected;
    student *head;
};
int n;

student* input(){
    student *head = NULL;
    student *p1,p2;
    p1=p2=new student;
    if (n==0) head=p1;
	    
}
