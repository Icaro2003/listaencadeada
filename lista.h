#ifndef LISTA_H
#define LISTA_H

typedef struct lista LISTA;

/**
 * @brief Cria uma nova lista vazia.
 * 
 * @return Um ponteiro para a lista criada, que será NULL se a lista estiver vazia.
 */
LISTA *criarLista();

/**
 * @brief Insere um elemento inteiro no início da lista.
 * 
 * @param lista Um ponteiro duplo para a lista onde o elemento será inserido.
 * @param elem O elemento inteiro a ser inserido.
 * @return Um ponteiro para a lista atualizada.
 */
LISTA *inserirElemInicioLista(LISTA **lista, int elem);

/**
 * @brief Insere um elemento inteiro no final da lista.
 * 
 * @param lista Um ponteiro duplo para a lista onde o elemento será inserido.
 * @param elem O elemento inteiro a ser inserido.
 * @return Um ponteiro para a lista atualizada.
 */
LISTA *inserirElemFinalLista(LISTA **lista, int elem);

/**
 * @brief Insere um elemento inteiro em uma posição específica da lista.
 * 
 * @param lista Um ponteiro duplo para a lista onde o elemento será inserido.
 * @param elem O elemento inteiro a ser inserido.
 * @param pos A posição onde o elemento deve ser inserido.
 * @return Um ponteiro para a lista atualizada.
 */
LISTA *inserirElemPosicaoLista(LISTA **lista, int elem, int pos);

/**
 * @brief Remove um elemento da lista na posição especificada.
 * 
 * @param lista Um ponteiro duplo para a lista de onde o elemento será removido.
 * @param pos A posição do elemento a ser removido.
 * @return Um ponteiro para a lista atualizada.
 */
LISTA *removerElemPosicaoLista(LISTA **lista, int pos);

/**
 * @brief Remove a primeira ocorrência de um elemento com um valor específico da lista.
 * 
 * @param lista Um ponteiro duplo para a lista de onde o elemento será removido.
 * @param elem O valor do elemento a ser removido.
 * @return Um ponteiro para a lista atualizada.
 */
LISTA *removerElemValorLista(LISTA **lista, int elem);

/**
 * @brief Obtém o elemento na posição especificada da lista.
 * 
 * @param lista Um ponteiro duplo para a lista de onde o elemento será obtido.
 * @param pos A posição do elemento a ser obtido.
 * @return O valor do elemento na posição especificada ou -1 se a posição for inválida.
 */
int obterElementoPosicao(LISTA **lista, int pos);

/**
 * @brief Procura um elemento na lista e retorna sua posição.
 * 
 * @param lista Um ponteiro duplo para a lista onde o elemento será procurado.
 * @param valor O valor do elemento a ser procurado.
 * @return A posição do elemento encontrado ou -1 se não for encontrado.
 */
int procurarElemento(LISTA **lista, int valor);

/**
 * @brief Retorna o número de elementos atualmente na lista.
 * 
 * @param lista Um ponteiro duplo para a lista cuja contagem de elementos será retornada.
 * @return O número de elementos na lista ou -1 se a lista estiver vazia.
 */
int tamanhoLista(LISTA **lista);

/**
 * @brief Imprime todos os elementos da lista em ordem.
 * 
 * @param lista Um ponteiro duplo para a lista a ser impressa.
 */
void imprimirLista(LISTA **lista);

/**
 * @brief Pausa a execução até que o usuário pressione uma tecla.
 * 
 * Esta função é útil para dar tempo ao usuário de ler mensagens no console.
 */
void pressioneBotaoParaContinuar();

/**
 * @brief Exibe uma mensagem para o usuário sobre a criação de uma lista.
 * 
 * Esta função pode ser utilizada para controle ao executar funções chamadas no menu caso não seja criada a lista inicialmente.
 */
void crieUmaLista();

/**
 * @brief Libera toda a memória alocada para a lista.
 * 
 * @param lista Um ponteiro duplo para a lista cuja memória será liberada.
 */
void liberarMemoriaLista(LISTA **lista);

#endif