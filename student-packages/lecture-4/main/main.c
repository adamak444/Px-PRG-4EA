#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

uint16_t map_value(uint16_t value, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main() {
    const uint LED_PIN = 15;
    const uint ADC_PIN = 26;

    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);

    pwm_set_wrap(slice_num, 65535);
    pwm_set_gpio_level(LED_PIN, 0);
    pwm_set_enabled(slice_num, true);

    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(0);

    while (true) {
        uint16_t adc_value = adc_read();
        uint16_t pwm_value = map_value(adc_value, 0, 4095, 0, 65535);
        pwm_set_gpio_level(LED_PIN, pwm_value);
        sleep_ms(10);
    }

    return 0;
}
