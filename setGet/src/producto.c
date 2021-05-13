/*
 * producto.c
 *
 *  Created on: 11 may. 2021
 *      Author: CEA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "producto.h"
#include  "nacionalidad.h"
#include "tipo.h"


Producto* producto_new(void);
Producto* producto_newParam(int idProducto, char* descripcion, Nacionalidad* nac, Tipo* tipo, float precioUnitario);

int producto_delete(Producto* this);

int producto_setIdProducto(Producto* this, int idProducto);
int producto_getIdProducto(Producto* this,int* flagError);
int isValidIdProducto(char*);

int producto_setDescripcion(Producto* this, char* descripcion);
char* producto_getDescripcion(Producto* this,int* flagError);
int isValidDescripcion(char*);

int producto_setNacionalidad(Producto* this, Nacionalidad* nac);
Nacionalidad* producto_getNacionalidad(Producto* this,int* flagError);
int isValidNacionalidad(Nacionalidad*);

int producto_setTipo(Producto* this, Tipo* tipo);
Tipo* producto_getTipo(Producto* this,int* flagError);
int isValidTipo(Tipo*);

int producto_setPrecioUnitario(Producto* this,char* idProducto);
float producto_getPrecioUnitario(Producto* this,int* flagError);
int isValidPrecioUnitario(char*);




