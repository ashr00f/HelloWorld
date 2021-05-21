
#define STACK_SIZE  4


typedef struct{
int *DataArray;
int Size;
int SP;
}Stackstruct_type;

typedef   Stackstruct_type*    STACK_type;


STACK_type Stack_create(int size);






typedef enum{
STACK_FULL=0,
STACK_EMPTY=1,
DONE=2


}StackStatus_type;

StackStatus_type push(Stackstruct_type* stack,int data);
StackStatus_type pop (int*pdata);

#define Q_SIZE 4

typedef enum{
Q_FULL=0,
Q_EMPTY=1,
Q_DONE=2


}QueueStatus_type;

QueueStatus_type inqueue(int  data);
QueueStatus_type dequeue(int  *pdata);
