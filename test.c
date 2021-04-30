#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// nis librerias
#include "include/ID3.h"
#include "include/Sistema.h"


char *nombre;
FILE *archivo;
ID3 cancion;
char *dir;

void menu()
{
	printf("Selecciona la opcion a realizar\n");
	printf("1) cambiar Cancion\n");
	printf("2) Mostrar Canciones\n");
	printf("3) editar Nombre\n");
	printf("4) editar Artista\n");
	printf("5) editar Album\n");
	printf("6) editar Año\n");
	printf("7) editar Comentario\n");
	printf("8) editar Genero\n");
	printf("9) salir\n\n");
	printf("_____________________________________\n");
}

void presentacion()
{
	limpiar();
	printf("_____________________________________\n");
	printTag(cancion);	
	printf("\n");
	printf("%s\n",obtenerDirectorio());
	printf("_____________________________________\n" );
}

void pideCancion()
{
	limpiar();
	printf("Ingresa el nombre de la cancion: \n");
	nombre = leeNombre();
	archivo = openSong(nombre);
	cancion = getTags(archivo);
}

void bloque()
{
	presentacion();
	menu();

}

int main()
{
	limpiar();
	
	
//int t = 1;
	pideCancion();
	while( 1)
	{
		bloque();
		while(1)
		{
			printf("Ingresa una opcion:\n");
			int n;
			scanf("%d",&n);
			if( n < 1 || n > 9 || putchar(n) != n)
			{
				//limpiar();
				printf("no has elegido una opcion valida, intenta otra vez\n");
				getchar();
				pausa();
				break;
				//bloque();
				//limpiar();
			}
			if( n == 1)
			{
				getchar();
				limpiar();
				printf("Ingresa el nombre de la cancion: \n");
				nombre = leeNombre();
				archivo = openSong(nombre);
				cancion = getTags(archivo);
				break;
			}
			else if( n == 2 )
			{
				limpiar();
				printf("Estas son las Canciones que hay en %s\n", obtenerDirectorio());
				printf("_____________________________________\n");
				muestraCanciones();
				printf("_____________________________________\n");
				getchar();
				pausa();
				break;

			}
			else if( n == 3)
			{
				char nuevo[80];
				getchar();
				fgets(nuevo, sizeof(nuevo), stdin);
				nuevo[strlen(nuevo)-1] = '\0';
				strcpy(cancion.title, nuevo);
				editarNombre(archivo);
				/*for(int c = 0 ;c<strlen(nuevo); c++)
					putchar(nuevo[c]);*/
				break;

			}
			else if( n == 4)
			{
				char nuevo[80];
				getchar();
				fgets(nuevo, sizeof(nuevo), stdin);
				nuevo[strlen(nuevo)-1] = '\0';
				strcpy(cancion.artist, nuevo);
				editArtista(archivo);
				/*for(int c = 0 ;c<strlen(nuevo); c++)
					putchar(nuevo[c]);*/
				break;

			}
			else if( n == 5)
			{
				char nuevo[80];
				getchar();
				fgets(nuevo, sizeof(nuevo), stdin);
				nuevo[strlen(nuevo)-1] = '\0';
				strcpy(cancion.albumName, nuevo);
				editAlbum(archivo);
				/*for(int c = 0 ;c<strlen(nuevo); c++)
					putchar(nuevo[c]);*/
				break;

			}
			else if( n == 6)
			{
				char nuevo[80];
				getchar();
				fgets(nuevo, sizeof(nuevo), stdin);
				nuevo[strlen(nuevo)-1] = '\0';
				strcpy(cancion.year, nuevo);
				editYear(archivo);
				/*for(int c = 0 ;c<strlen(nuevo); c++)
					putchar(nuevo[c]);*/
				break;

			}
			else if( n == 7)
			{
				char nuevo[80];
				getchar();
				fgets(nuevo, sizeof(nuevo), stdin);
				nuevo[strlen(nuevo)-1] = '\0';
				strcpy(cancion.comment, nuevo);
				editComment(archivo);
				/*for(int c = 0 ;c<strlen(nuevo); c++)
					putchar(nuevo[c]);*/
				break;

			}
			else if( n == 8)
			{
				
				getchar();
				tablaGeneros();
				int k;
				scanf("%d",&k);
				cancion.genere = k;
				editGenero(archivo);
	//			strcpy(cancion.genere, nuevo);
				/*for(int c = 0 ;c<strlen(nuevo); c++)
					putchar(nuevo[c]);*/
				break;

			}
			if( n == 9 || n == 0 )
				return 0;


		}

	
		//pausa();
		limpiar();

	}


	
	
}
