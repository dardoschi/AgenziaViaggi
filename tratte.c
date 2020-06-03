#include "tratte.h"



void creaTratte(weighted_edge*edges, FILE *fp){
    int prima, seconda, ore, prezzo, i=0;
    while(!feof(fp)){
        if(fscanf(fp, "%d %d %d %d", &prima, &seconda, &ore, &prezzo) == 4)
        weighted_edge_connect(edges, prima, seconda, ore, prezzo, &i);
    }
}

void salvaTratte(weighted_edge*edges, FILE *fp){
    int pos=0;
    //while(edges!=NULL){    
    for(pos = 0; pos < MAXVOLI; pos++){    
        if(edges[pos].prima<1000){
            int  prima = edges[pos].prima;
            int seconda = edges[pos].seconda;
            int ore = edges[pos].ore;
            int prezzo = edges[pos].prezzo;
            fprintf (fp, "%d %d %d %d\n", prima, seconda, ore, prezzo);
            //(pos)++;
        }
    }
}

void stampaTratte(weighted_edge*edges){
        for(int pos = 0; pos < MAXVOLI; pos++){    
        if(edges[pos].prima<1000){
            int  prima = edges[pos].prima;
            int seconda = edges[pos].seconda;
            int ore = edges[pos].ore;
            int prezzo = edges[pos].prezzo;
            printf ("%d %d %d %d\n", prima, seconda, ore, prezzo);
            //(pos)++;
        }
    }
}

int lunghezzaEdges(weighted_edge*edges){
    int *pos;
    for(pos = 0; pos < MAXVOLI; pos++){    
        if(edges[*pos].prima > 20 ){
            return pos;
        }else return NULL;
    }
}