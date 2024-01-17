#include "SevSeg.h"  /* Include seven-segment library */
SevSeg sevseg;       /* Seven Segment Variable */
int state1;          /* Variable to store pushbutton state */
int count = 0;       /* Variable that will store the counter value */
#define button1 12     /* Arduino Nano pin for pushbutton */

void setup() {
  pinMode(button1, INPUT_PULLUP);  /* Assign the button as input */
  
  byte sevenSegments = 1;   /* Number of seven segments being used */
  byte CommonPins[] = {};   /* Define common pins (none for common anode) */
  byte LEDsegmentPins[] = {2, 3, 4, 5, 6, 7, 8};  /* Arduino Nano digital pins defined for seven-segment sequence pins a to g */
  bool resistorsOnSegments = true;
  
  sevseg.begin(COMMON_ANODE, sevenSegments, CommonPins, LEDsegmentPins, resistorsOnSegments); /* Configuration of the seven-segment */
  sevseg.setBrightness(80);  /* Brightness of the seven-segment display */
}

void loop() {
  state1 = digitalRead(button1);  /* Read the pushbutton state */

  if (state1 == LOW) {  /* LOW state when the pushbutton is pressed */
    count++;  /* Increase the display value by 1 */
    sevseg.setNumber(count);  /* Display the count value on the seven-segment */
    sevseg.refreshDisplay();  /* Refresh the seven-segment display */
    delay(300);  /* Delay for a short period to debounce the button */
  }

  if (count == 10) {
    count = 0;  /* Reset the count when it reaches 10 */
  }

  sevseg.setNumber(count);  /* Display the count value on the seven-segment */
  sevseg.refreshDisplay();  /* Refresh the seven-segment display */
}
