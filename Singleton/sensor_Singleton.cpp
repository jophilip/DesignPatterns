#include <iostream>
using namespace std;

class Sensor {
   static Sensor *sensor1;
   int data;
 
   // Private constructor so that no objects can be created.
   Sensor() {
      data = 0;
   }

   public:
   static Sensor *getInstance() {
      if (!sensor1)
      sensor1 = new Sensor;
      return sensor1;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};
