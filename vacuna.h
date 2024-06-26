#ifndef VACUNA_H_INCLUDED
#define VACUNA_H_INCLUDED

///DEFINICIONES

struct Vacuna;


typedef struct Vacuna * Vac;

//ARMADO
Vac cargarVacuna ();
Vac cargarVacunaVacio ();

//MOSTRAR
void mostrarVacuna (Vac v);


//FILES
void guardarVacuna(Vac v);
Vac casteoTextoAVacuna(char c[50]);

//GETS
char* getNombreV(Vac v);
char* getLoteV(Vac v);


//SETS
void setNombreV(Vac v, char nuevoNombre[]);
void setLoteV (Vac v, char nuevoLote[]);

//EXTRAS
char letrita();

//DESTRUCTOR
void destruirVacuna (Vac v);


#endif // VACUNA_H_INCLUDED
