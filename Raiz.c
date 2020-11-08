#include <stdio.h>
#include <stdlib.h>

void fatorar(int, int);
void leitura(char *str, double *);
void raiz(double, double, double *);
double XaY(double *, double);

int main()
{
    double r, y, result;
    printf("Para sair, basta digitar um carater.\n\n");
    while(1)
    {
        leitura("radicando", &r);
        leitura("indice", &y);
        raiz(r, y, &result);
        if((int)r==r)
            fatorar((int)r, (int)y);
        printf("\n\n");
    }
    return 0;
}

void leitura(char *string, double *var)
{
    do
    {
        printf("Insira o %s: ", string);
        int id = scanf("%lf", var);
        if(id!=1)
            exit(0);
    }
    while(*var<=1);
}

void raiz(double r, double y, double *result)
{
    *result=r;
    do
        *result = ((y-1)**result+r/XaY(result, y-1))/y;
    while((XaY(result, y))-r>(double)0.0000001);
    if(*result-(int)*result<(double)0.0000001)
        printf("Raiz: %.0lf", *result);
    else
        printf("Raiz: %.6lf", *result);
}

double XaY(double *result, double y)
{
    double valor = *result;
    for(int i = y; i>1; i--)
        valor = valor**result;
    return valor;
}

void fatorar(int r, int y)
{
    int fora=1, cont=0, dentro=1;
    for(int i=2; i<=r; i++)
    {
        while(r%i==0)
        {
            r/=i;
            cont++;
            if(cont==y)
            {
                fora*=i;
                cont=0;
            }
        }
        if(cont!=0)
        {
            dentro*=i;
            cont=0;
        }
    }
    if(fora!=1 && dentro!=1)
        printf(" || %d raiz de %d", fora, dentro);
}
