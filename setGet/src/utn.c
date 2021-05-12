#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <ctype.h> //Funciones de isAlpha, isDigit, etc

static int myGets(char* pString, int size);
static int getInt(int* pResultado);
static int isNumber(char* pArray, int size);
static int getFloat(float* pResultado);
static int isFloat(char* pArray, int size);
static int getChar(char* pResultado);
static int isChar(char* pArray, int size);
static int getNameSurname(char* pResultado, int size);
static int isNameSurname(char* pArray,int size);
static int getDniCuit(char* pResultado, int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);



static int myGets(char* pString, int size)
{
	int retorno = -1;
	char bufferString[4096]; //la tengo que cambiar en algun momento
	if(pString != NULL && size > 0)
	{
		fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= size)
			{
				strncpy(pString, bufferString, size); // NO PUEDO HACER ESTO!!! pString = bufferString;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int utn_getInt(int *pResultado, char *pMensaje, char *pErrorMensaje, int minimo,
		int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt; //Un buffer antes de escribir en el resultado

	if (pResultado != NULL &&
		pMensaje != NULL &&
		pErrorMensaje != NULL &&
		minimo <= maximo && reintentos >0)
	{
		retorno = -2; //Codifico otro error

		do {
			printf("%s", pMensaje);
			fpurge(stdin); //fflush(stdin) WINDOWS / __fpurge(stdin) LINUX
			getInt(&bufferInt);
			if (bufferInt >= minimo && bufferInt <= maximo) {
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s", pErrorMensaje);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferInt [256];
	if(	pResultado != NULL &&
		!myGets(bufferInt,sizeof(bufferInt)) && //myGets da 0, si lo niego con ! obtengo un 1 y entro
		isNumber(bufferInt, sizeof(bufferInt)))
		{
			retorno = 0;
			*pResultado = atoi(bufferInt);
		}
	return retorno;
}

static int isNumber(char* pArray, int size)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && size > 0)
	{
		retorno = 1; //es verdadera / -	En C “0” es FALSO y cualquier valor != 0 es VERDADERO.
		for(i = 0; i < size && pArray[i] != 0; i++)
		{
			if(i==0 && (pArray[i] == '+' || pArray[i] == '-'))
			{
				continue;
			}
			if(pArray[i] < '0' || pArray[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * Revisar la validacion de utn_getInt y utn_getFloat por tema letras
 */

int utn_getFloat(float *pResultado, char *pMensaje, char *pErrorMensaje, float minimo,
		float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat; //Un buffer antes de escribir en el resultado

	if (pResultado != NULL && pMensaje != NULL && pErrorMensaje != NULL
			&& minimo <= maximo && reintentos >0) {
		retorno = -2; //Codifico otro error

		do {
			printf("%s", pMensaje);
			fpurge(stdin); //fflush(stdin) WINDOWS / __fpurge(stdin) LINUX
			if(	!getFloat(&bufferFloat) &&
				bufferFloat >= minimo &&
				bufferFloat <= maximo) {
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			printf("%s", pErrorMensaje);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferFloat [256];
	if(	pResultado != NULL &&
		!myGets(bufferFloat,sizeof(bufferFloat)) &&
		isFloat(bufferFloat, sizeof(bufferFloat)))
		{
			retorno = 0;
			*pResultado = atof(bufferFloat);
		}
	return retorno;
}

static int isFloat(char* pArray, int size)
{
	int retorno = 1; //es verdadera / -	En C “0” es FALSO y cualquier valor != 0 es VERDADERO.
	int i;
	int contadorDePuntos = 0;
	if(pArray != NULL && size > 0)
	{
		for(i = 0; i < size && pArray[i] != 0; i++)
		{
			if(i==0 && (pArray[i] == '+' || pArray[i] == '-'))
			{
				continue;
			}
			if(pArray[i] < '0' || pArray[i] > '9')
			{
				if(pArray[i] == '.' && contadorDePuntos == 0)
				{
					contadorDePuntos++;
					continue;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int utn_getChar(char *pResultado, char *pMensaje, char *pErrorMensaje, char minimo,
		char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar; //Un buffer antes de escribir en el resultado

	if (pResultado != NULL && pMensaje != NULL && pErrorMensaje != NULL
			&& minimo <= maximo && reintentos >= 0)
	{
		retorno = -2; //Codifico otro error

		do {
			printf("%s", pMensaje);
			fpurge(stdin); //fflush(stdin) WINDOWS / __fpurge(stdin) LINUX
			//scanf("%c", &bufferChar);
			//bufferChar = getchar();
			getChar(&bufferChar);
			if (bufferChar >= minimo && bufferChar <= maximo)
			{
				retorno = 0;
				//printf("%c", bufferChar);
				//strncpy(pResultado, bufferChar, sizeof(bufferChar));
				*pResultado = bufferChar;
				break;
			}
			printf("%s", pErrorMensaje);
			reintentos--;
			} while (reintentos >= 0);
	}
	return retorno;
}

static int getChar(char* pResultado)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL)
	{
		if(	!myGets(&bufferChar,sizeof(&bufferChar)) &&
			isChar(&bufferChar, sizeof(&bufferChar)))
		{
			retorno = 0;
			printf("%s", &bufferChar);
			//strncpy(pResultado, bufferChar, sizeof(bufferChar));
			*pResultado = bufferChar;
		}
	}
	return retorno;
}

static int isChar(char* pArray, int size)
{
	int i=0;
	int retorno = 1;

	if(pArray != NULL && size > 0)
	{
		for(i=0 ; pArray[i] != '\0' && i < size; i++)
		{
			if((pArray[i] < 'A' || pArray[i] > 'Z' ) && (pArray[i] < 'a' || pArray[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNameSurname(char* pResultado, int size, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNameSurname(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < size )
		{
			strncpy(pResultado,bufferString,size);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

static int getNameSurname(char* pResultado, int size)
{
    int retorno=-1;
    char bufferNameSurname[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(bufferNameSurname, sizeof(bufferNameSurname))==0 &&
    		isNameSurname(bufferNameSurname,sizeof(bufferNameSurname)) &&
			strnlen(bufferNameSurname,sizeof(bufferNameSurname))<size)
    	{
    		strncpy(pResultado,bufferNameSurname,size);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isNameSurname(char* pArray,int size)
{
	int i=0;
	int retorno = 1;

	if(pArray != NULL && size > 0)
	{
		for(i=0 ; pArray[i] != '\0' && i < size; i++)
		{
			if((pArray[i] < 'A' || pArray[i] > 'Z' ) && (pArray[i] < 'a' || pArray[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getDniCuit(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDniCuit(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

static int getDniCuit(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		isNumber(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
