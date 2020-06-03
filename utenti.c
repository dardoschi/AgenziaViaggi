#include "utenti.h"

int leggiPuntiUtente(struct nodoUtente* lista, int ID)
 {
   if(!lista) return 0;
    if(lista->id == ID)  return lista->punteggio;
    else return (leggiPuntiUtente(lista->next, ID));
 }
 
void decrementaPunteggioUtente(int idUtente, int punti, struct nodoUtente*lista)
{
    if(!lista) printf("\nErrore: utente non trovato\n");
    if(lista->id == idUtente) lista->punteggio=lista->punteggio - punti;
    else decrementaPunteggioUtente(idUtente, punti, lista->next);
}

void incrementaPunteggioUtente(int idUtente, int punti, struct nodoUtente*lista)
{
    if(!lista) printf("\nErrore: utente non trovato\n");
    if(lista->id == idUtente) lista->punteggio=lista->punteggio + punti;
    else incrementaPunteggioUtente(idUtente, punti, lista->next);
}

struct nodoUtente* CreaNodoUtente (int id, char* nome, int punteggio)
{
    struct nodoUtente* nuovoNodo=(struct nodoUtente*)malloc(sizeof(struct nodoUtente));
    if (!nuovoNodo) return NULL;
    strcpy(nuovoNodo->nome, nome);
    nuovoNodo->punteggio=punteggio;
    nuovoNodo->id=id;
    nuovoNodo->next=NULL;
    return nuovoNodo;
}

struct nodoUtente* InserisciCodaUtente(struct nodoUtente* lista, int id, char*nome,int punteggio)
{
    if (!lista) return CreaNodoUtente(id, nome, punteggio);
    lista->next=InserisciCodaUtente(lista->next, id, nome, punteggio);
    return lista;
}

struct nodoUtente* LeggiFileUtente (struct nodoUtente* lista, FILE* fp)
{
    int id=0; int punteggio=0; char nome[20];
    while(!feof(fp)){
        if(fscanf(fp, "%d %s %d", &id, &nome, &punteggio)==3)
        lista=InserisciCodaUtente(lista, id, nome, punteggio);
    }
    return lista;
    
}

int LunghezzaListaUtente(struct nodoUtente* lista)
{
    if(!lista)return 0;
    return (1+LunghezzaListaUtente(lista->next));
}

void ScriviFileUtente (struct nodoUtente* lista, FILE*fp)
{
    int n=LunghezzaListaUtente(lista);
    for (int i=0; i<n; i++){
        fprintf (fp, "%d %s %d \n", lista->id, lista->nome, lista->punteggio);
        lista=lista->next;
    }
}

void StampaListaUtente(struct nodoUtente* lista)
{
    if(!lista) return NULL;
    printf ("%d %s %d \n", lista->id, lista->nome, lista->punteggio);
    return StampaListaUtente(lista->next);
}
 
bool containsUtente(struct nodoUtente* lista, int ID)
 {
   if(!lista) return false;
    if(lista->id == ID)  return true;
    else return (containsUtente(lista->next, ID));
 }
 
void registraNuovoUtente(struct nodoUtente*lista)
{
    char nome[20];
    printf("Inserisci il tuo nome per completare la registrazione\n");
    scanf("%s", &nome);
    int id=LunghezzaListaUtente(lista)+1;
    lista=InserisciCodaUtente(lista, id, nome, 0);
}

