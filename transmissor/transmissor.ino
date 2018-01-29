/* 
 *  Transmissor RF 433
 *  envia mensagem, se o sensor de presença é acionado ou não
 *  Diogo Cardoso Silva
  ------------------------------------------------------------- */
#include <VirtualWire.h>


int rfTransmitPin = 4;  //RF Transmitter pin = digital pin 4 
int sensor = 5; //Pino ligado ao sensor PIR
int acionamento; //Variavel para guardar valor do sensor
int tempo = 1000;

 void setup(){
    vw_set_tx_pin(8);
    vw_setup(2000);   // Bits per sec
    pinMode(sensor, INPUT); //Define pino sensor como entrada
    Serial.begin(9600);
 }

 void loop(){
      delay(tempo);//tempo entre leitura do espaço pelo sensor
      acionamento = digitalRead(sensor); //Le o valor do sensor PIR
//      Serial.println(acionamento);
     
      if(acionamento == 1){
        send("movimento");
      }else{
        send("Sem Movimento !!!");
      }
} 
void send (char *message){
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Aguarda o envio de dados
}
 

