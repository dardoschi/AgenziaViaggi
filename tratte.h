#ifndef TRATTE_H
#define TRATTE_H

#include "grafi.h"
#include "citta.h"

void creaTratte(weighted_edge*edges, FILE *fp);
void salvaTratte(weighted_edge*edges, FILE *fp);
void stampaTratte(weighted_edge*edges);
int lunghezzaEdges(weighted_edge*edges);

#endif