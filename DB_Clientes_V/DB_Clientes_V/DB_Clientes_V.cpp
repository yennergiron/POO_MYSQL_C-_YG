// DB_Clientes_V.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Cliente.h"
#include <iostream>
using namespace  std;

int main()
{

	string NIT, Nombres, Apellidos, Direccion, Fecha_nacimiento;
	int telefono;
	cout << "Ingrese Nit:";
	getline(cin, NIT);
	cout << "Ingrese Nombres:";
	getline(cin, Nombres);
	cout << "Ingrese Apellidos:";
	getline(cin, Apellidos);
	cout << "Ingrese Direccion:";
	getline(cin, Direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Fecha Nacimiento:";
	cin >> Fecha_nacimiento;

	Cliente c = Cliente(Nombres, Apellidos, Direccion, telefono, Fecha_nacimiento, NIT);

	c.crear();
	c.leer();
	c.eliminar();
	c.editar();

	system("pause");
	return 0;

}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
