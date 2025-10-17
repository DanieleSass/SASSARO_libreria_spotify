#include <stdio.h>
#include <stdlib.h>

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
                cont++;                 //aumenta il contatore totale delle canzoni

            free(NuovaCanzone->titolo); //libera memoria della canzone appena creata
            free(NuovaCanzone->nome_artista);
            free(NuovaCanzone);
            NuovaCanzone=NULL;
        }

        if (input==2)   //mostra tutte le canzoni
        {
            VisualizzaLibreria(lista,cont);
        }

    }while (input!=3);  //esce
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
        printf("Titolo: %s; Autore: %s; Durata: %d : %d \n",(*(lista + i))->titolo, (*(lista + i))->nome_artista, (*(lista + i))->minuti, (*(lista + i))->secondi );
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

    printf("Nome Autore:\n");
    fgets(Canzone_da_returnare->nome_artista, 30, stdin);

    printf("Minuti durata:\n");
    scanf("%d", &Canzone_da_returnare->minuti);
    while (getchar() != '\n' );

    printf("Secondi durata:\n");
    scanf("%d", &Canzone_da_returnare->secondi);
    while (getchar() != '\n' );

    return Canzone_da_returnare;
}