#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/* DHT library 

MIT license
written by Adafruit Industries

Modified by Glenn Ramsey 15/7/2012
Added the ability to disable interrupts. This causes reads to fail more frequently
than with interrupts, but is required to prevent interference with other code that
needs interrupts, for example AC phase control.
Fixed a bug that caused the incorrect data to be returned for the rest of the 
poll period after a read failed. If a read failed then that call would correctly
return NAN but subsequent calls would return whatever was in the buffer.
*/

// how many timing transitions we need to keep track of. 2 * number bits + extra
#define MAXTIMINGS 85

#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21

class DHT {
 private:
  uint8_t data[6];
  uint8_t _pin, _type;
  boolean read(void);
  unsigned long _lastreadtime;
  boolean firstreading;
  boolean _readfailed;
  boolean _disableinterrupts;

 public:
  DHT(uint8_t pin, uint8_t type, bool disableinterrupts=true);
  void begin(void);
  float readTemperature(bool S=false);
  float convertCtoF(float);
  float readHumidity(void);

};
