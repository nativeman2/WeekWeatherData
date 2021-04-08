#include "Arduino.h"

#ifndef WeekWeatherData_h
#define WeekWeatherData_h

class WeekWeatherData
{
    public:
        WeekWeatherData();
        void displayWeather();
        void displayWeather(int day);
        String stringWeather(int day);
        String stringAllWeather();
        void setData(float temp[7], float hum[7]);
    private:
        float _temp[7];
        float _hum[7];
    
};

#endif