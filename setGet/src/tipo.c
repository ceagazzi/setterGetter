/*
 * tipo.c
 *
 *  Created on: 11 may. 2021
 *      Author: CEA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "tipo.h"


Tipo* tipo_new(void);
Tipo* tipo_newParam(int idTipo, char* marca, char* fabrica, char* tela);
int tipo_delete(Tipo* this);

int tipo_setIdTipo(Tipo* this, int idTipo);
int tipo_getIdTipo(Tipo* this,int* flagError);
int isValidIdTipo(int*);

int tipo_setMarca(Tipo* this, char* marca);
char tipo_getMarca(Tipo* this,int* flagError);
int isValidMarca(char*);

int tipo_setFabrica(Tipo* this, char* fabrica);
char tipo_getFabrica(Tipo* this,int* flagError);
int isValidFabrica(char*);

int tipo_setTela(Tipo* this, char* tela);
char tipo_getTela(Tipo* this,int* flagError);
int isValidTela(char*);


