#ifndef GRAFI_H
#define GRAFI_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include <string.h>
#define MAXCITY 50
#define MAXVOLI 100

typedef struct {
     int prima;
     int seconda;
     int ore;
     int prezzo;
} weighted_edge;


typedef struct{
    int* distances;
    int* prices;
} results;


results* creaRisultato(int*distanze, int*prezzi);
results* dijkstraOre(const weighted_edge *edges,  int size,  int order, int vertex);
results *dijkstraPrezzi(const weighted_edge *edges,  int size,  int order, int vertex);
void weighted_edge_connect(weighted_edge *edges,  int prima,  int seconda, int ore, int prezzo,  int *pos);

#endif