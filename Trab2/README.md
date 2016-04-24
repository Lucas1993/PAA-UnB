# Trabalho 2 - Comparação de algoritmos

## Instruções de execução do trabalho:
  * 1. Compilar os algoritmos de ordenação que estão na pasta **Algoritmos**. Para isso, basta apenas dar um **make**. Todos os algoritmos levam um parâmetro(com exceção do mergeinsert\_sort que leva 2 parâmetros). Para executar os algoritmos(com exceção do mergeinsert) apenas faça: `./ALGORITMO_DESEJADO <arq_ent>`. Para executar o mergeinsert_sort faça: `./mergeinsert_sort <k> <arq_ent>`.

  * 2. Gerar as entradas para os algoritmos. Para isso, primeiro temos que compilar o programa **generate_strings.c** com o seguinte comando: `gcc generate_strings.c -o generate_strings`. Depois basta apenas executar o script **call_generate.py** com o seguinte comando no terminal: `python3.5 call_generate.py`.

  * 3. Gerar as saídas com os tempos de cada algoritmo. Para isso execute o script **script.py** com o seguinte comando no terminal: `python3.5 script.py`.

  * 4. Gerar o arquivo que conta as inversões feitas pelo insertion\_sort. Para isso, compilar o programa conta\_inversoes.c com `gcc conta_inversoes.c -o conta_inversoes` e depois executar o script **script_conta.py** com o seguinte comando no terminal: `python3.5 script_conta.py`.
  
## Entradas:
Todas as entradas tem tipos(ordenado, inverso, aleatório) e tamanhos(10,20,...3276800) diferentes. Isso totaliza 60 entradas localizadas na pasta **Entradas**.

## Explicando o formato das saídas:
Na pasta **Saidas**, temos 30 arquivos(cujos nomes seguem o seguinte padrão: **s_ALGORITMO_TIPO.txt**) indicando os tempos de cada algoritmo com cada tipo de entrada (tipo = ordenado, inverso ou aleatório). Cada arquivo desses tem 20 linhas com o tempo de execução do algoritmo para cada um dos 20 tamanhos diferentes da entrada. Esses tempos foram gerados rodando cada algoritmo 10 vezes para cada entrada e depois foi tirada a média desse tempo, como pedido na especificação. 

Exemplo: No arquivo de saída s\_bubble_increasing.txt, a primeira linha do arquivo mostra o tempo demorado pelo algoritmo **bubble\_sort**, com o arquivo de entrada **ordenado** e tamanho de entrada **10**, a segunda linha mostra a mesma coisa, mas com o tamanho de entrada **20**. Os tamanhos estão de maneira crescente (10,20,...,3276800) como mostrado na especificação.

Na pasta **Saidas**, além dos 30 arquivos de saída citados acima, também temos mais 3 arquivos contando o número de inversões (de acordo com o item 6.1 da especificação) em cada entrada. Cada arquivo desse tem o número de inversões em cada tipo de entrada (ordenado, inverso, aleatório), por isso temos apenas 3 arquivos desse tipo. Cada arquivo desses tem 20 linhas, onde cada linha mostra o número de inversões em cada tamanho de entrada diferente.

Exemplo: No arquivo de saída conta\_inversoes_decreasing.txt, a primeira linha mostra o número de inversões em uma entrada com strings na ordem inversa e tamanho **10**. A segunda linha mostra a mesma coisa, mas com o tamanho de entrada **20**. Os tamanhos estão de maneira crescente (10,20,...,3276800) como mostrado na especificação.

## Gráficos:
Os gráficos foram gerados usando o script **graph.r** feito na linguagem **R** e estão localizados na pasta **Graficos** no formato *PNG*. Foi utilizada a biblioteca **ggplot2** para plotar os gráficos.

Alguns gráficos são do modo *log2[tempo(s)] x tamanho_entrada*. Isso foi feito, pois se esses gráficos fossem do tipo *tempo(s) x tamanho_entrada* seriam praticamente ilegíveis, afetando a análise do gráfico.

No total foram feitos 7 gráficos onde:

  - 3 gráficos são do tipo *log2[tempo(s)] x tamanho da entrada*, usados para comparar o tempo dos 10 algoritmos em relação a quantidade de strings na entrada. Esses gráficos são: *grafico_inverso.png*, *grafico_ordenado.png* e *grafico_aleat.png*.
  
  - 3 gráficos são do tipo *tempo(s) x tamanho da entrada*, usados para comparar as 4 variações do mergeinsertion\_sort em relação a quantidade de strings na entrada. Esses gráficos são: *grafico_mergeins_inverso.png*, *grafico_mergeins_ordenado.png* e *grafico_mergeins_aleat.png*.
  
  - 1 gráfico do tipo *log2[tempo(s)] x número de inversões*, usado para comparar o tempo dos 10 algoritmos em relação ao número de inversões na entrada. Nesse gráfico só usamos o número de inversões contidas nas entradas aleatórias e entradas inversas, pois o número de inversões nesses tipos de entradas é maior que 0, fazendo o gráfico ficar mais legível.

## Tabelas:
As tabelas foram geradas usando o script **table.r** feito na linguagem **R** e estão localizadas na pasta **Tabela** nos formatos *csv* e *ods*. Foi utilizada a biblioteca **data.table** para gerar as tabelas. No total, temos 3 tabelas, onde cada uma compara o desempenho de todos os algoritmos para cada tamanho de entrada. Temos 3 tabelas, pois temos 3 tipos de entradas (ordenada, inversa e aleatória).

## Respostas
**d)** O tempo de execução de alguns algoritmos não dependem do número de inversão(no trabalho, o mergesort é o único exemplo). Em alguns algoritmos a quantidade de strings a serem ordenadas influencia mais do que o número de inversões na entrada. Já o tempo de exucação de outros algoritmos(insertionsort, por exemplo) dependem praticamente só do número de inversões na entrada. Isso pode ser visto no gráfico *grafico_inversao_ordinv.png*.

A complexidade do tempo de execução do programa *conta_inversoes* é O(n*log(n)) se for feito usando como base o mergesort(como foi feito nesse trabalho). Se fosse usado como base o insertionsort, sua complexidade seria O(n^2).

------------------------------------------------------------------------------------------

**e)** Os 3 gráficos comparando o desempenho dos quatro mergeinsert\_sorts: *grafico_mergeins_ord.png*, *grafico_mergeins_aleat.png*, *grafico_mergeins_inv.png*.

Analisando os gráficos e as tabelas de resultado, vemos que nao há uma diferença gritante entre os quatro algoritmos. A maior diferença que dá pra notar é quando comparamos os algoritmos com entradas aleatórias. Onde podemos ver que o mergeinsertion_sort com *k = 64* apresenta um desempenho um pouco pior que os outros três algoritmos.

------------------------------------------------------------------------------------------

**f)** Algoritmos que estouraram o tempo de 2 horas com entrada do tipo:

  - Ordenada:
    1. Bubblesort: Tamanho das entradas:
      - 1638400: estimativa -> 4549.96\*4 segundos = **5 horas e 3 minutos**.
      - 3276800: estimativa -> (4549.96\*4)\*4 segundos = **20 horas e 13 minutos**.
    2. Selectionsort:
      - 1638400: estimativa -> 4625.74\*4 segundos = **5 horas e 8 minutos**.
      - 3276800: estimativa -> (4625.74\*4)\*4 segundos = **20 horas e 33 minutos**.

  - Inversa:
    1. Insertion: Tamanho das entradas:
      - 819200: estimativa -> 2308.99\*4 segundos = **2 horas e 34 minutos**.
      - 1638400: estimativa -> 2308.99\*16 segundos = **10 horas e 15 minutos**.
      - 1638400: estimativa -> 2308.99\*64 segundos = **41 horas e 3 minutos**.
    2. Bubblesort: Tamanho das entradas:
      - 819200: estimativa -> 5342.46\*4 segundos = **5 horas e 56 minutos**.
      - 1638400: estimativa -> 5342.46\*16 segundos = **23 horas e 44 minutos**.
      - 3276800: estimativa -> 5342.46\*64 segundos = **94 horas e 58 minutos**.
    3. Selectionsort:
      - 1638400: estimativa -> 4506.83\*4 segundos = **5 horas**.
      - 3276800: estimativa -> 4506.83\*16 segundos = **20 horas e 1 minuto**.
  
  - Aleatoria:
    1. Insertion: Tamanho das entradas:
      - 1638400: estimativa -> 4500.17\*4 segundos = **5 horas**.
      - 1638400: estimativa -> 4500.17\*16 segundos = **20 horas**.
    2. Bubblesort: Tamanho das entradas:
      - 819200: estimativa -> 4109.69\*4 segundos = **4 horas e 34 minutos**.
      - 1638400: estimativa -> 4109.69\*16 segundos = **18 horas e 16 minutos**.
      - 3276800: estimativa -> 4109.69\*64 segundos = **73 horas e 3 minutos**.
    3. Selectionsort:
      - 1638400: estimativa -> 5063.07\*4 segundos = **5 horas e 37 minutos**.
      - 3276800: estimativa -> 5063.07\*16 segundos = **22 horas e 30 minutos**.
      
**g)** Como dito anteriormente, foram geradas 3 tabelas comparando os algoritmos. Vamos analisar cada uma delas separadamente:
  
  - Tabela para entrada ordenada: Nessa tabela, o melhor algoritmo foi o insertionsort. Isso ocorre, pois quando a entrada está ordenada, o insertionsort nunca entra no seu segundo loop, mantendo uma complexidade quase linear.
  
  - Tabela para entrada inversa: Nessa tabela, vemos que o insertionsort tem o pior desempenho disparado, pois este tipo de entrada representa seu pior caso.
  
##Conclusão
Alguns algoritmos apresentaram um bom desempenho independente do tipo da entrada: combsort, shellsort, mergesort e os mergeinsertion_sorts. Do outro lado do espectro, também tivemos algoritmos que se mostraram constantemente ruins para os três tipos de entrada como bubblesort e o selectionsort.

Em geral, escolher o melhor algoritmo não é algo tão simples, pois vemos que o desempenho da maioria dos algoritmos varia dependendo do tipo de entrada (ordenada, inversa ou aleatória). A exceção disso é o mergesort que mantém seu desempenho constante, independente da ordenação da entrada. Vemos também, que a mesclagem do mergesort com o insertionsort é uma ótima ideia, pois ao analisarmos os gráficos e tabelas vemos que as quatro mesclagens do merge e insertion (mergeinsertion_sort) apresentaram melhor desempenho do que o próprio mergesort.