#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#define TAM 5
#include "vacuna.h"

struct Vacuna{
char nombre[35];
char lote[10];
};

//ARMADO
Vac cargarVacuna (){

Vac v = malloc(sizeof(struct Vacuna));

printf("\nPor favor ingrese el nombre de la vacuna:\n");
fflush(stdin);
gets(v->nombre);


for (int i=0;i<9;i++){

    v->lote[i]=letrita();
}

return v;
}

Vac cargarVacunaVacio (){

Vac v = malloc(sizeof(struct Vacuna));

strcpy(v->nombre,"VACIO");
strcpy(v->lote,"VACIO");

return v;
};

char letrita(){

char lotesPosible[40]="abcdefghijklmnopqrstuvwxyz0123456789";
int letra=rand()%36;


return lotesPosible[letra];
}

//MOSTRAR
void mostrarVacuna (Vac v){

int valor= strcmp(v->nombre,"VACIO");
if (valor != 0){
printf("\n\t---VACUNA---\n");
printf("\n\tNOMBRE: %s \n",v->nombre);
printf("\n\tLOTE:  %.9s\n",v->lote);
}
}


//GETS
char* getNombreV(Vac v){
return v->nombre;
}
char* getLoteV(Vac v){
return v->lote;
}

//SETS
void setNombreV(Vac v, char nuevoNombre[]){
  strcpy(v->nombre,nuevoNombre);
}
void setLoteV (Vac v, char nuevoLote[]){
strcpy(v->lote,nuevoLote);
};


//DESTRUCTOR
void destruirVacuna(Vac v){
free(v);
};


//FILES
void guardarVacuna(Vac v ){

FILE * archivo=fopen("vacunas.txt","a");

fprintf(archivo,"%s;%s\n",v->nombre,v->lote);

fclose(archivo);

}

Vac casteoTextoAVacuna(char c[50]){

Vac v=malloc(sizeof(struct Vacuna));

int posDel=-1;

for (int i=0;i<50;i++){
        if(c[i]==';'){
            posDel=i ;
            i=120;
        }
}

char auxNombre[30]=" ";
char auxLote[11]=" ";

for (int i=0;i<posDel;i++){
    auxNombre[i]=c[i];
}
for (int i=posDel+1;i<posDel+11;i++){
    auxLote[i-posDel-1]=c[i];
}

strcpy(v->lote,auxLote);
strcpy(v->nombre,auxNombre);

return v;
destruirVacuna(v);
};

