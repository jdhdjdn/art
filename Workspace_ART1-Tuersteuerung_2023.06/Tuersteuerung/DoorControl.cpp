/*
 * Praktikum MRT2 
 * ART1 Türsteuerung
 * Institut für Automatisierungstechnik
 * letztes Update Mai 2018
 * Autor: M.Herhold
 * Version: r2
 */

#include "DoorInterface.h"
#include "DoorControl.h"


DoorControl::DoorControl() : door_if(false, true)
{
	// constructor
	// ... maybe, insert your sensor and actor initialization here?
}

DoorControl::~DoorControl()
{
	// destructor
	door_if.quit_doorcontrol_flag = true;
}

void DoorControl::run()
{
	// ... insert your main loop here ...
	// example:

	std::string msg;		// temporary variable to construct message
	unsigned max_count = 1000;	// loop this often
	unsigned delay_ms = 20;		// Milliseconds to wait on one loop
	
	for(unsigned i=0; !door_if.quit_doorcontrol_flag && i < max_count; i++){

		//construct counter message
		msg = "press 'q', or wait ";
		msg += std::to_string((int)((max_count-i) / (1000/delay_ms) + 1));
		msg += " seconds to quit";

		// set current message to be displayed by user interface
		door_if.DebugString(msg);

		// wait some time
		usleep(delay_ms * 1000);
	}
}
