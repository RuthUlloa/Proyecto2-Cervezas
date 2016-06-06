#ifndef NODOCERVEZA_H
#define NODOCERVEZA_H
#include <iostream>
#include "lista.h"
#define INFINITO -1

using namespace std;


class NodoCerveza
{

private:
    int tipo;
    string tipoFermentacion;
    double tiempoFermentacion;
    int temperatura;
    string color;
    string cuerpo;
    double precio;


public:
    string nombre;
    NodoCerveza *siguiente;
    ListaAristas *listaAristas;
    bool visitado;

    NodoCerveza(int pTipo,string pNombre,string pTipoFerm, double pTiempoFerm, int pTemp, string pColor, string pCuerpo, double pPrecio){
        tipo=pTipo;
        nombre = pNombre;
        tipoFermentacion=pTipoFerm;
        tiempoFermentacion=pTiempoFerm;
        temperatura=pTemp;
        color=pColor;
        cuerpo=pCuerpo;
        precio=pPrecio;
        siguiente=NULL;
        listaAristas= new ListaAristas();
        visitado = false;
    }

    NodoCerveza(int pTipo, string pNombre){
        nombre = pNombre;
        tipo=pTipo;
        tipoFermentacion="";
        tiempoFermentacion=0;
        temperatura=NULL;
        color="";
        cuerpo="";
        precio=NULL;
        siguiente=NULL;
        listaAristas= new ListaAristas();
        visitado = false;
    }

    void setNombre(string pNombre){
        nombre = pNombre;
    }

    string getNombre(){
        return nombre;
    }

    int getTipo(){
        return tipo;
    }

    void setTipoFermentacion(string pTipoFerm){
        tipoFermentacion=pTipoFerm;
    }

    string getTipoFermentacion(){
        return tipoFermentacion;
    }

    void setTiempoFermentacion(double pTiempoFerm){
        tiempoFermentacion=pTiempoFerm;
    }

    double getTiempoFermentacion(){
        return tiempoFermentacion;
    }

    void setTemperatura(int pTemperatura){
        temperatura=pTemperatura;
    }

    int getTemperatura(){
        return temperatura;
    }

    void setColor(string pColor){
        color=pColor;
    }

    string getColor(){
        return color;
    }

    void setCuerpo(string pCuerpo){
        cuerpo=pCuerpo;
    }

    string getCuerpo(){
        return cuerpo;
    }

    void setPrecio(double pPrecio){
        precio=pPrecio;
    }

    double getPrecio(){
        return precio;
    }

    void setSiguiente(NodoCerveza *pSiguiente){
        siguiente=pSiguiente;
    }

    NodoCerveza * getSiguiente(){
        return siguiente;
    }

    ListaAristas * getListaAristas(){
        return listaAristas;
    }




};

#endif // NODOCERVEZA_H
