/* Records saved on Voice Recognition Module 3

   Index | Signature
  --------------------
     0   |  YoMama
     1   |  KnockKnock
     42  |  HeresAGood(one)  

*/

#include <SoftwareSerial.h>
#include <VoiceRecognitionV3.h>

VR myVR(2, 3);    // 2:RX 3:TX
uint8_t buf[64];  // Used by the VR3 to write info about detected words
// uint8_t records[3] = { 0, 1, 42 };

byte const YoMama = 0;
byte const KnockKnock = 1;
byte const HeresAGood = 42;

void setup() {

  /* initialize */
  myVR.begin(9600);
  Serial.begin(115200);

  /* load records */
  myVR.load(KnockKnock);
  myVR.load(YoMama);
  myVR.load(HeresAGood);
  // myVR.load(records, 3);

}  // close setup

void loop() {

  int ret = myVR.recognize(buf, 50);

  if (ret > 0) {
    
    switch (buf[1]) {
      case YoMama:
        Serial.println("YoMama Joke detected");
        break;
      case KnockKnock:
        Serial.println("KnockKnock Joke detected");
        break;
      case HeresAGood:
        Serial.println("Dad Joke detected");
        break;
    } //close switch
    
  } // close if

} // close loop























