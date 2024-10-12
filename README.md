# IOT-Weather-Station

This project features an IoT Weather Station using the Arduino Uno R4 Wi-Fi. It monitors temperature, humidity, atmospheric pressure, wind speed, wind direction, and rainfall using various sensors. Data is uploaded in real-time to the Blynk app for easy remote access and monitoring, making it a versatile tool for weather tracking.

**IMPACT STATEMENT**

1.Increased Accessibility: With user-friendly apps like Blynk, anyone can easily access weather data. This helps people make better decisions about farming, outdoor 
  events, and safety during storms.
2.Cost-Effective: Using affordable components like sensors and Arduino boards keeps the project within a low budget. This makes it possible for schools and small 
  communities to set up their own weather stations without spending too much.
3.Customizable and Scalable: The system can be easily adjusted to fit different needs. Users can add more sensors or change settings based on their specific 
  requirements. It can also grow over time as more features are added.
4.Remote Access: With WiFi capabilities, users can check weather data from anywhere. This is particularly useful for farmers and emergency responders who need up-to- 
  date information to make important decisions.
5.Research and Education: This project provides a hands-on learning experience for students. It encourages interest in science and technology by allowing them to 
  explore how weather works and how to use technology to measure it.

**OVERVIEW**

This project showcases an IoT Weather Station built using the Arduino Uno R4 Wi-Fi, designed to monitor and report various environmental parameters. Utilizing multiple sensors—including the DHT22 for temperature and humidity, the BMP180 for atmospheric pressure, an anemometer for wind speed, a wind vane for wind direction, and a rain gauge for measuring rainfall—this station provides comprehensive weather data. All collected data is uploaded in real-time to the Blynk app, enabling remote monitoring.

**FEATURES**

•DHT22 Sensor: Accurately measures temperature and humidity.

•BMP180 Sensor: Monitors atmospheric pressure, allowing for altitude calculations and weather predictions.

•Anemometer: Measures wind speed in meters per second, providing insights into local wind conditions.

•Wind Vane: Determines wind direction, enhancing understanding of weather patterns.

•Rain Gauge: Counts rainfall events to quantify precipitation over time.

•Real-Time Data Upload: Sends updates to the Blynk app every 10 seconds for continuous monitoring.

•User-Friendly Interface: The Blynk app displays temperature, humidity, pressure, wind speed, wind direction, and rainfall in an easily accessible format.

**COMPONENTS USED**

1.Arduino UNO R4 WiFi - (X1)
2.Reed Switch - (X10)
3.DHT22 - (X1)
4.BMP180 - (X1)
5.3D Printed Parts
6.Wires
7.PVC Pipe
8.PVC Pipe T - Joint (X1)
9.PVC Pipe L - Joint (X2)
10.Electronics Enclosure
11.5x8x2.5 Bearings (X4)

**CONNECTIONS**

1.DHT22 Sensor
DHT22 VCC → Arduino 5V
DHT22 GND → Arduino GND
DHT22 DATA → Arduino Digital Pin 12

2.BMP180 Sensor
BMP180 VCC → Arduino 3.3V
BMP180 GND → Arduino GND
BMP180 SCL → Arduino A5 (SCL)
BMP180 SDA → Arduino A4 (SDA)

3.Anemometer
Reed Switch COM → Arduino Digital Pin 2
Reed Switch NO → Arduino GND

4.Wind Vane
 Connect each reed switch to is designated pin from (4 to 11)
Connect the other side of each switch to Arduino GND    

5.Rain Gauge
Rain Gauge COM → Arduino Digital Pin 3
Rain Gauge NO → Arduino GND


