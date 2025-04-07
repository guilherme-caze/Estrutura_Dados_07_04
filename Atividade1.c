#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musica {
    char nome_musica[30];
    char nome_artista[30];
    int escolha_musica;
    struct Musica *proxima;

};

struct Musica* adicionarMusica(struct Musica *head, char nome[], char artista[]) {
    struct Musica *novaMusica = (struct Musica*)malloc(sizeof(struct Musica));
    strcpy(novaMusica->nome_musica, nome);
    strcpy(novaMusica->nome_artista, artista);
    novaMusica->proxima = head;
    return novaMusica;
}

int main(){
    struct Musica *listaMusicas = NULL;
    struct Musica musica;
    int opcao_menu;
    int musica_escolhida;

    listaMusicas = adicionarMusica(listaMusicas, "333", "Matue");
    listaMusicas = adicionarMusica(listaMusicas, "Billie Jean", "Michael Jackson");
    listaMusicas = adicionarMusica(listaMusicas, "Die With A Smile", "Bruno Mars");
    listaMusicas = adicionarMusica(listaMusicas, "Vlife", "Yunk Vino");

    printf("---MENU---\n\n");

    printf("Escolha uma opcao: \n");
    printf("1. Escolher musica para escutar \n");
    printf("2. Inserir nova musica e autor\n");
    scanf("%d", &opcao_menu);

    if (opcao_menu == 1) {

        struct Musica *atual = listaMusicas;
        int index = 1;

    if(opcao_menu == 1){

    printf("Lista de musicas disponiveis: \n");

    while (atual != NULL) {
            printf("%d. %s - %s\n", index++, atual->nome_musica, atual->nome_artista);
            atual = atual->proxima;
        }
    }



    printf("Escolha uma musica de acordo com o seu numero: \n");
    scanf("%d", &musica_escolhida);

    if(musica_escolhida == 1){printf("FAIXA TOCANDO: 1. Vlife - Yunk Vino\n");}
    else if(musica_escolhida == 2){printf("FAIXA TOCANDO: 2. Die With A Smile - Bruno Mars\n");}
    else if(musica_escolhida == 3){printf("FAIXA TOCANDO: 3. Billie Jean - Michael Jackson\n");}
    else if(musica_escolhida == 4){printf("FAIXA TOCANDO: 4. 333 - Matue\n\n");}

    if (atual != NULL) {
            printf("FAIXA TOCANDO: %s - %s\n", atual->nome_musica, atual->nome_artista);
    }

    printf("Deseja avancar ou voltar a musica? (1 = Avancar / 0 = Nao / 2 = Voltar)\n");
    scanf("%d", &atual->escolha_musica);

    if (atual->escolha_musica == 1 && atual->proxima != NULL) {
                atual = atual->proxima;
                printf("FAIXA TOCANDO: %s - %s\n", atual->nome_musica, atual->nome_artista);

            } else if (atual->escolha_musica == 2 && listaMusicas != atual) {
                struct Musica *anterior = listaMusicas;
                while (anterior->proxima != atual) {
                    anterior = anterior->proxima;
                }
                printf("FAIXA TOCANDO: %s - %s\n", anterior->nome_musica, anterior->nome_artista);
            } else {
                printf("FAIXA TOCANDO: %s - %s\n", atual->nome_musica, atual->nome_artista);
            }
    }
        

    }
        

    return 0;
}
