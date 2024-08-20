# Simulador de Robô de Limpeza

Este projeto foi desenvolvido por Tio Ben em 2018, durante o Curso de Mecatrônica no IFPE - Caruaru. O objetivo é simular um robô de limpeza que navega em uma matriz 8x8, removendo sujeiras e evitando obstáculos.

## Funcionalidades

- Simulação de um robô de limpeza que se movimenta automaticamente em uma matriz 8x8.
- Posicionamento manual do robô e da sujeira.
- O robô continua a limpeza até que toda a sujeira seja removida.
  
## Requisitos

Para compilar e executar o programa, você precisará de:

- Um compilador C, como `gcc`.
- Acesso a um terminal de comando.

## Como Usar

### 1. Clonar o Repositório

Clone este repositório para o seu ambiente local:

```bash
git clone <URL_DO_REPOSITORIO>
cd <NOME_DA_PASTA_DO_REPOSITORIO>
```

### 2. Compilar o Código

No terminal, navegue até o diretório onde está localizado o arquivo `main.c` e compile o código:

```bash
gcc -o robo main.c
```

### 3. Executar o Programa

Após a compilação, execute o programa com o seguinte comando:

```bash
./robo
```

### 4. Instruções de Uso

- **Posicionamento do Robô:** Quando solicitado, insira a linha (0-7) e a coluna (0-7) onde deseja posicionar o robô.
- **Posicionamento da Sujeira:** Insira as coordenadas da sujeira na matriz. Para finalizar a inserção, digite `-1` para ambas as coordenadas.
- **Iniciar a Limpeza:** O robô começará a se mover automaticamente até que todas as sujeiras sejam removidas.
- **Fim do Jogo:** O programa exibirá uma mensagem indicando que a limpeza foi concluída, junto com o número de passos dados pelo robô.

## Teste o Código Online

Você pode testar o código diretamente em seu navegador, sem precisar instalar nada, usando o compilador online disponível no seguinte link:

[Teste o código online](https://www.programiz.com/online-compiler/2nScUuS2AmIu3)

## Estrutura do Código

- `main.c`: Contém o código principal do simulador.

## Considerações

- Certifique-se de inserir as coordenadas dentro do intervalo válido (0-7 para linha e coluna).
- Posicionar o robô ou a sujeira fora dos limites da matriz pode causar comportamentos inesperados.

## Limitações

- O programa é baseado em texto e não possui uma interface gráfica.
- O movimento do robô é básico e pode ser aprimorado para cenários mais complexos, como navegação em labirintos.

## Contribuição

Contribuições são bem-vindas! Faça um fork deste repositório e envie um pull request com melhorias ou correções.
