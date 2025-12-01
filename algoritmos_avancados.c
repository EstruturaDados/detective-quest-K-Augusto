#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

// Definição da estutura e criação do nó
struct Sala{
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
};

// Função para criar dinamicament uma sala da mansão
struct Sala* criarSala(char* nome){
    struct Sala* novo = (struct Sala*) malloc(sizeof(struct Sala));

    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(novo -> nome, nome);
    novo -> esquerda = NULL;
    novo -> direita = NULL;
    
    return novo;
}

// Função para liberar a memória após o uso da árvore
void liberar(struct Sala* raiz){
    if(raiz != NULL){
        liberar(raiz -> esquerda);
        liberar(raiz -> direita);
        free(raiz);
    }
}

// Função para limpar o buffer de entrada 
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função de exploração da mansão
void explorarSalas(struct Sala* atual){
    char opcao;

    printf("\n***EXPLORANDO A MANSAO***\n");

    do{
        // Localização atual
        printf("\nVoce esta em: %s\n", atual->nome);

        // Nó-folha → encerra automaticamente
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este comodo nao possui caminhos. Fim da exploracao.\n");
            break;
        }

        printf("\n");
        printf("Pressione 'e' - Esquerda\n");
        printf("Pressione 'd' - Direita\n");
        printf("Pressione 's' - Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);
        limparBufferEntrada();
        switch(opcao){
            case 'e':
                if (atual->esquerda != NULL){
                    atual = atual->esquerda;
                }else{
                    printf("Nao existe caminho para a ESQUERDA!\n");
                }
                break;
            case 'd':
                if (atual->direita != NULL){
                    atual = atual->direita;
                }else{
                    printf("Nao existe caminho para a DIREITA!\n");
                }
                break;
            case 's':
                printf("Saindo da exploracao...");
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }while(opcao != 's');
}

int main() {

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // Construindo a árvore (mansão)
    struct Sala* hall = criarSala("Hall de Entrada");
    struct Sala* sala = criarSala("Sala de Estar");
    struct Sala* cozinha = criarSala("Cozinha");
    struct Sala* jardim = criarSala("Jardim");
    struct Sala* porao = criarSala("Porao");
    struct Sala* banheiro = criarSala("Banheiro");
    struct Sala* suite = criarSala("Suite");
    struct Sala* quarto1 = criarSala("Quarto 1");
    struct Sala* quarto2 = criarSala("Quarto 2");
    struct Sala* biblioteca = criarSala("Biblioteca");
    
    // Estrutura da mansão
    hall -> esquerda = sala;
    hall -> direita = cozinha;
    sala -> direita = jardim;
    sala -> esquerda = quarto1; 
    cozinha->esquerda = porao;
    cozinha -> direita = suite;
    quarto1 -> esquerda = quarto2;
    quarto1->direita = biblioteca;
    suite->direita = jardim;

    // Iniciar exploração
    explorarSalas(hall);

    // Libera memória
    liberar(hall);

    return 0;
}

