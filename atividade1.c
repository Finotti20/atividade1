#include <stdio.h>
#include "pico/stdlib.h"   // Biblioteca padrão para funcionalidades básicas
#include "hardware/timer.h" // Biblioteca para gerenciamento de temporizadores de hardware

#define LED_PIN_RED 13
#define LED_PIN_BLUE 12
#define LED_PIN_GREEN 11

// Estado do semáforo (0 = vermelho, 1 = azul, 2 = verde)
int state = 0; // Inicia com o LED vermelho ligado

// Função de callback chamada pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_PIN_RED, false);
    gpio_put(LED_PIN_BLUE, false);
    gpio_put(LED_PIN_GREEN, false);

    // Liga o LED correspondente ao estado atual
    if (state == 0) {
        gpio_put(LED_PIN_RED, true);
    } else if (state == 1) {
        gpio_put(LED_PIN_BLUE, true);
    } else {
        gpio_put(LED_PIN_GREEN, true);
    }
    
    // Alterna para o próximo estado
    state = (state + 1) % 3;
    
    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos GPIO
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    gpio_put(LED_PIN_RED, true); // Liga o LED vermelho inicialmente

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Semáforo em funcionamento\n");
        sleep_ms(1000);
    }
    return 0;
}
