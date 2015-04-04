#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_ARREGLOS 1000

int temp;
class Mainclass{
public:
	int n,r, total,i,j,k,elementos[MAX_ARREGLOS],numlines,InScreenPrint[MAX_ARREGLOS][MAX_ARREGLOS]; 
	void Combine(int* tempnum){
		bool permite=true;
		int matches=0;
		int a;
		matches=0;
		permite=true;
			
		if(numlines==0){
			for(k=0; k<r; k++){
				InScreenPrint[numlines][k]=tempnum[k];
			}
			numlines++; 
		}
		else{
		
		cout << "Lines "<<  numlines<<endl;
			for(i=0; i<numlines; i++){
				
				for(j=0; j<r; j++){
					for(k=0; k<r; k++){
						if(InScreenPrint[i][j]==tempnum[k]){
							matches++; 
							
						}
						//cout<<"Match: "<<matches<<":"<<endl;
						cout<< k<< ".- " <<InScreenPrint[i][j]<<" : "<< tempnum[k]<<endl;
						//cin >>a;
					}
					if(matches>=r){
						
						permite=false;
						break;
					};    
				}
				//////////////////////////////////////////////////
				if(permite){
					for(k=0; k<r; k++){
						//cout<<matches<<":"<<endl;
						//cin>>a;
						InScreenPrint[numlines][k]=tempnum[k];
					}
					numlines++; 
					
				}
				//////////////////////////////////////////////////////
				
				
			}

		} 
	} 
	
	
	
	
///////**//////////////////////
	void process(int* P, int N, int* total) { 
		/*int i;  
		for (i=N; i>0; i--) {
			printf("%d ", P[i]);
		}  
		printf("\n");
		(*total) ++;*/
		
		Combine(P);
		
	}

	void swap(int *x, int *y) { 
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	

	void reverse (int *P, int N) {
		int i = 1;  
		while ( i < (N+1-i) ) {
			swap(&P[i], &P[N+1-i]);
			i ++;
		}
	}
	
	int B(int N, int c) {  
		return ( (N % 2) != 0 ? 1 : c );
	}

	void lexperms (int *P, int N, int *total) {
		
		int i;
		int c[N];
		for (i = N; i > 1; i --) {
			c[i] = 1;
		}
		i = 2;
		
		process(P,N,total);   
		do {
			if (c[i] < i) {
				swap(&P[i],&P[c[i]]);
				reverse(P,i-1); /* inversion parcial! */
				process(P,N,total);
				c[i] ++;
				i = 2;
			} else {
				c[i] = 1;
      i ++;
    }
  } while (i <= N);
}
///////**//////////////////////
	
	void Filter(){
		int fil, x,num;
		bool encontro=false;
		cout <<"Ingrese El elemento a filtrar : ";
		cin>>fil;
		for(j=0; j<total; j++){
			for(x=0; x<r; x++){
				if(InScreenPrint[j][x]==fil)
					encontro=true;
			}    
			if(encontro){
				PrintLine(j);
				num++;
				encontro=false;             
			}   
		}    
		if(num==0){
			cout<<"Error: no se encontro ninguna conicidencia"<< endl;
		}
	}
/*
	int Calc(int tempn,int nf, int tempr){
		total=nf/(numFactorial(tempr)*numFactorial(tempn-tempr));
		cout <<"Total de combinaciones: " <<total<<endl;
	}*/
	
	int Factorial(int num){
		int ToReturn=1;
		for(i=1; i<=num; i++){
			ToReturn*=i;      
		}
		return ToReturn;
	} 
	int randint(int min, int max)
	{
		int rango = (max-min)+1;
		//cout << rango << " ";
		int factor = RAND_MAX/rango;
		//cout << factor << " " << RAND_MAX<< " ";
		int temprand= rand();
		//cout << temprand << " ";
		int a = temprand/factor;
		
		return a;
		
	}
	void PrintLine(int line){
		cout<<line+1<<":  ";
		for(i=0; i<r; i++){
			cout << InScreenPrint[line][i]<<"-";
		}     
		cout << endl;
	}
	
	
	void PrintAllLines(){
		for(j=0; j<total; j++){
			PrintLine(j);     
		}
	}

	void Calc_Combinations(){
		total= Factorial(n)/(Factorial(r)*Factorial(n-r)); 
		cout << "Total de Combinaciones: " << total<< endl;
		
	}  
	
    
	void InputA(){
		r=1;
		while(r>n){
			system("cls");
			cout << "Ingrese el numero de Total de Elementos (n) (maximo: "<< MAX_ARREGLOS<< ") : ";
			cin >>n;
			cout << "Ingrese el numero de elementos muestra (r) (maximo: "<< MAX_ARREGLOS<< ") : ";
			cin >>r;
			if(r>n) cout << "Error: el valor de r no puede ser mayor que el de n"<< endl; 
		}
		for(i=0; i<n; i++){
			cout << "Ingrese el elemento #" << i+1<<": ";
			cin >> elementos[i];
			for(j=0; j<i; j++){
				if(elementos[j]==elementos[i]){
					cout << "Error: No Pueden repetirse los elementos"<<endl;
					i--;
					break;                               
				}         
				
			}         
			
		}
		
	}	  
	void InputB(){
		r=1;
		while(r>n){
			cout << "Ingrese el numero de Total de Elementos (n) (maximo: "<< MAX_ARREGLOS<< ") : ";
			cin >>n;
			cout << "Ingrese el numero de elementos muestra (r) (maximo: "<< MAX_ARREGLOS<< ") : ";
			cin >>r;
			if(r>n) cout << "Error: el valor de r no puede ser mayor que el de n"<< endl; 
		}
		for(i=0; i<n; i++){
			elementos[i]=i+1;      
		}
	}
		  

};


int main(){
    int Selection;
	Mainclass ObjectA;
	srand((unsigned)time(0)); 
inicio:
    system("cls");
    cout<< "Seleccione Version del Programa (1 o 2) :";
    cin >>Selection;
	
	
    if(Selection==1){
		ObjectA.InputA();
    }
    else if(Selection==2){
		ObjectA.InputB();
    }
    else{
        cout<<"Error Seleccione otravez"<<endl;
        system("pause");
        goto inicio;     
    }
    ObjectA.Calc_Combinations();
	ObjectA.lexperms(ObjectA.elementos,ObjectA.n-1,&temp);
	ObjectA.PrintAllLines();
    return 0;   
}
