#include "USBInterfaceClass.h"
using namespace std;

int main(int argc, char *argv[])
{
	
	USBInterface USB;
	USB.EnumerateHIDs();
    USB.HIDOpen(0x3995,0x0001);	
    USB.HIDDescription();	
	USB.SendOutputPort((unsigned char) 0x01);
    usleep(1000000);
    USB.SendOutputPort((unsigned char) 0x02);
    usleep(1000000);	
	
    USB.ReciveBuffer();
    USB.PrintBufferIN();
    usleep(20000);
    USB.ReciveBuffer();
    USB.PrintBufferIN();
    	
    system("PAUSE");
    return EXIT_SUCCESS;
}
