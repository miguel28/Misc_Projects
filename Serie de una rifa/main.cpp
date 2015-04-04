#include <iostream>
using namespace std;

int main (int argc, char * const argv[]) {

	int n,i, suma;
	cout << "Se planea realizar una rifa (raspadito) de n boletos, \ndonde el costo del boleto es el número del mismo. \n¿ Cuanto se logra recabar si se venden todos los boletos? \n Teclee el numero n de boletos: ";
    cin >> n;
	
	for (i=1; i<=n; i++) {
		suma+=i;
	}
	cout << "\nResultado : " << suma << endl;
	return 0;
}
