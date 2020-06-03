#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include <string.h>

#define MAXCITY 50
#define MAXVOLI 100

#include "citta.h"
#include "funzioni.h"
#include "prenotazioni.h"
#include "utenti.h"
#include "grafi.h"
#include "tratte.h"

int main(void)
{
    int size = MAXVOLI; /* Voli */
    int order = MAXCITY; /* Città */
    weighted_edge *edges = malloc(size * sizeof(weighted_edge));
    int *distances;
    int* prices;
    
    FILE*fp;
    struct nodoCitta* listaCitta=NULL; struct nodoUtente* listaUtenti=NULL; struct nodoPrenotazione* listaPrenotazioni=NULL;

    fp=fopen("utenti.txt", "r");
    if(!fp) {perror("ERRORE\n"); exit(0);}
    listaUtenti=LeggiFileUtente(listaUtenti, fp);
    fclose(fp);
    printf("\nLista utenti:\n");
    StampaListaUtente(listaUtenti);
    
    
    fp=fopen("citta.txt", "r");
    if(!fp) {perror("ERRORE\n"); exit(0);}
    listaCitta=LeggiFile(listaCitta, fp);
    fclose(fp);
    printf("\nLista città:\n");
    StampaLista(listaCitta);
    
    fp=fopen("prenotazioni.txt", "r");
    if(!fp) {perror("ERRORE\n"); exit(0);}
    listaPrenotazioni=LeggiFilePrenotazione(listaPrenotazioni, fp);
    fclose(fp);
 
    
    login(distances, prices, edges, order, size, listaCitta, listaUtenti, listaPrenotazioni);
   
    fp=fopen("citta.txt", "w");
    if(!fp) {perror("ERRORE\n"); exit(0);}
    ScriviFile(listaCitta, fp);
    fclose(fp);
    
    fp=fopen("utenti.txt", "w");
    if(!fp) {perror("ERRORE\n"); exit(0);}
    ScriviFileUtente(listaUtenti, fp);
    fclose(fp);
    
    fp=fopen("prenotazioni.txt", "w");
    if(!fp) {perror("ERRORE\n"); exit(0);}
    ScriviFilePrenotazione(listaPrenotazioni, fp);
    fclose(fp);
    
    fp=fopen("tratte.txt", "w");
    if(!fp) {perror("ERRORE\n"); exit(0);}
    salvaTratte(edges, fp);
    fclose(fp);


    return 0;
}
