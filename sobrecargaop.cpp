#include <iostream>
using namespace std;
 
class Suma {
public:
    double a;

    Suma(const double x)
    {
        this->a = x;
    }
};
 
Suma& operator +(const Suma &p1,const Suma &p2)
{
  return *(new Suma(p1.a + p2.a) );
}

class Resta {
public:
    double a;

    Resta(const double x)
    {
        this->a = x;
    }
};
 
Resta& operator -(const Resta &p1,const Resta &p2)
{
  return *(new Resta(p1.a - p2.a) );
}


int main()
{
	//Declaracion de Objetos
    Suma A(0);
    Suma B(0);
    
    Resta F(0);
    Resta G(0);
    
    cout<<"\nEscriba 2 Numeros para sumar\n";
    cin>>A.a;
    cin>>B.a;
    
    cout<<"Escriba 2 Numeros para restar\n";
    cin>>F.a;
    cin>>G.a;
    
    Suma C = A + B;
 	Resta H = F - G;
    
    cout << "Suma = " << C.a << "\n";
    cout << "Resta = " << H.a << "\n";
 
    return 0;
}