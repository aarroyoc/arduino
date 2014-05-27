#include <iostream>
#include <string>
#include <unistd.h>
#include <SerialStream.h>

using namespace std;
using namespace LibSerial;

int main (int argc, char **argv) {

    int oc; 
    string dev;
    bool dsp = false;
    while ((oc = getopt(argc, argv, ":d:")) != -1) {
        switch(oc) {
            case 'd':
                //device
                cout << "Dispositivo: ";
                dev = optarg;
                cout << " :: " << dev << endl;
                dsp = true;
                break;
            case ':':
                cerr << "Missing argument " << endl;
                return -1;
                break;
        }
    }    
    
    if (!dsp) {
        dev = "/dev/ttyACM0";
    }
    SerialStream serial_port(dev,std::ios_base::out);
    serial_port.SetBaudRate(SerialStreamBuf::BAUD_57600);
    serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8);

    char num;
    while (1) {
        cout << "Number of blinks? : ";
        cin >> num;
        serial_port << num;
    }
    return 0;
}
