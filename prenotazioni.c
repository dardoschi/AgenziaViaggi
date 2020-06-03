#include "prenotazioni.h"

struct nodoPrenotazione* CreaNodoPrenotazione (int idutente, int citta1, int citta2, int prezzo)
{
    struct nodoPrenotazione* nuovoNodo=(struct nodoPrenotazione*)malloc(sizeof(struct nodoPrenotazione));
    if (!nuovoNodo) return NULL;
    nuovoNodo->id=idutente;
    nuovoNodo->prezzo=prezzo;
    nuovoNodo->citta1=citta1;
    nuovoNodo->citta2=citta2;
    nuovoNodo->next=NULL;
    return nuovoNodo;
}

struct nodoPrenotazione* InserisciCodaPrenotazione(struct nodoPrenotazione* lista, int idutente, int citta1, int citta2, int prezzo)
{
    if(!lista) return CreaNodoPrenotazione(idutente, citta1, citta2, prezzo);
    lista->next=InserisciCodaPrenotazione(lista->next, idutente, citta1, citta2, prezzo);
    return lista;
}

struct nodoPrenotazione* LeggiFilePrenotazione (struct nodoPrenotazione* lista, FILE* fp)
{
    int idutente=0;
    int prezzo=0;
    int citta1=0;
    int citta2=0;
    while(!feof(fp)){
        if(fscanf (fp, "%d %d %d %d", &idutente, &citta1, &citta2, &prezzo)==4)
        lista=InserisciCodaPrenotazione(lista,idutente, citta1, citta2, prezzo);
    }
    return lista;
}  



int LunghezzaListaPrenotazione(struct nodoPrenotazione* lista)
{
    if(!lista)return 0;
    return (1+LunghezzaListaPrenotazione(lista->next));
}



void StampaListaPrenotazione(struct nodoPrenotazione* lista, int idutente)
{
    if(!lista) return NULL;
    if(lista->id==idutente)
    printf ("Prenotazione da %d a %d - prezzo = %d \n", lista->citta1, lista->citta2, lista->prezzo);
    return StampaListaPrenotazione(lista->next, idutente);
}


char* containsPrenotazione (struct nodoPrenotazione* lista, int numero)
{
    if(!lista) return false;
    if(lista->id == numero)  return lista->citta1;
    else return (containsPrenotazione(lista->next, numero));
}



void ScriviFilePrenotazione (struct nodoPrenotazione* lista, FILE*fp)
{
    int n=LunghezzaListaPrenotazione(lista);
    for (int i=0; i<n; i++){
        fprintf (fp, "%d %d %d %d \n", lista->id, lista->citta1, lista->citta2, lista->prezzo);
        lista=lista->next;
    }
}
