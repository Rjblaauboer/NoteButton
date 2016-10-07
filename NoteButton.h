/*
 * NoteButton.h - Library for checking digitalpins and sending out midi notes 
 */

 #ifndef NoteButton_h
 #define NoteButton_h

 #include "Arduino.h"

 class NoteButton
 {
  public: 
    NoteButton(int pin, int note);
    void update();
  private: 
  	//The pushbutton digital pin
    int _pin; 
    //Midi note sent by this button
    int _note; 
    bool _isOn;
    long _lastSwitchTime = 0; 
    long _debounceDelay = 10;
    void noteOn();
    void noteOff();
 };
#endif