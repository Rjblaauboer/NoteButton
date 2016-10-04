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
 	//Check the associated digital pin
 	int buttonState = digitalRead( _pin );
 	bool currentState = _isOn;
 	if ( buttonState == HIGH ) {
 		_isOn = true; 
 	} else {
 		_isOn = false;
 	}

 	//If the button state is different than the current state
 	//turn the note on or off depending on the new state
 	if( currentState != _isOn ){
 		if( _isOn )
 		{
 			noteOn();
 		} else {
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