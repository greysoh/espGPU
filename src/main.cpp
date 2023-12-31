#include <Arduino.h>
#include "LLGPU.h"

bool is_set_up;

void setup() {
  Serial.begin(115200);
  Serial.print("device_tree: GPU.");
  Serial.print(921600);
  Serial.print("@");
  Serial.print(LowGPU::get_width());
  Serial.print("x");
  Serial.println(LowGPU::get_height());

  Serial.flush();
  Serial.end(); 
  Serial.begin(921600);
  delay(5000);

  // Encoded OwO
  for (int i = 0; i < LowGPU::get_width(); i++) {
    if (i > LowGPU::get_height()) break;

    LowGPU::putpixel(i, i, 0, 255, 0);
  }
  
  is_set_up = true;
}

void loop() {
  while (!is_set_up) delay(1000);
  LowGPU::processing_loop_iteration();
}