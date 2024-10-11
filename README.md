# IOT-Weather-Station
This project features an IoT Weather Station using the Arduino Uno R4 Wi-Fi. It monitors temperature, humidity, atmospheric pressure, wind speed, wind direction, and rainfall using various sensors. Data is uploaded in real-time to the Blynk app for easy remote access and monitoring, making it a versatile tool for weather tracking.

**OVERVIEW**
This project showcases an IoT Weather Station built using the Arduino Uno R4 Wi-Fi, designed to monitor and report various environmental parameters. Utilizing multiple sensors—including the DHT22 for temperature and humidity, the BMP180 for atmospheric pressure, an anemometer for wind speed, a wind vane for wind direction, and a rain gauge for measuring rainfall—this station provides comprehensive weather data. All collected data is uploaded in real-time to the Blynk app, enabling remote monitoring.

**Features**
-DHT22 Sensor: Accurately measures temperature and humidity.
-BMP180 Sensor: Monitors atmospheric pressure, allowing for altitude calculations and weather predictions.
-Anemometer: Measures wind speed in meters per second, providing insights into local wind conditions.
-Wind Vane: Determines wind direction, enhancing understanding of weather patterns.
-Rain Gauge: Counts rainfall events to quantify precipitation over time.
-Real-Time Data Upload: Sends updates to the Blynk app every 10 seconds for continuous monitoring.
-User-Friendly Interface: The Blynk app displays temperature, humidity, pressure, wind speed, wind direction, and rainfall in an easily accessible format.

**Components Used**
Arduino Uno R4 Wi-Fi
DHT22 Temperature and Humidity Sensor
BMP180 Barometric Pressure Sensor
Anemometer (Reed Switch X1)
Wind Vane (Reed Switch X8)
Rain Gauge (Reed Switch X1)
Blynk app for mobile monitoring

**Connections**
-DHT22 Sensor
Data Pin: Connect to digital pin 12 on the Arduino
VCC: Connect to the 5V power supply
GND: Connect to ground (GND)

- BMP180 Sensor
SDA: Connect to the SDA pin on the Arduino to A4
SCL: Connect to the SCL pin on the Arduino to A5
VCC: Connect to the 3.3V
GND: Connect to ground (GND)

-Anemometer
Reed Switch: 1st leg to pin 2 of Arduino and 2nd leg to GND

-Wind Vane
1st Reed switch (North) - 0°                     1st leg to pin 4 of Arduino and 2nd leg to GND        

2nd Reed switch (North East) - 45°               1st leg to pin 5 of Arduino and 2nd leg to GND 

3rd Reed switch (East)-90°                       1st leg to pin 6 of Arduino and 2nd leg to GND  

4th Reed switch (South East)-135°                1st leg to pin 7 of Arduino and 2nd leg to GND  

5th Reed switch (South)-180°                     1st leg to pin 8 of Arduino and 2nd leg to GND

6th Reed switch (south west)-225°                1st leg to pin 9 of Arduino and 2nd leg to GND

7th Reed switch (west)-270°                      1st leg to pin 10 of Arduino and 2nd leg to GND

8th Reed switch (North West)-315°                1st leg to pin 11 of Arduino and 2nd leg to GND

-Rain Gauge
Reed Switch: 1st leg to pin 3 of Arduino and 2nd leg to GND
