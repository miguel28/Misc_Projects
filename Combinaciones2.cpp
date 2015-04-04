#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;
 
class Mainclass{
public:
	int i,n,r,total;
	int elementos[100];
	string InScreenToWrite[100];
	
	void Input(){
		
		system("clear");
		system("cls");

		cout << "Insete el numero Total de elementos (n) :";
		cin>>n;	
		cout << "Insete el numero de elementos de la muestra a tomar (r) (maximo 10): ";
		cin>>r;
		if(r>n){
			cout << "Error: el valor de (r) no puede ser mayor al de (n)"<<endl;
			exit(1);
		}
		
		for(i=0;i<n;i++)
		{
			cout << "Ingrese numero " << i+1<< ": ";
			cin>> elementos[i];
			
		}
		
	}
	int numFactorial(int num){
		int factorial=1;
		for (i=1; i<=num;i++){
			factorial*=i;
			
		}
		return factorial;	
	}
	int Calc(int tempn,int nf, int tempr){
		total=nf/(numFactorial(tempr)*numFactorial(tempn-tempr));
		cout <<"Total de combinaciones: " <<total<<endl;
	}
	
	int PrintCombinations(){
		int numcom=0;
		/*char format[400];
		for(i=0;i<=r;i++){
			format[poscount]='%';
			format[poscount+1]='d';
			poscount+=2;
		}format[poscount+1]='\0';*/
		
		
		while(numcom!=total){
			
			
			
		}
	}
	
	/*
	void numComvinaciones(){
		int a,b,c,d,e,f,g,h,j,k;
		cout << "Todas las combinaciones posibles: "<<endl;
		for (a=0; a<r;a++){
			if(r==1){
				cout << elementos[a];
				cout << " ";
			}
			else {
				for (b=0; b<r;b++){
					if(r==2){
						cout << elementos[a];
						cout << elementos[b];
						cout << " ";
					}
					else {
						for (c=0; c<r;c++){
							if(r==3){
								cout << elementos[a];
								cout << elementos[b];
								cout << elementos[c];
								cout << " ";
							}
							else {
								for (d=0; d<r;d++){
									if(r==4){
										cout << elementos[a];
										cout << elementos[b];
										cout << elementos[c];
										cout << elementos[d];
										cout << " ";
									}
									else {
										for (e=0; e<r;e++){
											if(r==5){
												cout << elementos[a];
												cout << elementos[b];
												cout << elementos[c];
												cout << elementos[d];
												cout << elementos[e];
												cout << " ";
											}
											else {
												for (f=0; f<r;f++){
													if(r==6){
														cout << elementos[a];
														cout << elementos[b];
														cout << elementos[c];
														cout << elementos[d];
														cout << elementos[e];
														cout << elementos[f];
														cout << " ";
													}
													else {
														for (g=0; g<r;g++){
															if(r==7){
																cout << elementos[a];
																cout << elementos[b];
																cout << elementos[c];
																cout << elementos[d];
																cout << elementos[e];
																cout << elementos[f];
																cout << elementos[g];
																cout << " ";
															}
															else {
																for (h=0; h<r;h++){
																	if(r==8){
																		cout << elementos[a];
																		cout << elementos[b];
																		cout << elementos[c];
																		cout << elementos[d];
																		cout << elementos[e];
																		cout << elementos[f];
																		cout << elementos[g];
																		cout << elementos[h];
																		cout << " ";
																	}
																	else {
																		for (j=0; j<r;j++){
																			if(r==8){
																				cout << elementos[a];
																				cout << elementos[b];
																				cout << elementos[c];
																				cout << elementos[d];
																				cout << elementos[e];
																				cout << elementos[f];
																				cout << elementos[g];
																				cout << elementos[h];
																				cout << elementos[j];
																				cout << " ";
																			}
																			else {
																				for (k=0; k<r;k++){
																					cout << elementos[a];
																					cout << elementos[b];
																					cout << elementos[c];
																					cout << elementos[d];
																					cout << elementos[e];
																					cout << elementos[f];
																					cout << elementos[g];
																					cout << elementos[h];
																					cout << elementos[j];
																					cout << elementos[k];
																					cout << " ";
																				}
																			}

																			
																		}
																	}

																	
																}
															}

															
														}
													}

													
												}
											}

											
										}
									}
									
								}
							}
							
						}
					}

									
				}
			}

			
			
		}	
		cout << endl;
	}*/
	
};

int main()
{
	Mainclass obj;
	obj.Input();
	obj.Calc(obj.n,obj.numFactorial(obj.n),obj.r);
	obj.numComvinaciones();
	
	
    return 0;
}