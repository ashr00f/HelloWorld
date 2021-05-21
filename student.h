

typedef unsigned long long   u64;
typedef unsigned long long*  pu64;




typedef struct student
{
    char name[20];
    int age;
    char grade;


}std_t;



void student_print(std_t s);
void student_printByRef(const std_t* ps);
std_t student_scan(void);
void student_scanByRef(std_t*ps);
