//sound, touch and light set up
#include <DHT.h>
#define DHTPIN 2       // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11  // DHT11 sensor type
int sound_sensor = A2; // Sound Sensor
int touch_sensor = A1; // touch sensor
int light_sensor = A0; // light sensor
DHT dht(DHTPIN, DHTTYPE);
float temperature;
bool temperature_test = false;
bool sound_test = false;
bool touch_test = false;
bool light_test = false;

/////////////////////////////////////////////////////////////////

//3 button set up
#define BUTTON_PIN1 4
#define BUTTON_PIN2 3
#define BUTTON_PIN3 2

////////////////////////////////////////////////////////////////

//lcd screen set up
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

////////////////////////////////////////////////////////////////

void setup() {
  //sound, touch, light
  Serial.begin(9600);
  dht.begin();
  Serial.println("Start");

  //3 buttons
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  //lc screen
  lcd.begin(16,2);  
  lcd.setRGB(224,60,70);  
}

////////////////////////////////////////////////////////////////

void loop() {
  lcd.clear();
  lcd.print("Start");
  Serial.println("First Step: Touch and Light");
  bool first = touch_then_light_test();
  if(first == true){
    Serial.println("Second Step: Sound");
    bool second = temperatureTest();
    if(second == true){
      Serial.println("Third Step: Temperature");
      bool third = soundTest();
      if(third == true){
        //if(three_buttons() == true){
          //if(screen_riddle() == true){
            lcd_screen_win();
          //}
        //}
      }
    }
  }
}

////////////////////////////////////////////////////////////////

bool touch_then_light_test(){
    // light and touch test
  while (!touch_test) {
    int current_state = digitalRead(touch_sensor);
    if (current_state == HIGH) {
      Serial.println("The sensor was touched");
      while (!light_test) {
        lcd.clear();
        lcd.print("Hint: It cannot be seen");
        lcd.setCursor(16,1);
        lcd.print("be seen!");
        lcd.begin(16,2);
        int raw_light = analogRead(light_sensor);
        int light = map(raw_light, 0, 1023, 0, 100);
        //Serial.println(light);
        if (light < 50) {
          Serial.println("Light and Touch Test Passed");
          light_test = true;
          return light_test; //test successful, end
        }
      } 
      touch_test = true;
    }
  }
}

bool temperatureTest(){
  // temperature test
  while (!temperature_test) {
    float temperature = dht.readTemperature();
    Serial.println(temperature);
    delay(500);
    if (temperature > 29) {
      temperature_test = true;
      Serial.println("Temperature Test Passed");
      return temperature_test; //test successful, end
    }
    delay(1000); // Adjust the delay as needed
  }
}

bool soundTest(){
  // sound test
  while (!sound_test) {
    int sound = analogRead(sound_sensor);
    Serial.println(sound);
    if (sound > 900) {
      sound_test = true;
      Serial.println("Sound Test Passed");
      return sound_test; //test successful, end
    }
    delay(1000);
  }
}

bool three_buttons(){
  //3 buttons test
  int onOFF1 = digitalRead(BUTTON_PIN1);
  int onOFF2 = digitalRead(BUTTON_PIN2);
  int onOFF3 = digitalRead(BUTTON_PIN3);
  //Serial.println(digitalRead(BUTTON_PIN1));
  //Serial.println(((onOFF1 == 0) && (onOFF2 == 0)) && (onOFF3 == 0));

  if(onOFF1 == 0){
    if(onOFF2 == 0){
      if(onOFF3 == 0){
        digitalWrite(13,HIGH);
        return true; //test successful, end
      }
    }
  } 
  else {
    digitalWrite(13,LOW);
  }
}

bool screen_riddle(){
  //have the lcd display the following riddle with a number answer: 
  lcd.clear();
  lcd.setRGB(0, 0,200);
  lcd.print("What is the answer to life, the universe, and everything?");
  int answer; //gives this a value
  int count = 0;
  if(count == answer){
    return true; //test successful, end
  } else if (count == 0){
    lcd.clear();
    lcd.setRGB(150,0,0);
    lcd.print("Hint: Middle Button = 10, Right Button = 1");
  } else if (count == 100){
    count = 0;
  }

  int state;
  int past_state = digitalRead(BUTTON_PIN1);
  while (count != answer){
    state = digitalRead(BUTTON_PIN1);
    if(past_state != state){
      count+=1;
    }
    past_state = state;
  }
}

int lcd_screen_win(){
  delay(5000);
  win();
  win();
  win();
  win();
  win();
}

int win(){    
  lcd.print("You Win!");     
  lcd.setRGB(224,60,70);   
  delay(500);  
  lcd.setRGB(0,0,0); 
  delay(500);  
  lcd.clear();
}