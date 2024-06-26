#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

#include "ciudadano.h"
#include "vacuna.h"

#define TAM 5

struct Ciudadano{

char nombreYApellido[30];
int nroCiudadano;

Vac vacunas[TAM];
};

//ARMADO
Ciu cargarCiudadano(){

Ciu c=malloc(sizeof(struct Ciudadano));

printf("\nPor favor ingrese su nombre y apellido:\n");
fflush(stdin);
gets(c->nombreYApellido);

c->nroCiudadano=100000+rand()%900000;

for (int i=0;i<TAM;i++){

(c->vacunas)[i]=cargarVacunaVacio();
}

return c;
};

void agregarVacuna(Ciu c){

int posVacia=-1;

posVacia=buscarPosVacia(c,"VACIO");

if (posVacia != -1){
    printf("\nEs momento de agregar una dosis");
    c->vacunas[posVacia]=cargarVacuna();
}
else printf("\n\t--YA TE DISTE TODAS LAS DOSIS PAPA--\n");

};

//MOSTRAR
void mostrarCiudadano(Ciu c){

printf("\n---CIUDADANO----\n");
printf("\nNombre y Apellido: %s\n",c->nombreYApellido);
printf("\nCodigo de Ciudadano: %d\n",c->nroCiudadano);

for (int i=0;i<TAM;i++){

    mostrarVacuna(c->vacunas[i]);
}
};

//MODIFICACION
int buscarVacuna (Ciu c, char nombreVacuna[20]){

int iguales;
int pos=-1;

for (int i=0;i<TAM;i++){
          iguales=strcmp(nombreVacuna,getNombreV(c->vacunas[i]));
        if(iguales==0){
            pos=i;
        }
}

return pos;
};

void contarVacuna (Ciu c, char nombreVacuna[20]){

int iguales;
int bandera=0;
int pos=-1;

for (int i=0;i<TAM;i++){
          iguales=strcmp(nombreVacuna,getNombreV(c->vacunas[i]));
        if(iguales==0){
            bandera=bandera+1;
            pos=i;
        }
}
if (bandera>=1){
        printf("\nLa VACUNA %s se aplico %d vez/es\nLa ultima dosis aplicada fue la:%d",nombreVacuna,bandera,pos+1);

}else{
printf("\nEsa vacuna NO ha sido aplicada en el paciente %s\n",c->nombreYApellido);
}

}
int buscarPosVacia(Ciu c, char b[20]){

int pos=-1;

for (int i=0;i<TAM;i++){

    if(strcmp(getLoteV(c->vacunas[i]),b) == 0){
        pos=i;
        i=TAM+1;
    }
}

return pos;
}

void modificarNombreVacuna(Ciu c, char b[20]){

setNombreV(c,b);

};
void modificarLoteVacuna (Ciu c, char b[20]){
setLoteV(c,b);
};


//ELIMINAR
void eliminarVacuna(Ciu c,char b[20]){

int pos=-1;

pos=buscarVacuna(c,b);

if (pos != -1){
c->vacunas[pos]=cargarVacunaVacio();
}
};


//GETS
char* getNombreC(Ciu c){
return c->nombreYApellido;
}
int getCodigoC(Ciu c){
return c->nroCiudadano;
}

//SETS
void setNombreC(Ciu c, char nuevoNombre[]){
strcpy(c->nombreYApellido,nuevoNombre);
};
void setCodigoC(Ciu c, int nuevoCodigo){
c->nroCiudadano=nuevoCodigo;
};

//DESTRUCTOR
 void destruirCiudadano(Ciu c){
 free(c);
 };


//FILES
Ciu leerCiudadano(){

Ciu c;
FILE * archivo= fopen("ciudadanos.txt","r");

while(!feof(archivo)){

    char datos[50]=" ";

    fgets (datos,50,archivo);

    c=casteoTextoACiudadano(datos);
}
fclose(archivo);

FILE * archivoV= fopen("vacuna.txt","r");
int i=0;
while(!feof(archivoV)){

    char datos[50]=" ";

    fgets(datos,50,archivoV);

    c->vacunas[i]=casteoTextoAVacuna(datos);
    i++;
}
fclose(archivoV);


return c;
}

void guardarCiudadano(Ciu c){

FILE * archivo=fopen("ciudadano.txt","w");

fprintf(archivo,"%s;%d\n",c->nombreYApellido,c->nroCiudadano);

for (int i=0;i<TAM;i++){

    guardarVacuna(c->vacunas[i]);

}
fclose(archivo);

}

Ciu casteoTextoACiudadano(char c[50]){

Ciu ciud=malloc(sizeof(struct Ciudadano));

int posDel=-1;

for (int i=0;i<50;i++){
        if(c[i]==';'){
            posDel=i ;
            i=120;
        }
}

char auxNombre[30]=" ";
char auxNum[7]=" ";

for (int i=0;i<posDel;i++){
    auxNombre[i]=c[i];
}
for (int i=posDel+1;i<posDel+7;i++){
    auxNum[i-posDel-1]=c[i];
}

ciud->nroCiudadano= atoi(auxNum);
strcpy(ciud->nombreYApellido,auxNombre);
return ciud;
}
