# Robo de Limpeza

Este projeto foi desenvolvido por Tio Ben, no IFPE - Caruaru, no Curso de Mecatrônica em 2018.

Este projeto implementa um simulador simples de um robô de limpeza que se move em uma matriz 8x8, limpando sujeira e evitando obstáculos. O robô é inicializado em uma posição especificada pelo usuário e limpa sujeiras colocadas manualmente até que toda a sujeira seja removida.

## Pré-requisitos

Para compilar e executar este programa, você precisará de:

- Um compilador C, como `gcc`, instalado em seu sistema.
- Um terminal de comando para executar os comandos necessários.

## Como Usar

### 1. Clonar o Repositório

Primeiro, clone este repositório para o seu ambiente local:

```bash
git clone <URL_DO_REPOSITORIO>
cd <NOME_DA_PASTA_DO_REPOSITORIO>
2. Compilar o Código
No terminal, navegue até o diretório onde está localizado o arquivo main.c e compile o código com o comando:

bash
Copiar código
gcc -o robo main.c
3. Executar o Programa
Após a compilação bem-sucedida, execute o programa com o seguinte comando:

bash
Copiar código
./robo
4. Instruções de Uso
Posicionamento do Robô
Quando solicitado, insira a linha (0-7) e a coluna (0-7) onde deseja posicionar o robô.

Posicionamento da Sujeira
Após posicionar o robô, insira as coordenadas da sujeira na matriz. Você pode repetir este processo várias vezes para colocar sujeiras em diferentes locais. Para finalizar a inserção de sujeira, digite -1 para ambas as coordenadas (linha e coluna).

Iniciar a Limpeza
O robô começará a se mover automaticamente, limpando as sujeiras até que todas sejam removidas.

Fim do Jogo
O programa mostrará uma mensagem indicando que a limpeza foi concluída e o número de passos dados pelo robô.

Estrutura do Código
main.c: O arquivo principal que contém o código do simulador de limpeza do robô.
Considerações
Certifique-se de que as entradas do usuário estejam dentro dos limites (0-7 para linha e coluna).
Se o robô ou a sujeira forem posicionados fora dos limites da matriz, o comportamento do programa pode ser imprevisível.
Limitações
O programa não possui uma interface gráfica, sendo totalmente baseado em texto.
O movimento do robô é básico e pode ser aprimorado para lidar com situações mais complexas, como labirintos.
Contribuição
Sinta-se à vontade para fazer fork deste repositório e enviar pull requests com melhorias ou correções.
