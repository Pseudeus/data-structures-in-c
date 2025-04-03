#include <stdio.h>

struct student
{
    int rollNo;
    char* firstName;
    char* lastName;
};

int main()
{
    int i = 0;
    struct student stud;
    struct student* ptrStud;
    ptrStud = &stud;
    ptrStud->rollNo = 1;
    ptrStud->firstName = "john";
    ptrStud->lastName = "smith";

    printf("Roll No: %d\nStudent Name: %s %s\n",
            ptrStud->rollNo, ptrStud->firstName, ptrStud->lastName);

    return 0;
}