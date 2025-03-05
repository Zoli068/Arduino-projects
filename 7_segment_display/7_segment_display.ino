//Board:Arduino Uno
//7-Segment Display: 5161AS

int a = 6;
int b = 5;
int c = 4;
int d = 3;
int e = 2;
int f = 7;
int g = 8;
int numberToDisplay = 0;

void clearDisplay() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void display0() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}

void display1() {
  clearDisplay();
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void display2() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
}

void display3() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(g, HIGH);
}

void display4() {
  clearDisplay();
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void display5() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void display6() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void display7() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void display8() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void display9() {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void setup() {
  int i;
  for (i = 2; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
}


void loop() {
  if (numberToDisplay == 0) {
    display0();
  } else if (numberToDisplay == 1) {
    display1();
  } else if (numberToDisplay == 2) {
    display2();
  } else if (numberToDisplay == 3) {
    display3();
  } else if (numberToDisplay == 4) {
    display4();
  } else if (numberToDisplay == 5) {
    display5();
  } else if (numberToDisplay == 6) {
    display6();
  } else if (numberToDisplay == 7) {
    display7();
  } else if (numberToDisplay == 8) {
    display8();
  } else {
    display9();
  }

  delay(1000);

  if (numberToDisplay == 9) {
    numberToDisplay = 0;
  } else {
    numberToDisplay++;
  }
}
