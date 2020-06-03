#include "grafi.h"

results* creaRisultato(int*distanze, int*prezzi)
{
    results* nuovo=(results*)malloc(sizeof(results));
    if (!nuovo) return NULL;
    nuovo->distances=distanze;
    nuovo->prices=prezzi;
    return nuovo;
   
}
 
results* dijkstraOre(const weighted_edge *edges,  int size,  int order, int vertex)
{
     int i;
     int *distances = malloc(order * sizeof(int));
     int* prices = malloc(order*sizeof(int));
     int *unvisited = malloc(order * sizeof(int));
    
     int unvisited_count = order;
     int current = vertex;
    if (distances == NULL || unvisited == NULL) {
        free(distances);
        free(unvisited);
        return NULL;
    }
  
    for (i = 0; i < order; i++) {
        distances[i] = INT_MAX; //tutte le distanze inizialmente sono infinito
        unvisited[i] = 1;       //tutti i vertici sono non visitati
    }
    
    distances[vertex] = 0; //la distanza al vertice di partenza è 0
    while (unvisited_count > 0) {
        /* Aggiorniamo le distanze di tutti i vicini */
         int e, v;
         int min_distance;
        for (e = 0; e < size; e++) {
            if (edges[e].prima == current || edges[e].seconda == current) {
                const  int neighbour = edges[e].prima == current ?
                    edges[e].seconda : edges[e].prima;
                const  int distance = distances[current] + edges[e].ore; //
                if (distance < distances[neighbour]) {
                    prices[neighbour]=prices[current]+edges[e].prezzo;
                    distances[neighbour] = distance;
                }
            }
        }
        /* Terminato con questo vertice */
        unvisited[current] = 0;
        unvisited_count--;
        /* Troviamo il vertice più vicino */
        min_distance = 0;
        for (v = 0; v < order; v++) {
            if (unvisited[v] == 1 && (min_distance == 0 || distances[v] < min_distance)) {
                min_distance = distances[v];
                current = v;
            }
        }
    }
    
    free(unvisited);
    results* r = creaRisultato(distances, prices);
    return r;
}


results *dijkstraPrezzi(const weighted_edge *edges,  int size,  int order, int vertex)
{
     int i;
     int *prices = malloc(order * sizeof(int));
     int*distances = malloc(order*sizeof(int));
     int *unvisited = malloc(order * sizeof(int));
     int unvisited_count = order;
     int current = vertex;
    if (prices == NULL || unvisited == NULL) {
        free(prices);
        free(unvisited);
        return NULL;
    }
  
    for (i = 0; i < order; i++) {
        prices[i] = INT_MAX; //tutte le distanze inizialmente sono infinito
        unvisited[i] = 1;       //tutti i vertici sono non visitati
    }
    
    prices[vertex] = 0; //la distanza al vertice di partenza è 0
    while (unvisited_count > 0) {
        /* Aggiorniamo le distanze di tutti i vicini */
         int e, v;
         int min_distance;
        for (e = 0; e < size; e++) {
            if (edges[e].prima == current || edges[e].seconda == current) {
                const  int neighbour = edges[e].prima == current ?
                    edges[e].seconda : edges[e].prima;
                const  int distance = prices[current] + edges[e].prezzo; //qui
                if (distance < prices[neighbour]) {
                    prices[neighbour] = distance;
                    distances[neighbour]=distances[current]+edges[e].ore;
                }
            }
        }
        /* Terminato con questo vertice */
        unvisited[current] = 0;
        unvisited_count--;
        /* Troviamo il vertice più vicino */
        min_distance = 0;
        for (v = 0; v < order; v++) {
            if (unvisited[v] == 1 && (min_distance == 0 || prices[v] < min_distance)) {
                min_distance = prices[v];
                current = v;
            }
        }
    }
    free(unvisited);
    results* r = creaRisultato(distances, prices);
    return r;
}


void weighted_edge_connect(weighted_edge *edges,  int prima,  int seconda, int ore, int prezzo,  int *pos)
{
    edges[*pos].prima = prima;
    edges[*pos].seconda = seconda;
    edges[*pos].ore = ore;
    edges[*pos].prezzo = prezzo;
    (*pos)++;
}

