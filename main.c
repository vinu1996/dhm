+#include "TinyGPS++.h"
+#include "SoftwareSerial.h"
+
+SoftwareSerial serial_connection(10, 11); //RX=pin 10, TX=pin 11
+TinyGPSPlus gps;//This is the GPS object that will pretty much do all the grunt work with the NMEA data
+void setup()
+{
+  Serial.begin(9600);//This opens up communications to the Serial monitor in the Arduino IDE
+  serial_connection.begin(9600);//This opens up communications to the GPS
+  Serial.println("GPS Start");//Just show to the monitor that the sketch has started
+}
+
+void loop()
+{
+  while(serial_connection.available())//While there are characters to come from the GPS
+  {
+    gps.encode(serial_connection.read());//This feeds the serial NMEA data into the library one char at a time
+  }

+}
