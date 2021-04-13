/****************************************************************************************************************************
  defines.h
  For ESP8266 / ESP32 boards

  ESP_WiFiManager_Lite (https://github.com/khoih-prog/ESP_WiFiManager_Lite) is a library 
  for the ESP32/ESP8266 boards to enable store Credentials in EEPROM/SPIFFS/LittleFS for easy 
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi and other services without Hardcoding.

  Built by Khoi Hoang https://github.com/khoih-prog/ESP_WiFiManager_Lite
  Licensed under MIT license      
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if !( ESP8266 || ESP32)
  #error This code is intended to run only on the ESP8266/ESP32 boards ! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define ESP_WM_LITE_DEBUG_OUTPUT      Serial

#define _ESP_WM_LITE_LOGLEVEL_        2

#define USING_MRD                     true

#if USING_MRD
  #define MULTIRESETDETECTOR_DEBUG      true
  
  // Number of seconds after reset during which a
  // subseqent reset will be considered a double reset.
  #define MRD_TIMEOUT                   10
  
  // RTC Memory Address for the DoubleResetDetector to use
  #define MRD_ADDRESS                   0
  #warning Using MULTI_RESETDETECTOR
#else
  #define DOUBLERESETDETECTOR_DEBUG     true
  
  // Number of seconds after reset during which a
  // subseqent reset will be considered a double reset.
  #define DRD_TIMEOUT                   10
  
  // RTC Memory Address for the DoubleResetDetector to use
  #define DRD_ADDRESS                   0
  #warning Using DOUBLE_RESETDETECTOR
#endif

/////////////////////////////////////////////

// LittleFS has higher priority than SPIFFS
  #define USE_LITTLEFS    true
  #define USE_SPIFFS      false

/////////////////////////////////////////////

// Add customs headers from v1.2.0
#define USING_CUSTOMS_STYLE           true
#define USING_CUSTOMS_HEAD_ELEMENT    true
#define USING_CORS_FEATURE            true

/////////////////////////////////////////////

// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       false

// Force some params
#define TIMEOUT_RECONNECT_WIFI                    10000L

// Permit running CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET times before reset hardware
// to permit user another chance to config. Only if Config Data is valid.
// If Config Data is invalid, this has no effect as Config Portal will persist
#define RESET_IF_CONFIG_TIMEOUT                   true

// Permitted range of user-defined CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET between 2-100
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

// Config Timeout 120s (default 60s). Applicable only if Config Data is Valid
#define CONFIG_TIMEOUT                      120000L

#define USE_DYNAMIC_PARAMETERS              true

/////////////////////////////////////////////

#include <ESP_WiFiManager_Lite.h>

#if ESP8266 
  #define HOST_NAME   "ESP8266-Controller"
#else
  #define HOST_NAME   "ESP32-Controller"
#endif

#ifdef LED_BUILTIN
  #define LED_PIN     LED_BUILTIN
#else
  #define LED_PIN     13
#endif

#endif      //defines_h
