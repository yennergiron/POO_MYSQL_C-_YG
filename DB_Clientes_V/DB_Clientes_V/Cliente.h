#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"


using namespace std;

class Cliente : Persona {
private: string NIT;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		NIT = n;
	}

	// METODOS
	//set (modificar)
	void setNit(string n) { NIT = n; }
	void setNombres(string nom) { Nombres = nom; }
	void setApellidos(string ape) { Apellidos = ape; }
	void setDireccion(string dir) { Direccion = dir; }
	void setTelefono(int tel) { Telefono = tel; }
	void setFecha_Nacimiento(int fn) { Fecha_nacimiento = fn; }

	//get (mostrar)
	string getNit() { return NIT; }
	string getNombres() { return Nombres; }
	string getApellidos() { return Apellidos; }
	string getDireccion() { return Direccion; }
	int getTelefono() { return Telefono; }
	string getFecha_Nacimiento() { return Fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(Telefono);
		if (cn.getconectar()) {
			string  insertar = "INSERT INTO clientes(NIT,Nombres,Apellidos,Direccion,Telefono,Fecha_nacimiento) VALUES ('" + NIT + "','" + Nombres + "','" + Apellidos + "','" + Direccion + "'," + t + ",'" + Fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}
	
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string e;
		cout << "Ingrese el idclientes a eliminar: ";
		cin >> e;
		string eliminar = "delete from db_customer.clientes where idclientes= '" + e + "'";
		const char* f = eliminar.c_str();
		q_estado = mysql_query(cn.getconectar(), f);

		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "**** Error al ingresar ****" << endl;
		}
		cn.cerrar_conexion();
	}
	void editar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string a;
		string b;
		string h;
		string j;
		string k;
		string l;
		/*string m;
		string n;
		string o;
		string p;*/
		string g;
		cout << "Ingrese el ID a Editar: ";
		cin >> g;
		cout << "Ingrese nuevo NIT: ";
		cin >> a;
		cout << "Ingrese nuevo Nombres: ";
		cin >> b;
		cout << "Ingrese nueva Apellidos: ";
		cin >> h;
		cout << "Ingrese nuevo Direccion: ";
		cin >> j;
		cout << "Ingrese nuevo Telefono: ";
		cin >> k;
		cout << "Ingrese nuevo Fecha de Nacimiento: ";
		cin >> l;
		/*cout << "Ingrese nueva Fecha de Nacimiento: ";
		cin >> m;
		cout << "Ingrese nuevo idPuesto: ";
		cin >> n;
		cout << "Ingrese nueva Fecha incio de Labores: ";
		cin >> o;
		cout << "Ingrese nueva Fecha de ingreso: ";
		cin >> p;*/
		string editar = "update empleado set NIT= '" + a + "', Nombres= '" + b + "', Apellidos= '" + h + "', Direccion= '" + j + "', Telefono= '" + k + "', Fecha_nacimiento= '" + l + "'";
		const char* c = editar.c_str();
		q_estado = mysql_query(cn.getconectar(), c);

		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "**** Error al ingresar ****" << endl;
		}

		cn.cerrar_conexion();
	}
};