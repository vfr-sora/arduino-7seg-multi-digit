

#define LED_A 7
#define LED_B 6
#define LED_C 4
#define LED_D 2
#define LED_E 1
#define LED_F 9
#define LED_G 10
#define LED_DP 5

#define SW 12
int loopCount;
boolean swOffOn;
boolean play;

void setup() {

  // put your setup code here, to run once:
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_DP, OUTPUT);
  //
  init7seg();
  //
  pinMode(SW, INPUT);
  //
  loopCount = 0;
  swOffOn = false;
  play = false;
}

void loop() {
  if (digitalRead(SW)==true && swOffOn==false){
    swOffOn=true;
    if (play==false){
      play = true;
      pause();
    } 
    else {
      play = false;
      pause();
    }


  }
  if (digitalRead(SW) == false) {
    swOffOn = false;
  }

  if (play==true){
    loopCount++;
    //
    //
    //
    //
  }
  digit(loopCount);
 }

void pause(){
  for ( int ii = 0; ii < 5; ii++) {
    ledBlackOut();
    delay(200);
    ledAll();
    delay(200);
  }
}

void init7seg() {
  int pins[] = {7,6,4,2,1,9,10,5};
  for (int ii=0; ii<8; ii++) {
    digitalWrite(pins[ii], HIGH);
    delay(100);
    digitalWrite(pins[ii], LOW);  
    delay(100);
  }
  for (int ii=0; ii<8; ii++) {
    digitalWrite(pins[ii], HIGH);
  }
  delay(500);
  for (int ii=0; ii<8; ii++) {
    digitalWrite(pins[ii], LOW);
    delay(200);
  }
   
}

void digit3(int nn) {
  ledBlackOut();
  delay(1000);
  digit( nn);
  delay(1000);  
  digit( nn);
  delay(1000);  
  digit( nn);
}

void digit(int nn) {
  threeDigit(nn);
}

void threeDigit(int nn) {
  int third = nn / 100;
  int first = (nn - third *100) % 10; 
  int second = (nn - third *100 - second *10) / 10;

  ledBlackOut();
  delay(100);
  oneDigit(third, 0);
  delay(500);
  oneDigit(second, 0);
  delay(500);
  oneDigit(first, 1);
  delay(500);
}

void twoDigit(int nn) {
  int second = nn / 10;
  int first = nn - second *10; 

  ledBlackOut();
  delay(100);
  oneDigit(second, 0);
  delay(500);
  oneDigit(first, 1);
  delay(500);
}

void oneDigit(int nn, int dp) {
  switch (nn) {
    case 0:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, LOW);
      break;
    case 1:
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      break;
    case 2:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, LOW);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, HIGH);
      break;
    case 3:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, HIGH);
      break;
    case 4:
      digitalWrite(LED_A, LOW);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 5:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 6:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, LOW);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 7:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, LOW);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, LOW);
      digitalWrite(LED_G, LOW);
      break;
    case 8:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, HIGH);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    case 9:
      digitalWrite(LED_A, HIGH);
      digitalWrite(LED_B, HIGH);
      digitalWrite(LED_C, HIGH);
      digitalWrite(LED_D, HIGH);
      digitalWrite(LED_E, LOW);
      digitalWrite(LED_F, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
    default:
      break;
  }
  // DP
  if ( dp == 0 ){
    digitalWrite(LED_DP, LOW);
  }
  else {
    digitalWrite(LED_DP, HIGH);
  }
}

void ledBlackOut() {
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_C, LOW);
  digitalWrite(LED_D, LOW);
  digitalWrite(LED_E, LOW);
  digitalWrite(LED_F, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_DP, LOW);
}
void ledAll() {
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, HIGH);
  digitalWrite(LED_C, HIGH);
  digitalWrite(LED_D, HIGH);
  digitalWrite(LED_E, HIGH);
  digitalWrite(LED_F, HIGH);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_DP, HIGH);
}
