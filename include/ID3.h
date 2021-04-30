#ifndef ID3_H
#define ID3_H
///librerias globales
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/// terminan las globales

///mis otras librerias


/// terminan mis librerias


///definicion de tipos
typedef char byte;
/// terminan los tipos 

///delaracion de variables
//char **genero;
/// terminan las variables


/// declaracion de registros
struct id3
{
	byte tag[3];
	byte title[30];
	byte artist[30];
	byte albumName[30];
	byte year[4];
	byte comment[30];
	//byte genere;
	byte genere;
};

typedef struct id3 ID3;
/// terminan mis registros


/// mis funciones 
ID3 getTags(FILE *);
FILE *openSong(byte *);
byte *getCodec(FILE *);
void printTag(ID3);
void showCodec(FILE *);
void editarNombre(FILE * );
void editArtista(FILE *);
void editAlbum(FILE *);
void editYear(FILE *);
void editComment(FILE *);
void editGenero(FILE *);

void tablaGeneros();
 

//terminan mis registros
#endif