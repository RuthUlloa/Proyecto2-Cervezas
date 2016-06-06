
#include "NodoCerveza.h"



void ListaSimple::insertarTipoFamilia(int tipo, string nombre){
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoCerveza(tipo,nombre);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo
     }
     else
     {
         // se crea el nuevo nodo
         NodoCerveza *nuevo = new NodoCerveza(tipo,nombre);
         // uN siguiente debe apuntar al nuevo nodo
         // uN debe apuntar al nuevo nodo enlazado
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }

}

void ListaSimple::insertarCerveza(int pTipo,string pNombre,string pTipoFerm, double pTiempoFerm, int pTemp, string pColor, string pCuerpo, double pPrecio){

    // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoCerveza(pTipo,pNombre,pTipoFerm,pTiempoFerm,pTemp,pColor,pCuerpo,pPrecio);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo
     }
     else
     {
         // se crea el nuevo nodo
         NodoCerveza *nuevo = new NodoCerveza(pTipo,pNombre,pTipoFerm,pTiempoFerm,pTemp,pColor,pCuerpo,pPrecio);
         // uN siguiente debe apuntar al nuevo nodo
         // uN debe apuntar al nuevo nodo enlazado
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }

}

// funcion que inserta un nodo nuevo en la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaSimple::insertarAlInicio (int tipo, string nombre)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoCerveza(tipo,nombre);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo
     }
     else
     {
         NodoCerveza *nuevo = new NodoCerveza(tipo,nombre);
         // a lo que apunta pN ahora es el segundo
         // por eso, nuevo->siguiente es pN
         nuevo->siguiente = primerNodo;
         // ahora devolvemos pN a que apunte al nuevo
         // y primero de las lista
         primerNodo = nuevo;
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }
}

void ListaSimple::borrarNodoCerveza(string pNombre)
{
       NodoCerveza * tmp = primerNodo;
       while (tmp!=NULL)
       {
         if (tmp->nombre == pNombre && tmp==primerNodo){
            primerNodo = primerNodo->siguiente;
            borrarAristas(pNombre);
            delete tmp;
         }else if (tmp->siguiente->nombre == pNombre && tmp==ultimoNodo){
            ultimoNodo = NULL;
            tmp->siguiente=ultimoNodo;
            borrarAristas(pNombre);
            delete tmp;
         }else if(tmp->siguiente->nombre == pNombre){
             tmp->siguiente=tmp->siguiente->siguiente;
             borrarAristas(pNombre);
             delete tmp;
         }else{
             tmp = tmp->siguiente;
         }
       }

}

void ListaSimple::borrarAristas(string pNombre){
    NodoCerveza *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           ListaAristas *aristas = tmp->getListaAristas();
           int pos = aristas->posicion(pNombre);
           if (pos>=0){
                aristas->borrarEnPosicion(pos);
           }
           tmp = tmp->siguiente;
     }

}
// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria

NodoCerveza* ListaSimple::borrarAlInicio(void){
      // si no hay elementos, no borra nada, retorna null
      if (primerNodo == NULL)
      {
         return NULL;
      }
      else
      {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          NodoCerveza* borrado = primerNodo;
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          primerNodo = primerNodo->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
      }
}


// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void ListaSimple::imprimir(void)
{
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     NodoCerveza *tmp = primerNodo;

     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->nombre << "  ";
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     cout << endl;
}

// funcion que inserta un nodo nuevo al final de la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaSimple::insertarAlFinal (int tipo, string nombre)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoCerveza(tipo,nombre);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo
     }
     else
     {
         // se crea el nuevo nodo
         NodoCerveza *nuevo = new NodoCerveza(tipo,nombre);
         // uN siguiente debe apuntar al nuevo nodo
         // uN debe apuntar al nuevo nodo enlazado
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }
}



// funcion que retorna true si la lista es vacia
// entradas: ninguna
// salidas: true si es no tiene elmentos, false otro caso
bool ListaSimple::vacia()
{
     // si primerNodo es nulo, no hay elementos
     if (primerNodo == NULL)
        return true;
     else
         return false;
}

NodoCerveza* ListaSimple::borrarAlFinal(void)
{
      if (vacia())
         return NULL;
      // este caso es cuando tiene un solo elemento
      else if (primerNodo->siguiente == NULL)
      {
            NodoCerveza* actual = primerNodo;
            primerNodo = ultimoNodo = NULL;
            return actual;
      }
      else
      {
            // referencia al primero para recorrer la lista
            NodoCerveza* actual = primerNodo;
            // recorre la lista hasta llegar al penultimo nodo
            //while (actual->siguiente != NULL)
            while (actual->siguiente->siguiente != NULL)
              actual = actual->siguiente;

            // al salir actual referencia al penultimo nodo
            // refencia nueva al ultimo nodo para despues retornarlo
            NodoCerveza* tmp = ultimoNodo;
            // ultimo nodo pasa al penultimo
            ultimoNodo = actual;
            //le quita el enlace al que era ultimo
            actual->siguiente = NULL;
            // retorna el que desenlazo al final
            return tmp;
        }
}

NodoCerveza * ListaSimple::buscar(string pNombre)
{
       NodoCerveza * tmp = primerNodo;
       while (tmp!=NULL)
       {
             if (tmp->nombre == pNombre)
                return tmp;

             tmp = tmp->siguiente;

       }

       return NULL;
}

int ListaSimple::posicion(string pNombre)
{
    int pos = 0;
       NodoCerveza * tmp = primerNodo;
       while (tmp!=NULL)
       {
             if (tmp->nombre == pNombre)
                return pos;

             pos++;
             tmp = tmp->siguiente;

       }

       return -1;
}


// Funcion que elimina el elmento de la lista en una posicion
// esta funcion no retorna el nodo eliminado, por lo que
// si libera memoria
void ListaSimple::borrarEnPosicion(int pos)
{
     // si esta vacia no borra
        if (vacia())
        { }
        // pos 0 borra el inicio
        else
        if (pos == 0)
        {
            // borrar al inicial no libera memoria, se hace
            // luego de llamar a la funcion
            NodoCerveza* borrado = borrarAlInicio();

            if (borrado != NULL)
               delete borrado;

        }
        else
        {
            //recorre la lista hasta el nodo previo a eliminar
            NodoCerveza *actual = primerNodo;
            // deja el puntero en el nodo antes a eliminar
            for (int i=1; i < pos && actual->siguiente != NULL;i++)
                actual=actual->siguiente;

            // si es el ultimo borra el final
            if (actual->siguiente == NULL)
            {
                 // borrar al final no libera memoria, se hace
                 // luego de llamar a la funcion
                 NodoCerveza* borrado = borrarAlFinal();
                 if (borrado != NULL)
                        delete borrado;
            }
            else
            {
                //referencia tmp que apunta al que se eliminara
                NodoCerveza *tmp = actual->siguiente;
                // anterior a borrar siguiente será el sig.sig
                actual->siguiente = actual->siguiente->siguiente;
                // el que se eliminara.sig sera null
                tmp->siguiente = NULL;
                delete tmp;
            }
        }
    }

// se hace un borrar al inicio llamado desencolar
// para simular una cola
NodoCerveza* ListaSimple::desencolar(void)
{
      // si no hay elementos, no borra nada, retorna null
      if (primerNodo == NULL)
      {
         return NULL;
      }
      else
      {
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          NodoCerveza* borrado = primerNodo;
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          primerNodo = primerNodo->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          return borrado;
      }
}

// se hace un insertar al final, llamado encolar
void ListaSimple::encolar (int tipo, string nombre)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         primerNodo = new NodoCerveza(tipo,nombre);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo
     }
     else
     {
         // se crea el nuevo nodo
         NodoCerveza *nuevo = new NodoCerveza(tipo,nombre);
         // uN siguiente debe apuntar al nuevo nodo
         // uN debe apuntar al nuevo nodo enlazado
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
         // el puntero nuevo deja de existir, no se libera
         // memoria porque se pierde la info
     }
}



