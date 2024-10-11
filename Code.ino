#define BLYNK_TEMPLATE_ID "TMPL35914SkfN"
#define BLYNK_TEMPLATE_NAME "IOT Weather Station"
#define BLYNK_AUTH_TOKEN "SrFpz6gen8jgXQg6M2yT9bQGECW0CyUd"

#include <DHT.h>
#include <Adafruit_BMP085.h>
#include <WiFiS3.h>
#include <BlynkSimpleWifi.h>

// DHT22 sensor pin connections
#define DHTPIN 12     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

char ssid[] = "Hyacinth";       // WiFi SSID
char pass[] = "Errol19052008*"; // WiFi password

BlynkTimer timer;

// Wind Speed
float radius = 0.065;           // Metres from center pin to middle of cup
volatile int revolutions = 0;   // Counted by interrupt
volatile int rps = 0;           // Revs per second
volatile float mps = 0;         // Wind speed in metres/sec
volatile unsigned long lastTrigger = 0; // Last trigger time
volatile unsigned long debounceTime = 50; // Debounce time in milliseconds
volatile unsigned long lastWindSpeedCalculation = 0; // Last wind speed calculation time

// Rainfall
volatile int rainfallCount = 0; // Count of rainfall tips
volatile unsigned long lastRainfallTip = 0; // Last rainfall tip time

// Wind direction
const int reedPins[] = {4, 5, 6, 7, 8, 9, 10, 11}; // Pin connections for Reed switches
const int numReedSwitches = sizeof(reedPins) / sizeof(reedPins[0]);
const float windDirections[] = {0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5}; // Wind directions in degrees
const char* windDirectionLabels[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"}; // Labels for wind directions

String windDirectionText = ""; // To hold the textual representation of wind direction

// Function to handle wind speed interrupt
void rps_fan() {
    unsigned long currentTime = millis();
    if (currentTime - lastTrigger > debounceTime) {
        revolutions++;
        lastTrigger = currentTime;
    }
}

// Function to handle rainfall interrupt
void rainfall_tip() {
    unsigned long currentTime = millis();
    if (currentTime - lastRainfallTip > debounceTime) {
        rainfallCount++;
        lastRainfallTip = currentTime;
    }
}

void setup() {
    Serial.begin(9600);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

    // Initialize DHT sensor
    dht.begin();

    // Initialize BMP180 sensor
    if (!bmp.begin()) {
        Serial.println("Could not find BMP180 sensor!");
        while (1) {}
    }

    // Set up timer to send data to Blynk every 10 seconds
    timer.setInterval(10000L, sendSensorData);

    // Initialize wind speed interrupt
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), rps_fan, FALLING);

    // Initialize rainfall interrupt
    pinMode(3, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(3), rainfall_tip, FALLING);

    // Initialize Reed switch pins as inputs
    for (int i = 0; i < numReedSwitches; i++) {
        pinMode(reedPins[i], INPUT_PULLUP);
    }
}

void loop() {
    Blynk.run();
    timer.run();

    // Read wind direction
    int windDirectionReading = readWindDirection();
    if (windDirectionReading != -1) {
        // Get the corresponding text label
        windDirectionText = getWindDirectionText(windDirectionReading);
    }

    // Send wind direction text to Blynk
    Blynk.virtualWrite(V6, windDirectionText); // Send textual representation to Blynk
}

void sendSensorData() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    float pressureValue = bmp.readPressure() / 100.0; // Convert to hPa

    // Calculate altitude using pressure value
    float altitude = calcAltitude(pressureValue);

    // Calculate wind speed
    unsigned long currentTime = millis();
    if (currentTime - lastWindSpeedCalculation > 5000) { // 5 seconds
        rps = revolutions / 5;
        revolutions = 0;
        lastWindSpeedCalculation = currentTime;

        // Convert rps to m/s
        mps = rps * 3.1414 * 2 * radius / 60; // Corrected calculation
    }

    // Calculate rainfall
    float rainfall = rainfallCount * 7.0; // 7ml per tip

    // Send data to Blynk
    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
    Blynk.virtualWrite(V2, pressureValue);
    Blynk.virtualWrite(V3, mps);        // Send wind speed to Blynk
    Blynk.virtualWrite(V4, altitude);    // Send altitude to Blynk
    Blynk.virtualWrite(V5, rainfall);    // Send rainfall to Blynk
    Blynk.virtualWrite(V6, windDirectionText); // Send wind direction text to Blynk
}

int readWindDirection() {
    int activatedReedSwitches = 0;
    int reedSwitchValues[numReedSwitches];

    // Read Reed switch states
    for (int i = 0; i < numReedSwitches; i++) {
        reedSwitchValues[i] = digitalRead(reedPins[i]);
        if (reedSwitchValues[i] == LOW) {
            activatedReedSwitches++;
        }
    }

    // Handle multiple Reed switches activated
    if (activatedReedSwitches > 1) {
        int minIndex = -1;
        int maxIndex = -1;
        for (int i = 0; i < numReedSwitches; i++) {
            if (reedSwitchValues[i] == LOW) {
                if (minIndex == -1 || i < minIndex) {
                    minIndex = i;
                }
                if (maxIndex == -1 || i > maxIndex) {
                    maxIndex = i;
                }
            }
        }
        return (windDirections[minIndex] + windDirections[maxIndex]) / 2;
    } else {
        // Find the activated Reed switch
        for (int i = 0; i < numReedSwitches; i++) {
            if (reedSwitchValues[i] == LOW) {
                return windDirections[i];
            }
        }
    }

    return -1; // No Reed switch activated
}

float calcAltitude(float pressure) {
    // Calculate altitude using the barometric formula
    // Assuming a sea-level pressure of 1013.25 hPa
    float altitude = 44330 * (1 - pow(pressure / 1013.25, 0.1903));
    return altitude;
}

// Function to get the wind direction text based on degree
String getWindDirectionText(int degree) {
    if (degree == -1) return "Unknown"; // No direction

    for (int i = 0; i < 16; i++) {
        if (degree < windDirections[i] + 11.25) { // 11.25 is half the interval
            return windDirectionLabels[i];
        }
    }
    return "N"; // Default to North
}
