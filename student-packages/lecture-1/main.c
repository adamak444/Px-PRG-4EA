// Pico SDK libraries
#include "pico/stdlib.h"

#define LED_PIN 6
#define BLINK_DELAY_MS 1000
#define tecka_DELAY_MS 250
#define carka_DELAY_MS 600

int blinktecka(){

  gpio_put(LED_PIN, 1);
        sleep_ms(tecka_DELAY_MS);

        // Turn off the LED
        gpio_put(LED_PIN, 0);
        sleep_ms(tecka_DELAY_MS);  
}

int blinkcarka(){

  gpio_put(LED_PIN, 1);
        sleep_ms(carka_DELAY_MS);

        // Turn off the LED
        gpio_put(LED_PIN, 0);
        sleep_ms(carka_DELAY_MS);
}

int main()
{
    // Initialize GPIO pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Infinite loop
    while (1)
    {
        blinktecka();
        blinktecka();
        blinktecka();

        blinkcarka();
        blinkcarka();
        blinkcarka();

        blinktecka();
        blinktecka();
        blinktecka();

        sleep_ms(BLINK_DELAY_MS);
    }
    return 0;
}
