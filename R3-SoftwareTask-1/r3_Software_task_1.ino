// C++ code
//
int map_val = 0;

//binary digits are required as the decoder is BCD (Binary Coded Decimal)
byte digits[2];

int counter;

int counter2;

void setup()
{}

void loop()
{
  //reading potentiometer output and mapping it to to a value between 0-99
  int reading = analogRead(A1);
  map_val = map(reading, 0, 1023, 0, 99);
  
  //simple nested array with the 2 decoders and the pins they're connected to
  int digit_output[2][4] = {
    {2, 3, 4, 5}, 
    {8, 9, 10, 11},
  };
  
  //digit manipulation
  for (int i = 0; i < 2; i++){
  	digits[i] = map_val % 10;
    map_val/=10;
  }
  
  for (int i = 0; i < 2; i++) {  //to access each of the 2 7-seg display
    for (int j = 0; j < 4; j++) { //4 bits is all the decoder can take since it has 4 input pins
      
      //"writing" to the appropriate decoder pin each bit that is then converted to the appropriate number
      digitalWrite(digit_output[i][j], bitRead(digits[i], j));
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}