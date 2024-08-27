#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Declara um ponteiro para a lista que será manipulada
    LISTA *novaLista;
    // Declara variáveis para armazenar a opção do menu, valor a ser inserido/removido, posição e um indicador se a lista foi criada
    int opcao, valor, posicao, criouLista = 0;

    // Inicia um loop que continuará até que o usuário escolha sair
    do
    {
        // Exibe o cabeçalho do menu

        printf("================================================================\n");
        printf("                    LISTA DE VALORES INTEIROS\n");
        printf("================================================================\n");
        printf("1. Criar Lista\n");
        printf("2. Inserir Elemento no Início\n");
        printf("3. Inserir Elemento no Final\n");
        printf("4. Inserir Elemento em uma Posição\n");
        printf("5. Remover Elemento por Posição\n");
        printf("6. Remover Elemento por Valor\n");
        printf("7. Obter Elemento por Posição\n");
        printf("8. Procurar Elemento\n");
        printf("9. Tamanho da Lista\n");
        printf("10. Imprimir Lista\n");
        printf("0. Sair da Lista\n");
        printf("================================================================\n");
        printf("Escolha uma opção:  "); // Solicita ao usuário para escolher uma opção do menu
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        switch (opcao)
        {
        case 1:
            novaLista = criarLista(); // Chama a função para criar uma nova lista
            printf("Lista criada!\n"); // Define que a lista foi criada
            criouLista = 1;
            pressioneBotaoParaContinuar(); // Chama a função para pausar a execução até que o usuário pressione uma tecla
            break;
        case 2:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Informe um valor inteiro: "); // Solicita ao usuário um valor inteiro
                scanf("%d", &valor); // Lê o valor fornecido pelo usuário
                novaLista = inserirElemInicioLista(&novaLista, valor); // Chama a função para inserir o elemento no início da lista
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro 
            }

            pressioneBotaoParaContinuar(); // Pausa a execução
            break;
        case 3:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Informe um valor inteiro: "); // Solicita ao usuário um valor inteiro
                scanf("%d", &valor); // Lê o valor fornecido pelo usuário
                novaLista = inserirElemFinalLista(&novaLista, valor); // Chama a função para inserir o elemento no final da lista
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa a execução
            break;
        case 4:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Informe um valor inteiro para inserir na lista: "); // Solicita um valor inteiro ao usuário
                scanf("%d", &valor); // Lê o valor fornecido pelo usuário
                printf("Informe a posição para inserir valor: "); // Solicita a posição onde o valor deve ser inserido
                scanf("%d", &posicao); // Lê a posição fornecida pelo usuário
                novaLista = inserirElemPosicaoLista(&novaLista, valor, posicao); // Chama a função para inserir o elemento na posição especificada
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa a execução
            break;
        case 5:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Informe a posição para remover valor: "); // Solicita a posição do elemento a ser removido
                scanf("%d", &posicao); // Lê a posição fornecida pelo usuário
                novaLista = removerElemPosicaoLista(&novaLista, posicao); // Chama a função para remover o elemento na posição especificada
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa a execução
            break;
        case 6:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Informe um valor inteiro para remover na lista: "); // Solicita um valor inteiro ao usuário
                scanf("%d", &valor); // Lê o valor fornecido pelo usuário
                novaLista = removerElemValorLista(&novaLista, valor); // Chama a função para remover o elemento com o valor especificado
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa execução
            break;
        case 7:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Informe a posição do valor a ser buscado: "); // Solicita a posição do elemento a ser buscado
                scanf("%d", &posicao); // Lê a posição fornecida pelo usuário
                printf("Elemento: %d\n", obterElementoPosicao(&novaLista, posicao)); // Chama a função para obter o elemento na posição especificada e exibe o resultado
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa a execução
            break;
        case 8:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Informe o valor a ser procurado: "); // Solicita o valor a ser procurado
                scanf("%d", &valor); // Lê o valor fornecido pelo usuário
                printf("Posição do elemento: %d\n", procurarElemento(&novaLista, valor)); // Chama a função para procurar o elemento e exibe sua posição
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa execução
            break;
        case 9:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                printf("Tamanho da lista: %d\n", tamanhoLista(&novaLista)); // // Chama a função para obter o tamanho da lista e exibe o resultado
            }
            else
            {
                crieUmaLista(); // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa exeucução
            break;
        case 10:
            // Verifica se a lista foi criada
            if (criouLista != 0)
            {
                imprimirLista(&novaLista); // Chama a função para imprimir todos os elementos da lista
            }
            else
            {
                crieUmaLista();  // Informa ao usuário que a lista precisa ser criada primeiro
            }

            pressioneBotaoParaContinuar(); // Pausa a execução
            break;
        case 0:
            printf("Saindo...\n"); // Informa ao usuário que o programa está saindo
            break;

        default:
            printf("Opção incorreta!\n");  // Informa ao usuário que a opção escolhida é inválida
            pressioneBotaoParaContinuar(); // Pausa execução
            break;
        }
    } while (opcao != 0); // Continua exibindo o menu até que a opção seja 0 (sair)

    // Verifica se a lista foi criada
    if (criouLista != 0)
    {
        liberarMemoriaLista(&novaLista); // Chama a função para liberar a memória alocada para a lista
    }

    return 0;
}