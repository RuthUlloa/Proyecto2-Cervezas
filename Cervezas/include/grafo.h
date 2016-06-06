#include "NodoCerveza.h"

struct Grafo
{
       ListaSimple * vertices;

       Grafo()
       {
              vertices = new ListaSimple();
       }

       // para insertar un vertice
       void insertarTipoFamilia(int tipo,string nombre)
       {
            // valida que no exista
            NodoCerveza * tmp = vertices->buscar(nombre);
            // si es null no existe, lo inserta
            if (tmp == NULL)
            {
                    // solo llama a insertar de lista
                vertices->insertarTipoFamilia(tipo,nombre);
            }
            else
            {
                cout << "El nodo "<< nombre << "ya existe"<<endl;
            }
       }

       void insertarCerveza(int pTipo,string pNombre,string pTipoFerm, double pTiempoFerm, int pTemp, string pColor, string pCuerpo, double pPrecio)
       {
            // valida que no exista
            NodoCerveza * tmp = vertices->buscar(pNombre);
            // si es null no existe, lo inserta
            if (tmp == NULL)
            {
                    // solo llama a insertar de lista
                vertices->insertarCerveza(pTipo,pNombre,pTipoFerm,pTiempoFerm,pTemp,pColor,pCuerpo,pPrecio);
            }
            else
            {
                cout << "El nodo "<< pNombre << "ya existe"<<endl;
            }
       }

       void insertarArista(string origen, string destino)
       {
            // si existe el vertice inserta
            NodoCerveza* tmp = vertices->buscar(origen);
            NodoCerveza * tmpDest = vertices->buscar(destino);
            if (tmp != NULL)
            {
               if (tmpDest != NULL)
               {
                 // si la arista no existe
                 Arista * listaAristas = tmp->listaAristas->buscar(destino);
                 if (listaAristas == NULL)
                 {
                    tmp->listaAristas->insertarAlFinal(destino);
                 }
                 else
                 {
                     cout << "Arista ya existe";
                 }
               }
               else
               {
                   cout << "Destino no existe";
               }
            }
            else
            {
                cout << "Nodo origen no existe"<< endl;
            }
       }


// IMPRIMIR IMPRIMIR IMPRIMIR
       void imprimir ()
       {
            NodoCerveza * tmp = vertices->primerNodo;

            while (tmp != NULL)
            {
                 cout << tmp->nombre <<": ";
                 tmp->listaAristas->imprimir();
                 cout << endl;
                 tmp = tmp -> siguiente;
            }
            cout << endl;
       }
// BORRAR ARISTA  BORRAR ARISTA
void borrarArista(string origen, string destino)
{
     NodoCerveza * tmp = vertices->buscar(origen);

     if (tmp != NULL)
     {
        int posA = tmp->listaAristas->posicion(destino);
        if (posA > -1)
        {
           tmp->listaAristas->borrarEnPosicion(posA);
           cout << "Eliminada arista "<<origen<<" - "<< destino<<endl;
        }
        else
        {  }
     }
}



// BORRAR BORRAR BORRAR

void borrarVertice (string pNombre)
{
     // se usan las funciones de lista
     int posV = vertices->posicion(pNombre);
     // si lo encontro, posV es <> -1
     if (posV > -1)
     {
        //recorre toda la lista de vertices
        // eliminando aristas a dato
        NodoCerveza * tmp = vertices->primerNodo;
        while (tmp != NULL)
        {
              // usa borrar arista
              borrarArista(tmp->nombre, pNombre);
              tmp = tmp->siguiente;
        }
        // ya borro las aristas, ahora el vertice
        vertices->borrarEnPosicion(posV);
     }
     else
     {
         cout << "Vertice no existe"<<endl;
     }

}

// visitar vertice
void visitarVertice(string pNombre)
{
     NodoCerveza * tmp = vertices->buscar(pNombre);
     if (tmp != NULL)
        tmp->visitado = true;
}

// visitar vertice
bool visitadoVertice(string pNombre)
{
     NodoCerveza * tmp = vertices->buscar(pNombre);
     if (tmp != NULL)
        return tmp->visitado;
     else
         return false;
}

// limpiar visitados
void limpiarVisitados()
{
     NodoCerveza * tmp = vertices->primerNodo;
     while (tmp != NULL)
     {
           tmp->visitado = false;
           tmp = tmp->siguiente;
     }
}

// visitar Adyacentes

void visitarAdyacentes(string pNombre)
{
     // visita el nodo
     visitarVertice(pNombre);
     cout << pNombre << " - " ;
     // busca el vertice para recorrer aristas
     NodoCerveza * tmp = vertices->buscar(pNombre);

     if (tmp != NULL)
     {
             // recorre las lista de adyacencia
        Arista * actual = tmp->listaAristas->primerNodo;
        while (actual!=NULL)
        {
              // si no esta visitado
            if (visitadoVertice(actual->nombre)==false)
            {
                visitarAdyacentes(actual->nombre);
            }

            actual = actual->siguiente;
        }
     }
}

// PROFUNDIDAD - Recorrido por profundidad

void profundidad()
{
     NodoCerveza * tmp = vertices->primerNodo;
     // hace un while de n para recorrer todos
     // aun cuando el grafo es disconexo
     while (tmp != NULL)
     {
         if (tmp->visitado == false)
            visitarAdyacentes(tmp->nombre);

         tmp = tmp->siguiente;
     }
     limpiarVisitados();







}




// fin struct
};



