#include <iostream>
using namespace std;

class Sensor {
   static Sensor *sensor1;
   int data;
 
   // Private constructor.
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

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Sensor *Sensor::sensor1 = 0;

int test_singleton(){
   Sensor *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(57);
   cout << s->getData() << endl;
   return 0;
}
