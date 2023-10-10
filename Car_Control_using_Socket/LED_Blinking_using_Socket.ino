#include <WiFi.h>
#include <Wire.h>


const char* ssid = "AndroidXXX";
const char* password = "cbnjXXXXX";
const int serverPort = 3000;

int in1 = 13;
int in2 = 12;
int in3 = 14;
int in4 = 27;

int en1 = 25;
int en2 = 26;

WiFiServer server(serverPort);

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);

  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP()); # find your IP address from here
  digitalWrite(2, HIGH);
  delay(2000);
  digitalWrite(2, LOW);

  // Start the server
  server.begin();
}

void forward()
{
  digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);  
}

void backward()
{
  digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);  
}

void left()
{
  digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);  
}

void right()
{
  digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);  
}  

void stop()
{
digitalWrite(en1,LOW);
digitalWrite(en2,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}


void loop() {
  WiFiClient client = server.available();
  if (client) {
        
    Serial.println("Client connected");
    while (client.connected()) 
    {
      if (client.available())
       {
        String command = client.readStringUntil('\n');

        // Process received commands
        if (command == "up") 
        {
          digitalWrite(2, HIGH);
          forward();          
        } 
        else if (command == "down") 
        {
          digitalWrite(2, HIGH);
          backward();
        }
        else if (command == "right")
        {
          digitalWrite(2, HIGH);
          right();          
        }
        else if (command == "left")
        {
          digitalWrite(2, HIGH);
          left();          
        }
        else if (command == "stop")
        {
          digitalWrite(2, LOW);
          stop();          
        }
      Serial.println("Received command: " + command);
    }
    }
    // Disconnect the client
    client.stop();
    Serial.println("Client disconnected");
  }
}

