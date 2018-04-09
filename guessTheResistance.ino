#define red 4
#define yellow 3
#define green 2
#define startButton 5

int counter = 0;
int settedRes = 0;
int shoot = 0;
bool isWinner = false;

void setup(){
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(startButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){ 
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);

  Serial.println("Ustaw potencjometr i wciśniej przycisk...");

  if(digitalRead(startButton) == LOW){
    while(counter < 3){

     settedRes = analogRead(A5);
      
     Serial.println("Teraz oszacuj liczbę: ");
     Serial.println(settedRes);
     
     while(Serial.available() == 0){}

     shoot = Serial.readStringUntil('\n').toInt();

     if(shoot == 100){
      digitalWrite(green, HIGH);
      delay(5000);
      digitalWrite(green, LOW);
     }else{
      if(counter < 3){
        digitalWrite(yellow, HIGH);
        delay(2000);
        digitalWrite(yellow, LOW);
        counter = counter + 1;
      }else{
        digitalWrite(red, HIGH);
      }
     }
    }
  }

  delay(6000);
  counter = 0;

  digitalWrite(yellow, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);

  delay(2000);

  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);

}


