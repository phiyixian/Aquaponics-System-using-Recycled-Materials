const int dry = 1023;
const int wet = 352;
int value = 0;
int percentage = 0;
const int relay_Pin =3;


void setup(){
  Serial.begin(9600);
    pinMode(relay_Pin, OUTPUT);
}


void loop(){
  value = analogRead(A0);
  percentage = map(value, dry, wet, 0, 100);
  Serial.print("Moisture Percentage :");
  Serial.print(percentage);
  Serial.println("%");


  if (percentage <30){
    Serial.print("Moisture Level: ");
    Serial.println("LOW");
    digitalWrite(relay_Pin, LOW);
  }
  else {
    Serial.print("Moisture Level: ");
    Serial.println("HIGH");
    digitalWrite(relay_Pin, HIGH);
  }
  delay(1000);
}
