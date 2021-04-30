#include "ID3.h"

///delaracion de variables
char genero[][80] = {"Blues","Classic Rock","Country","Dance","Disco",
"Funk","Grunge","Hip-Hop","Jazz","Metal","New Age","Oldies","Other",
"Pop","Rhythm and Blues","Rap","Reggae","Rock","Techno","Industrial",
"Alternative","Ska","Death Metal","Pranks","Soundtrack","Euro-Techno",
"Ambient","Trip-Hop","Vocal","Jazz & Funk","Fusion","Trance","Classical",
"Instrumental","Acid","House","Game","Sound clip","Gospel","Noise",
"Alternative Rock","Bass","Soul","Punk","Space","Meditative","Instrumental Pop",
"Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic",
"Pop-Folk","Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40",
"Christian Rap","Pop/Funk","Jungle music","Native US", "Cabaret","New Wave",
"Psychedelic","Rave","Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz",
"Polka","Retro","Musical","Rock ’n’ Roll","Hard Rock"};
/// terminan las variables

ID3 getTags(FILE *archivo)
{

	ID3 info;
	if( archivo == NULL)
	{
		fprintf(stderr, "no se puede abir el archivo\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*
		fseek(archivo, 0, SEEK_END);
		long pos = ftell(archivo);
		fseek(archivo, ( pos - sizeof(ID3)), SEEK_SET) ;*/

		if( fseek(archivo, 0, SEEK_END) == -1)
		{
			fprintf(stderr, "ocurrio un error al leer los tags\n");
			exit(EXIT_FAILURE);
		}

		long pos = ftell(archivo);
		if( fseek(archivo, ( pos - sizeof(ID3)), SEEK_SET ) == -1 )
		{
			fprintf(stderr, "error con los tags \n");
			exit(EXIT_FAILURE);	
		}

		else if( fread( &info, sizeof(ID3), 1, archivo ) != 1)
		{
			fprintf(stderr, "No podemos abrir los tags\n");
			exit(EXIT_FAILURE);
		}

//		info.FILE_OK = 1;
		else if(  memcmp( info.tag, "TAG", 3) != 0 )
		{
			fprintf(stderr, "Los tags presentan errores\n");
			exit(EXIT_FAILURE);
		}
		else	
			return info;
	}
}


FILE *openSong(byte *nombre)
{
	FILE *temp;
	temp = fopen(nombre, "r+");
	if( temp == NULL)
	{
		fprintf(stderr, "No existe el archivo %s\n", nombre);
		exit(EXIT_FAILURE);
	}
	return temp;
}



byte *getCodec(FILE *archivo)
{
	fseek(archivo, 0, SEEK_END);
	long tam = ftell(archivo);
	/// declaro un codec enorme
	fprintf(stderr, "size del archivo %ld\n", tam );
	byte *codec = malloc(tam);
	fprintf(stderr, "el tamaño del archivo %ld\n",  sizeof codec);
	fseek(archivo, 0, SEEK_SET);

	fread(codec, sizeof (codec), tam, archivo);

	
	return codec;
}

void printTag(ID3 cancion)
{
	printf("Tags:\n");
	printf("Nombre: %s\n",cancion.title );
	printf("Artista: %s\n", cancion.artist);
	printf("Album: %s\n", cancion.albumName );
	printf("Año: %.4s\n", cancion.year);
	printf("Comentario: %s\n", cancion.comment );
	int pos = cancion.genere;
	char *a;
	if( pos < 0 || pos > 79)
		a = genero[12];
	else a = genero[pos];
	printf("Genero: %s\n", a);

}

void editarNombre(FILE *archivo)
{
	return;
}

void editArtista(FILE *archivo)
{
	return;
}
void editAlbum(FILE *archivo)
{
	return;
}
void editYear(FILE *archivo)
{
	return;
}
void editComment(FILE *archivo)
{
	return;
}
void editGenero(FILE *archivo)
{
	return;
}

void tablaGeneros()
{
	printf("elija un numero de genero\n");
	for(int c = 0 ; c<80; c++)
	{
		printf("%d  %s\n",c,genero[c]);
	}
}