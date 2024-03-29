#include <Keyboard.h>
#include <Mouse.h>

#define BUTTON_PIN 2

char ctrlKey = KEY_LEFT_CTRL;  

// Needed to change this sketch to use a normally closed button that someone installed in the sim.
// If someone replaces it with a normally open button, delete the exclamation mark in front of digitalRead on line 22

void setup() 
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
	
  // initialize control over the keyboard:
  Keyboard.begin();
  Mouse.begin();  
}

void loop()
{
  if (!digitalRead(BUTTON_PIN)) 
  {
    // do nothing until pin 2 goes low
    delay(50);
  }
  else 
  {
    sendAssettoCorsaResetHotkey();
  
	  moveMouseToUpperRightOfScreen();

	  clickRaceStartButton();
		
	  delay(2000);
  }
}

void sendAssettoCorsaResetHotkey()
{
  delay(10);
  Keyboard.press(0x80); // left ctrlkey
  delay(50);
  Keyboard.press('o');
  delay(20);
  Keyboard.releaseAll();
  
  delay(1000); // wait time for game to reset
}

void moveMouseToUpperRightOfScreen()
{
  for(int i = 0; i < 20; i++)
  {
    Mouse.move(127,-127,0);
    delay(5);
  }
}

void clickRaceStartButton()
{
  for(int i = 0; i < 6; i++)
  {
    Mouse.move(-125,12,0);
    delay(5);
  }

  delay(50);

  Mouse.click();
}