#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void student_print(std_t s)
{
    printf("name:%9s   age:%d   grade:%c\n",s.name,s.age,s.grade);

}


void student_printByRef(const std_t* ps)
{
   pu64 p1,p2,p3;
    printf("name:%9s   age:%d   grade:%c\n",(*ps).name,ps->age,(*ps).grade);

}

std_t student_scan(void)
{
    std_t s;
    string_scan(s.name,20);
    scanf("%d",&s.age);
    fflush(stdin);
    scanf("%c",&s.grade);
    return s;


}
void student_scanByRef(std_t*ps)
{

    string_scan(ps->name,20);
    scanf("%d",&ps->age);
    fflush(stdin);
    scanf("%c",&ps->grade);

}


