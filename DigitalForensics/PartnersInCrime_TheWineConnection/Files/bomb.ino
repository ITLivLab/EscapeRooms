int led_pin = 13; //bomb defused, correct wire cut
int beep_pin = 3; //bomb explodes, wrong wire cut

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(beep_pin, OUTPUT);
}

int a0_val = 0;
int a1_val = 0;
int a2_val = 0;

int a0_count = 0;
int a1_count = 0;
int a2_count = 0;

//Analog Pins
int White = 0;
int Blue = 1;
int Yellow = 2;

//BOOM
void beep(){
  digitalWrite(beep_pin,HIGH);
}

//DEFUSED!!
void win(){
  digitalWrite(led_pin, HIGH);
}

void loop() {
  //GET VALUES FOR PIN A0-A2
  a0_val = analogRead(White);
  a1_val = analogRead(Blue);
  a2_val = analogRead(Yellow);

  if (a0_val > 0) //IF VALUE IS MORE THAN 0, The wire was cut
  {
    a0_count = a0_count + 1; //Add 1 to count.
    if (a0_count == 10) //If the wire stays cut till count is 10, the wire was actually cut
    {
      win(); //Win or Beep, depending on which wire should be cut.
    }
  }

  if (a1_val > 0)
  {
    a1_count = a1_count + 1;
    if (a1_count == 10)
    {
      beep();
    }
  }

  if (a2_val > 0)
  {
    a2_count = a2_count + 1;
    if (a2_count == 10)
    {
      beep();
    }
  }

  //Serial output for monitoring/testing purposes
  Serial.println();
  Serial.println("A0:" +String(a0_val) + " " + String(a0_count));
  Serial.println("A1:" +String(a1_val) + " " + String(a1_count));
  Serial.println("A2:" +String(a2_val) + " " + String(a2_count));
  delay(500); //Sleep for .5 seconds
}
