int led = 4;
int entrada = 7;
int aux = 1;
int cont =0;
bool estado = LOW; // variável de estado do botão
unsigned long time; // variável vara a função millis()

void setup() {
pinMode(led,OUTPUT);
pinMode(entrada,INPUT);
Serial.begin(9600);
time = millis();
}

void loop() {
  
do{
  estado_anterior = digitalRead(entrada);
delay(50);
estado = digitalRead(entrada);
}while(estado_anterior != estado); // aqui definimos um intervalo de tempo de segurança usando a função delay(), para sair do loop é
// necessário identificar uma constancia no estado do botão, ele precisa ser o mesmo durante 50 ms

if (estado==HIGH && aux==1){
    aux = 0;
    cont++;
    digitalWrite(led,HIGH); // este não é só um algoritimo de verificação, quando acionamos o botão também ascendemos um Led
}

if (estado==LOW && aux==0){
  aux = 1;
  cont++;
  digitalWrite(led,LOW);
}

if (millis()-time>=500){  // imprime o número de variações a cada 0,5 segundo
  time=millis();          //guarda o novo ponto de inicio para a proxima analise
    Serial.print("variações = ");
    Serial.print(cont);
    Serial.print("\n");
    cont = 0;
}
}