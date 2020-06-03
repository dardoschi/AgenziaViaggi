#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include <string.h>

#include "citta.h"
#include "funzioni.h"
#include "prenotazioni.h"
#include "utenti.h"
#include "grafi.h"
#include "tratte.h"

#define MAXCITY 50
#define MAXVOLI 100

void metaPiuEconomica(int order, int*prices, struct nodoCitta*listaCitta);
void trattaPiuEconomica(int order, int*prices, int city1, int city2, char citta[20][20], int*distances);
void trattaPiuBreve(int order, int*prices, int city1, int city2, char citta[20][20], int*distances);
void metaPiuGettonata(int citta, char meteGettonate[20][20]);
bool controllaTrattaDiretta(int city1, int city2, weighted_edge* edges);
void scegliOperazioneUtente(int*dis2tances, int*pri2ces, weighted_edge*edges, int order, int size, struct nodoCitta* listaCitta, struct nodoPrenotazione* listaPrenotazioni, int ID, struct nodoUtente* listaUtenti);
weighted_edge* rimuoviTratta(weighted_edge *edges, int city1, int city2, int size);
void login(int*distances, int*prices, weighted_edge*edges, int order, int size, struct nodoCitta* listaCitta, struct nodoUtente* listaUtenti, struct nodoPrenotazione* listaPrenotazioni);



#endif