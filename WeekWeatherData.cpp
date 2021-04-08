#include "Arduino.h"
#include "WeekWeatherData.h"

WeekWeatherData::WeekWeatherData()
{
    for (int i = 0; i < 7; i++)
    {
        _temp[i] = 0;
        _hum[i] = 0;
    }
}

/**
 * Displays weather data for the week in the Serial Monitor. 
 * 
 * In the following format:
 * Temp: xx.xx, Humidity: xx.xx 
 */
void WeekWeatherData::displayWeather()
{
    Serial.println("Display Weather Data");
    for (int i = 0; i < 7; i++)
    {
        Serial.print("Temp");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(_temp[i]);
        Serial.println();
    }
}

/**
 * Displays weather for the specified day in the Serial Monitor. 
 * 
 * In the following format:
 * Temp: xx.xx, Humidity: xx.xx 
 */
void WeekWeatherData::displayWeather(int day)
{
    Serial.print("Temp: ");
    Serial.print(_temp[day]);
    Serial.print(", ");
    Serial.print("Humidity: ");
    Serial.print(_hum[day]);
    Serial.println();

}

/**
 * Returns a string containing the weather for the specified day.
 * 
 * In the following format:
 * T: xx.x H: xx.x
 * 
 * @param day to return weather data for. Current day is 0, the following day is 1...
 * @return A string containing weather for the specified day. 
 */
String WeekWeatherData::stringWeather(int day)
{
    return String("T: " + String(_temp[day],1) + " H: " + String(_hum[day],1));
}

/**
 * Returns a string containing all weather data for the week. 
 * 
 * In the following format:
 * T: xx.x H: xx.x
 * 
 * @return A string containing all weather data for the week. 
 */
String WeekWeatherData::stringAllWeather()
{
    String all_weather = "";

    for (int i = 0; i < 7; i++)
    {
        all_weather += String("T: " + String(_temp[i],1) + " H: " + String(_hum[i],1));

        if (i != 6)
        {
            all_weather += String("\n");
        }
    }

    return all_weather;
}

/**
 * Sets weather data for the WeekWeatherData object. 
 * 
 * @param temp[7], hum[7] the arrays containing temperature and humidity data respectively. 
 */
void WeekWeatherData::setData(float temp[7], float hum[7])
{
    for (int i = 0; i < 7; i++)
    {
        _temp[i] = temp[i];
        _hum[i] = hum[i];
    }
}