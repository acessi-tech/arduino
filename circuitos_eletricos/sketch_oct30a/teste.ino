int buttonPin1 = 2;  // the number of the pushbutton pin
int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonPin2 = 3; // sum button
int buttonState2 = 0; // sum button's state

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
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop(){
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == HIGH) {
    rawData = analogRead(analogPin2);
    if(rawData){
      buffer2 = rawData * Vin;
      Vout = (buffer2)/1024.0;
      buffer2 = (Vin/Vout) - 1;
      H3 = Ref * buffer2;
//      Serial.print("Vout: ");
//      Serial.println(Vout);
      for(int i=1; i<11; i++){
        int b = 0;
        b = i * 1000;
        if((b+600) > H3 && (b-600) < H3){
          switch(b){
            case 10000:
              H3 = 0;
              Serial.println("zero centenas");
              delay(500);
              break;
            case 9000:
              H3 = 1;
              Serial.println("uma centena");
              delay(500);
              break;
            case 8000:
              H3 = 2;
              Serial.println("duas centenas");
              delay(500);
              break;
            case 7000:
              H3 = 3;
              Serial.println("três centenas");
              delay(500);
              break;
            case 6000:
              H3 = 4;
              Serial.println("quatro centenas");
              delay(500);
              break;          
            case 5000:
              H3 = 5;
              Serial.println("cinco centenas");
              delay(500);
              break;          
            case 4000:
              H3 = 6;
              Serial.println("seis centenas");
              delay(500);
              break;          
            case 3000:
              H3 = 7;
              Serial.println("sete centenas");
              delay(500);
              break;          
            case 2000:
              H3 = 8;
              Serial.println("oito centenas");
              delay(500);
              break;   
            case 1000:
              H3 = 9;
              Serial.println("nove centenas");
              delay(500);
              break;                
            }
          }
        }
    }
    rawData = analogRead(analogPin1);
    if(rawData){
      buffer1 = rawData * Vin;
      Vout = (buffer1)/1024.0;
      buffer1 = (Vin/Vout) - 1;
      H2 = Ref * buffer1;
//      Serial.print("Vout: ");
//      Serial.println(Vout);
      for(int i=1; i<11; i++){
        int b = 0;
        b = i * 1000;
        if((b+600) > H2 && (b-600) < H2){
          switch(b){
            case 10000:
              H2 = 0;
              Serial.println("zero dezenas");
              delay(500);
              break;
            case 9000:
              H2 = 1;
              Serial.println("uma dezena");
              delay(500);
              break;
            case 8000:
              H2 = 2;
              Serial.println("duas dezenas");
              delay(500);
              break;
            case 7000:
              H2 = 3;
              Serial.println("três dezenas");
              delay(500);
              break;
            case 6000:
              H2 = 4;
              Serial.println("quatro dezenas");
              delay(500);
              break;          
            case 5000:
              H2 = 5;
              Serial.println("cinco dezenas");
              delay(500);
              break;          
            case 4000:
              H2 = 6;
              Serial.println("seis dezenas");
              delay(500);
              break;          
            case 3000:
              H2 = 7;
              Serial.println("sete dezenas");
              delay(500);
              break;          
            case 2000:
              H2 = 8;
              Serial.println("oito dezenas");
              delay(500);
              break;   
            case 1000:
              H2 = 9;
              Serial.println("nove dezenas");
              delay(500);
              break;                
            }
          }
        }
    }
    rawData = analogRead(analogPin0);
    if(rawData){
      buffer = rawData * Vin;
      Vout = (buffer)/1024.0;
      buffer = (Vin/Vout) - 1;
      H1= Ref * buffer;
      for(int i=1; i<11; i++){
        int a = 0;
        a = i * 1000;
        if((a+600) > H1 && (a-600) < H1){
          switch(a){
            case 10000:
              H1 = 0;
              Serial.println("zero unidades");
              delay(500);
              break;
            case 9000:
              H1 = 1;
              Serial.println("uma unidade");
              delay(500);
              break;
            case 8000:
              H1 = 2;
              Serial.println("duas unidades");
              delay(500);
              break;
            case 7000:
              H1 = 3;
              Serial.println("três unidades");
              delay(500);
              break;
            case 6000:
              H1 = 4;
              Serial.println("quatro unidades");
              delay(500);
              break;          
            case 5000:
              H1 = 5;
              Serial.println("cinco unidades");
              delay(500);
              break;          
            case 4000:
              H1 = 6;
              Serial.println("seis unidades");
              delay(500);
              break;          
            case 3000:
              H1 = 7;
              Serial.println("sete unidades");
              delay(500);
              break;          
            case 2000:
              H1 = 8;
              Serial.println("oito unidades");
              delay(500);
              break;   
            case 1000:
              H1 = 9;
              Serial.println("nove unidades");
              delay(500);
              break;                
            }
          }
        }
    }
  }
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH){
    Serial.print((int)(H1+(H2*10)+(H3*100)));
    delay(500);
  }
}
