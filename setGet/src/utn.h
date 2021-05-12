/*
 * utn.h
 *
 *  Created on: 11 may. 2021
 *      Author: CEA
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int *pResultado, char *pMensaje, char *pErrorMensaje, int minimo,
		int maximo, int reintentos);
int utn_getFloat(float *pResultado, char *pMensaje, char *pErrorMensaje, float minimo,
		float maximo, int reintentos);
int utn_getChar(char *pResultado, char *pMensaje, char *pErrorMensaje, char minimo,
		char maximo, int reintentos);
int utn_getNameSurname(char* pResultado, int size, char* mensaje, char* mensajeError, int reintentos);
int utn_getDniCuit(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


#endif /* UTN_H_ */
