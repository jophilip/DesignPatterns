// Example  program in C++ to explain factory method design pattern 
#include <iostream> 
using namespace std; 

enum SensorType { 
	S_temp, S_pres, S_humi 
}; 

// Library classes 
class Sensor { 
public: 
	virtual void printSensor() = 0; 
	static Sensor* Create(SensorType type); 
};

class TempSensor : public Sensor { 
public: 
	void printSensor() { 
		cout << "This is temperature sensor" << endl; 
	} 
};

class PressureSensor : public Sensor { 
public: 
	void printSensor() { 
		cout << "This is pressure sensor" << endl; 
	} 
}; 

class HumiditySensor : public Sensor { 
	public: 
	void printSensor() { 
		cout << "This is humidity sensor" << endl; 
	} 
}; 

// Factory method : This method creates objects of different type 
// To create a new object type we need to change only this function
Sensor* Sensor::Create(SensorType type) { 
	if (type == S_temp) 
		return new TempSensor(); 
	else if (type == S_pres) 
		return new PressureSensor(); 
	else if (type == S_humi) 
		return new HumiditySensor(); 
	else return NULL; 
} 

// Utility class 
class Utility { 
public: 

	//Instead of creating objects, Utility passes type to factory method "Create" 
	Utility() 
	{ 
		SensorType type = S_pres; 
		pSensor = Sensor::Create(type); 
	} 
	~Utility() { 
		if (pSensor) { 
			delete[] pSensor; 
			pSensor = NULL; 
		} 
	} 
	Sensor* getSensor() { 
		return pSensor; 
	} 

private: 
	Sensor *pSensor; 
}; 

// main task 
int main() { 
	Utility *pUtility = new Utility(); 
	Sensor * pSensor = pUtility->getSensor(); 
	pSensor->printSensor(); 
	return 0; 
} 
