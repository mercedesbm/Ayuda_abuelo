#include <ESP8266WiFi.h>

//Nombre de red
const char *nombre = "MiFibra-B24A";
//Password
const char *password = "HSzLs9Fc";

//Nombre de red clase 
//const char *nombre = "informatica-inf1-2";
//Password
//const char *password = "hdphdj1234";

WiFiClient client;
IPAddress server(192, 168, 1, 85); // IP casa
// IPAddress server(172, 30, 20, 5); // IP clase

void setup()
{
   Serial.begin(115200);
   delay(50); // breve espera para que se concrete la conexion

   // Conexion al WiFi 
   WiFi.begin(nombre, password);
   while (WiFi.status() != WL_CONNECTED)
   {
      delay(100); //aqui debemos esperar unos instantes
   }
   
   Serial.println("Conexión exitosa al WiFi");

   Serial.print("la IP es: ");
   Serial.print(WiFi.localIP());
   Serial.println("");

   pinMode(BUILTIN_LED, OUTPUT);
   pinMode(4, INPUT_PULLUP);
   //0 en el flash 4 D2
}

void loop()
{
    // put your main code here, to run repeatedly:
   if (digitalRead(4) == LOW)
   {
      digitalWrite(BUILTIN_LED, LOW);
      if (client.connect(server, 8080))
      {
         Serial.println("connected");
          // Make a HTTP request:
         client.println("GET / HTTP/1.0");
         client.println();
         Serial.println("Conectado a www.ayuda.abuelo.tk");
      }

      delay(2000);
   }
   else
   {
      digitalWrite(BUILTIN_LED, HIGH);
   }
}
