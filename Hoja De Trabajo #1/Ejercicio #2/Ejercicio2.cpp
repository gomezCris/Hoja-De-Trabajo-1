/*
	Una empresa tiene diez almacenes y necesita crear un programa que lea las ventas mensuales de los diez almacenes, 
	calcular la media de ventas y obtener un  listado de los almacenes cuyas ventas mensuales son superiores a la media
*/

//Importación de librerías
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
	//Declaración de variables
	int noProcesar = 10;
	float media = 0.00;
	float venta = 0.00;
	float totalVenta = 0.00;
	float arrAlmacenes[10];
	
	for (int i = 1; i <= 10; i++){
		cout << "Ingrese la venta mensual del almacen #" << i << endl;
		cin >> venta;
		totalVenta += venta;
		arrAlmacenes[i] = venta;
	}
	
	
	media = totalVenta/10;
	
	//Muestra en pantalla la media de venta
	cout << "-------------------------------------" << endl;
	cout << "LA MEDIA DE VENTAS ES: Q" << media << endl;
	cout << "-------------------------------------" << endl;
	
	
	//Muestra en pantalla la media de venta
	cout << "------------------------------------------------------------" << endl;
	cout << "LISTADO DE ALMACENES CON VENTAS SUPERIORES A LA MEDIA" << endl;
	cout << "------------------------------------------------------------" << endl;
	
	
	for (int i = 1; i <= 10; i++){
		if(arrAlmacenes[i] > media){
			cout << "El almacen #" << i << " posee ventas superiores a la media con: Q" << arrAlmacenes[i] << endl;
		}
	}
	
	//Pausa la ejecución del programa
	system("Pause");
	//Limpia pantalla
	system("CLS");
	return 0;
}
