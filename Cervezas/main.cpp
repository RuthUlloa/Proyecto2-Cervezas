#include <iostream>
#include "NodoCerveza.h"
#include "grafo.h"
using namespace std;

void crearGrafo(Grafo * pGrafo){
    Grafo *grafo1 = pGrafo;
    int opcion = 0;
    while(opcion == 0){
        cout << endl;
        cout << "-------------Crear Grafo---------------" << endl;
        cout << "1- Agregar Familia" << endl;
        cout << "2- Agregar Tipo" << endl;
        cout << "3- Agregar Cerveza" << endl;
        cout << "4- Agregar Arista" << endl;
        cout << "5- Salir" << endl;
        cout << "Opcion selecionada: " ;
        cin >> opcion;
        cout << endl;
        string nombre;
        string tipoFerment;
        double tiempFerment;
        int temperatura;
        string color;
        string cuerpo;
        double precio;
        string origen;
        string destino;
        switch(opcion){

            case 1:
                cout << "Ingrese el nombre de la familia" << endl;
                cin >> nombre;
                grafo1->insertarTipoFamilia(1,nombre);
                opcion = 0;
                break;

            case 2:
                cout << "Ingrese el nombre del tipo de cerveza" << endl;
                cin >> nombre;
                grafo1->insertarTipoFamilia(2,nombre);
                opcion = 0;
                break;

            case 3:
                cout << "Ingrese el nombre de la cerveza" << endl;
                cin >> nombre;
                cout << "Ingrese el tipo de fermentacion de la cerveza" << endl;
                cin >> tipoFerment;
                cout << "Ingrese el tiempo de fermentacion de la cerveza" << endl;
                cin >> tiempFerment;
                cout << "Ingrese la temperatura de la cerveza" << endl;
                cin >>temperatura;
                cout << "Ingrese el color de la cerveza" << endl;
                cin >> color;
                cout << "Ingrese el cuerpo de la cerveza" << endl;
                cin >> cuerpo;
                cout << "Ingrese el precio de la cerveza" << endl;
                cin >> precio;
                grafo1->insertarCerveza(3,nombre,tipoFerment,tiempFerment,temperatura,color,cuerpo,precio);
                opcion = 0;
                break;

            case 4:
                cout << "Ingrese el origen de la arista" << endl;
                cin >> origen;
                cout << "Ingrese el destino de la arista" << endl;
                cin >> destino;
                grafo1->insertarArista(origen,destino);
                opcion = 0;
                break;

            case 5:
                break;

            default:
                opcion = 0;

        }
    }
}

void eliminarVertice(Grafo * pGrafo){

    Grafo *grafo1 = pGrafo;
    int opcion = 0;
    while(opcion == 0){

        cout << endl;
        cout << "-------------Crear Grafo---------------" << endl;
        cout << "1- Eliminar Vertice" << endl;
        cout << "2- Eliminar Arista" << endl;
        cout << "3- Salir" << endl;
        cout << "Opcion selecionada: " ;
        cin >> opcion;

        string pNombre;
        string origen;
        string destino;
        switch(opcion){

            case 1:
                cout << "Ingrese el nombre del vertice a eliminar: ";
                cin >> pNombre;
                cout << endl;
                grafo1->borrarVertice(pNombre);
                opcion = 0;
                break;

            case 2:
                cout << "Ingrese el origen de la arista a eliminar: ";
                cin >> origen;
                cout << endl;
                cout << "Ingrese el destino de la arista a eliminar: ";
                cin >> destino;
                cout << endl;
                grafo1->borrarArista(origen,destino);
                opcion = 0;
                break;

            case 3:
                break;

            default:
                opcion = 0;
                break;
            }
        }
    }



int main()
{

    Grafo * grafo1 = new Grafo();
    int select = 0;
    while (select == 0){
        cout << "-----------------MENU-------------------"<< endl;
        cout << "1- Crear grafo" << endl;
        cout << "2- Eliminar vertice o Arista" << endl;
        cout << "3- Imprimir grafo" << endl;
        cout << "4- salir" << endl;
        cout << "Opcion selecionada: " ;
        cin >> select;
        switch(select){

            case 1:
                crearGrafo(grafo1);
                select = 0;
                break;

            case 2:
                eliminarVertice(grafo1);
                select = 0;
                break;

            case 3:
                grafo1->imprimir();
                select = 0;
                break;

            case 4:
                break;

            default:
                select = 0;
                break;

        }
    }

}
