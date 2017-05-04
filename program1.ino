void setup()
{
  Serial.begin(9600);
}

//This defined the serial begin for the Arduino’s serial 
//monitor which is 9600. And below it in the loop the serial 
//will ask the user to input an integer.

void loop()
{
  Serial.print("Please input an integer : ");
  Serial.println(readInt());
}

//After that, created a function with the signature “int readInt(void)” .
int readInt(void)
{
  
  //First of all I set up the input data which is 30 and defined
 // integer I =0, and made a loop until we break at new line.
  char input[30];
  int i = 0;

  while (true)
  {
    if (Serial.available() > 0)
    {
      char Character = Serial.read();

      if (Character == '\n')
      {
        input[i] = 0;
        break;
      }
      
      else
      {
        input[i] = Character;
        i++;
      }
    }
  }
  return atoi(input);
}
