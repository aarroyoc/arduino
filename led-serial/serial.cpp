#include <SerialStream.h>
#include <iostream>

using namespace LibSerial;

int main(int argc, char** argv)
{
	char parpadeos[256];
	SerialStream arduino("/dev/ttyACM0", std::ios_base::out);
	arduino.SetBaudRate(SerialStreamBuf::BAUD_57600);
	arduino.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
	arduino.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);
	arduino.SetParity(SerialStreamBuf::PARITY_NONE);
	arduino.SetNumOfStopBits(1);
	while(1){
		std::cout << "Parpadeos?" << std::endl;
		std::cin >> parpadeos;
		arduino << parpadeos;
	}
	/*const int Dsize = 2;
        char buffer[1];
        buffer[0] = 125; //0b00000001;
        buffer[1] = '\0';
        bitset(buffer[0]);
        //myss << buffer;
        myss.write(buffer,1);*/
	return 0;
}
