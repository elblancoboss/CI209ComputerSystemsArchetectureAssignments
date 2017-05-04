void setup()
{
  Serial.begin(9600);
}

//the serial monitor will print out a question to the user asking 
//to input BR in range -3276 to 32767 and the same for inputting 
//AD, finally it will ask to input a number in range 1 to 8 which 
//will translate the answers in the serial monitor.

void loop() {
Serial.print("Input BR in range -32768 to 32767 : ");
int numberInputBR = readInt();
Serial.println(numberInputBR);

Serial.print("Input AD in range -32768 to 32767 : ");
int numberInputAD = readInt();
Serial.println(numberInputAD);

Serial.print("Input n   in range 1 to 8          : ");
int n = readInt();
Serial.println(n);

trace(numberInputBR, numberInputAD, n);
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

//In void trace function I defined integer A and B,
//integer B is BR which right shifts to 8 and the same 
//for integer A and AD. The serial monitor will then 
//print the number plus the string number, and after 
//that will print the values for each “AD, B, A, and BR”
//and will print 2 new lines to separate from the next input.

void trace(word BR, word AD, byte n)
{
int B = BR >> 8;
int A = AD >> 8;

Serial.println();
Serial.print("n=" + (String)n);
Serial.print(decimalToBinary(" D=", AD));
Serial.print(decimalToBinary(" B=", B));
Serial.print(decimalToBinary(" A=", A));
Serial.print(decimalToBinary(" R=", BR));
Serial.println();
Serial.println();
}
