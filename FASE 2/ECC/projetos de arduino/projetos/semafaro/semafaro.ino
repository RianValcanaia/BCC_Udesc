// C++ code
//

int v[3]={11,12,13};
int t[2]={5000,2000};

void setup()
{
  pinMode(v[0], OUTPUT);//verde
  pinMode(v[1], OUTPUT);//amarelo
  pinMode(v[2], OUTPUT);//vermelho
}

void loop()
{
  digitalWrite(v[0], LOW);
  digitalWrite(v[1], LOW);
  digitalWrite(v[2], HIGH);
  delay(t[0]); 
  digitalWrite(v[0], HIGH);
  digitalWrite(v[1], LOW);
  digitalWrite(v[2], LOW);
  delay(t[0]);
  digitalWrite(v[0], LOW);
  digitalWrite(v[1], HIGH);
  digitalWrite(v[2], LOW);
  delay(t[1]);
}
