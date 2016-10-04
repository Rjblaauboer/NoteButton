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
    int _pin; 
    int _note; 
    bool _isOn;
    void noteOn();
    void noteOff();
 };
#endif