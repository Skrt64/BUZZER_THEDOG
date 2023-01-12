#define BUZZER 23
#define But 35
hw_timer_t *My_timer = NULL;

int dlay = 700;
// This is the Timer ISR. It is automatically called 
// on a timer alarm event.
void IRAM_ATTR onTimer(){
  digitalWrite(BUZZER, !digitalRead(BUZZER));
}

void IRAM_ATTR IO_INT_ISR()
{
  if(dlay > 350) dlay -= 70;
  else dlay = 700;
  if(dlay == 700) Serial.println(1);
  else if(dlay == 630) Serial.println(2);
  else if(dlay == 560) Serial.println(3);
  else if(dlay == 490) Serial.println(4);
  else if(dlay == 420) Serial.println(5);
  // delay(1000);
}


void sound(char text){
  int hz;
  if (text == 'c') hz = 1047;
  else if (text == 'd') hz = 1175;
  else if (text == 'e') hz = 1319;
  else if (text == 'f') hz = 1397;
  else if (text == 'g') hz = 1568;
  else if (text == 'a') hz = 1760;
  else if (text == 'b') hz = 1976;
  My_timer = timerBegin(0, 80, true);  // use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR
  // Serial.println(text);
  if (text == 's'){
    timerAlarmWrite(My_timer, 20, true);//stop note
    timerAlarmEnable(My_timer);  // enable the alarm
    delay(25);
  }
  else{
    timerAlarmWrite(My_timer, 1000000/(2*hz), true);//นำค่าความถี่มาหาร1000000เพื่อให้ได้โน็ตที่ต้องการ
    timerAlarmEnable(My_timer);  // enable the alarm
    delay(dlay);//delay ตามการกดปุ่ม
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);//ตั้งpinmode ของ buzzer
  pinMode(But, INPUT_PULLUP);//ตั้งpinmode ของ button
  attachInterrupt(But, IO_INT_ISR, RISING); // interrupt on rising edge
}

void loop() {
  //โน๊ตเพลง The Dog
  sound('c');
  sound('c');
  sound('s');

  sound('c');
  sound('d');
  sound('e');
  sound('s');

  sound('e');
  sound('e');
  sound('s');

  sound('e');
  sound('f');
  sound('g');
  sound('s');

  sound('g');
  sound('g');
  sound('s');

  sound('c');
  sound('d');
  sound('e');
  sound('s');

  sound('f');
  sound('e');
  sound('s');

  sound('f');
  sound('e');
  sound('d');
  sound('s');

  sound('c');
  sound('c');
  sound('s');

  sound('c');
  sound('d');
  sound('e');
  sound('s');

  sound('g');
  sound('g');
  sound('s');

  sound('a');
  sound('b');
  sound('c');
  sound('s');

  sound('c');
  sound('c');
  sound('s');

  sound('b');
  sound('a');
  sound('g');
  sound('s');

  sound('f');
  sound('f');
  sound('s');

  sound('e');
  sound('d');
  sound('c');
  sound('s');
}