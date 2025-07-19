int LED1 = D0;
int LED2 = D1;
int LED3 = D2;

int BUT1 = D3;
int BUT2 = D4;
int BUT3 = D5;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);

  pinMode(LED1, INPUT);
  pinMode(LED2, INPUT);
  pinMode(LED3, INPUT);
  
  long startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  long but1time;
  long but2time;
  long but3time;

  // logging whether button was pressed
  if (digitalRead(BUT1) == HIGH) {
    but1time = millis();
  } else {
    but1time = 0;
  }
  if (digitalRead(BUT2) == HIGH) {
    but2time = millis();
  } else {
    but2time = 0;
  }
  if (digitalRead(BUT3) == HIGH) {
    but3time = millis();
  } else {
    but3time = 0;
  }

  // if button 2 is pressed w/in 2s of button 1, LED 1 lights up
  if ((but2time - but1time) <= 2000) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  // if button 3 is pressed w/in 2s of button 2, LED 3 lights up
  if ((but3time - but2time) <= 2000) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  // if all are pressed together, LED 2 lights up
  if (digitalRead(BUT1) == HIGH && digitalRead(BUT2) == HIGH && digitalRead(BUT3) == HIGH) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite (LED2, LOW);
  }

}
