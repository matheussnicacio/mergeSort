#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10000

// Prototipos de Função
void geraNumero(int *vet, int op);

void mergeSort(int *vet, int inicio, int fim);

void merge(int *vet, int inicio, int meio, int fim);

void imprimirVetor(int *vet);

// Variáveis Globais
int qtd_comparacoes, qtd_trocas;

int main(void) {
    int vet1[TAMANHO];
    float tempo_inicial, tempo_final;
    printf("----- MERGE SORT -----\n");
    // ORDENADO
    printf("Ordenado:\n");
    qtd_trocas = 0;
    qtd_comparacoes = 0;
    geraNumero(vet1, 1);
    tempo_inicial = clock();
    mergeSort(vet1, 0, TAMANHO - 1);
    tempo_final = clock() - tempo_inicial;
    printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
    printf("Quantidade de trocas: %i\n", qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f segundos\n", tempo_final / 1000);


    // INVERTIDO
    printf("\nInvertido:\n");
    qtd_trocas = 0;
    qtd_comparacoes = 0;
    geraNumero(vet1, 2);
    tempo_inicial = clock();
    mergeSort(vet1, 0, TAMANHO - 1);
    tempo_final = clock() - tempo_inicial;
    printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
    printf("Quantidade de trocas: %i\n", qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f segundos\n", tempo_final / 1000);
    //imprimirVetor(vet1);

    // ALEATÓRIO
    printf("\nAleatorio:\n");
    qtd_trocas = 0;
    qtd_comparacoes = 0;
    geraNumero(vet1, 3);
    tempo_inicial = clock();
    mergeSort(vet1, 0, TAMANHO - 1);
    tempo_final = clock() - tempo_inicial;
    printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
    printf("Quantidade de trocas: %i\n", qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f segundos\n", tempo_final / 1000);
    return 0;
}

// Gera os vetores
void geraNumero(int *vet, int op) {
    int i;
    switch (op) {
        case 1: // Ordenado
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = i + 1;
            }
            break;
        case 2: // Invertido
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = TAMANHO - i;
            }
            break;
        case 3: // Aleatório
            /*for (i = 0; i < TAMANHO; i++) {
              vet[i] = (int) (rand() % TAMANHO);
            }

            break; */
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = i + 1;
            }
            for (i = TAMANHO - 1; i > 0; i--) {
                int j = rand() % (i + 1);
                int temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
            break;
    }
}

// Merge Sort
void mergeSort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        //qtd_comparacoes++;
        int meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

// Função que realiza a junção dos subvetores ordenados
void merge(int *vet, int inicio, int meio, int fim) {
    //qtd_comparacoes++;
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int *esq = (int *) malloc(n1 * sizeof(int));
    int *dir = (int *) malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++) {
        esq[i] = vet[inicio + i];
    }
    for (j = 0; j < n2; j++) {
        dir[j] = vet[meio + 1 + j];
    }
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        qtd_comparacoes++;
        if (esq[i] <= dir[j]) {
            //qtd_comparacoes++;
            vet[k] = esq[i];
            i++;
        } else {
            //qtd_comparacoes++;
            vet[k] = dir[j];
            j++;
        }
        k++;
        qtd_trocas++;
    }
    while (i < n1) {
        //qtd_comparacoes++;
        vet[k] = esq[i];
        i++;
        k++;
        qtd_trocas++;
    }
    while (j < n2) {
        //qtd_comparacoes++;
        vet[k] = dir[j];
        j++;
        k++;
        qtd_trocas++;
    }
    //qtd_comparacoes++;
    free(esq);
    free(dir);
}

// Imprimir vetor (opcional)
void imprimirVetor(int *vet) {
    for (int i = 0; i < TAMANHO; i++) {
        printf("%i, ", vet[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}
