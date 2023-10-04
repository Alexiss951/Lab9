#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>

int vali_num(int ri, int rf, char* msge, char* msge2)
{
    char xnum[30];
    int num;
    do
    {
        system("CLS");
        printf("%s",msge);
        fflush(stdin);
        gets(xnum);
        num=atoi(xnum);
        if(num< ri || num> rf)
        {
            printf("\n%s \n", msge2);
            system("PAUSE");
        }
    }while(num< ri || num> rf);
    return num;
}

void ordenar(int vect[], int n)
{
    int i, j;
    int temp;
    for ( i = 0; i <(n-1); i++)
    {
        for(j=(i+1);j<n;j++)
        {
            if(vect[j]<vect[i])
            {
                temp=vect[i];
                vect[i]=vect[j];
                vect[j]=temp;
            }
        }
    }
    
}

int busq_seq(int vect[], int n, int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i]==num)
        {
            return i;
        }
    }
    return -1;
}