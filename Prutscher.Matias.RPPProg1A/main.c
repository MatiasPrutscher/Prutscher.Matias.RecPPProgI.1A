#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 4
/*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array
de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos
desde el main. */
typedef struct{

    int id;
    char procesador[20];
    char marca[20];
    float precio;

}eNotebooks;
void ordenarNotebooks (eNotebooks notebooks[], int tamNote);

/*1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y
devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main. */
float aplicarDescuento (float precioProducto);

/*2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena **/
int contarCaracteres (char cadena[], char caracter);

int main()
{
    float precioRemera = 10;
    float precioConDescuento;
    int cantidadDeLetras;

    eNotebooks notebooks[TAM]={{10,"corei3","TCL",25000},{11,"moderadum","Lenovo",30000},{12,"celeron","Vga",14000},{13,"fushi","TCL",11000}};

/*--------------------------------------------------------------------------------------------------*/
    precioConDescuento = aplicarDescuento(precioRemera);
    printf("El descuento es de: %2.f\n",precioConDescuento);

/*---------------------------------------------------------------------------------------------------*/
    cantidadDeLetras=contarCaracteres("ELEFANTE",'E');
    printf("La cantidad de veces que se repite la 'e' en elefante es: %d\n",cantidadDeLetras);

/*---------------------------------------------------------------------------------------------------*/
    ordenarNotebooks(notebooks,TAM);
    printf(" _______________________________________________________________________________\n");
    printf("|\tID\t|\tPROCESADOR\t|\tMARCA\t\t|\tPRECIO\t|\n");
    printf("|_______________|_______________________|_______________________|_______________|\n");
    for(int i=0;i<TAM;i++)
    {
        printf("|\t%d\t|\%-10s\t\t|\t%-10s\t|\t%2.f\t|\n",notebooks[i].id,notebooks[i].procesador,notebooks[i].marca,notebooks[i].precio);
    }
    printf("|_______________|_______________________|_______________________|_______________|\n");
    return 0;
}

float aplicarDescuento(float precioProducto)
{
    float precioFinal = 0;
    float precioDescuento = 0;

   precioDescuento = (precioProducto * 5)/100;
   precioFinal = precioProducto - precioDescuento;

    return precioFinal;
}

int contarCaracteres (char cadena[],char caracter)
{
    int cantidad=0;

    for(int i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]==caracter)
        {
            cantidad++;
        }
    }

    return cantidad;
}

void ordenarNotebooks (eNotebooks notebooks[],int tamNote)
{
    eNotebooks auxiliar;
    for(int i=0;i<tamNote-1;i++)
    {
        for(int j=i+1;j<tamNote;j++)
        {
            if(strcmp(notebooks[i].marca,notebooks[j].marca)>0)
            {
                auxiliar=notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=auxiliar;
            }
            else
            {
                 if((strcmp(notebooks[i].marca,notebooks[j].marca)==0)&&notebooks[i].precio>notebooks[j].precio)
                {
                    auxiliar=notebooks[i];
                    notebooks[i]=notebooks[j];
                    notebooks[j]=auxiliar;
                }
            }
        }
    }
}
