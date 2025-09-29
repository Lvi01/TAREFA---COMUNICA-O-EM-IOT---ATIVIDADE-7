# Manipulação de GPIOs na Placa Labrador em Linguagem C

Este projeto demonstra o acionamento de pinos **GPIO** da placa **Labrador** utilizando a linguagem **C**, a biblioteca de alto nível `gpio_high_level.h` e a IDE **Code::Blocks**.
O objetivo é configurar uma GPIO como saída digital e realizar o acionamento periódico de dispositivos, como um LED, através da alternância entre os estados lógico **alto (HIGH)** e **baixo (LOW)**.

---

## Ambiente de Desenvolvimento

- **Placa:** Labrador (Projeto Caninos Loucos)
- **Sistema Operacional:** Distribuição baseada em Debian
- **IDE utilizada:** [Code::Blocks](http://www.codeblocks.org/)
- **Compilador:** GCC
- **Biblioteca utilizada:** `gpio_high_level.h` (abstração para manipulação de GPIOs via sysfs)

---

## Funcionamento do Código

#### Identificação da GPIO
A função `get_gpio_number("C0")` obtém o número lógico correspondente ao pino C0, que será utilizado para manipulação pelo espaço do usuário.

#### Exportação e configuração
O comando `open_gpio(gpio_num)` exporta a GPIO, enquanto `set_gpio_dir(gpio_num, GPIO_DIR_OUT)` define sua direção como saída digital.

#### Laço de execução
O laço `for` alterna o estado da GPIO entre **HIGH** (alto) e **LOW** (baixo) 100 vezes, com atraso de 500 ms entre cada transição. Esse comportamento resulta, por exemplo, no piscar de um LED conectado ao pino.

#### Encerramento
Após o término do laço, o programa é encerrado por `exit(1)`. O `return -1` está presente, mas não é essencial.

---

## Observações

- O mapeamento de GPIOs (grupos A, B, C, D e E) deve ser consultado na documentação oficial da Labrador.
- O exemplo utiliza a GPIO `C0`, mas qualquer outro pino do conector de 40 pinos pode ser utilizado, bastando alterar a string passada à função `get_gpio_number()`.
- A execução do programa deve ser feita com permissões de superusuário (`root`) para garantir acesso aos dispositivos de GPIO.
- O código pode servir como base para aplicações maiores, incluindo acionamento de relés, leitura de sensores digitais ou desenvolvimento de rotinas de automação embarcada.
