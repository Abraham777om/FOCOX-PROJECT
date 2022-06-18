#define LEDVERDE1 2
#define LEDAMARILLO1 3
#define LEDROJO1 4
#define LEDVERDE2 5
#define LEDAMARILLO2 6
#define LEDROJO2 7
#define PULSADOR1 8
#define PULSADOR2 9
 

bool activo1 = true;
int tiempoCambio = 1500; 
int tiempoEspera = 5000; 
 
void setup() {
  Serial.begin(9600);
 
  pinMode(LEDVERDE1, OUTPUT);
  pinMode(LEDAMARILLO1, OUTPUT);
  pinMode(LEDROJO1, OUTPUT);
  pinMode(LEDVERDE2, OUTPUT);
  pinMode(LEDAMARILLO2, OUTPUT);
  pinMode(LEDROJO2, OUTPUT);
  pinMode(PULSADOR1, INPUT);
  pinMode(PULSADOR2, INPUT);
 
  digitalWrite(LEDVERDE1, LOW);
  digitalWrite(LEDAMARILLO1, LOW);
  digitalWrite(LEDROJO1, LOW);
  digitalWrite(LEDVERDE2, LOW);
  digitalWrite(LEDAMARILLO2, LOW);
  digitalWrite(LEDROJO2, LOW);
 
 
  digitalWrite(LEDVERDE1, HIGH);
  digitalWrite(LEDROJO2, HIGH);
}
 
void loop() {
  if (activo1)
  {
    int valor2 = digitalRead(PULSADOR2);
 
    if (valor2 == HIGH)
    {
      ecenderSemaforo2();
      activo1 = false;
    }
  }
  else
  {
    int valor1 = digitalRead(PULSADOR1);
 
    if (valor1 == HIGH)
    {
      
      ecenderSemaforo1();
      activo1 = true;
    }
  }
}
 
void ecenderSemaforo2()
{
  delay(tiempoEspera);

  digitalWrite(LEDVERDE1, LOW);
  digitalWrite(LEDAMARILLO1, HIGH);

  delay(tiempoCambio);
  
  digitalWrite(LEDAMARILLO1, LOW);
  digitalWrite(LEDROJO1, HIGH);
 
  delay(tiempoCambio);
 
  digitalWrite(LEDROJO2, LOW);
  digitalWrite(LEDVERDE2, HIGH);
}
 
void ecenderSemaforo1()
{
  delay(tiempoEspera);
 
  digitalWrite(LEDVERDE2, LOW);
  digitalWrite(LEDAMARILLO2, HIGH);
 
  delay(tiempoCambio);
 
  digitalWrite(LEDAMARILLO2, LOW);
  digitalWrite(LEDROJO2, HIGH);
 
  delay(tiempoCambio);
 
  digitalWrite(LEDROJO1, LOW);
  digitalWrite(LEDVERDE1, HIGH);
}
