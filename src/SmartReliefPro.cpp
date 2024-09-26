#include "SmartReliefPro.h"
#include "esp32-hal-ledc.h"

SmartRelief::SmartRelief(){};
void SmartRelief::setDuration()
{
   for(int i = 0; i < maxIndex; i++)
     {
        Params.coefficient[i] = Params.coefficientPointer[Params.splitResult[1].toInt() - 1][i];
     }
}
void SmartRelief::pulse1_FastInSlowOut(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[0] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[0] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[0] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[0] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[0] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[0] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[0] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[0] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[0] * 100);
}
void SmartRelief::pulse3_SOSBlink(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 50); 
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 100); 
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[2] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[2] * 50);
}

void SmartRelief::pulse4_BlinkThrice(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[3] * 250);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[3] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[3] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[3] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[3] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[3] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[3] * 250);
}

void SmartRelief::pulse5_FadeIn(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[4] * 300);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[4] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[4] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[4] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[4] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[4] * 200);
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
void SmartRelief::pulse8_GradualBuild(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[7] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[7] * 100);
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
void SmartRelief::pulse10_DarkFlash(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[9] * 200);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[9] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[9] * 50);  
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[9] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[9] * 200);
}

void SmartRelief::pulse11_BlinkDecreasing(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[10] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[10] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[10] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[10] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[10] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[10] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[10] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[10] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[10] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[10] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[10] * 100);
}

void SmartRelief::pulse12_Heartbeat(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[11] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[11] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[11] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[11] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[11] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[11] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[11] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[11] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[11] * 50);
}

void SmartRelief::pulse13_BlinkIncreasing(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[12] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[12] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[12] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[12] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[12] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[12] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[12] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[12] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[12] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[12] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[12] * 100);
}

void SmartRelief::pulse14_Raindrops(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[13] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[13] * 50);
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
void SmartRelief::pulse16_TransmissionRandomBrightness(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[15] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[15] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[15] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[15] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[15] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[15] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[15] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[15] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[15] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
}

void SmartRelief::pulse17_Lightning(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[16] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[16] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[16] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[16] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[16] * 100);
}

void SmartRelief::pulse18_TransmissionFixedBrightness(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[17] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[17] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[17] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[17] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[17] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[17] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[17] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[17] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[17] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[17] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[17] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[17] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[17] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
}

void SmartRelief::pulse19_StaircaseContinuous(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[18] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[18] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[18] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[18] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[18] * 150);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[18] * 100);
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
void SmartRelief::pulse21_StaircaseBlink(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[20] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[20] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[20] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[20] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[20] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[20] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[20] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[20] * 100);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[20] * 100);
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

void SmartRelief::pulse23_BlinkSlow(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[22] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[22] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[22] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[22] * 50);
}

void SmartRelief::pulse24_BlinkFast(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[23] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[23] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[23] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[23] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[23] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[23] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[23] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[23] * 50);
}

void SmartRelief::pulse25_PulseSlow(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[24] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]); // end.
}

void SmartRelief::pulse26_PulseFast(int Pin)
{
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[4]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[3]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[1]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[2]);
  delay(Params.coefficient[25] * 50);
  ledcWrite(RelePins_[Pin], Params.vibrationStrength[0]); // end.
}
void SmartRelief::ReleInit(int numRele,int RelePins[]){
   numRele_ = numRele;
   RelePins_ = new int[numRele_];
   for(int i=0; i<numRele_;i++){
        pinMode(RelePins_[i],OUTPUT);
   }
}
void SmartRelief::VibroMode(int RelePin){
Params.currentMillis1=millis();
 unsigned long elapsedTime = Params.currentMillis1-Params.previousMillis1;
if(Params.state == 0){
if(elapsedTime>=Params.interval){Params.state=1; Params.previousMillis1 = Params.currentMillis1; digitalWrite(RelePins_[RelePin],HIGH);}}
else if(Params.state==1){
if(elapsedTime>= Params.ReleTime){Params.state = 2; Params.previousMillis1 = Params.currentMillis1; digitalWrite(RelePins_[RelePin],LOW);}}
else if(Params.state==2){
if(elapsedTime >= Params.ReleTime){Params.state=0; Params.previousMillis1 = Params.currentMillis1;}}
}

void SmartRelief::HeatZone(int RelePin){
Params.currentMillis2=millis();
 unsigned long elapsedTime = Params.currentMillis2-Params.previousMillis2;
if(Params.state == 0){
if(elapsedTime>=Params.interval){Params.state=3; Params.previousMillis2 = Params.currentMillis2; digitalWrite(RelePins_[RelePin],HIGH);}}
else if(Params.state==3){
if(elapsedTime>= Params.ReleTime){Params.state = 4; Params.previousMillis2 = Params.currentMillis2; digitalWrite(RelePins_[RelePin],LOW);}}
else if(Params.state==4){
if(elapsedTime >= Params.ReleTime){Params.state=0; Params.previousMillis2 = Params.currentMillis2;}}
}