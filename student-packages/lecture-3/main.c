#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include <stdio.h>

#define LED_PIN 15
#define MAX_DUTY_CYCLE 65535
#define STEP_SIZE 100  // Velikost kroku pro změnu jasu
#define SLEEP_MS 10    // Doba spánku pro zpomalení změny jasu

void init_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();

    pwm_config_set_clkdiv(&config, 64.0f);  // Nastavení frekvence PWM
    pwm_config_set_wrap(&config, MAX_DUTY_CYCLE);

    pwm_init(slice_num, &config, true);
}

void fade_led(uint pin) {
    int duty_cycle = 0;
    int direction = 1;  // 1 pro zvyšování, -1 pro snižování

    while (true) {
        pwm_set_gpio_level(pin, duty_cycle);

        // Změna jasu podle směru
        duty_cycle += STEP_SIZE * direction;

        // Kontrola, jestli je potřeba otočit směr
        if (duty_cycle >= MAX_DUTY_CYCLE) {
            duty_cycle = MAX_DUTY_CYCLE;
            direction = -1;  // Změna směru na snižování
        }
        if (duty_cycle <= 0) {
            duty_cycle = 0;
            direction = 1;  // Změna směru na zvyšování
        }

        sleep_ms(SLEEP_MS);  // Zpoždění pro plynulou změnu jasu
    }
}

int main() {
    stdio_init_all();
    sleep_ms(2000);
    printf("Starting...\n");

    init_pwm(LED_PIN);
    fade_led(LED_PIN);

    return 0;
}
