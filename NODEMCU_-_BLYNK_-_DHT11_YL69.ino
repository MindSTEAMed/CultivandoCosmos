//TARJETA NODEMCU CON SENSOR DE HUMEDAD DE SUELO YL69 Y SENSOR DE T Y H ATMOSFÉRICO DHT11
//CULTIVANDO COSMOS 1.1 - 2022
//PARA EL CONTROL Y MONITOREO DE LA TEMPERATURA Y HUMEDAD DEL AIRE Y LA TIERRA
//

#define BLYNK_PRINT Serial
 
 
#include <ESP8266WiFi.h> //LIBRERIA PARA QUE FUNCIONE LA TARJETA EN MODO WIFI
#include <BlynkSimpleEsp8266.h> //LIBRERIA PARA PODER USAR LA APLICACIÓN BLYNK
#include <DHT.h> //LIBRERIA PARA QUE FUNCIONE EL TERMOMETRO DHT11

 int output_value ; //CREACIÓN DE UNA VARIABLE (ALGO NECESARIO PARA PODER MEDIR COSAS)
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "***********"; //TOKEN PARA CONECTAR MI CELULAR CON LA TARJETA NODEMCU
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "*******"; //NOMBRE DEL WIFI
char pass[] = "*******"; //CONTRASEÑA DEL WIFI
 
#define DHTPIN 0          // CONECTAR AL PIN D3
 
// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // QUITAR SLASH EN CASO DE USAR EL SENSOR DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301
 
DHT dht(DHTPIN, DHTTYPE);  //ACTIVAR LIBRERIA DHT
BlynkTimer timer;         //ACTIVAR LIBRERIA BLYNKTIMER PARA MEDIR CADA CIERTOS SEGUNDOS
 
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

void sendSensor()  //INICIO DE FUNCIÓN QUE MIDE HUMEDAD Y TEMPERATURA DEL DHT11
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);    //TRASPASO DE DATOS DE TEMPERATURA A PIN VIRTUAL V5
  Blynk.virtualWrite(V6, h);    //TRASPASO DE DATOS DE HUMEDAD A PIN VIRTUAL V6
}
 
void setup()
{
  // Debug console
  Serial.begin(9600);        //COMUNICACIÓN DE DATOS A UNA VELOCIDAD DE 9600 BAUDIOS
 
  Blynk.begin(auth, ssid, pass,"blynk.mindsteam.cl",8080);        //INICIO DE FUNCIÓN BLYNK CON CONEXIÓN A SERVER
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
 Serial.println("Reading From the Sensor ...");    //ESCRIBIR EN MONITOR SERIAL EL MENSAJE
 delay(2000);
  dht.begin();  //INICIO DE FUNCIÓN DEL TERMÓMETRO
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}
 
void loop()        //REPETICIÓN DE CÓDIGO
{
  output_value= analogRead(A0);  //LECTURA DE SENSOR DE HUMEDAD EN PIN A0
Serial.print("Moisture : ");       //IMPRIMIR MENSAJE
 Serial.print(output_value);       //IMPRIMIR VALOR DE HUMEDAD
 Serial.print("\n");           
delay(1000); 
  Blynk.run();                //CORRER PROGRAMA BLYNK
  timer.run();
}
