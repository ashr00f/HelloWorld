#include "stack.h"

static int stack[STACK_SIZE];
static int sp=0;


STACK_type Stack_create(int size)
{
    STACK_type stack=(STACK_type)malloc(sizeof(Stackstruct_type));
    stack->Size=size;
    stack->SP=0;
    stack->DataArray=(int*)malloc(size*sizeof(int));
    return stack;
}

void stack_Delete(STACK_type stack)
{
    free(stack->DataArray);
    free(stack);
}

StackStatus_type push(Stackstruct_type* stack,int data)
{
    if(stack->SP==stack->Size)
        return STACK_FULL;
    else
    {
        stack->DataArray[stack->SP]=data;
        stack->SP++;
        return DONE;
    }
}
StackStatus_type pop (int*pdata)
{
     if(sp==0)
        return STACK_EMPTY;
    else
    {
       *pdata= stack[--sp];
        return DONE;
    }
}

static int Queue[Q_SIZE];
static int in=0;
static int out=0;
static int c_flag=0;

QueueStatus_type inqueue(int  data)
{
    if(in==Q_SIZE)
        return Q_FULL;
    else
    {
      Queue[in]=data;
      in++;
      return Q_DONE;
    }

}
QueueStatus_type dequeue(int  *pdata)
{
    if(in==out)
    {
        in=0;
        out=0;
        return Q_EMPTY;
    }

    else
    {
        *pdata=Queue[out];
        out++;
        return Q_DONE;
    }

}


QueueStatus_type C_inqueue(int  data)
{
    if(in==Q_SIZE)
        {
            in=0;
            c_flag=1;
        }
     if((in==out)&&(c_flag==1))
        return Q_FULL;
    else
    {
      Queue[in]=data;
      in++;
      return Q_DONE;
    }

}
QueueStatus_type C_dequeue(int  *pdata)
{
   if(out==Q_SIZE)
        {
            out=0;
            c_flag=0;
        }

    if((in==out)&&(c_flag==0))
    {
        return Q_EMPTY;
    }

    else
    {
        *pdata=Queue[out];
        out++;
        return Q_DONE;
    }

}
