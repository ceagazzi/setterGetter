/*
 * tipo.h
 *
 *  Created on: 11 may. 2021
 *      Author: CEA
 */

#ifndef TIPO_H_
#define TIPO_H_

#define TAM_MARCA 50
#define TAM_FABR 50
#define TAM_TELA 50

typedef struct
{
	int idTipo;
	char marca[TAM_MARCA];
	char fabrica[TAM_FABR];
	char tela[TAM_TELA];
}Tipo;



#endif /* TIPO_H_ */
