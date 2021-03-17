//20/07/2016 atualizado em 10/09/2017.
//Michael Moraes Sabino 
//email: estuartyy@gmail.com 

#include <Servo.h>

#define COXA_SOBE 105     //105
#define COXA_DESCE 70     //70
#define PERNA_SOBE 92     //92
#define PERNA_DESCE 125   //125
#define TEMPO1 200        //velocidade da caminhada
#define TEMPO2 200        //velocidade da caminhada
#define TEMPO3 200        //velocidade da caminhada
#define TEMPO4 200        //velocidade da caminhada
#define TEMPO5 100        //velocidade da caminhada

const int BluetoothState = A2; // Pino A2 como o pino de comunicação do Bluetooth.

int SOBE = PERNA_SOBE;
int DESCE = PERNA_DESCE;
int state_rec; //variavel para armazenamento de dados.
char state; //state recebe os caracteres do celular

Servo CoxaEsquerdaTraseira;
Servo PernaEsquerdaTraseira;
Servo CoxaDireitaMeio;
Servo PernaDireitaMeio;
Servo CoxaEsquerdaFrente;
Servo PernaEsquerdaFrente;
Servo coxaDireitaFrente;
Servo pernaDireitaFrente;
Servo CoxaEsquerdaMeio;
Servo PernaEsquerdaMeio;
Servo CoxaDireitaTraseira;
Servo PernaDireitaTraseira;

void setup(){
  
  Serial.begin(9600);
  
  pinMode(BluetoothState, INPUT); //abre conexao com bluetooth
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(2, OUTPUT);
  digitalWrite(3, OUTPUT);
  digitalWrite(4, OUTPUT);
  digitalWrite(5, OUTPUT);
  digitalWrite(6, OUTPUT);
  digitalWrite(7, OUTPUT);
  digitalWrite(8, OUTPUT);
  digitalWrite(9, OUTPUT);
  digitalWrite(10, OUTPUT);
  digitalWrite(11, OUTPUT);
  digitalWrite(12, OUTPUT);
  digitalWrite(13, OUTPUT);
 
  CoxaEsquerdaTraseira.attach(2);
  PernaEsquerdaTraseira.attach(3);
  CoxaDireitaMeio.attach(10);
  PernaDireitaMeio.attach(11);
  CoxaEsquerdaFrente.attach(6);
  PernaEsquerdaFrente.attach(7);
  coxaDireitaFrente.attach(12);
  pernaDireitaFrente.attach(13);
  CoxaEsquerdaMeio.attach(4);
  PernaEsquerdaMeio.attach(5);
  CoxaDireitaTraseira.attach(8);
  PernaDireitaTraseira.attach(9);
}
 
void loop(){

  if (digitalRead(BluetoothState) == LOW) { // Para o robô quando a conexão com Bluetooth é desconectada.
    state_rec = 'S';
  }

  if (Serial.available() > 0) { // Salva os valores da variável 'state'
    state_rec = Serial.read();
    state = state_rec;
  }

 if (state != 'S') {
    Serial.print(state);
  }
  
   if (state == 'F') {   // Se o estado recebido for igual a 'F', o robô se movimenta para frente.
    AndarParaFrente();
  }

   else if (state == 'B') {    // Se o estado recebido for igual a 'B', o robô se movimenta para trás.
    AndarParaTras();
  }

   else if (state == 'R') { // Se o estado recebido for igual a 'R', o robô se movimenta para direita.       
    IrParaDireita();
  }

  else if (state == 'L') {  // Se o estado recebido for igual a 'L', o robô se movimenta para esquerda.
      IrParaEsquerda();
  }

  else if (state == 'S') {   // Se o estado recebido for igual a 'S', o robô permanece parado.
  //ROBÔ PARADO
  }

  else if (state == 'X') { // Se o estado recebido for iguala 'V', aciona a buzina.
        Apresentacao();
    }
  
 /*else if (state == 'I') {  // Se o estado recebido for igual a 'G', o robô se movimenta para Frente Esquerda.
     //VAZIO SEM FUNÇAO
  }

   else if (state == 'G') {   // Se o estado recebido for igual a 'I', o robô se movimenta para Frente Direita.
    //VAZIO SEM FUNÇAO    
  }

   else if (state == 'H') {  // Se o estado recebido for igual a 'H', o robô se movimenta para Trás Esquerda.
    //VAZIO SEM FUNÇAO
  }
  
   else if (state == 'J') {  // Se o estado recebido for igual a 'J', o robô se movimenta para Trás Direita.
    //VAZIO SEM FUNÇAO
  }*/
}

void Apresentacao(){
  Amostra1();
}
void AndarParaFrente() {
  PASSO1(); PASSO2(); PASSO3(); PASSO4();
}
void AndarParaTras() {
   Tras4(); Tras3(); Tras2(); Tras1(); 
}
void IrParaEsquerda() {
  Vire_A_ESQUERDA1(); Vire_A_ESQUERDA2(); Vire_A_ESQUERDA3(); Vire_A_ESQUERDA4();
}
void IrParaDireita() {
  Vire_A_DIREITA1(); Vire_A_DIREITA2(); Vire_A_DIREITA3(); Vire_A_DIREITA4();
}

void Amostra1(){
  CoxaEsquerdaFrente.write(40);
  delay(100);
  coxaDireitaFrente.write(155);
  delay(100);
  CoxaEsquerdaTraseira.write(100);
  delay(100);
  CoxaDireitaTraseira.write(75);
  delay(100);
  CoxaEsquerdaMeio.write(120);
  delay(100);
  CoxaDireitaMeio.write(120);
  delay(100);
  PernaEsquerdaTraseira.write(70);
  delay(100);
  PernaDireitaTraseira.write(130);
  delay(100);
  PernaDireitaMeio.write(100);
  delay(100);
  PernaEsquerdaMeio.write(130);
  delay(100);
  pernaDireitaFrente.write(60);
  delay(100);
  PernaEsquerdaFrente.write(75);
  delay(100);
}

void PASSO1() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO1);
};
void PASSO2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void PASSO3() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO3);
};
void PASSO4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};

void  Tras1() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO1);
};
void  Tras2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void  Tras3() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO3);
};
void  Tras4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};

void Vire_A_ESQUERDA1() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO1);
};
void Vire_A_ESQUERDA2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void Vire_A_ESQUERDA3() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO3);
};
void Vire_A_ESQUERDA4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};

void Vire_A_DIREITA1() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO1);
};
void Vire_A_DIREITA2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void Vire_A_DIREITA3() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO3);
};
void Vire_A_DIREITA4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};
