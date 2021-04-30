#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void limpiar();
void pausa();
char *obtenerDirectorio();
char *leeNombre();
void eliminarArchivo(char *);
void muestraCanciones();
char *transforma(char*);


#endif