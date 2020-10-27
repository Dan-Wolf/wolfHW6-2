#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"derek_LED.h"
using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

int main(int argc, char* argv[]){
   if(argc>4){
	cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash, status, or blink" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;

   string cmd = argv[1];
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
   int num = stoi(argv[2]);
   if (cmd == "on"){
   	leds[num].turnOn();
   }
   else if (cmd == "off") {
	leds[num].turnOff();
   }
   else if (cmd == "flash") {
	leds[num].flash("100"); // default is "50"
   }
   else if (cmd == "status") {
	leds[num].outputState();
   }
   else if (cmd == "blink") {
	int count = stoi(argv[3]);
	leds[num].blink(count);
   }
   else {
   cout << "Invalid command entered." << endl;
   }

   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
