#include <iostream>
using namespace std;

class ErrorLogger{
    static string s_errors;
public:
    static void addError(string newError){
        s_errors += newError += '\n';
    }

    static void printErrors(){
        cout << s_errors << endl;
    }
};

string ErrorLogger::s_errors = "";

class ElectricCar{
    float m_maxAh;
    float m_availableAh;
    float m_carMaxCurrent;
public:
    ElectricCar(float maxAh, float availableAh, float carMaxCurrent){
        if (maxAh <= 0){
            ErrorLogger::addError("ElectricCar: maxAh must be > 0");
            m_maxAh = 1;
        } else {
            m_maxAh = maxAh;
        }
        m_availableAh = availableAh;
        m_carMaxCurrent = carMaxCurrent;
    }

    float getCarMaxCurrent(){
        return m_carMaxCurrent;
    }

    void charge(float maxAhFromPowerStation){
        if (maxAhFromPowerStation > (m_maxAh - m_availableAh))
            m_availableAh = m_maxAh;
        else
            m_availableAh += maxAhFromPowerStation;
    }

    void printInfo(){
        cout << "Max: " << m_maxAh << endl;
        cout << "Available: " << m_availableAh << endl;
    }
};

class PowerStation{
    float m_maxCurrent;
    float m_hourChargeAh;
public:
    PowerStation(float maxCurrent, float hourChargeAh){
        m_maxCurrent = maxCurrent;
        m_hourChargeAh = hourChargeAh;
    }

    void chargeForHour(ElectricCar* car){
        float charge = (car->getCarMaxCurrent()/m_maxCurrent) * m_hourChargeAh;
        car->charge(charge);
    }
};

int main() {
    ElectricCar* tesla = new ElectricCar(20.0, 10.0, 3.0);
    PowerStation* ps1 = new PowerStation(4.0, 4.0);

    ps1->chargeForHour(tesla);
    tesla->printInfo();

    ErrorLogger::printErrors();

    delete ps1;
    delete tesla;
    return 0;
}