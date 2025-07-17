const byte LED = 13;//constante pois não será alterado 
const byte BOTAO = 12;
byte valorBotao; //declaracao valor byte

void setup(){
  pinMode(LED, OUTPUT); //o led tera uma saida do arduino
  pinMode(BOTAO, INPUT);//o botao tera um imput para o arduino
}

void loop(){
  valorBotao = digitalRead(BOTAO); //le o valor do botao e armazena na variavel byte
  digitalWrite(LED, valorBotao); //escreve a função para o LED
}
