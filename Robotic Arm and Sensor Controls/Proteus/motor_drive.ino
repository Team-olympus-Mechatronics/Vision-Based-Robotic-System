// the first motor pins
int in1= 22;
int in2 =  23;
int en1 = 25;
// the second motor pins
int en2= 9;
int in3 =8;
int in4=7;
void setup() {
  // put your setup code here, to run once:
   pinMode(in1 ,OUTPUT);
   pinMode(in2 ,OUTPUT);
   pinMode(en1 ,OUTPUT);
   
   pinMode(en2 ,OUTPUT);
   pinMode(in3 ,OUTPUT);
   pinMode(in4 ,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(in1, HIGH);
 digitalWrite(in2,LOW);
 analogWrite(en1, 255);

 analogWrite(en2,255);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
 
}
