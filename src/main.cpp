#include <Arduino.h>
#include <BluetoothSerial.h>
#include <EEPROM.h>
#define Hot 5 
#define Vibro 4
#include "esp32-hal-ledc.h"

BluetoothSerial ESP_BT; // создиние объекта для Bluetooth
/////////////// массив смещений для вираций
//частота ШИМ                                         
const int frequency = 5000;

//канал, на который назначим в дальнейшем ШИМ                                         
const int ledChannel = 0;

//разрешение ШИМа (в битах)
const int resolution = 8;


#define maxIndex 26
String splitResult[6]; // Save the result of the split function.
int vibrationStrength[5] = {0, 150, 185, 220, 255}; // The second argument to the digitalWrite function.
float coefficient[maxIndex]; // A coefficient that multiplies each pulse to adjust the pulse period.
                                   
// Coefficients that multiply each pulse to match the period //
float coefficientSet1[maxIndex] = {1.9231, 3.3333, 1.9231, 3.3333, 3.3333, 3.3333, 2.2727, 2.2727, 2.1739, 3.3333,  // Duration : 2.500 second.  - Experiment 3
                                   2.7778, 4.5455, 2.7778, 3.8462, 3.1250, 2.5000, 2.7778, 2.5000, 3.3333, 3.3333,
                                   3.5714, 1.9231, 12.5000, 6.2500, 2.9412, 1.5152};                                

// An array of pointers to point to a set of coefficient //   
float * coefficientPointer[10] = {coefficientSet1};
void setDuration()
{
   for(int i = 0; i < maxIndex; i++)
     {
        coefficient[i] = coefficientPointer[splitResult[1].toInt() - 1][i];
        //Serial.print("Pulse "); Serial.print(i + 1); Serial.print(" Duration : "); Serial.println(defaultDuration[i] * coefficient[i]); // Print duration.
     }
}
void pulse1_FastInSlowOut()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[0] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[0] * 100);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[0] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[0] * 150);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[0] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[0] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[0] * 100);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[0] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[0] * 100);
}
void pulse3_SOSBlink()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 50); 
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 100); 
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[2] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[2] * 50);
}

void pulse4_BlinkThrice()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[3] * 250);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[3] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[3] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[3] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[3] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[3] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[3] * 250);
}

void pulse5_FadeIn()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[4] * 300);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[4] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[4] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[4] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[4] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[4] * 200);
}
/*
void pulse6_FadeOut()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[5] * 200);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[5] * 100);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[5] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[5] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[5] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[5] * 300);
}

void pulse7_EKG()
{
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[6] * 100);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[6] * 200);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[6] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[6] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
}
*/
void pulse8_GradualBuild()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[7] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[7] * 100);
}
/*
void pulse9_Lighthouse()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[8] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[8] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[8] * 50); 
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[8] * 50); 
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[8] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[8] * 50); 
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[8] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[8] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[8] * 100);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[8] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[8] * 50); 
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[8] * 50); 
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[8] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[8] * 50); 
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[8] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[8] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[8] * 100);
}
*/
void pulse10_DarkFlash()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[9] * 200);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[9] * 150);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[9] * 50);  
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[9] * 150);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[9] * 200);
}

void pulse11_BlinkDecreasing()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[10] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[10] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[10] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[10] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[10] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[10] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[10] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[10] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[10] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[10] * 150);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[10] * 100);
}

void pulse12_Heartbeat()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[11] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[11] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[11] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[11] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[11] * 150);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[11] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[11] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[11] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[11] * 50);
}

void pulse13_BlinkIncreasing()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[12] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[12] * 150);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[12] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[12] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[12] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[12] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[12] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[12] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[12] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[12] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[12] * 100);
}

void pulse14_Raindrops()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[13] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[13] * 50);
}
/*
void pulse15_Candle()
{
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[14] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[14] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[14] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[14] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[14] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[14] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[14] * 50);  
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[14] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[14] * 50);  
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[14] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[14] * 50);  
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[14] * 50);  
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[14] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
}
*/
void pulse16_TransmissionRandomBrightness()
{
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[15] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[15] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[15] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[15] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[15] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[15] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[15] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[15] * 100);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[15] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[15] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[15] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[15] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[15] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
}

void pulse17_Lightning()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[16] * 100);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[16] * 150);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[16] * 100);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[16] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[16] * 100);
}

void pulse18_TransmissionFixedBrightness()
{
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[17] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[17] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[17] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[17] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[17] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[17] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[17] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[17] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[17] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[17] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[17] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[17] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[17] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
}

void pulse19_StaircaseContinuous()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[18] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[18] * 150);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[18] * 150);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[18] * 150);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[18] * 150);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[18] * 100);
}
/*
void pulse20_Twinkle()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[19] * 100);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[19] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[19] * 100);
}
*/
void pulse21_StaircaseBlink()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[20] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[20] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[20] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[20] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[20] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[20] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[20] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[20] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[20] * 100);
}
/*
void pulse22_IrregularBlink()
{
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[21] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[21] * 150);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[21] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[21] * 100);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[21] * 150);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[21] * 100);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[21] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
}
*/

void pulse23_BlinkSlow()
{
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[22] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[22] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[22] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[22] * 50);
}

void pulse24_BlinkFast()
{
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[23] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[23] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[23] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[23] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[23] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[23] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[23] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[23] * 50);
}

void pulse25_PulseSlow()
{
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[24] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]); // end.
}

void pulse26_PulseFast()
{
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[4]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[3]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[1]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[2]);
  delay(coefficient[25] * 50);
  ledcWrite(ledChannel, vibrationStrength[0]); // end.
}
///////////////
void VibroMode();
void HeatZone();
// переменные для отсчета минут и секунд
int SEC = 0;
int MIN = 0;

char incoming;//переменная для оправки
///////////////
long ReleTime = 20000;
long A = 60000; // 1 min
long B = 300000; // 5 min
long C = 900000; // 15 min
long D = 1800000;  // 30 min
unsigned long interval = A;
unsigned long previousMillis1 = 0 ;
unsigned long previousMillis2 = 0 ;
int state=0;
/////////////////////////
unsigned long currentMillis1 = 0;
unsigned long currentMillis2 = 0;
//////////////
int ReleState1 = LOW;
int ReleState2 = LOW;
// флаги для управления режимами
bool ZONE1 = false;
bool ZONE2 = false;
/// Статус подключения bluetooth 
void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
  if(event == ESP_SPP_SRV_OPEN_EVT){
    ESP_BT.print("Client Connected");}
  else {ESP_BT.print("Client Disconnected");}}

 void VibroMode(){
currentMillis1=millis();
 unsigned long elapsedTime = currentMillis1-previousMillis1;
if(state == 0){if(elapsedTime>=interval){state=1; previousMillis1 = currentMillis1; digitalWrite(Vibro,HIGH);}}
else if(state==1){
if(elapsedTime>= ReleTime){state = 2; previousMillis1 = currentMillis1; digitalWrite(Vibro,LOW);}}
else if(state==2){if(elapsedTime >= ReleTime){state=0; previousMillis1 = currentMillis1;}}
}

   void HeatZone(){
currentMillis2=millis();
 unsigned long elapsedTime = currentMillis2-previousMillis2;
if(state == 0){if(elapsedTime>=interval){state=3; previousMillis2 = currentMillis2; digitalWrite(Hot,HIGH);}}
else if(state==3){
if(elapsedTime>= ReleTime){state = 4; previousMillis2 = currentMillis2; digitalWrite(Hot,LOW);}}
else if(state==4){if(elapsedTime >= ReleTime){state=0; previousMillis2 = currentMillis2;}}
  }

void setup() {
  pinMode(Hot,OUTPUT);
pinMode(Vibro,OUTPUT);
  EEPROM.begin(512);  // Инициализация EEPROM с размером 512 байт
    int address = 0;   // адрес памяти для записи (от 0 до 511)
    byte value = 123;  // значение данных (от 0 до 255)
    EEPROM.write(address, value);  // Запись данных
    EEPROM.commit();   // Сохранение изменений

 value = EEPROM.read(address);   // Чтение данных

 EEPROM.end(); 


Serial.begin(9600);
Serial.println("--------------->"+value);
////подключим шим
ledcSetup(ledChannel, frequency, resolution);

// подключаем ШИМ-канал к пину светодиода:                                         
ledcAttachPin(Vibro, ledChannel);
  for(int i = 0; i < maxIndex; i++)
    coefficient[i] = coefficientSet1[i];
///////////////////////
 // ESP_BT.begin("SmartRelief V1.0"); //Название устройсва Bluetooth
  // ESP_BT.register_callback(callback);
 //  previousMillis1 = millis();
 //  previousMillis2 = millis();

}

void loop() {
pulse1_FastInSlowOut();
  delay(1500);

        pulse3_SOSBlink();
      delay(1500);
        pulse4_BlinkThrice();
       delay(1500);
        pulse5_FadeIn();
  delay(1500);
        pulse8_GradualBuild();
        delay(1500);
        pulse10_DarkFlash();
        delay(1500);
        pulse11_BlinkDecreasing();
        delay(1500);
        pulse12_Heartbeat();
      delay(1500);
        pulse13_BlinkIncreasing();
       delay(1500);
        pulse14_Raindrops();
       delay(1500);
        pulse16_TransmissionRandomBrightness();
        delay(1500);
        pulse17_Lightning();
         delay(1500);
        pulse18_TransmissionFixedBrightness();
       delay(1500);
        pulse19_StaircaseContinuous();
       delay(1500);
        pulse21_StaircaseBlink();
       delay(1500);
        pulse23_BlinkSlow();
        delay(1500);
        pulse24_BlinkFast();
     delay(1500);
        pulse25_PulseSlow();
        delay(1500);
        pulse26_PulseFast();
    delay(1500);
  
  /*
    if (ESP_BT.available())//Проверяем, получаем ли мы что-нибудь по Bluetooth
 {incoming = ESP_BT.read(); //Считываем что мы получаем
 if(incoming=='1'){
ZONE1=true;}
 if(incoming=='2'){
ZONE1=false; digitalWrite(Vibro, LOW);}
if(incoming=='3'){
ZONE2=true;}
if(incoming=='4'){
ZONE2=false; digitalWrite(Hot,LOW);}
if(incoming=='A'){
interval = A;}
if(incoming=='B'){
interval = B;}
if(incoming=='C'){
interval = C;}
if(incoming=='D'){
interval = D;}
 }
 if(ZONE1==true){
  VibroMode();
 }
 if(ZONE2==true){
  HeatZone();
 }
 */
}

