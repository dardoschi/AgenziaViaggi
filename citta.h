#ifndef CITTA_H
#define CITTA_H


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include <string.h>
#define MAXCITY 50
#define MAXVOLI 100

//citta
struct nodoCitta{
    int valore;
    char citta[20];
    char destinazioneGettonata[20];
    struct nodoCitta* next;
};

struct nodoCitta* CreaNodo (int valore, char*citta, char*destinazioneGettonata);
struct nodoCitta* InserisciCoda (struct nodoCitta* lista, int valore, char*citta, char*gettonata);
struct nodoCitta* LeggiFile (struct nodoCitta* lista, FILE* fp);
struct nodoCitta* EliminaNodi (struct nodoCitta* lista, int x);
int LunghezzaLista(struct nodoCitta* lista);
void StampaLista(struct nodoCitta* lista);
char* contains (struct nodoCitta* lista, int numero);
char* checkGettonata (struct nodoCitta* lista, int numero);
void ScriviFile (struct nodoCitta* lista, FILE*fp);


#endif