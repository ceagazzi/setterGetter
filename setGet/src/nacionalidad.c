/*
 * nacionalidad.c
 *
 *  Created on: 11 may. 2021
 *      Author: CEA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "nacionalidad.h"

Nacionalidad* nacion_new(void);
Nacionalidad* nacion_newParam(int idNacionalidad, char* descNac);
int nacion_delete(Nacionalidad* this);

int tipo_setIdNacionalidad(Nacionalidad* this, int idNacionalidad);
int nacion_getIdNacionalidad(Nacionalidad* this,int* flagError);
int isValidIdNacionalidad(int*);

int nacion_setDescNac(Nacionalidad* this, char* descNac);
int nacion_getDescNac(Nacionalidad* this,int* flagError);
int isValidDescNac(char*);
