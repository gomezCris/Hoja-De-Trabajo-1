/* 	Ejercicio # 1: Usar estructuras y grabar datos a un archivo, utilizar funciones

Descripci�n de problema:  Escribir una funci�n Salario que calcule los salarios de un trabajador para un n�mero dado de horas trabajadas y un salario hora.
Las horas que superen las 40 horas semanales se pagar�n como extras con un salario hora 1,5 veces el salario ordinario. 
As� mismo se deber� calcular el monto a pagar de IGSS por cada trabajador.

El programa debera contener un menu para:
	1) Invocar dicha funcion y grabar datos a un archivo,
	2) Adicionalmente deber� tener una opci�n para leer el archivo y grabar los datos en memoria. 
	3) Una opci�n para mostrar cuanto se paga de total de planilla e IGSS.

*/


//Importaci�n de librer�as
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <sstream> 
#include <windows.h>

using namespace std;

//Declaraci�n de estructura.
struct Empleado{
	string nombre;
	string apellido;
	float salario;
	float horasExtras;
	float totalHE;
	float igss;
	float totalPagoPlanilla;
};

//Funci�n encargada de agrandar la pantalla
void agrandarPantalla(){
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1300, 720, TRUE);
}

//Funci�n encargada de c�lculo de salario y grabado en archivos
void Salario(){
	
	Empleado strEmpleado;
	int contador = 1;
	int registros= 0;
	float horasTrabajadas = 0.00, valorHora = 0.00;
	
	cout << "Ingrese el numero de empleados que desea registrar y calcular salarios: " << endl;
	cin >> registros;
	
	do{
		//Ingreso de datos de empleado
		cout << "Ingrese el nombre del empleado #" << contador << endl;
		cin >> strEmpleado.nombre;
		
		cout << "Ingrese el apellido del empleado #" << contador << endl;
		cin >> strEmpleado.apellido;
		
		cout << "Ingrese el salario del empleado #" << contador << endl;
		cin >> strEmpleado.salario;
		
		cout << "Ingrese las horas trabajadas en la semana del empleado #" << contador << endl;
		cin >> horasTrabajadas;
		
		//Calculo de precio de hora
		valorHora = (strEmpleado.salario / 30) / 8;
		
		//Validaci�n para el c�lculo de salario hora
		if (horasTrabajadas > 40){
			strEmpleado.horasExtras = horasTrabajadas - 40;
			strEmpleado.totalHE = strEmpleado.horasExtras * valorHora;
			strEmpleado.totalHE = (strEmpleado.totalHE *0.015) + strEmpleado.totalHE;
		}else{
			strEmpleado.horasExtras = 0;
			strEmpleado.totalHE = 0;
		}
		
		//calculo de igss
		strEmpleado.igss = (strEmpleado.salario * 0.0483);
		strEmpleado.salario = strEmpleado.salario - strEmpleado.igss;
		
		//Se realiza la suma para el pago correspondiente a recibir de planilla
		strEmpleado.totalPagoPlanilla = strEmpleado.salario + strEmpleado.totalHE;
		
		//Creaci�n y apertura de archivo
		ofstream archivo("Ejercicio1_HT1.txt", std::ios_base::app);
	
		//Grabar datos en archivo
		archivo << strEmpleado.nombre << "\t" << strEmpleado.apellido << "\t" << strEmpleado.salario << "\t" << strEmpleado.horasExtras << "\t" <<
		strEmpleado.totalHE << "\t" << strEmpleado.igss << "\t" << strEmpleado.totalPagoPlanilla << endl;
	
		//Cierre de archivo
		archivo.close();
		
		//Mensaje de consola	
		cout << "EMPLEADO REGISTRADO!" << endl;
		
		//Muestra los datos del empleado: Nombre, Apellido, Total de Descuento IGSS y Total a Recibir en Planilla
		cout << "-----------------------------------------------------------------" << endl;
		cout << "Nombre:            " << strEmpleado.nombre << endl;
		cout << "Apellido:          " << strEmpleado.apellido << endl;
		cout << "Total IGSS:        " << "Q" << strEmpleado.igss << endl;
		cout << "L�quido a Recibir: " << "Q" << strEmpleado.totalPagoPlanilla << endl; 
		cout << "-----------------------------------------------------------------" << endl;
		
	
		//Pausa la ejecuci�n del programa
		system("Pause");
		//Limpia pantalla
		system("CLS");
		
		//Incremento de contador
		contador += 1;	
		
	}while(contador <= registros);
	
}


//Lectura de archivo para mostrar planilla
void lecturaArchivo(){
	//declaraci�n de variables para uso dentro de funci�n
	string _nombre;
	string _apellido;
	float _salario;
	float _horasExtras;
	float _totalHE;
	float _igss;
	float _totalPagoPlanilla;
	//Variable para el manejo de conteo de empleados
	int contador = 1;
	
	//Invocaci�n de funci�n para agrandar la consola
	agrandarPantalla();
	
	//lectura y creaci�n de planilla en pantalla
	ifstream archivo;
	archivo.open("Ejercicio1_HT1.txt", ios::in);
	
	cout <<" No|" <<"      Nombre      |"<<"      Apellido      |"<<"      Salario      |"<<"        HE        |"<<"       IGSS       |"<<"      Liquido     |" << endl;
	
	while(archivo >> _nombre >> _apellido >>_salario >> _horasExtras >> _totalHE >> _igss >> _totalPagoPlanilla){
		cout <<setw(3)<< contador<<"|" << setw(18) <<_nombre <<"|"  << setw(20) << _apellido <<"|" << setw(19) <<_salario <<"|" << setw(18) <<_totalHE <<"|" << setw(18) <<_igss <<"|" << setw(18) << _totalPagoPlanilla <<"|" << endl;
		contador +=1;
	}
	
	archivo.close();
	
	//Pausa la ejecuci�n del programa
	system("Pause");
	//Limpia pantalla
	system("CLS");
}

void totales(){
	//declaraci�n de variables para uso dentro de la funci�n
	string _nombre;
	string _apellido;
	float _salario;
	float _horasExtras;
	float _totalHE;
	float _igss;
	float _totalPagoPlanilla;
	//Variables para sumatoria de totales
	float totalesIGSSS = 0.00;
	float totalesPlanilla = 0.00;
	
	//lectura y sumatoria de totales
	ifstream archivo;
	archivo.open("Ejercicio1_HT1.txt", ios::in);
	
	
	while(archivo >> _nombre >> _apellido >>_salario >> _horasExtras >> _totalHE >> _igss >> _totalPagoPlanilla){
		totalesIGSSS += _igss;
		totalesPlanilla += _totalPagoPlanilla;
	}
	
	//Cierre de archivo
	archivo.close();
	
	//Salida de consola
	cout << "-----------------------------------------------------------" << endl;
	cout << "TOTAL A PAGAR EN PLANILLA: Q" << totalesPlanilla << endl;
	cout << "TOTAL A PAGAR DE IGSS:     Q" << totalesIGSSS << endl;
	cout << "-----------------------------------------------------------" << endl;
	
	//Pausa la ejecuci�n del programa
	system("Pause");
	//Limpia pantalla
	system("CLS");
}

int main(){
	//Declaraci�n de variables
	int opcion;
	bool finalizar = false;
   
	do {
		fflush(stdin);
		cin.clear();
		//Salida de consola
		cout << "------------------------------MENU PRINCIPAL------------------------------" << endl;
		cout << "1. Calcular Salario" << endl;
		cout << "2. Mostrar Planilla" << endl;
		cout << "3. Total Pagar Planilla e IGSS" << endl;
		cout << "4. Salir" << endl;
		//Obtiene la opci�n ingresada por el usuario
		cin >> opcion;
		
		switch (opcion){
			case 1:
				Salario();
				break;
			case 2:
				lecturaArchivo();
				break;
			case 3:
				totales();
				break;
			case 4:
				//Variable bandera para finalizar ejecuci�n del men�
				finalizar = true;
				break;
			default:
				cout << "�Opci�n inv�lida!" << endl;
				opcion = 0;
				break;
		}
		
	}while (finalizar != true);
	return 0;
}


