#include <Arduino.h>

class LowGPU {
  public:
    static void putpixel(int x, int y, int r, int g, int b);
    static void clear();

    static int get_width();
    static int get_height();

    static void processing_loop_iteration();
};