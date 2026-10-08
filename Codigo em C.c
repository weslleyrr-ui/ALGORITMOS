// Estoque Lanchonete - Versao Didatica
#include <stdio.h>

#define TAM_MAX 10 // Define a capacidade maxima do estoque (evita numeros soltos no codigo)

int main()
{
    // Vetores inicializados diretamente com zero {0}
    float precos[TAM_MAX] = {0};    // Preco de cada salgado
    int quantidades[TAM_MAX] = {0}; // Quantidade de cada salgado

    int total = 0;  // Contador de salgados cadastrados
    int opcao = -1; // Armazena a escolha do menu

    do
    {
        // Exibicao do Menu
        printf("\n===== ESTOQUE DA LANCHONETE =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Modificar\n");
        printf("4 - Apagar\n");
        printf("5 - Estatisticas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        int leitura_menu = scanf("%d", &opcao);
        if (leitura_menu == EOF){
            return 0;
        }
        if (leitura_menu != 1){
            int caractere_menu;
            printf("entrada invalida! Digite um numero do menu.\n");
            while ((caractere_menu = getchar()) != '\n' && caractere_menu != EOF)
            {
                /*descartou a entrada inválida*/
            }
            opcao = -1; 
            continue;
        }


        switch (opcao)
        {

        case 1: // CADASTRAR
            if (total < TAM_MAX)
            {
                printf("Preco: ");
                scanf("%f", &precos[total]);
                printf("Quantidade: ");
                scanf("%d", &quantidades[total]);

                // Valida entradas invalidas
                if (precos[total] > 0 && quantidades[total] >= 0)
                {
                    total++; // Incrementa 1 ao total
                    printf("Cadastrado com sucesso!\n");
                }
                else
                {
                    printf("Valores invalidos! Preco deve ser positivo.\n");
                }
            }
            else
            {
                printf("Estoque cheio!\n");
            }
            break;

        case 2: // LISTAR
            if (total == 0)
            {
                printf("Nada cadastrado.\n");
            }
            else
            {
                printf("\n--- ITENS CADASTRADOS ---\n");
                // O 'for' executa do indice 0 ate (total - 1)
                for (int i = 0; i < total; i++)
                {
                    printf("Posicao [%d] -> R$ %.2f | Qtd: %d\n", i, precos[i], quantidades[i]);
                }
            }
            break;

        case 3: // MODIFICAR
            if (total == 0)
            {
                printf("Nada para modificar.\n");
            }
            else
            {
                int posicao;
                printf("Posicao (0 a %d): ", total - 1);
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < total)
                {
                    float novo_preco;
                    int nova_quantidade;

                    int leitura;
                    int caractere;

                    do
                    {
                        printf("Novo preco:");
                        leitura = scanf("%f", &novo_preco);

                        if (leitura == EOF)
                        {
                            return 0;
                        }
                        if (leitura != 1)
                        {
                            printf("Entrada invalida! Digite um numero.\n");

                            while ((caractere = getchar()) != '\n' && caractere != EOF)
                            {
                                /*descarta a entrada inválida*/
                            }
                        }
                    } while (leitura != 1);

                    do
                    {
                        printf("Nova quantidade: ");
                        leitura = scanf("%d", &nova_quantidade);

                        if (leitura == EOF)
                        {
                            return 0;
                        }

                        if (leitura != 1)
                        {
                            printf("Entrada invalida! Digite um numero inteiro.\n");

                            while ((caractere = getchar()) != '\n' && caractere != EOF)
                            {
                                /* Descarta a entrada invalida. */
                            }
                        }
                    } while (leitura != 1);

                    if (novo_preco > 0 && nova_quantidade >= 0)
                    {
                        precos[posicao] = novo_preco;
                        quantidades[posicao] = nova_quantidade;
                        printf("Modificado com sucesso!\n");
                    }
                    else
                    {
                        printf("Valores invalidos! Dados anteriores mantidos.\n");
                    }
                }
                else
                {
                    printf("Posicao invalida!\n");
                }
            }
            break;

        case 4: // APAGAR
            if (total == 0)
            {
                printf("Nada para apagar.\n");
            }
            else
            {
                int posicao;
                printf("Posicao (0 a %d): ", total - 1);
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < total)
                {
                    // Reorganiza o vetor deslocando os elementos para a esquerda
                    for (int i = posicao; i < total - 1; i++)
                    {
                        precos[i] = precos[i + 1];
                        quantidades[i] = quantidades[i + 1];
                    }
                    total--; // Reduz a contagem total
                    printf("Apagado com sucesso!\n");
                }
                else
                {
                    printf("Posicao invalida!\n");
                }
            }
            break;

        case 5: // ESTATISTICAS
            if (total == 0)
            {
                printf("Sem dados.\n");
            }
            else
            {
                float soma_precos = 0;
                float valor_total = 0;
                int estoque_baixo = 0;

                // Calcula totais em um unico laco
                for (int i = 0; i < total; i++)
                {
                    soma_precos += precos[i];
                    valor_total += precos[i] * quantidades[i];

                    if (quantidades[i] < 5)
                    {
                        estoque_baixo = 1;
                        printf("Item na posicao %d: apenas %d unidades.\n", i, quantidades[i]);
                    }
                }

                printf("\n--- ESTATISTICAS ---\n");
                printf("Media de precos: R$ %.2f\n", soma_precos / total);
                printf("Valor total em estoque: R$ %.2f\n", valor_total);

                if (estoque_baixo)
                {
                    printf("ATENCAO: Existem itens com estoque baixo (menos de 5 units)!\n");
                }
                else
                {
                    printf("Estoque normal.\n");
                }
            }
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
