#include <cstdlib>
#include <iostream>
#include "NodoCerveza.h"

using namespace std;

class NodoCerveza;
// estructura nodo para lista simple

// estructura arista para lista de aristas
struct Arista {
       string nombre; // parte de datos
       // int poblacion
       // int distancia
       //int.....
       Arista * siguiente;// puntero para enlazar nodos
       // constructor

       Arista(string pNombre)
       {
                nombre = pNombre; // asigna los datos
                siguiente = NULL; // sig es null

       }

       // imprimir
       void imprimir()
       {
            cout << nombre;
       }
};


struct ListaAristas {
       // solo con pN es suficiente
       Arista *primerNodo, *ultimoNodo;

       ListaAristas()
       {
           primerNodo = ultimoNodo = NULL;
       }

       // encabezados de funcion
       void insertarAlInicio (string pNombre);
       Arista* borrarAlInicio(void);
       void imprimir(void);
       void insertarAlFinal(string pNombre);
       Arista* borrarAlFinal(void);
       Arista* buscar (string pNombre);//
       int largo (void);//
       bool vacia(void);
       void borrarEnPosicion(int pos);
       int posicion (string);
       void borrarArista(string pNombre);

};





struct ListaSimple {
       // solo con pN es suficiente
       NodoCerveza *primerNodo, *ultimoNodo;

       ListaSimple()
       {
                    primerNodo = ultimoNodo = NULL;
       }

       // encabezados de funcion
       void borrarNodoCerveza(string pNombre);
       void insertarTipoFamilia(int tipo,string nombre);
       void insertarCerveza(int pTipo,string pNombre,string pTipoFerm, double pTiempoFerm, int pTemp, string pColor, string pCuerpo, double pPrecio);
       void borrarAristas(string pNombre);
       void insertarAlInicio (int tipo,string nombre);
       NodoCerveza* borrarAlInicio(void);
       void imprimir(void);
       void insertarAlFinal(int tipo,string nombre);
       NodoCerveza* borrarAlFinal(void);
       NodoCerveza* buscar (string pNombre);//
       int largo (void);//
       int largoRec (void);
       int largo_aux(NodoCerveza*);
       void insertarAlFinalConRecorrido(int dato);//
       bool vacia(void);
       ListaSimple* retornaNuevaListaInvertida(void);//
       void insertarEnPosicion(int dato, int pos);
       void borrarEnPosicion(int pos);
       int posicion (string pNombre);

       void encolar(int tipo,string nombre);
       NodoCerveza* desencolar();
};

