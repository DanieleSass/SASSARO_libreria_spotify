#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Canzone {
    char* titolo;
    char* nome_artista;
    int secondi;
    int minuti;
};


void VisualizzaLibreria(struct Canzone**, int);
struct Canzone* RichiediCanzone();

int main(void) {


    int input;
    int cont=0;
    int quantita_array=10;
    struct Canzone** lista = (struct Canzone**) malloc(sizeof(struct Canzone**)*quantita_array);
    do
    {
    printf("Inserire un numero:\n1 - Aggiungi Canzone\n2 - Visualizza Libreria\n3 - Esci\n");

        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n' );
        }

        //se si vuole aggiungere una nuova canzone
        if (input == 1)
        {
            struct Canzone* NuovaCanzone=RichiediCanzone();
            //la crea dal return della funzione

            if (cont<quantita_array)    //se necessario alloca + memoria
            {
                quantita_array+=10;
                lista=realloc(lista,sizeof(struct Canzone*)*quantita_array);
            }
            lista[cont]=NuovaCanzone;   //la salva nell' array
                cont++;                 //aumenta il contatore totale delle canzone
        }

        if (input==2)   //mostra tutte le canzoni
        {
            VisualizzaLibreria(lista,cont);
        }

    }while (input!=3);  //esce

    for (int i = 0; i < cont; i++)
    {
        free(lista[i]->titolo);
        free(lista[i]->nome_artista);
        free(lista[i]);
    }
    free(lista);
    lista = NULL;

    return 0;
}

void VisualizzaLibreria(struct Canzone** lista, int contatore)
{

    if (contatore==0)
    {
        printf("Nessuna canzone \n");
        return;
    }

    for (int i = 0; i < contatore; i++)
    {
        printf("Titolo: %s; Autore: %s; Durata: %d:%02d \n",(*(lista + i))->titolo, (*(lista + i))->nome_artista, (*(lista + i))->minuti, (*(lista + i))->secondi );
    }
}

struct Canzone* RichiediCanzone()
{

    struct Canzone* Canzone_da_returnare=malloc(sizeof(struct Canzone));

    while (getchar() != '\n' );

    Canzone_da_returnare->titolo = malloc(30 * sizeof(char));
    Canzone_da_returnare->nome_artista = malloc(30 * sizeof(char));

    printf("Nome Canzone:\n");
    fgets(Canzone_da_returnare->titolo, 30, stdin);
    Canzone_da_returnare->titolo[strcspn(Canzone_da_returnare->titolo, "\n")] = '\0';

    printf("Nome Autore:\n");
    fgets(Canzone_da_returnare->nome_artista, 30, stdin);
    Canzone_da_returnare->nome_artista[strcspn(Canzone_da_returnare->nome_artista, "\n")] = '\0';

    do {
        printf("Minuti durata:\n");
        if (scanf("%d", &Canzone_da_returnare->minuti) != 1)
        {
            while (getchar() != '\n');  //pulisce e lo fa fallire per richiedere input
            Canzone_da_returnare->minuti = -1;
        }
    } while (Canzone_da_returnare->minuti < 0);


    while (getchar() != '\n');

    do {
        printf("Secondi durata:\n");
        if (scanf("%d", &Canzone_da_returnare->secondi) != 1)
        {
            while (getchar() != '\n');
            Canzone_da_returnare->secondi = -1;
        }
    } while (Canzone_da_returnare->secondi < 0 || Canzone_da_returnare->secondi > 59);


    while (getchar() != '\n');

    return Canzone_da_returnare;
}