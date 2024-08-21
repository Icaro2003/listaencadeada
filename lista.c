#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
    int info;
    LISTA *prox;
};

LISTA *criarLista()
{
    return NULL;
}

LISTA *inserirElemInicioLista(LISTA **lista, int elem)
{
    if (elem < 0)
    {
        printf("Elemento negativo, não é possível inserir no início da lista!\n");
        return *lista;
    }

    LISTA *novo = (LISTA *)malloc(sizeof(LISTA));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória para inserir um novo elemento no início da lista!\n");
        return *lista;
    }

    novo->info = elem;
    novo->prox = *lista;
    *lista = novo;

    return *lista;
}

LISTA *inserirElemFinalLista(LISTA **lista, int elem)
{
    if (elem < 0)
    {
        printf("Elemento negativo, não é possível inserir no final da lista!\n");
        return *lista;
    }

    LISTA *aux, *novo = (LISTA *)malloc(sizeof(LISTA));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória para inserir elemento no fim da lista!\n");
        return *lista;
    }

    novo->info = elem;
    novo->prox = NULL;

    if (*lista == NULL)
    {
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        aux = *lista;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    return *lista;
}

LISTA *inserirElemPosicaoLista(LISTA **lista, int elem, int pos)
{
    if (elem < 0)
    {
        printf("Valor negativo, não é possível inserir na posição da lista!\n");
        return *lista;
    }

    LISTA *aux, *novo = (LISTA *)malloc(sizeof(LISTA));
    int tam = 0;

    if (novo == NULL)
    {
        printf("Erro ao alocar memória para inserir elemento por posição na lista!\n");
        return *lista;
    }

    novo->info = elem;

    if (*lista == NULL || pos == 0)
    {
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        aux = *lista;

        while (aux->prox != NULL && tam < pos - 1)
        {
            aux = aux->prox;
            tam++;
        }

        if (pos < 0 || pos >= tamanhoLista(lista))
        {
            printf("Posição inválida, não é possível inserir elementos por posição!\n");
            return *lista;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return *lista;
}

LISTA *removerElemPosicaoLista(LISTA **lista, int pos)
{
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível remover elementos pela posição!\n");
        return *lista;
    }

    LISTA *remover = NULL;
    int tam = 0;

    if (pos == 0)
    {
        remover = *lista;
        *lista = remover->prox;
    }
    else
    {
        LISTA *aux = *lista;

        while (aux->prox != NULL && tam < pos - 1)
        {
            aux = aux->prox;
            tam++;
        }

        if (pos < 0 || pos >= tamanhoLista(lista))
        {
            printf("Posição inválida, não é possível remover elementos por posição!\n");
            return *lista;
        }
        
        if (aux->prox != NULL)
        {
            remover = aux->prox;
            aux->prox = remover->prox;
        }
    }

    if (remover != NULL)
    {
        free(remover);
    }
    
    return *lista;
}

LISTA *removerElemValorLista(LISTA **lista, int elem)
{
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível remover elementos pela posição!\n");
        return *lista;
    }
    
    if (elem < 0)
    {
        printf("Valor negativo, não é possível remover elementos pela posição!");
        return *lista;
    }

    LISTA *remover = NULL;

    if ((*lista)->info == elem)
    {
        remover = *lista;
        *lista = remover->prox;
    }
    else
    {
        LISTA *aux = *lista;

        while (aux != NULL && aux->prox->info != elem)
        {
            aux = aux->prox;
        }
        
        if (aux->prox != NULL)
        {
            remover = aux->prox;
            aux->prox = remover->prox;
        }
    }

    if (remover != NULL)
    {
        free(remover);
    }

    return *lista;
}

int obterElementoPosicao(LISTA **lista, int pos)
{
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível obter elemento por posição!\n");
        return -1;
    }

    int tam = 0;
    LISTA *aux = *lista;

    while (tam < pos && aux != NULL)
    {
        aux = aux->prox;
        tam++;
    }

    if (pos < 0 || pos >= tamanhoLista(lista))
    {
        printf("Posição inválida! Não é possível obter elemento!\n");
        return -1;
    }

    return aux->info;
}

int procurarElemento(LISTA **lista, int valor)
{
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível procurar elemento!\n");
        return -1;
    }

    if (valor < 0)
    {
        printf("Valor negativo, não é possível procurar elemento!\n");
        return -1;
    }

    LISTA *aux = *lista;
    int tam = 0, valorEncontrado = 0;

    while (aux != NULL)
    {
        if (aux->info == valor)
        {
            valorEncontrado = 1;
            break;
        }

        aux = aux->prox;
        tam++;
    }

    if (valorEncontrado != 1)
    {
        printf("Falha ao encontrar valor!\n");
        return -1;
    }

    return tam;
}

int tamanhoLista(LISTA **lista)
{
    if (*lista == NULL)
    {
        printf("Lista vazia, não é possível retornar seu tamanho!\n");
        return -1;
    }

    LISTA *aux;
    int tam = 0;

    aux = *lista;

    while (aux != NULL)
    {
        aux = aux->prox;
        tam++;
    }

    return tam;
}

void imprimirLista(LISTA **lista)
{
    if (*lista == NULL)
    {
        printf("Lista vazia, não possui elementos para imprimir!\n");
    }
    

    LISTA *aux;
    aux = *lista;

    while (aux != NULL)
    {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

void pressioneBotaoParaContinuar()
{
    printf("\nPressione um botão para exibir o menu novamente...\n");
    getchar();
    getchar();
}

void crieUmaLista()
{
    printf("Crie uma lista!\n");
}

void liberarMemoriaLista(LISTA **lista)
{
    LISTA *aux;

    while (*lista != NULL)
    {
        aux = *lista;
        *lista = aux->prox;
        free(aux);
    }
}