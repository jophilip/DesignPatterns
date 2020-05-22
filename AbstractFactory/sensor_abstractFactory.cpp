#include <iostream>

using namespace std;

class Sensor {
  public:
    Sensor() {
      id_ = total_++;
    }
    virtual void output() = 0;
  protected:
    int id_;
    static int total_;
};
int Sensor::total_ = 0;

class Temperature : public Sensor {
  public:
    void output() {
      cout << "temperature " << id_ << ": output" << endl;
    }
};
class Current : public Sensor {
  public:
    void output() {
      cout << "Current " << id_ << ": output" << endl;
    }
};
class CO2 : public Sensor {
  public:
    void output() {
      cout << "CO2 " << id_ << ": output" << endl;
    }
};
class TVOC : public Sensor {
  public:
    void output() {
      cout << "TVOC " << id_ << ": output" << endl;
    }
};

class Factory {
  public:
    virtual Sensor* createBoardInstance() = 0;
    virtual Sensor* createGasInstance() = 0;
};

class roomSensorFactory : public Factory {
  public:
    Sensor* createBoardInstance() {
      return new Temperature;
    }
    Sensor* createGasInstance() {
      return new CO2;
    }
};
class carSensorFactory : public Factory {
  public:
    Sensor* createBoardInstance()   {
      return new Current;
    }
    Sensor* createGasInstance() {
      return new TVOC;
    }
};

int main() {

  Factory* factory1 = new roomSensorFactory;
  Factory* factory2 = new carSensorFactory;

  Sensor* sensor[6];

  sensor[0] = factory1->createBoardInstance();
  sensor[1] = factory1->createGasInstance();
  sensor[2] = factory1->createBoardInstance();
  sensor[3] = factory2->createBoardInstance();
  sensor[4] = factory2->createGasInstance();
  sensor[5] = factory2->createBoardInstance();

  for (int i=0; i < 6; i++) {
    sensor[i]->output();
  }
}
