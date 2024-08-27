#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Estrutura que define um nó da lista simplesmente encadeada
struct lista
{
    int info;    // Informação armazenada no nó
    LISTA *prox; // Ponteiro para o próximo nó da lista
};

// Função para criar uma lista vazia
LISTA *criarLista()
{
    return NULL; // Retorna NULL indicando que a lista está vazia
}

// Função para inserir um elemento no início da lista
LISTA *inserirElemInicioLista(LISTA **lista, int elem)
{
    // Verifica se o elemento é negativo
    if (elem < 0)
    {
        printf("Elemento negativo, não é possível inserir no início da lista!\n");
        return *lista; // Retorna a lista sem modificações
    }

    // Aloca memória para um novo nó
    LISTA *novo = (LISTA *)malloc(sizeof(LISTA));

    // Verifica se a alocação de memória falhou
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para inserir um novo elemento no início da lista!\n");
        return *lista; // Retorna a lista sem modificações
    }

    novo->info = elem;   // Atribui o valor do elemento ao novo nó
    novo->prox = *lista; // Faz o novo nó apontar para o antigo primeiro nó
    *lista = novo; // Atualiza o ponteiro da lista para o novo nó

    return *lista; // Retorna a lista atualizada
}

// Função para inserir um elemento no final da lista
LISTA *inserirElemFinalLista(LISTA **lista, int elem)
{
    // Verifica se o elemento é negativo
    if (elem < 0)
    {
        printf("Elemento negativo, não é possível inserir no final da lista!\n");
        return *lista; // Retorna a lista sem modificações
    }

    // Cria ponteiro auxiliar e aloca memória para um novo nó
    LISTA *aux, *novo = (LISTA *)malloc(sizeof(LISTA));

    // Verifica se a alocação de memória falhou
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para inserir elemento no fim da lista!\n");
        return *lista; // Retorna a lista sem modificações
    }

    novo->info = elem; // Atribui o valor do elemento ao novo nó
    novo->prox = NULL; // O novo nó será o último, então seu próximo será NULL

    // Verifica se a lista está vazia
    if (*lista == NULL)
    {
        novo->prox = *lista; // Novo nó apontará para NULL
        *lista = novo; // O novo nó se torna o primeiro nó da lista
    }
    else
    {
        // Inicializa o auxiliar no primeiro nó
        aux = *lista;

        // Percorre a lista até o último nó
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo; // Faz o último nó apontar para o novo nó
    }

    return *lista; // Retorna a lista atualizada
}

// Função para inserir um elemento em uma posição específica da lista
LISTA *inserirElemPosicaoLista(LISTA **lista, int elem, int pos)
{
    // Verifica se o elemento é negativo
    if (elem < 0)
    {
        printf("Valor negativo, não é possível inserir na posição da lista!\n");
        return *lista; // Retorna a lista sem modificações
    }

    // Verifica se a posição é válida
    if (pos < 0 || pos >= tamanhoLista(lista))
    {
        printf("Posição inválida, não é possível inserir elementos por posição!\n");
        return *lista; // Retorna a lista sem modificações
    }

    // Cria ponteiro auxiliar e aloca memória para um novo nó
    LISTA *aux, *novo = (LISTA *)malloc(sizeof(LISTA));
    int tam = 0; // Variável para controlar a posição atual

    // Verifica se a alocação de memória falhou
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para inserir elemento por posição na lista!\n");
        return *lista; // Retorna a lista sem modificações
    }

    novo->info = elem; // Atribui o valor do elemento ao novo nó

    // Se a posição é 0, insere no início
    if (pos == 0)
    {
        novo->prox = *lista; // O próximo do novo nó aponta para o atual primeiro nó
        *lista = novo; // A lista agora começa com o novo nó
    }
    else
    {
        aux = *lista; // Inicializa o auxiliar no primeiro nó

        // Percorre a lista até a posição desejada
        while (aux->prox != NULL && tam < pos - 1)
        {
            aux = aux->prox;
            tam++; // Iteração para controlar a posição desejada
        }

        novo->prox = aux->prox; // Novo nó aponta para o próximo da posição atual
        aux->prox = novo; // Nó anterior aponta para o novo nó
    }

    return *lista; // Retorna a lista atualizada
}

// Função para remover um elemento por posição na lista
LISTA *removerElemPosicaoLista(LISTA **lista, int pos)
{
    // Verifica se a lista está vazia
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível remover elementos pela posição!\n");
        return *lista; // Retorna a lista sem modificações
    }

    // Verifica se a posição é válida
    if (pos < 0 || pos >= tamanhoLista(lista))
    {
        printf("Posição inválida, não é possível remover elementos por posição!\n");
        return *lista; // Retorna a lista sem modificações
    }

    LISTA *remover = NULL; // Ponteiro para o nó a ser removido
    int tam = 0; // Variável para controlar a posição atual

    // Se a posição é 0, remove o primeiro nó
    if (pos == 0)
    {
        remover = *lista; // O nó a ser removido é o primeiro.
        *lista = remover->prox; // O primeiro nó agora é o segundo
    }
    else
    {
        LISTA *aux = *lista; // Se a posição é 0, remove o primeiro nó

        // Percorre a lista até a posição desejada
        while (aux->prox != NULL && tam < pos - 1)
        {
            aux = aux->prox;
            tam++; // Iteração para controlar a posição desejada
        }

        // Verificação se o próximo nó existe
        if (aux->prox != NULL)
        {
            remover = aux->prox; // O nó a ser removido é o próximo.
            aux->prox = remover->prox; // O nó anterior agora aponta para o próximo do nó a ser removido.
        }
    }

    // Se um nó foi removido, libera a memória.
    if (remover != NULL)
    {
        free(remover);
    }

    return *lista; // Retorna a lista atualizada.
}

// Função para remover um elemento por valor na lista
LISTA *removerElemValorLista(LISTA **lista, int elem)
{
    // Verifica se a lista está vazia
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível remover elementos pela posição!\n");
        return *lista; // Retorna a lista sem modificações
    }

     // Verifica se o elemento é negativo
    if (elem < 0)
    {
        printf("Valor negativo, não é possível remover elementos pela posição!");
        return *lista;
    }

    LISTA *remover = NULL; // Ponteiro para o nó a ser removido

    // Verifica se o primeiro nó contém o elemento a ser removido
    if ((*lista)->info == elem)
    {
        remover = *lista; // O nó a ser removido é o primeiro.
        *lista = remover->prox; // O primeiro nó agora é o segundo.
    }
    else
    {
        // Inicializa o auxiliar no primeiro nó
        LISTA *aux = *lista;

        // Percorre a lista para encontrar o nó com o valor desejado
        while (aux != NULL && aux->prox->info != elem)
        {
            aux = aux->prox;
        }

        // Verificação se o próximo nó existe
        if (aux->prox != NULL)
        {
            remover = aux->prox; // O nó a ser removido é o próximo
            aux->prox = remover->prox; // O nó anterior agora aponta para o próximo do nó a ser removido
        }
    }

    // Se um nó foi removido, libera a memória
    if (remover != NULL)
    {
        free(remover);
    }

    return *lista; // Retorna a lista atualizada
}

int obterElementoPosicao(LISTA **lista, int pos)
{
    // Verifica se a lista está vazia
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível obter elemento por posição!\n");
        return -1; // Retorna -1 para indicar erro
    }

    // Verifica se a posição é válida
    if (pos < 0 || pos >= tamanhoLista(lista))
    {
        printf("Posição inválida! Não é possível obter elemento!\n");
        return -1; // Retorna -1 para indicar erro
    }

    int tam = 0; // Variável para controlar a posição atual
    LISTA *aux = *lista; // Inicializa o auxiliar no primeiro nó

    // Percorre até a posição desejada.
    while (tam < pos && aux != NULL)
    {
        aux = aux->prox;
        tam++; // Iteração para controlar a posição desejada
    }

    return aux->info; // Retorna o valor do elemento na posição especificada
}

// Função para procurar um elemento na lista por valor
int procurarElemento(LISTA **lista, int valor)
{
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível procurar elemento!\n");
        return -1; // Retorna -1 para indicar erro
    }

    // Verifica se o valor é negativo
    if (valor < 0)
    {
        printf("Valor negativo, não é possível procurar elemento!\n");
        return -1; // Retorna -1 para indicar erro
    }

    LISTA *aux = *lista; // Inicializa o auxiliar no primeiro nó
    // Variáveis de controle
    int tam = 0, valorEncontrado = 0;

    // Percorre a lista até o final
    while (aux != NULL)
    {
        // Verica se o valor existe na lista
        if (aux->info == valor)
        {
            valorEncontrado = 1; // Marca que o valor foi encontrado
            break;
        }

        aux = aux->prox;
        tam++; // Iteração para controlar a posição desejada
    }

    // Se o valor não foi encontrado
    if (valorEncontrado != 1)
    {
        printf("Falha ao encontrar valor!\n");
        return -1; // Retorna -1 para indicar erro
    }

    return tam; // Retorna a posição do elemento encontrado
}

// Função que retorna o número de elementos atualmente na lista
int tamanhoLista(LISTA **lista)
{
    // Verifica se a lista está vazia
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível retornar seu tamanho!\n");
        return -1; // Retorna -1 para indicar erro
    }

    LISTA *aux = *lista; // Inicializa o auxiliar no primeiro nó
    int tam = 0; // Contador dos elementos da lista

    // Percorre a lista para contar os nós    
    while (aux != NULL)
    {
        aux = aux->prox;
        tam++; // Iteração para contar nós
    }

    return tam; // Retorna o número de elementos na lista
}

// Função para imprimir todos os elementos da lista
void imprimirLista(LISTA **lista)
{
    // Verifica se a lista está vazia
    if (*lista == NULL)
    {
        printf("Lista vazia, não possui elementos para imprimir!\n");
        return;
    }

    LISTA *aux = *lista; // Inicializa o auxiliar no primeiro nó

    // Percorre a lista para imprimir os elementos
    while (aux != NULL)
    {
        printf("%d\n", aux->info); // Imprime o valor do nó atual
        aux = aux->prox;
    }
}

// Função para controle ao executar funções chamadas no menu, para dar tempo ao usuário de ler mensagens no console.
void pressioneBotaoParaContinuar()
{
    printf("\nPressione um botão para exibir o menu novamente...\n");
    getchar();
    getchar();
}

// Função para controle ao executar funções chamadas no menu caso não seja criada a lista inicialmente
void crieUmaLista()
{
    printf("Crie uma lista!\n");
}

// Função para liberar a memória de todos os nós da lista
void liberarMemoriaLista(LISTA **lista)
{
    LISTA *aux; // Ponteiro auxiliar 

    // Percorre a lista enquanto não estiver vazia
    while (*lista != NULL)
    {
        aux = *lista; // Armazena o primeiro nó da lista
        *lista = aux->prox; // A lista é atualizada para apontar para o próximo nó 
        free(aux); // Libera a memória do nó atual
    }
}