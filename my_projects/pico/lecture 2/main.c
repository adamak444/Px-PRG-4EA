#include "pico/stdlib.h"
#include <stdbool.h>

// Definice pinů pro tlačítka
#define BUTTON_INCREASE_PIN 6
#define BUTTON_DECREASE_PIN 20

int main() {
    // Inicializace stdio pro komunikaci se Serial monitorem
    stdio_init_all();
    printf("Starting\n");

    // Nastavení pinů pro tlačítka jako vstup
    gpio_init(BUTTON_INCREASE_PIN);
    gpio_set_dir(BUTTON_INCREASE_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_INCREASE_PIN);

    gpio_init(BUTTON_DECREASE_PIN);
    gpio_set_dir(BUTTON_DECREASE_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_DECREASE_PIN);

    int value = 0;  // Počáteční hodnota

    while (true) {
        // Kontrola stisknutí tlačítka pro zvýšení
        if (gpio_get(BUTTON_INCREASE_PIN)) {
            value++;
            printf("Hodnota: %d\n", value);
            sleep_ms(200);  // Debounce zpoždění
        }

        // Kontrola stisknutí tlačítka pro snížení
        if (gpio_get(BUTTON_DECREASE_PIN)) {
            value--;
            printf("Hodnota: %d\n", value);
            sleep_ms(200);  // Debounce zpoždění
        }

        sleep_ms(10);  // Krátké zpoždění, aby se ulevilo CPU
    }

    return 0;
}
