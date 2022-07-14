#ifndef SENSOR_HUB_H_
#define SENSOR_HUB_H_

#define HIDE_BLE_SCAN_RESULTS
#define USE_WHITELIST_FILTER

/* Aquí se deben configurar las direcciones fisicas del periferico BLE de nuestros sensores */
/* Mirando el monitor del sensor, se puede obtener la MAC con este formato: fc f5 c4 0e cc 62 */
/* Debe transformarse para que quede como se ve a continuacion, agregando "0x" y "," */

#define TEMP_SENSOR_1_BLE_ADDR      { 0xa4, 0xcf, 0x12, 0x1b, 0xd4, 0x46 }
#define TEMP_SENSOR_2_BLE_ADDR      { 0xfc, 0xf5, 0xc4, 0x0e, 0xcc, 0x62 }

#define MAX_SENSORS_QUANTITY        10

typedef struct 
{
    float temp;
    uint8_t ble_addr[8];
    uint8_t registered;
} tempSensor_t;

typedef struct
{
    // Hub props
    tempSensor_t *tempSensor;
    uint8_t *sensorCount;

    // Hub Functions
    void (*initialize)(void);
    int8_t (*add_sensor)(uint8_t *sensorBleAddr);
    void (*update_sensor_data)(uint8_t *bleAddr, uint8_t *data, uint8_t data_len);
    void (*register_white_list)(void);
} sensorHub_t;

extern const sensorHub_t sensorHub;




#endif /* SENSOR_HUB_H_ */