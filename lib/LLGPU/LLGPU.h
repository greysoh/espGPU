#include <Arduino.h>

class LowGPU {
  public:
    static void putpixel(int x, int y, int lightness);
    static void clear();

    static int get_width();
    static int get_height();

    static void processing_loop_iteration();
};