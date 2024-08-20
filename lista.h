#ifndef LISTA_H
#define LISTA_H

typedef struct lista LISTA;

LISTA *criarLista();
LISTA *inserirElemInicioLista(LISTA **lista, int elem);
LISTA *inserirElemFinalLista(LISTA **lista, int elem);
LISTA *inserirElemPosicaoLista(LISTA **lista, int elem, int pos);

int obterElementoPosicao(LISTA **lista, int pos);
int procurarElemento(LISTA **lista, int valor);
int tamanhoLista(LISTA **lista);
void imprimirLista(LISTA **lista);
void pressioneBotaoParaContinuar();
// depois remover
LISTA *inserirElemMeioLista(LISTA **lista, int elem, int ant);


#endif