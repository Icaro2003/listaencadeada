#ifndef LISTA_H
#define LISTA_H

typedef struct lista LISTA;

LISTA *criarLista();
LISTA *inserirElemInicioLista(LISTA **lista, int elem);
LISTA *inserirElemFinalLista(LISTA **lista, int elem);
LISTA *inserirElemPosicaoLista(LISTA **lista, int elem, int pos);
LISTA *removerElemPosicaoLista(LISTA **lista, int pos);
LISTA *removerElemValorLista(LISTA **lista, int elem);
int obterElementoPosicao(LISTA **lista, int pos);
int procurarElemento(LISTA **lista, int valor);
int tamanhoLista(LISTA **lista);
void imprimirLista(LISTA **lista);
void pressioneBotaoParaContinuar();
void crieUmaLista();
void liberarMemoriaLista(LISTA **lista);

#endif