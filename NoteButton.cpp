/* 
 * NoteButton.cpp - Library for checking digitalpins and sending out midi notes
 */

 #include "Arduino.h"
 #include "NoteButton.h"

 NoteButton::NoteButton(int pin, int note)
 {
 	//initialize the indicated digitalPin as an input 
 	pinMode( pin, INPUT );
 	_pin = pin; 
 	_note = note; 
 	_isOn = false;
 }

 void NoteButton::update()
 {	

 	//if enough time has passed since the previous switch to 
 	//allow for debouncing
 	if( millis() + _debounceDelay > _lastSwitchTime ){
	 	//Check the associated digital pin
	 	int currentButtonState = digitalRead( _pin );
	 	bool previousButtonState = _isOn;
	 	//Send note on midi event if the button was pressed (LOW->HIGH) 
	 	if ( previousButtonState == false && currentButtonState == HIGH ) {
	 		_isOn = true; 
	 		noteOn();
	 	} else if( previousButtonState == true && currentButtonState == LOW) {
	 	//Send note off midi event if the button was pressed (HIGH->LOW) 	
	 		_isOn = false;
	 		noteOff();
	 	}
	} 
 }

 // Sends a Note Off Midi message.
 void NoteButton::noteOff()
 { 
   int channel = 0;
   Serial.write(0x80 | channel);
   Serial.write( _note );
   Serial.write( 127 );
 };

//Sends a Note On Midi message.
 void NoteButton::noteOn()
 {
   int channel = 0;
   Serial.write(0x90 | channel);
   Serial.write( _note );
   Serial.write( 127 );
 };