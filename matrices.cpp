//Sanchez Santos B. Alexis 367714
//04/OCTUBRE/2023
//Pedir al usuario que elija una de las opciones y llene un vector o una matriz e imprima ya sea el vector o la matriz
//VECTOR Y MATRIZ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include "libreria.h"

void llenaut(int vec[17], int n, int ri, int rf);
int vali_vec(int vec[17], int x, int j);
void llenamat(int mat[][4],int m, int ri, int rf);
void impvec(int vec[17], int n);
void impmat(int mat[][4], int m);

int main()
{
    int opc, vect[16], mat[4][4], n, m, num, res;
    n=15;
    m=4;
    srand(time(NULL));
    do
    {
        system("CLS");
        printf("\n----------------------MENU-----------------------");
        printf("\n0-------------------------------------------Salir");
        printf("\n1----------------Llenar un vector automaticamente");
        printf("\n2---------------Llenar una matriz automaticamente");
        printf("\n3---------------------------------Imprimir vector");
        printf("\n4---------------------------------Imprimir matriz");
        printf("\n5--------------Ordenar de menor a mayor el vector");
        printf("\n6-------------------Buscar un numero en el vector\n");
        system("PAUSE");
        opc=vali_num(0, 6, "elige una opcion ", "Favor de elegir una de las opciones antes mostradas (del 0 al 6)");
        switch(opc)
        {
            case 1:
            llenaut(vect, n, 100, 200);
            system("CLS");
            printf("Llenad de vector\n");
            printf("\nlisto\n");
            system("PAUSE");
            break;
            case 2:
            llenamat(mat, m, 1, 16);
            system("CLS");
            printf("Llenado de matriz\n");
            printf("\nListo\n");
            system("PAUSE");
            break;
            case 3:
            impvec(vect, n);
            break;
            case 4:
            impmat(mat, m);
            break;
            case 5:
            ordenar(vect, n);
            system("CLS");
            printf("Ordenamiento de vector\n");
            printf("\nListo\n");
            system("PAUSE");
            break;
            case 6:
            system("CLS");
            num=vali_num(100, 200, "Escribe el numero que buscas entre el 100 y el 200 ", "QUE PARTE QUE ENTRE EL 100 Y EL 200 NO ENTENDISTE");
            res=busq_seq(vect, n, num);
            if(res!=-1)
            {
                printf("EL numero %d, se encuentra en la posicion %d \n", num, res);
            }
            else
            {
                printf("El numero %d, no se encuentra en la tabla \n",num);
            }
            system("PAUSE");
            break;
            default:
            printf("\nAdios");
        }
    }while(opc!=0);
}


void llenaut(int vec[17], int n, int ri, int rf)
{
    int i, rango, band, num;
    rango=(rf-ri)+1;
    vec[0]=(rand()%rango)+ri;
    for(i=1;i<n;i++)
    {
        num=(rand()%rango)+ri;
        band=vali_vec(vec, num, i);
        if(band==1)
        {
            i=i-1;
        }
        else
        {
            vec[i]=num;
        }
    }
}

int vali_vec(int vec[17], int x, int j)
{
    int i;
    for(i=0;i<j;i++)
    {
        if(vec[i]==x)
        {
            return 1;
        }
    }
    return 0;
}

void llenamat(int mat[][4], int m, int ri, int rf)
{
    int i, j, k;
    k=0;
    int voc[17];
    llenaut(voc, 16, 1, 16);
    system("CLS");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            mat[i][j]=voc[k];
            printf("%d\n",k);
            k=k+1;
        }
    }
    system("PAUSE");

}



void impvec(int vec[17], int n)
{
    int i;
    system("CLS");
    printf("Impresion del vector\n");
    for(i=0;i<n;i++)
    {
        printf("Posicion %d [%d] \n", i, vec[i]);
    }
    system("PAUSE");
}

void impmat(int mat[][4], int m)
{
    int i, j;
    system("CLS");
    printf("Impresion de matriz\n");
    for(i=0;i<m;i++)
    {
        printf("Fila %d", i);
        for(j=0;j<m;j++)
        {
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}