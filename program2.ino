void setup() {
  Serial.begin(9600);
}

// First of all we are going to print out the question to the user 
//asking to input an integer in range -128 to 127. After that I 
//defined the integer numberInput which will read in the integer, 
//and will print out the message and binary number, and lastly will 
//print out the input number at the end.

void loop() {
  Serial.print("Please input an integer in range -128 to 127 : ");

  int numberInput = readInt();
  Serial.print(decimalToBinary("bin=", (byte)numberInput));
  Serial.println(numberInput);
}

int readInt(void)
{
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

//in the decimalToBinary string, I set up variables which are
//“binaryValue” and “finalValue” and will loop them through 8
//times which is the size of a binary value. The right bit shift
//will check the bit number if it’s 1 or 0 and then it will add 1
//to the end of array which is an increment and also it will add 0 
//to the end of the array which is also an increment. After that we
//will sort the binary array into a string (right to left) and will
//return the message and binary value followed by a space.

String decimalToBinary(String message, byte n)
{
  String binaryValue[8] = "";
  String finalValue = "";

  for (int i = 0; i < 8; i++)
  {
    int bit = n >> i;
    if (bit & 1)
    {
      binaryValue[i] += "1";
    }
    else
    {
      binaryValue[i] = "0";
    }
  }
  for (int i = 0; i < 8; i++)
  {
    finalValue += binaryValue[7 - i];
  }
  return message + finalValue + " ";
}

