#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent an IoT sensor data
typedef struct {
    int sensor_id;
    char sensor_type[20];
    float value;
    char timestamp[30];
} SensorData;

// Function to simulate reading sensor data
SensorData read_sensor_data(int id, const char* type, float min_val, float max_val) {
    SensorData data;
    data.sensor_id = id;
    strcpy(data.sensor_type, type);
    
    // Generate random value between min_val and max_val
    data.value = min_val + ((float)rand() / RAND_MAX) * (max_val - min_val);
    
    // Get current timestamp
    time_t now = time(0);
    strcpy(data.timestamp, ctime(&now));
    // Remove newline from timestamp
    data.timestamp[strlen(data.timestamp) - 1] = '\0';
    
    return data;
}

// Function to display sensor data (simulating data transmission)
void transmit_data(SensorData data) {
    printf("=== IoT Data Transmission ===\n");
    printf("Sensor ID: %d\n", data.sensor_id);
    printf("Sensor Type: %s\n", data.sensor_type);
    printf("Value: %.2f\n", data.value);
    printf("Timestamp: %s\n", data.timestamp);
    printf("Data transmitted successfully!\n\n");
}

// Function to simulate IoT communication protocol
void iot_communication_demo() {
    printf("Starting IoT Communication Demo...\n\n");
    
    // Initialize random seed
    srand(time(NULL));
    
    // Simulate different types of sensors
    SensorData temperature = read_sensor_data(1, "Temperature", 15.0, 35.0);
    SensorData humidity = read_sensor_data(2, "Humidity", 30.0, 80.0);
    SensorData pressure = read_sensor_data(3, "Pressure", 980.0, 1020.0);
    
    // Transmit data from each sensor
    transmit_data(temperature);
    transmit_data(humidity);
    transmit_data(pressure);
    
    printf("IoT Communication Demo completed.\n");
}

int main() {
    printf("IoT Communication System - Activity 7\n");
    printf("=====================================\n\n");
    
    // Run the IoT communication demonstration
    iot_communication_demo();
    
    return 0;
}