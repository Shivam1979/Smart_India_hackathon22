#include <LiquidCrystal.h>

const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//-----------------------------
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2);
//#include <Wire.h>
//-----------------------------

#include <dht.h>
#define DHT22 A0

const int ok = A2;
const int UP = A1;
const int DOWN = A3;
const int bulb = 8;
const int vap = 9;
//const int con = 4;

int ack = 0;

int T_threshold = 27;
int H_threshold = 70;
int SET = 0;
//int Direction = 0;
boolean T_condition = true;
boolean H_condition = true;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

dht DHT;
void setup()
{


  Serial.begin(9600);
  //    lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  // lcd.backlight();
  //lcd.setBacklight(HIGH);


  pinMode(ok, INPUT);
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(bulb, OUTPUT);
  pinMode(vap, OUTPUT);
  pinMode(vap, OUTPUT);
  digitalWrite(bulb, LOW);
  digitalWrite(vap, LOW);
  /// digitalWrite(con, LOW);
  digitalWrite(ok, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(DOWN, HIGH);


  Serial.begin(9600);
  lcd.begin(16, 2);

  // LCD coding presentation

  lcd.setCursor(2, 0);
  lcd.print("SIRT AGRITECH");
  lcd.setCursor(0, 1);
  lcd.print("loading.....");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("Checking all the ");
  lcd.setCursor(0, 1);
  lcd.print(" sensor");
  delay(1500);


}

void loop()
{

  if (SET == 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Set Temperature:");
    lcd.setCursor(0, 1);
    lcd.print(T_threshold);
    lcd.print(" *C");
    while (T_condition)
    {
      if (digitalRead(UP) == LOW)
      {
        T_threshold = T_threshold + 1;
        lcd.setCursor(0, 1);
        lcd.print(T_threshold);
        lcd.print(" *C");
        delay(200);


        // botton condition


      }
      if (digitalRead(DOWN) == LOW)
      {
        T_threshold = T_threshold - 1;
        lcd.setCursor(0, 1);
        lcd.print(T_threshold);
        lcd.print(" *C");
        delay(200);
      }
      if (digitalRead(ok) == LOW)
      {
        delay(200);
        T_condition = false;
      }
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Set Humidity:");
    lcd.setCursor(0, 1);
    lcd.print(H_threshold);
    lcd.print("%");
    delay(100);
    while (H_condition)
    {
      if (digitalRead(UP) == LOW)
      {
        H_threshold = H_threshold + 1;
        lcd.setCursor(0, 1);
        lcd.print(H_threshold);
        lcd.print("%");
        delay(100);
      }
      if (digitalRead(DOWN) == LOW)
      {
        H_threshold = H_threshold - 1;
        lcd.setCursor(0, 1);
        lcd.print(H_threshold);
        lcd.print("%");
        delay(200);



      }
      if (digitalRead(ok) == LOW)
      {
        delay(100);
        H_condition = false;
      }
    }
    SET = 1;
  }
  ack = 0;
  int chk = DHT.read22(DHT22);
  switch (chk)
  {
    case DHTLIB_ERROR_CONNECT:
      ack = 1;
      break;
  }
  if (ack == 0)



    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(DHT.temperature);
    lcd.setCursor(0, 1);
    lcd.print("Humidity:");
    lcd.print(DHT.humidity);


    //start condition----------------------------

    //00000000000000000000000000000000000000000000000000000000000000000000000
    //condition -------------for----- heater------------- for 0


    /*
        if (DHT.temperature >= T_threshold)
        {
          delay(400);
          if (DHT.temperature >= T_threshold)
          {
            digitalWrite(bulb, LOW);
          }
        }

        //condition for-------------- fan---------- ----------for 0
        if (DHT.humidity >= H_threshold)
        {
          delay(300);
          if (DHT.humidity >= H_threshold)
          {
            digitalWrite(vap, LOW);
          }
        }


        //condition for-------------- condense---------- ----------for 0
        if ((DHT.humidity >= H_threshold) && (DHT.temperature >= T_threshold))
        {
          delay(300);
          if ((DHT.humidity >= H_threshold) && (DHT.temperature >= T_threshold))
          {
            digitalWrite(con, LOW);
          }
        }



        //1111111111111111111111111111111111111111111111111111111111111111111111111



        //condition -------------for----- heater------------- for 1



        if (DHT.temperature < T_threshold)
        {
          delay(300);
          if (DHT.temperature < T_threshold)
          {
            digitalWrite(bulb, HIGH);
          }
        }



        //condition for-------------- fan---------- ----------for 1

        if (DHT.humidity < H_threshold)
        {
          delay(300);
          if (DHT.humidity < H_threshold)
          {
            digitalWrite(vap, HIGH);
          }
        }



        //condition for-------------- fan---------- ----------for 1


        if ((DHT.humidity >= H_threshold) && (DHT.temperature >= T_threshold))
        {
          delay(300);
          if ((DHT.humidity >= H_threshold) && (DHT.temperature >= T_threshold))
          {
            digitalWrite(vap, HIGH);
          }
        }




        // end ----------------------of -----------------condition

    */












    if ((DHT.humidity >= H_threshold) && (DHT.temperature >= T_threshold))
    {
      // digitalWrite(con, LOW);
    }

    //=============================================================================




    delay(300);
    if (DHT.temperature >= T_threshold)
    {
      digitalWrite(bulb, LOW);
    }

    //======================================================================================================


    delay(300);
    if (DHT.humidity >= H_threshold)
    {
      digitalWrite(vap, LOW);
    }




    //=========================================================================================

    //========================================================================================


    delay(300);
    if (DHT.temperature < T_threshold)
    {
      digitalWrite(bulb, HIGH);
    }



    //============================================================================================

    delay(300);
    if (DHT.humidity < H_threshold)
    {
      digitalWrite(vap, HIGH);
    }




    //===================================================================================================================================



    delay(300);




    // -----------------------------------LOGIC FOR TEMPERATURE--------------------------------------------------
    /*
          if (DHT.temperature <= (T_threshold-3))
           {
             digitalWrite(bulb, HIGH);
             digitalWrite(vap, LOW);

           }
          if (DHT.temperature >= (T_threshold+3))
          {
            digitalWrite(bulb, LOW);
            digitalWrite(vap, HIGH);

          }
          if (DHT.temperature >= (T_threshold-3) && DHT.temperature <=(T_threshold+3) )
          {
            digitalWrite(bulb, LOW);
            digitalWrite(vap, LOW);

          }
      //------------------LOGIC FOR HUMIDITY----------------------------

          if (DHT.humidity <= (H_threshold-3))
          {
            digitalWrite(vap, HIGH);
            digitalWrite(bulb, LOW);
          }
          if (DHT.humidity >= (H_threshold+3))
          {
            digitalWrite(vap, HIGH);
            digitalWrite(bulb,HIGH);
          }
          if (DHT.humidity >= (H_threshold-3) && DHT.humidity <=(H_threshold+3))
          {
            digitalWrite(vap, LOW);
            digitalWrite(bulb, LOW);
          }

      //--------------------- LOGIC FOR TEMP AND HUMIDITY BOTH TOGETHER -------------

         if (DHT.humidity <= (H_threshold-3) && DHT.temperature <= (T_threshold-3))
          {
            digitalWrite(vap, LOW);
            digitalWrite(bulb, HIGH);
          }
      //--------------------- LOGIC FOR CONDENSOR-------------------------------------

          if (DHT.humidity >= (H_threshold+3) && DHT.temperature >= (T_threshold+3))
          {
            digitalWrite(con, HIGH);
          }


    */
  }
  if (ack == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Sensor data.");
    lcd.setCursor(0, 1);
    lcd.print("System Halted.");
    digitalWrite(bulb, LOW);
    digitalWrite(vap, LOW);
  }
  delay(800);
}

//********
