#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    LISTA *novaLista;
    int opcao, valor, posicao, criouLista = 0;

    do
    {
        printf("================================================================\n");
        printf("                    LISTA DE VALORES INTEIROS\n");
        printf("================================================================\n");
        printf("1. Criar Lista\n");
        printf("2. Inserir Elemento no Início\n");
        printf("3. Inserir Elemento no Final\n");
        printf("4. Inserir Elemento em uma Posição\n");
        printf("5. Remover Elemento por Valor\n");
        printf("6. Remover Elemento por Valor\n");
        printf("7. Obter Elemento por Posição\n");
        printf("8. Procurar Elemento\n");
        printf("9. Tamanho da Lista\n");
        printf("10. Imprimir Lista\n");
        printf("0. Sair da Lista\n");
        printf("================================================================\n");
        printf("Escolha uma opção:  ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            novaLista = criarLista();
            printf("Lista criada!\n");
            criouLista = 1;
            pressioneBotaoParaContinuar();
            break;
        case 2:
            if (criouLista != 0)
            {
                printf("Informe um valor inteiro: ");
                scanf("%d", &valor);
                novaLista = inserirElemInicioLista(&novaLista, valor);
            }
            else
            {
                crieUmaLista();
            }

            pressioneBotaoParaContinuar();
            break;
        case 3:
            if (criouLista != 0)
            {
                printf("Informe um valor inteiro: ");
                scanf("%d", &valor);
                novaLista = inserirElemFinalLista(&novaLista, valor);
            }
            else
            {
                crieUmaLista();
            }

            pressioneBotaoParaContinuar();
            break;
        case 4:
            if (criouLista != 0)
            {
                printf("Informe um valor inteiro para inserir na lista: ");
                scanf("%d", &valor);
                printf("Informe a posição para inserir valor: ");
                scanf("%d", &posicao);
                novaLista = inserirElemPosicaoLista(&novaLista, valor, posicao);
            }
            else
            {
                crieUmaLista();
            }

            pressioneBotaoParaContinuar();
            break;
        // falta as funções de remover
        case 7:
            if (criouLista != 0)
            {
                printf("Informe a posição do valor a ser buscado: ");
                scanf("%d", &posicao);
                printf("Elemento: %d\n", obterElementoPosicao(&novaLista, posicao));
            }
            else
            {
                crieUmaLista();
            }

            pressioneBotaoParaContinuar();
            break;
        case 8:
            if (criouLista != 0)
            {
                printf("Informe o valor a ser procurado: ");
                scanf("%d", &valor);
                printf("Posição do elemento: %d\n", procurarElemento(&novaLista, valor));
            }
            else
            {
                crieUmaLista();
            }

            pressioneBotaoParaContinuar();
            break;
        case 9:
            if (criouLista != 0)
            {
                printf("Tamanho da lista: %d\n", tamanhoLista(&novaLista));
            }
            else
            {
                crieUmaLista();
            }

            pressioneBotaoParaContinuar();
            break;
        case 10:
            if (criouLista != 0)
            {
                imprimirLista(&novaLista);
            }
            else
            {
                crieUmaLista();
            }

            pressioneBotaoParaContinuar();
            break;
        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção incorreta!\n");
            pressioneBotaoParaContinuar();
            break;
        }
    } while (opcao != 0);

    if (criouLista != 0)
    {
        liberarMemoriaLista(&novaLista);
    }

    return 0;
}