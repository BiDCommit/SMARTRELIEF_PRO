#ifndef SmartReliefPro_H
#define SmartReliefPro_H
#include <Arduino.h>

typedef struct{
 int address = 0;// адрес памяти для записи (от 0 до 511)   
 int address2 = 1;
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
}SmartReliefVal;
class SmartRelief{
public:
SmartRelief();
void setDuration();
/// Vibro Patterns/////
void pulse1_FastInSlowOut(int Pin);
void pulse3_SOSBlink(int Pin);
void pulse4_BlinkThrice(int Pin);
void pulse5_FadeIn(int Pin);
void pulse8_GradualBuild(int Pin);
void pulse10_DarkFlash(int Pin);
void pulse11_BlinkDecreasing(int Pin);
void pulse12_Heartbeat(int Pin);
void pulse13_BlinkIncreasing(int Pin);
void pulse14_Raindrops(int Pin);
void pulse16_TransmissionRandomBrightness(int Pin);
void pulse17_Lightning(int Pin);
void pulse18_TransmissionFixedBrightness(int Pin);
void pulse19_StaircaseContinuous(int Pin);
void pulse21_StaircaseBlink(int Pin);
void pulse23_BlinkSlow(int Pin);
void pulse24_BlinkFast(int Pin);
void pulse25_PulseSlow(int Pin);
void pulse26_PulseFast(int Pin);
//// First functions///////
void ReleInit(int numRele,int RelePins[]);
void VibroMode(int RelePin);
void HeatZone(int RelePin);
private:
SmartReliefVal Params;
int* RelePins_;
int numRele_;
};
#endif // SmartRelief_H