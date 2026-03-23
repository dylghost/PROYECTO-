
/*
AUTOR: Dylan Sebaastián Cabrera Enríquez
FECHA: 22-03-2025
TEMA: SISTEMA DE CONTROL DE INVENTARIO
Este algoritmo es para el registro de productos puede servir para un a tienda de pequeña a mediana 
para poder registrar todos los productos que posee
*/
#include<iostream>
using namespace std;
void Registrar(string nombres[], float precios[], int cantidades[], int &n);
void MostrarInventario(string nombres[], float precios[], int cantidades[], int n);
void valorTotal(float precios[], int cantidades[], int n);
void menu();
 
void menu(){
    cout << "\n===== INVENTARIO =====\n";
    cout << "1. Registrar producto\n";
    cout << "2. Mostrar inventario\n";
    cout << "3. Valor total\n";
    cout << "4. Buscar producto (MEJORA)\n";
    cout << "5. Salir\n";
    cout << "Seleccione: ";
}
int main(){
    string nombres[20];
    float precios[20];
    int cantidades[20];
    int n=0;
    int opcion;
    do{
        menu();
        cin >> opcion;
        switch(opcion){
            case 1:
            Registrar(nombres, precios, cantidades, n);
            cout << endl;
            break;
            case 2:
            MostrarInventario(nombres, precios, cantidades, n);
            cout << endl;
            break;
            case 3:
            valorTotal(precios,cantidades, n);
            cout << endl;
            break;
            case 4:

            case 5:
            cout << "Gracias por usar";
            break;
            default:
            cout << "Opcion invalida vuelva a elegir";

        }
    }while(opcion !=5);
}
void Registrar(string nombres[], float precios[], int cantidades[], int &n){
    int cantidad;
    cout << "Cuantos productos desea ingresar :";
    cin >> cantidad;

    if(cantidad <=0){
        cout << "Cantidad invalida ";
        return;
    }
    for(int i=0; i<cantidad; i++){
        cout << "Nombre del producto " << i+1 << " : " << endl;
        cin >> nombres[n];
        do{
            cout << "Ingrese el precio de " << nombres[n] << endl;
            cin >> precios[n];
        }while(precios[n] <=0);
        do{
            cout << "Ingrese la cantidad de " << nombres[n] << endl;
            cin >> cantidades[n];
        }while(cantidades[n] <0);
        n++;
    }
}
void MostrarInventario(string nombres[], float precios[], int cantidades[], int n){
    if(n==0){
        cout << "No dispone d productos" << endl;
    }
    for(int i=0; i< n ;i++){
        cout << nombres[i] << " Precio : " << precios[i] << " Cantidad: " << cantidades[i] << endl;
    }
}
void valorTotal(float precios[], int cantidades[], int n){
    if(n==0){
        cout << "No existen productos" << endl;
    }
    float suma=0;
    for(int i=0; i<n; i++){
        suma+=cantidades[i]* precios[i];
    }
    cout << "Valor total del inventario es: " << suma << endl;

}
