#include <stdio.h>
#include <stdlib.h>

struct Canzone {
    char* titolo;
    char* nome_artista;
    int secondi;
    int minuti;
};


void VisualizzaLibreria(struct Canzone*, int);
struct Canzone* RichiediCanzone();

int main(void) {


    int input;
    int cont=0;
    int quantita_array=10;
    struct Canzone* lista = (struct Canzone*) malloc(sizeof(struct Canzone)*quantita_array);
    do
    {
    printf("Inserire un numero:\n1 - Aggiungi Canzone\n2 - Visualizza Libreria\n3 - Esci\n");
    input = scanf("%d", &input);

        //cont=sizeof(lista)/sizeof(lista[0]);
        if (input == 1)
        {
            struct Canzone* NuovaCanzone=RichiediCanzone();
            if (cont<quantita_array)
            {
                quantita_array+=10;
                lista=realloc(lista,sizeof(struct Canzone)*quantita_array);
            }
                cont++;
        }

        if (input==2)
        {

            VisualizzaLibreria(lista,cont);
        }
    }while (input!=3);
    free(lista);
    lista = NULL;

    return 0;
}

void VisualizzaLibreria(struct Canzone* lista, int contatore)
{
    for (int i = 0; i < contatore; i++)
    {
        printf("Titolo: %s; Autore: %s; Minuti: %d; Secondi: %d \n",lista->titolo,lista->nome_artista,lista->minuti,lista->secondi);
    }
}

struct Canzone* RichiediCanzone()
{
    printf("Nome Canzone:\n");
    printf("Nome Autore:\n");
    printf("Minuti durata:\n");
    printf("Secondi durata:\n");
}