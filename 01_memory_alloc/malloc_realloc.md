## Alocação dinâmica

```c
#define MAX 1000

float vet[MAX]; // definimos um vetor de tamanho MAX (1000)
float* vet = (float*) malloc(n * sizeof(float)); // n representa uma variável com a dimensão do vetor, em tempo de execução
```

Neste caso, a área de memória ocupada pelo vetor permanece válida até que seja explicitamente liberada (através da função
free)

Portanto, mesmo que um vetor seja criado dinamicamente dentro da função, podemos acessá-lo depois da função ser finalizada, 
pois a área de memória ocupada por ele permanece válida, isto é, o vetor não está alocado na pilha de execução

## Realocação dinâmica

C oferece um mecanismo para realocar um vetor dinamicamente. Em tempo de execução, podemos verificar que a dimensão inicialmente escolhida para um vetor tornou-se insuficiente (ou excessivamente grande), necessitando um redimensionamento. 

A função ```realloc``` da biblioteca padrão nos permite redimensionar um vetor, preservando os elementos existentes, que permanecem inalterados após a realocação. O fragmento de código a seguir ilustra o uso da função realloc . Neste trecho, a variável m representa a nova dimensão do vetor:

```c
vet = (float *) realloc(vet, m*sizeof (float ));
```
A partir desta realocação, se bem-sucedida, vet aponta para uma área de
memória contígua suficiente para armazenar m valores reais. A função
realloc recebe dois parâmetros: o endereço de memória do vetor a ser
redimensionado e o novo número, em bytes, a ser reservado para o vetor.

```c
float * temp = (float *) malloc(m*sizeof (float )); // aloca novo vetor 
int min = m < n ? m : n; // menor valor entre m e n 
memcpy(temp , vet, min*sizeof (float )); // copia elementos
free(vet); // libera vetor original
vet = temp; // atribui novo endereço à variável original
```

Uma realocação de vetor, embora possível e muito útil, tem um alto custo computacional. 

A execução da função realloc pode ser, na verdade, um pouco mais eficiente, **pois o sistema tenta preservar o vetor no espaço de memória já reservado para ele**. Se a nova dimensão é maior que a original, o sistema verifica se um espaço de memória adicional à frente do vetor está livre; se sim, ele é incorporado ao espaço reservado para o vetor

### A função realloc é especialmente importante para a implementação de vetores dinâmicos que envolvem grandes quantidades de informações.


Contudo, podemos adotar uma estratégia semelhante para implementar cadeias de caracteres dinâmicas. Aqui, o principal objetivo é abstrair o gerenciamento da memória e sempre representar a cadeia com a dimensão necessária. 

### Como o realloc funciona por baixo dos panos?

A execução da função realloc tenta ser eficiente:

- Expansão local: O sistema verifica se há memória livre logo à frente do vetor atual. Se houver, ele apenas "estica" o vetor (muito rápido).

- Realocação real: Se não houver espaço contíguo, ele:

- Aloca um novo bloco em outro lugar da memória.

- Copia os dados do antigo para o novo (memcpy).

- Libera o antigo (free).

- Retorna o novo endereço.

## Boas práticas:
### Estratégia de crescimento exponencial
Realocar o vetor a cada inserção (n + 1) é ineficiente (custo computacional alto de cópia). O padrão de mercado é dobrar a capacidade quando o vetor enche e reduzir pela metade se esvaziar muito.

```c
if (n == nmax) {
    // Se nmax for 0, inicia com 2. Senão, dobra.
    int novo_nmax = (nmax == 0) ? 2 : nmax * 2;
    // ... chama realloc com novo_nmax ...
}
```
Encolhimento: Para economizar memória, reduzimos o vetor se o uso cair abaixo de 50% `(n < nmax/2)`.

### Realocação segura
Fazer vetor = realloc(vetor, ...) direto é perigoso. Se o realloc falhar (retornar NULL por falta de memória), você perde o endereço original dos dados, causando um vazamento de memória (memory leak).

A forma segura é:
```c
float* temp = (float*) realloc(vetor, novo_tamanho);
if (temp != NULL) {
    vetor = temp; // Só atualiza se deu certo
} else {
    // Trata o erro, mas os dados originais em 'vetor' ainda estão salvos
    printf("Erro: Memória insuficiente.\n");
}
```

### Manipulação de Strings (`char*`)

Strings em C exigem cuidados especiais:
- Caractere nulo: Sempre alocar tamanho + 1 para lidar com \0.
- Cópia: Jamais usa = para strings. Use strcpy(destino, origem).
- Leitura com scanf (Scanset): O %s para no espaço. Para ler nomes completos:
```c
// O espaço antes do % limpa o buffer (lixo de enters anteriores)
// [^\n] lê tudo até encontrar uma quebra de linha
fscanf(f, " %[^\n]", nome);
```

### Liberação de Memória (de dentro para fora)
Para destruir estruturas complexas, a ordem do free é crucial. Deve-se liberar da `"ponta"` para a `"raiz"`.

```c
void libera_turma(Turma* t) {
    // 1. Libera o conteúdo individual (Nível 3)
    for (int i = 0; i < t->n; i++) {
        free(t->p[i]); 
    }
    
    // 2. Libera o vetor de ponteiros (Nível 2)
    free(t->p);
    
    // 3. Libera a estrutura principal (Nível 1)
    free(t);
}
```