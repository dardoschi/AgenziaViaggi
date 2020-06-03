#ifndef UTENTI_H
#define UTENTI_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include <string.h>
#define MAXCITY 50
#define MAXVOLI 100

//utenti
struct nodoUtente{
    int id;
    char nome[20];
    int punteggio;
    struct nodoUtente* next;
};

int leggiPuntiUtente(struct nodoUtente* lista, int ID);
void decrementaPunteggioUtente(int idUtente, int punti, struct nodoUtente*lista);
void incrementaPunteggioUtente(int idUtente, int punti, struct nodoUtente*lista);
struct nodoUtente* CreaNodoUtente (int id, char* nome, int punteggio);
struct nodoUtente* InserisciCodaUtente(struct nodoUtente* lista, int id, char*nome,int punteggio);
struct nodoUtente* LeggiFileUtente (struct nodoUtente* lista, FILE* fp);
int LunghezzaListaUtente(struct nodoUtente* lista);
void ScriviFileUtente (struct nodoUtente* lista, FILE*fp);
void StampaListaUtente(struct nodoUtente* lista);
bool containsUtente(struct nodoUtente* lista, int ID);
void registraNuovoUtente(struct nodoUtente*lista);


#endif