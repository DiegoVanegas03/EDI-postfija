#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 10

struct struct_pila
{
    char datos[TAM_PILA];
    int tope;

};
typedef struct struct_pila Pila;

void InicializarPila(Pila *p);
int apila(Pila *p, char dato);
int desapilar(Pila *p, char *dato);
int RangoDeSimbolo(char caracter);



int main()
{
    Pila pila;
    int tamexp;
    int rango, rangop;
    char dato,simbolo;
    char Expresion[20], caracter;

    InicializarPila(&pila);

    printf("Dame la expresion sin espacios\n");
    scanf("%s", Expresion);
    printf("\n**************************\n");
    printf("Impresion a postfija\n");


    for (int i = 0; i < 20; i++)
    {
        caracter = Expresion[i];
        if (caracter != '*' || '/' || '+' || '-' || '(' || ')')
        {
            printf("%s", Expresion[i]);
        }
        else
        {
            rango = RangoDeSimbolo(caracter);
            rangop = RangoDeSimbolo(pila.datos[pila.tope]);
            switch (rango)
            {
            case 2:
                if (rangop == -1)
                {
                    apila(&pila, caracter);
                }
                else if (rangop == 2)
                {
                    desapilar(&pila, &simbolo);
                    printf("%s",simbolo);   
                    apila(&pila, caracter);
                }
                else
                {
                    while (pila.tope>0)
                    {
                        desapilar(&pila, &simbolo);
                        if (simbolo != '(' || ')' )
                        {
                            printf("%s",simbolo);
                        }
                    }
                    apila(&pila, caracter);
                }
                break;
            case 1:
                if (rangop == -1 || rangop < 1)
                {   
                    apila(&pila, caracter);
                }
                else if (rangop > 1 || rangop == 1)
                {
                    desapilar(&pila, &simbolo);
                    printf("%s",simbolo);   
                    apila(&pila, caracter);
                }
                
                break;
            case 0:
                while (pila.tope>0)
                {
                    desapilar(&pila, &simbolo);
                    if (simbolo != '(' || ')' )
                    {
                        printf("%s",simbolo);
                    }
                }
                apila(&pila, caracter);
                break;
            default:
                break;
            }
        }
    }
    system("pause");
    return 0;

}

void InicializarPila(Pila *p)
{
    p->tope = -1;
}

int apila(Pila *p, char dato)
{
    int pudoApilar = 0;

    if (p->tope < TAM_PILA - 1)
    {
        p->tope++;
        p->datos[p->tope] = dato;

        pudoApilar = 1;
    }
    return pudoApilar;
}

int desapilar(Pila *p, char *dato)
{
    int pudoDesapilar = 0;
    if(p->tope >-1)
    {
        *dato = p->datos[p->tope];
        p->tope--;
        pudoDesapilar = 1;
    }
    return pudoDesapilar;
}

int RangoDeSimbolo(char caracter)
{
    int rango;
    switch (caracter)
    {
    case '*':
        rango = 2;
        break;
    case '/':
        rango = 2;
        break;
    case '+':
        rango = 1;
        break;
    case '-':
        rango = 1;
        break;
    case '(':
        rango = 0;
        break;
    case ')':
        rango = 0;
        break;
    default:
        rango = -1;
        break;
    }
    return rango;
}