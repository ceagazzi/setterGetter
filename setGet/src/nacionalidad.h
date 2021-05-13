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

int tipo_setIdNacionalidad(Nacionalidad* this, int idNacionalidad);
int nacion_getIdNacionalidad(Nacionalidad* this,int* flagError);
int isValidIdNacionalidad(int*);

int nacion_setDescNac(Nacionalidad* this, char* descNac);
int nacion_getDescNac(Nacionalidad* this,int* flagError);
int isValidDescNac(char*);


#endif /* NACIONALIDAD_H_ */
