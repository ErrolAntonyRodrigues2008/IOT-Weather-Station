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
SDA: Connect to the SDA pin on the Arduino (typically A4 on Uno)
SCL: Connect to the SCL pin on the Arduino (typically A5 on Uno)
VCC: Connect to the 3.3V or 5V power supply (check the sensor specifications)
GND: Connect to ground (GND)

-Anemometer
Signal Pin: Connect to digital pin 2 on the Arduino (this pin is used for interrupts)
VCC: Connect to the power supply (check the anemometer specs, typically 5V)
GND: Connect to ground (GND)

-Wind Vane
Connect multiple Reed switches to digital pins 4 to 11 (as specified in the code) for reading the wind direction
Each Reed switch should have one pin connected to the digital pin and the other pin connected to ground (GND)
VCC is not typically required for Reed switches since they are passive

-Rain Gauge
Signal Pin: Connect to digital pin 3 on the Arduino (used for interrupts).
VCC: Connect to the power supply (check the rain gauge specs, typically 5V).
GND: Connect to ground (GND).

