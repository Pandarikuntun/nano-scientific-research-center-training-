/************************************************************
 *                 LIBRARIES USED
 ************************************************************/
#include <ESP8266WiFi.h>          
#include <ESP8266WebServer.h>     
#include <SinricPro.h>            
#include <SinricProLight.h>       

/************************************************************
 *                 WIFI CREDENTIALS
 ************************************************************/
#define WIFI_SSID "Redmi 9 Power"
#define WIFI_PASS "TULASIRAM"

/************************************************************
 *                 SINRIC PRO DETAILS
 ************************************************************/
#define APP_KEY    "369a87ad-eea2-4275-8e0e-5ec89897c28c"
#define APP_SECRET "9c31a0dc-38bb-407d-b569-ed4ac049a605-f1cbff0c-a08c-466c-8ee2-da36ae752a1b"
#define DEVICE_ID  "6948e5706dbd335b28f8fc4d"

/************************************************************
 *                 PIN DEFINITIONS
 ************************************************************/
#define LED_PIN        5     // GPIO5  (D1) → PWM LED
#define EXTRA_OUT_PIN 12     // GPIO12 (D6) → Extra output
#define EXTRA_IN_PIN  14     // GPIO14 (D5) → Touch / Switch input
#define IR_PIN        16     // GPIO16 (D0) → IR sensor input
#define BUTTON_PIN     4     // GPIO4  (D2) → Push Button input

/************************************************************
 *                 WEB SERVER
 ************************************************************/
ESP8266WebServer server(80);

/************************************************************
 *                 GLOBAL VARIABLES
 ************************************************************/
bool webLedState = false;      
int brightness = 50;           
String irStatus = "Not Detected";
String ledStatus = "OFF";

/************************************************************
 *           SINRIC CALLBACK : POWER
 ************************************************************/
bool onPowerState(const String &, bool &state) {

  webLedState = state;

  if (state) {
    analogWrite(LED_PIN, brightness);
    digitalWrite(EXTRA_OUT_PIN, HIGH);
    ledStatus = "ON";
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(EXTRA_OUT_PIN, LOW);
    ledStatus = "OFF";
  }
  return true;
}

/************************************************************
 *         SINRIC CALLBACK : BRIGHTNESS (1–5)
 ************************************************************/
bool onBrightness(const String &, int &level) {

  int stage = map(level, 0, 100, 1, 5);

  switch (stage) {
    case 1: brightness = 20; break;
    case 2: brightness = 40; break;
    case 3: brightness = 60; break;
    case 4: brightness = 80; break;
    case 5: brightness = 100; break;
  }

  webLedState = true;
  analogWrite(LED_PIN, brightness);
  digitalWrite(EXTRA_OUT_PIN, HIGH);
  ledStatus = "ON";

  return true;
}

/************************************************************
 *                 WEB PAGE
 ************************************************************/
void handleRoot() {
  server.send(200, "text/html", R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP8266 Smart LED</title>
<style>
body{background:linear-gradient(135deg,#667eea,#764ba2);font-family:Segoe UI;text-align:center;color:white;}
.card{background:white;color:#333;max-width:350px;margin:40px auto;padding:25px;border-radius:15px;}
.led{width:60px;height:60px;border-radius:50%;background:black;margin:15px auto;}
.on{background:#2ecc71;box-shadow:0 0 20px #2ecc71;}
</style>
</head>
<body>
<div class="card">
<h2>Smart LED</h2>
<div id="icon" class="led"></div>
<p>LED: <span id="led">OFF</span></p>
<p>IR: <span id="ir">Not Detected</span></p>
<button onclick="fetch('/on')">ON</button>
<button onclick="fetch('/off')">OFF</button>
<p>Brightness: <span id="val">50</span>%</p>
<input type="range" min="0" max="100" value="50" oninput="setB(this.value)">
</div>
<script>
function setB(v){document.getElementById("val").innerHTML=v;fetch('/slider?value='+v);}
setInterval(()=>{
 fetch('/ledstatus').then(r=>r.text()).then(d=>{
  document.getElementById("led").innerHTML=d;
  document.getElementById("icon").className=d=="ON"?"led on":"led";
 });
 fetch('/irstatus').then(r=>r.text()).then(d=>{
  document.getElementById("ir").innerHTML=d;
 });
},500);
</script>
</body>
</html>
)rawliteral");
}

/************************************************************
 *                 SETUP
 ************************************************************/
void setup() {

  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(EXTRA_OUT_PIN, OUTPUT);
  pinMode(EXTRA_IN_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);   //  Button added

  analogWriteRange(100);
  digitalWrite(LED_PIN, LOW);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.on("/on", [](){
    webLedState = true;
    analogWrite(LED_PIN, brightness);
    digitalWrite(EXTRA_OUT_PIN, HIGH);
    ledStatus = "ON";
    server.send(200,"text/plain","ON");
  });

  server.on("/off", [](){
    webLedState = false;
    digitalWrite(LED_PIN, LOW);
    digitalWrite(EXTRA_OUT_PIN, LOW);
    ledStatus = "OFF";
    server.send(200,"text/plain","OFF");
  });

  server.on("/slider", [](){
    if(server.hasArg("value")){
      brightness = server.arg("value").toInt();
      webLedState = true;
      analogWrite(LED_PIN, brightness);
    }
    server.send(200,"text/plain","OK");
  });

  server.on("/irstatus", [](){ server.send(200,"text/plain",irStatus); });
  server.on("/ledstatus", [](){ server.send(200,"text/plain",ledStatus); });

  server.begin();

  SinricProLight &light = SinricPro[DEVICE_ID];
  light.onPowerState(onPowerState);
  light.onBrightness(onBrightness);
  SinricPro.begin(APP_KEY, APP_SECRET);
}

/************************************************************
 *                 LOOP
 ************************************************************/
void loop() {

  server.handleClient();
  SinricPro.handle();

  bool ir  = digitalRead(IR_PIN);
  bool ext = digitalRead(EXTRA_IN_PIN);
  bool btn = digitalRead(BUTTON_PIN);   //  Button read

  irStatus = (ir == LOW) ? "Detected" : "Not Detected";

  // Any input turns LED ON
  if (btn == LOW || ext == HIGH || ir == LOW || webLedState) {
    analogWrite(LED_PIN, brightness);
    digitalWrite(EXTRA_OUT_PIN, HIGH);
    ledStatus = "ON";
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(EXTRA_OUT_PIN, LOW);
    ledStatus = "OFF";
  }
}
