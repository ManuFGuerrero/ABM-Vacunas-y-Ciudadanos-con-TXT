#ifndef CIUDADANO_H_INCLUDED
#define CIUDADANO_H_INCLUDED


struct Ciudadano;


typedef struct Ciudadano * Ciu;

//ARMADO
Ciu cargarCiudadano();
void agregarVacuna(Ciu c);

//ELIMINADO
void eliminarVacuna(Ciu c,char b[20]);

//MUESTRA
void mostrarCiudadano(Ciu c);

//MODIFICACION
int buscarVacuna (Ciu c, char nombreVacuna[20]);
int buscarPosVacia(Ciu c, char b[20]);
void modificarNombreVacuna(Ciu c, char b[20]);
void modificarLoteVacuna (Ciu c, char b[20]);
void contarVacuna(Ciu c, char nombreVacuna[20]);

//FILES
Ciu leerCiudadano();
Ciu casteoTextoACiudadano(char c[50]);
void guardarCiudadano(Ciu c);

//GETS
char* getNombreC(Ciu c);
int getCodigoC(Ciu c);

//SETS
void setNombreC(Ciu c, char nuevoNombre[]);
void setCodigoC(Ciu c,int nuevoCodigo);

//DESTRUCTOR
void destruirCiudadano(Ciu c);


#endif // CIUDADANO_H_INCLUDED
