#include "citta.h"

struct nodoCitta* CreaNodo (int valore, char*citta, char*destinazioneGettonata)
{
    struct nodoCitta* nuovoNodo=(struct nodoCitta*)malloc(sizeof(struct nodoCitta));
    if (!nuovoNodo) return NULL;
    nuovoNodo->valore=valore;
    strcpy(nuovoNodo->citta, citta);
    strcpy(nuovoNodo->destinazioneGettonata, destinazioneGettonata);
    nuovoNodo->next=NULL;
}

struct nodoCitta* InserisciCoda (struct nodoCitta* lista, int valore, char*citta, char*gettonata)
{
    if (!lista) return CreaNodo (valore, citta, gettonata);
    lista->next=InserisciCoda (lista->next, valore, citta, gettonata);
    return lista;
}

struct nodoCitta* LeggiFile (struct nodoCitta* lista, FILE* fp)
{
    int valore=0;
    char citta[20];
    char gettonata[20];
    while(!feof(fp)){
        if(fscanf (fp, "%s %s", &citta, &gettonata)==2)
        lista=InserisciCoda(lista, valore, citta, gettonata);
        valore++;
    }
    return lista;
}  


struct nodoCitta* EliminaNodi (struct nodoCitta* lista, int x)
{
    if(!lista) return NULL;
    if(lista->valore==x) return EliminaNodi(lista->next, x);
    lista->next=EliminaNodi(lista->next, x);
    return lista;
}

int LunghezzaLista(struct nodoCitta* lista)
{
    if(!lista)return 0;
    return (1+LunghezzaLista(lista->next));
}



void StampaLista(struct nodoCitta* lista)
{
    if(!lista) return NULL;
    printf ("%d: %s \n", lista->valore, lista->citta);
    return StampaLista(lista->next);
}

char* contains (struct nodoCitta* lista, int numero)
{
    if(!lista) return false;
    if(lista->valore == numero)  return lista->citta;
    else return (contains(lista->next, numero));
}

char* checkGettonata (struct nodoCitta* lista, int numero)
{
    if(!lista) return false;
    if(lista->valore == numero)  return lista->destinazioneGettonata;
    else return (checkGettonata(lista->next, numero));
}

void ScriviFile (struct nodoCitta* lista, FILE*fp)
{
    int n=LunghezzaLista(lista);
    for (int i=0; i<n; i++){
        fprintf (fp, "%s %s \n", lista->citta, lista->destinazioneGettonata);
        lista=lista->next;
    }
}




