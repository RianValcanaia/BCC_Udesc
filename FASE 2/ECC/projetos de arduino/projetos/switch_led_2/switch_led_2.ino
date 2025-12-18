const byte LEDVERMELHO = 13;//constante pois não será alterado 
const byte BOTAOVERMELHO = 12;

const byte LEDVERDE = 11;//constante pois não será alterado 
const byte BOTAOVERDE = 10;

//Vermelho
byte valorBotaoVermelho; //declaracao valor byte
byte valorBotaoAnteriorVermelho;
boolean ledLigadoVermelho = false;

//Verde
byte valorBotaoVerde; //declaracao valor byte
byte valorBotaoAnteriorVerde;
boolean ledLigadoVerde = false;


void setup(){
  pinMode(LEDVERMELHO, OUTPUT); //o led tera uma saida do arduino
  pinMode(BOTAOVERMELHO, INPUT);//o botao tera um imput para o arduino
  pinMode(LEDVERDE, OUTPUT); //o led tera uma saida do arduino
  pinMode(BOTAOVERDE, INPUT);//o botao tera um imput para o arduino
  
}

void loop(){
  valorBotaoVermelho = digitalRead(BOTAOVERMELHO); //le o valor do botao vermelho e armazena na variavel byte
  valorBotaoVerde = digitalRead(BOTAOVERDE); //le o valor do botao verde e armazena na variavel byte
  
  if (valorBotaoAnteriorVermelho != valorBotaoVermelho){
    if(valorBotaoVermelho == 1) {
      ledLigadoVermelho = !ledLigadoVermelho;
      digitalWrite(LEDVERMELHO, ledLigadoVermelho); //escreve a função para o LED
    }
  }

  if (valorBotaoAnteriorVerde != valorBotaoVerde){
    if(valorBotaoVerde == 1) {
      ledLigadoVerde = !ledLigadoVerde;
      digitalWrite(LEDVERDE, ledLigadoVerde); //escreve a função para o LED
    }
  }
  
  valorBotaoAnteriorVermelho = valorBotaoVermelho;
  valorBotaoAnteriorVerde = valorBotaoVerde;

  delay(10);
}
