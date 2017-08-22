

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

String inputString = "";         // a string to hold incoming data
String firstString = ""; 
String secondString = "";
String thirdString = "";
String fourthString = ""; 
String fifthString = ""; 
boolean stringComplete = false;  // whether the string is complete
boolean firstComplete = false;
boolean secondComplete = false;
boolean thirdComplete = false;
boolean fourthComplete = false;
boolean fifthComplete = false;

void setup() {

// set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  
  
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  

}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();

    if (inChar == '!') {
      firstComplete = true;
      firstString = inputString.substring(0, inputString.length());
      inputString = "";
      
    }

    if (inChar == '@') {
      secondComplete = true;
      secondString = inputString.substring(1, inputString.length());
      inputString = "";
      
    }

     if (inChar == '#') {
      thirdComplete = true;
      thirdString = inputString.substring(1, inputString.length());
      inputString = "";
      
    }

    if (inChar == '$') {
      fourthComplete = true;
      fourthString = inputString.substring(1, inputString.length());
      inputString = "";
      
    }
    
    if (inChar == '%') {
      fifthComplete = true;
      fifthString = inputString.substring(1, inputString.length());
      inputString = "";
      
    }
    
    
    if (inChar == '\n') {
      stringComplete = true;
      lcd.clear();
      lcd.print("CPU: ");
      lcd.print(firstString);
      lcd.print("C");

      lcd.setCursor(0,1);
      lcd.print("GPU: ");
      lcd.print(secondString);
      lcd.print("C");

      lcd.setCursor(0,2);
      lcd.print("RAM: ");
      lcd.print(thirdString);

      lcd.setCursor(0,3);
      lcd.print("TIME: ");
      lcd.print(fourthString);
      //lcd.print("Watts");
      
      lcd.setCursor(11,0);
      lcd.print("Mario S.");
      //lcd.print(fourthString);
      //lcd.print("Watts");
      
      lcd.setCursor(11,1);
      lcd.print(fifthString);
      //lcd.print(fourthString);
      //lcd.print("Watts");
      
      
    } else {
      // add it to the inputString:
    inputString += inChar;
    }
  }

  
}


