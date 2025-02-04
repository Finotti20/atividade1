![68747470733a2f2f736f667465782e62722f77702d636f6e74656e742f75706c6f6164732f323032342f30392f456d6261726361546563685f6c6f676f5f417a756c2d31303330783432382e706e67](https://github.com/user-attachments/assets/efd58ef1-331a-4978-bb80-52925d9d4b1b)

🛑 Explicação do Código: Semáforo com Raspberry Pi Pico 🚦

Este código implementa um semáforo simples usando um Raspberry Pi Pico e três LEDs (vermelho, azul e verde). Ele alterna entre os LEDs a cada 3 segundos, simulando o funcionamento de um semáforo.

📝 Funcionamento do Código

Definição dos pinos GPIO

LED_PIN_RED → LED vermelho no pino 13

LED_PIN_BLUE → LED azul no pino 12

LED_PIN_GREEN → LED verde no pino 11

Variável state para controlar os LEDs


0 → LED vermelho ligado

1 → LED azul ligado

2 → LED verde ligado

Função repeating_timer_callback


Desliga todos os LEDs

Liga o LED correspondente ao estado atual

Atualiza o estado para o próximo ciclo

Retorna true para manter o temporizador ativo

Configuração dos pinos no main

Inicializa os pinos como saída

Liga o LED vermelho no início

Configura um temporizador de 3 segundos para alternar os LEDs

Mantém o programa rodando com mensagens de status

🔄 Ciclo de Troca dos LEDs

🔴 (Estado 0 - Início) → 3s → 🔵 (Estado 1) → 3s → 🟢 (Estado 2) → 3s → 🔴 (Volta ao início)

O processo se repete indefinidamente, alternando os LEDs a cada 3 segundos.

🚀 Resumo


✅ Uso do Raspberry Pi Pico

✅ Temporizador para alternar LEDs automaticamente

✅ Ciclo contínuo de estados (vermelho → azul → verde)

Este código pode ser expandido para projetos maiores, como simulação de semáforos reais ou sinais luminosos inteligentes. 🚦💡
