/* 
 *  Receptor RF 433
 *  recebe mensagem, se o senhor de presença foi acionado emite sinal sonoro
 *  Diogo Cardoso Silva
 ------------------------------------------------------------- */
#include <VirtualWire.h>

int bip = 13;//Onboard buzzer = digital pin 13
byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens

 void setup(){
    vw_set_rx_pin(8); // Define o pino 8 do Arduino como entrada de dados do receptor
    vw_setup(2000);             // Bits por segundo
    vw_rx_start();              // Inicializa o receptor
    pinMode(bip, OUTPUT);
    Serial.begin(9600);
//    Serial.println("Pronto!");
 }

 void loop(){
      char temp;
      String palavra = "";
      uint8_t message[VW_MAX_MESSAGE_LEN];    
      uint8_t msgLength = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(message, &msgLength)){
          Serial.print("Recebido: ");
          for (int i = 0; i < msgLength; i++){
              temp = message[i];
              Serial.write(temp);
              palavra += temp;
          }
          Serial.println();
      }
          if(palavra == "movimento"){
              Serial.print("som ");
              Serial.println(palavra);
              alarmeSonoro();
          }
          palavra = "a";

}
void alarmeSonoro(){
    for(int i = 0; i < 10;i++){ 
        tone(bip,1);
        delay(35);
        noTone(bip);
    }
}

