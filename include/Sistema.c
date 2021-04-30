#include "Sistema.h"

void limpiar()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void pausa()
{
	char salto = getchar();
	while( salto != '\n')
		salto = getchar();
	return;
}

char *obtenerDirectorio()
{
	#ifdef _WIN32
		system(" cd > temporalfile.dat");
	#else 
		system(" pwd > temporalfile.dat");
	#endif

	FILE *archivo = fopen("temporalfile.dat", "r");
	char direccion[500];
	fseek(archivo, 0, SEEK_END);
	long tam = ftell(archivo);
	fseek(archivo, 0, SEEK_SET);
	fread(direccion, sizeof *direccion, tam, archivo);
	direccion[strlen(direccion)-1] = '\0';
	#ifdef _WIN32
		system("del temporalfile.dat");
	#else 
		system("rm temporalfile.dat");
	#endif

	char *dinamico = malloc(sizeof(direccion));
	for(int c = 0 ; c<strlen(direccion) && direccion[c] !='\n'; c++)
	{
		//fprintf(stderr, "el c -> %d es %c\n", c, direccion[c]);
		dinamico[c] = direccion[c];
	}
	//dinamico[strlen(dinamico)-1] = '\0';
	//printf("el tamanio es %ld\n", strlen(dinamico));
	return dinamico;
}

char *leeNombre()
{
	char nombre[80];
	fgets(nombre, sizeof(nombre), stdin);
	nombre[strlen(nombre)-1]  = '\0';
	if( strlen(nombre) < 4 )
	{
		fprintf(stderr, "el nombre de archivo es invalido\n" );
		exit(EXIT_FAILURE);
	}
	char a = nombre[strlen(nombre)-4]; //.
	char b = nombre[strlen(nombre)-3]; //m
	char c = nombre[strlen(nombre)-2]; //p
	char d = nombre[strlen(nombre)-1]; //3

	//fprintf(stderr, "el caracter es %c\n", a);
	char comprueba[] = {a,b,c,d};
	
	char extension[80]; /// por si hay que añadir el .mp3
	strcpy(extension, nombre);
	if( memcmp(comprueba, ".mp3", 4) != 0 )
	{
		//fprintf(stderr, "encontro diferencia\n" );
		strcat(extension, ".mp3");
		//fprintf(stderr, "el archivo es %s\n",extension );

	}
	char *dinamico = malloc(sizeof(extension));
	for(int c = 0 ; c<strlen(extension); c++)
		dinamico[c] = extension[c];
	return dinamico;
}



/// funcion peligrosa NO PONER CUALQUIER COSA
/// PORDRIA BORRAR INCLUSO TODO EL DIRECTORIO FUENTE
void eliminarArchivo(char *nombre)
{
	char *comando;
	#ifdef _WIN32
		comando = "del ";
	#else
		comando = "rm ";
	#endif
	strcat(comando, nombre);

	system(comando);
}

void muestraCanciones()
{
	
	#ifdef _WIN32
		system("dir | find \"mp3\"");
	#else 
		system(" ls | grep  mp3 ");
	#endif
}
char *transforma(char *nombre)
{
	
	#ifdef _WIN32
		strcat(nombre,"\\");
		strcat(nombre,"musica");
		strcat(nombre,"\\");
	#else
		strcat(nombre, "/");
		strcat(nombre,"musica");
		strcat(nombre, "/");
	#endif
	return nombre;

}
/// ejemplo