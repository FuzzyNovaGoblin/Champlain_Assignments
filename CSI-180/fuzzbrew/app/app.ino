const unsigned long WAIT_TIME = 1000;
bool motOn;
unsigned long countTime;
unsigned long lasTime;
unsigned long time;

//-------PINS------
const uint8_t Motor_PIN = 7;
const uint8_t Button_PIN = 8;

void setup()
{
   motOn = false;
   lasTime = millis();
   pinMode(Motor_PIN, OUTPUT);
}

void loop()
{
   // time = millis();
   // countTime += (time - lasTime);
   // lasTime = time;
   // if (countTime >= WAIT_TIME)
   // {
   //    motOn = !motOn;
   //    countTime -= WAIT_TIME;
   // }
   if (digitalRead(Button_PIN) == HIGH)
   {
      digitalWrite(Motor_PIN, HIGH);
   }
   else
   {
      digitalWrite(Motor_PIN, LOW);
   }
}
