/*
 * nacionalidad.h
 *
 *  Created on: 11 may. 2021
 *      Author: CEA
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_

#define TAM_NAC 50

typedef struct
{
	int idNacionalidad;
	char descNac[TAM_NAC];
}Nacionalidad;

Nacionalidad* nacion_new(void);
Nacionalidad* nacion_newParam(int idNacionalidad, char* descNac);
int nacion_delete(Nacionalidad* this);

int nacion_setIdNacionalidad(Producto* this, int idProducto);
int nacion_getIdNacionalidad(Producto* this,int* flagError);
int isValidIdNacionalidad(int*);

int nacion_setDescNac(Producto* this, char* descNac);
int nacion_getDescNac(Producto* this,int* flagError);
int isValidDescNac(char*);


#endif /* NACIONALIDAD_H_ */
