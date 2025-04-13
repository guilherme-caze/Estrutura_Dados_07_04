#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COR 20
#define TOTAL_CARRINHOS 10

typedef struct Carrinho {
    int pessoas;
    char cor[MAX_COR];
    struct Carrinho* proximo;
    struct Carrinho* anterior;
} Carrinho;

Carrinho* criarRodaGigante() {
    const char* cores[TOTAL_CARRINHOS] = {
        "Vermelho", "Azul", "Verde", "Amarelo", "Rosa",
        "Roxo", "Laranja", "Marrom", "Cinza", "Preto"
    };

    Carrinho* inicio = NULL;
    Carrinho* anterior = NULL;

    for (int i = 0; i < TOTAL_CARRINHOS; i++) {
        Carrinho* novo = (Carrinho*)malloc(sizeof(Carrinho));
        novo->pessoas = 0;
        strncpy(novo->cor, cores[i], MAX_COR);
        novo->proximo = NULL;
        novo->anterior = anterior;

        if (inicio == NULL) {
            inicio = novo;
        } else {
            anterior->proximo = novo;
        }

        anterior = novo;
    }

    // Tornar circular
    inicio->anterior = anterior;
    anterior->proximo = inicio;

    return inicio;
}

Carrinho* girarHorario(Carrinho* atual) {
    return atual->proximo;
}

Carrinho* girarAntiHorario(Carrinho* atual) {
    return atual->anterior;
}

void embarcar(Carrinho* atual) {
    int qtd;
    printf("Quantas pessoas deseja embarcar no carrinho %s? ", atual->cor);
    scanf("%d", &qtd);
    atual->pessoas += qtd;
    printf("Agora o carrinho %s tem %d pessoas.\n", atual->cor, atual->pessoas);
}

void desembarcar(Carrinho* atual) {
    int qtd;
    printf("Quantas pessoas deseja desembarcar do carrinho %s? ", atual->cor);
    scanf("%d", &qtd);
    if (qtd > atual->pessoas) {
        printf("Só há %d pessoas no carrinho. Esvaziando-o.\n", atual->pessoas);
        atual->pessoas = 0;
    } else {
        atual->pessoas -= qtd;
    }
    printf("Agora o carrinho %s tem %d pessoas.\n", atual->cor, atual->pessoas);
}

void menu() {
    printf("\n--- RODA GIGANTE ---\n");
    printf("1. Girar para a direita (horario)\n");
    printf("2. Girar para a esquerda (anti-horario)\n");
    printf("3. Embarcar pessoas\n");
    printf("4. Desembarcar pessoas\n");
    printf("5. Ver carrinho atual\n");
    printf("0. Sair\n");
    printf("Escolha uma opacao: ");
}

int main() {
    Carrinho* atual = criarRodaGigante();
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                atual = girarHorario(atual);
                printf("Carrinho atual: %s (%d pessoas)\n", atual->cor, atual->pessoas);
                break;
            case 2:
                atual = girarAntiHorario(atual);
                printf("Carrinho atual: %s (%d pessoas)\n", atual->cor, atual->pessoas);
                break;
            case 3:
                embarcar(atual);
                break;
            case 4:
                desembarcar(atual);
                break;
            case 5:
                printf("Carrinho atual: %s (%d pessoas)\n", atual->cor, atual->pessoas);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
