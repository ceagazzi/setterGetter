/*
 * producto.h
 *
 *  Created on: 11 may. 2021
 *      Author: CEA
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define TAM_DESC 50
#define TAM_NAC 50
#define TAM_TIPO 50
#define TAM_MARCA 50
#define TAM_FABR 50
#define TAM_TELA 50

/*idProducto (numérico)
·       descripción (alfanumérico)
·       nacionalidad (teniendo en cuenta que cada país tiene su propio Id y descripción con su nombre)
·       tipo (teniendo en cuenta de que este puede tener más características: Id, Marca, Fabrica y tipo de tela.)
·       precio por unidad (numérico decimal)*/

typedef struct
{
	int idNacionalidad;
	char descNac[TAM_NAC];
}Nacionalidad;

typedef struct
{
	int idTipo;
	char marca[TAM_MARCA];
	char fabrica[TAM_FABR];
	char tela[TAM_TELA];
}Tipo;

typedef struct
{
	int idProducto;
	char descripcion[TAM_DESC];
	Nacionalidad nac;
	Tipo tipo;
	float precioUnitario;
}Producto;

Producto* producto_new(void);
Producto* producto_newParam(char* nombre,char* apellido,char* dni,int idEmpleado);

int producto_delete(Producto* this);

int producto_setDescripcion(Producto* this, char* descripcion);
char* producto_getDescripcion(Producto* this,int* flagError);
int isValidDescripcion(char*);

int producto_setApellido(Producto* this,char* apellido);
char* producto_getApellido(Producto* this,int* flagError);
int isValidApellido(char*);

int producto_setIdProducto(Producto* this,char* idProducto);
char* producto_getIdProducto(Producto* this,int* flagError);
int isValidIdProducto(char*);

int empleado_setId(Empleado* this,int idEmpleado);
int empleado_getId(Empleado* this,int* flagError);
int isValidId(int);



#endif /* PRODUCTO_H_ */
