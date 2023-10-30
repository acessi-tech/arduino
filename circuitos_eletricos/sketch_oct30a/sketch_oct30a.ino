
int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;  // variable for reading the pushbutton status

int analogPin0 = 0;
int analogPin1 = 1;
int analogPin2 = 2;
int rawData = 0;
int Vin = 5;
float Vout = 0;
float Ref = 1000;
float H1, H2, H3 = 0;
float buffer, buffer1, buffer2 = 0;

void setup(){
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    rawData = analogRead(analogPin0);
    if(rawData){
      buffer = rawData * Vin;
      Vout = (buffer)/1024.0;
      buffer = (Vin/Vout) - 1;
      H1= Ref * buffer;
//      Serial.print("Vout: ");
//      Serial.println(Vout);
      Serial.print("H1: ");
      Serial.println(H1);
      delay(100);
    }
    rawData = analogRead(analogPin1);
    if(rawData){
      buffer1 = rawData * Vin;
      Vout = (buffer1)/1024.0;
      buffer1 = (Vin/Vout) - 1;
      H2 = Ref * buffer1;
//      Serial.print("Vout: ");
//      Serial.println(Vout);
      Serial.print("H2: ");
      Serial.println(H2);
      delay(100);
    }
    rawData = analogRead(analogPin2);
    if(rawData){
      buffer2 = rawData * Vin;
      Vout = (buffer2)/1024.0;
      buffer2 = (Vin/Vout) - 1;
      H3 = Ref * buffer2;
//      Serial.print("Vout: ");
//      Serial.println(Vout);
      Serial.print("H3: ");
      Serial.println(H3);
      delay(100);
    }
    Serial.println("");
  }
}
