//Question8
//choose(set,clear,toggle,read bit)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int num,bit,out;
    unsigned char choice;

    while (1)
    {
        choice = 0;
        out = 0;

        printf("1-Set bit\n2-Clear bit\n3-Toggle bit\n4-Read bit\nChoose operation:\n");
        fflush(stdin);
        scanf("%d",&choice);
        printf("Enter number and bit number:");
        scanf("%d%d",&num,&bit);

        switch (choice)
        {
        case 1:
            out = num | (1<<bit);
            break;
        case 2:
            out = num & ~(1<<bit);
            break;
        case 3:
            out = num ^ (1<<bit);
            break;
        case 4:
            if( num & (1<<bit))
                out=1;
        default:
            printf("Invalid operation \n");
            continue;

        }
        printf("output is %d \n",out);

    }
    return 0;
}
