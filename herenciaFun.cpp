#include <iostream>
#include <cstdlib>
using namespace std;

//Char AvionModel[64]="Avion: militar (F14 Tom Cat)";

class Vehiculo {
	
public:
	void ShowInfo() { cout <<"Tipos de Vehiculo: \n"; }
};

class AutoC : public Vehiculo {
public:
	void Showk() { cout << "Auto: SUV (Sport utility Vehicle)" << "\n"; }
};

class Barco : public Vehiculo {
public:
	void Showk() { cout << "Barco :Velero" << "\n"; }
};

class Avion : public Vehiculo {
public:
	void Showk() { cout << "Avion: militar (F14 Tom Cat)" << "\n"; }
};

int main()
{
	AutoC Object;
	Object.ShowInfo();
	Object.Showk();
	
	cout << "\n\n";
	Barco Object2;
	Object2.ShowInfo();
	Object2.Showk(); 
	
	cout << "\n\n";
	Avion Object3;
	Object3.ShowInfo();
	Object3.Showk(); 
	
	system ("pause");
	return 0;
}