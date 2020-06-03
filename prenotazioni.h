#ifndef PRENOTAZIONI_H
#define PRENOTAZIONI_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include <string.h>
#define MAXCITY 50
#define MAXVOLI 100

//prenotazioni
struct nodoPrenotazione{
    int id;
    int citta1;
    int citta2;
    int prezzo;
    struct nodoPrenotazione* next;
};

struct nodoPrenotazione* CreaNodoPrenotazione (int idutente, int citta1, int citta2, int prezzo);
struct nodoPrenotazione* InserisciCodaPrenotazione(struct nodoPrenotazione* lista, int idutente, int citta1, int citta2, int prezzo);
struct nodoPrenotazione* LeggiFilePrenotazione (struct nodoPrenotazione* lista, FILE* fp);
int LunghezzaListaPrenotazione(struct nodoPrenotazione* lista);
void StampaListaPrenotazione(struct nodoPrenotazione* lista, int idutente);
char* containsPrenotazione (struct nodoPrenotazione* lista, int numero);
void ScriviFilePrenotazione (struct nodoPrenotazione* lista, FILE*fp);

#endif