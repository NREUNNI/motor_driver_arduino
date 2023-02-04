  const int Joystick_X = A0;
  const int Joystick_Y = A1;

  int pin_giro = 13;
  bool estado_giro= false;
  int led_pin = 6;
  int incremento = 5;
  int tiempo = 100;

  int valor_X;
  int valor_Y;

  int valor_Xv;
  int valor_Yv;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(pin_giro, OUTPUT);

}

void loop() {

  valor_X=analogRead(Joystick_X);
  valor_Y=analogRead(Joystick_Y);
  valor_Xv = fmap(valor_X, 0, 1023, 0.0, 5.0);
  //valor_Yv = fmap(valor_Y, 0, 1023, 0.0, 5.0);

  if(valor_Y >507){
    estado_giro=true;
    digitalWrite(pin_giro,estado_giro);
    valor_Yv = fmap(valor_Y, 507, 1023, 0, 255);
    marcha_motor(estado_giro,valor_Yv);
    }
  else{
    estado_giro=false;
    digitalWrite(pin_giro,estado_giro);
    valor_Yv = fmap(valor_Y, 0, 507, 255, 0);
    marcha_motor(estado_giro,valor_Yv);
    }
  Serial.println("X ="+String(valor_Xv) +" Y = "+String(valor_Yv));



  /*
  digitalWrite(pin_giro,LOW);
  for(int dutyCycle =0; dutyCycle<=255;dutyCycle++){
    analogWrite(led_pin,dutyCycle);
    delay(tiempo);
  }
  delay(1000);
  digitalWrite(pin_giro,HIGH);
    for(int dutyCycle =255; dutyCycle>=0;dutyCycle--){
    analogWrite(led_pin,dutyCycle);
    delay(tiempo);
  }
  */

}

// cambio de escala entre floats
int fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void marcha_motor(bool sentido, int Joystick_value){
digitalWrite(pin_giro,sentido);
analogWrite(led_pin,Joystick_value);
}
