#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {
  stdio_init_all();
  adc_init();
  adc_gpio_init(28);
  adc_select_input(2);

  while (1) {
    int val = adc_read();
    int r = 10000;
    float vcc = 3.3;
    uint32_t beta = 3977;
    float vrt;
    float rt;
    float t;
    
    vrt = (3.3*val)/4095;
    rt = r/((vcc/vrt)-1);
    t = beta/(log(rt/r)+(beta/298.0));
    t = t - 273.15;

    printf ("Resistencia del Termistor = %.2f Temperatura \n", rt);
    printf ("Temperatura = %.2f\n", t);
    sleep_ms(500);
  }
}
