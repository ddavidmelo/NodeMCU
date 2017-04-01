#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

String rsp = "";
String HTML = "";
IPAddress         apIP(10, 10, 10, 1);

void setup()
{
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("Chat room");

  //Serial.begin(115200);
  //Serial.print("Server ON...");
  
  HTML +="<!DOCTYPE HTML>";
  HTML +="<html>";
  HTML +="<h1>Chat room</h1>";
  HTML +="<p>User : <input style=\"width:10%; margin-left: 40px;\" type=\"text\" id = \"chatT\" ><br> </p>";
  HTML +="<p>Message : <input style=\"width:70%; margin-left: 15px;\" type=\"text\" id=\"User\" ><br> </p>";
  HTML +="<a id = \"coias\" ><button style=\"    background-color: #66ffcc; border: none; color: #000033; padding: 12px 12px; text-align: center; text-decoration: none; font-size: 16px; margin: 4px 2px;\" onclick=\"myFunction()\" >Send</button></a>";
  HTML +="<a href=\"refresh\"><button style=\"background-color: #66ffcc; border: none; color: #000033; padding: 12px 12px; text-align: center; text-decoration: none; font-size: 16px; margin: 4px 2px;\" >refresh</button></a>";
  HTML +="<script>";
  HTML +="function myFunction() {";
  HTML +="var x1 = document.getElementById(\"chatT\").value;";
  HTML +="var x2 = document.getElementById(\"User\").value;";
  HTML +="var y = document.getElementById('coias');";
  HTML +="y.href = \"chat?&user=\"+x1+\"&text=\"+x2;";
  HTML +="}";
  HTML +="</script>";
  HTML +="</html>";

  //server.on("/",[](){server.send(200,"text/plain","Send message to 192.168.4.1/chat?&user=DAVID&text=lalalalallalal");});
  
  server.on("/",[](){server.send(200,"text/html",HTML + rsp);});
  server.on("/chat",chat);
  server.on("/refresh",refresh);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void chat()
{
  String user = server.arg("user");
  String text = server.arg("text");
  if(user != "" || text != "")
  {
    rsp = "<br> USER : "+user+" | " + text + rsp;
    server.send(200,"text/html",HTML+rsp);
  }
  server.send(200,"text/html",HTML+rsp);
}

void refresh()
{
  server.send(200,"text/html",HTML+rsp);
}




