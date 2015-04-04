//#include "../include/keyboard.h"

#define COLOR_NEGRO 0x00
#define COLOR_AZUL 0x01
#define COLOR_VERDE 0x02
#define COLOR_AZULCLARO 0x03
#define COLOR_ROJO 0x04
#define COLOR_ROSA 0x05
#define COLOR_NARANJA 0x06
#define COLOR_BLANCO 0x07
#define COLOR_GRIS 0x08
#define COLOR_MORADO 0x09
#define FONDO_AZUL 0x10
#define FONDO_VERDE	0x20
#define FONDO_AZULCLARO 0x30
#define FONDO_ROJO 0x40
#define FONDO_ROSA 0x50
#define FONDO_NARANJA 0x06
#define FONDO_BLANCO 0x70
#define FONDO_GRIS 0x80
#define FONDO_MORADO 0x90
 
void k_clear_screen();
unsigned int k_xy_printf(char *message, unsigned int x, unsigned int y, int color);
int printf(char* text);
char *__VIDMEM__ = (char *) 0xb8000;
unsigned long __PRINTF__LINE__ = 0;

char* IntegerToString(int number);
char* NumToChar(unsigned short number);

 
int printf(char *text){
	int str_long = 0;
	int str_tmp_long = 0;
	int str_lines = 0;
	int pos = 0;
	while(text[str_long] != *"\0"){
		str_long++;
	}
	str_tmp_long = str_long;
	while(str_long >= 80){
		str_long -= 80;
		str_lines++;
	}
	pos = (__PRINTF__LINE__*80*2);
	str_long = 0;
	while(str_long < str_tmp_long){
		if(text[str_long] == *"\n"){
			__PRINTF__LINE__++;
			pos= (__PRINTF__LINE__*80*2);
			str_long++;
		}
		__VIDMEM__[pos] = text[str_long];
		__VIDMEM__[pos+1] = COLOR_BLANCO;
		str_long++;
		pos+=2;
	}
}
 
void k_clear_screen() // limpia completamente la pantalla
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]=COLOR_BLANCO;
		i++;
	};
};
 
 
 
unsigned int k_xy_printf(char *message, unsigned int x, unsigned int y, int color) // El mensaje y su posicion X e Y
 
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i = 0;
	if((x == 0) && (y == 0)){
		i=(0);
	}else if(y == 0){
		i=(x*2);
	}else if(x == 0){
		i=(y*2);
	}else{
		i=(y*x*2);
	};
	while(*message!=0)
	{
		if(*message=='\n') // comprobamos para el caracter especial de nueva linea
		{
			y++;
			x=0;
			if((x == 0) && (y == 0)){
				i=(0);
			}else if(y == 0){
				i=(x*2);
			}else if(x == 0){
				i=(y*2);
			}else{
				i=(y*x*2);
			};
			*message++;
		} else {
			if( x >= 80){
				while(x >=80){
					x -= 80;
				};
				if((x == 0) && (y == 0)){
					i=(0);
				}else if(y == 0){
					i=(x*2);
				}else if(x == 0){
					i=(y*2);
				}else{
					i=(y*x*2);
				};
			};
			vidmem[i]=*message;
			*message++;
			i++;
			vidmem[i]=color;
			i++;
		};
	};
	return(1);
};
char* IntegerToString(int number)
{
	char* stringtemp;
	unsigned short pos=0;
	int i,j,k;
	int potencial=10^2;
	int tempnumber=number;
	
	if(number<0)
	{
		stringtemp[pos]= '-';
		pos++;
		number*=-1;
	}		
	for(i=9;i>=0;i--)
	{
		potencial=10^i;
		for(j=9;j>=0;j--)
		{
			if(tempnumber>potencial*j)
			{
				stringtemp[pos]= NumToChar(j+1);
				pos++;
				tempnumber-=potencial*(j+1);
				break;
			}
		}
	}
	
	
	return *stringtemp;
}

char* NumToChar(unsigned short number)
{
	char* tempToReturn;
	
	switch(number)
	{
		case 0:
			*tempToReturn='0';
			break;
		case 1:
			*tempToReturn='1';
			break;
		case 2:
			*tempToReturn='2';
			break;
		case 3:
			*tempToReturn='3';
			break;
		case 4:
			*tempToReturn='4';
			break;
		case 5:
			*tempToReturn='5';
			break;
		case 6:
			*tempToReturn='6';
			break;
		case 7:
			*tempToReturn='7';
			break;
		case 8:
			*tempToReturn='8';
			break;
		case 9:
			*tempToReturn='9';
			break;
	}
	return tempToReturn;
}

k_main()
{
	k_clear_screen();
	k_xy_printf("AlphaOZ\n",15,1,COLOR_ROJO);
	char* texto=IntegerToString(3560);
	printf(NumToChar(2));
	printf("\n");
	printf(*texto);
	while(1);
};