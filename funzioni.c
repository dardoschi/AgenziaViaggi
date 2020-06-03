#include "funzioni.h"

void metaPiuEconomica(int order, int*prices, struct nodoCitta*listaCitta)
{
    int min = 7;
    for(int i=0; i<order; i++)
    {
        if(prices[i] < prices[min] && prices[i]!=0)
        min = i;
    }
    
    printf ("\n La meta più economica è %s\n", contains(listaCitta, min));
}

void trattaPiuEconomica(int order, int*prices, int city1, int city2, char citta[20][20], int*distances)
{
    printf ("\n La tratta più economica costa %d$ \n", prices[city2]);
}

void trattaPiuBreve(int order, int*prices, int city1, int city2, char citta[20][20], int*distances)
{
    printf ("\n La tratta più breve dura %d ore\n", distances[city2]);
}

void metaPiuGettonata(int citta, char meteGettonate[20][20])
{
    printf ("\n La meta più gettonata è %s\n", meteGettonate[citta]);
    
}

bool controllaTrattaDiretta(int city1, int city2, weighted_edge* edges){
    for(int i = 0; i<MAXVOLI; i++){
        if(edges[i].prima == city1 && edges[i].seconda == city2){
            return true;
        }
    }
    return false;
}
 

void scegliOperazioneUtente(int*dis2tances, int*pri2ces, weighted_edge*edges, int order, int size, struct nodoCitta* listaCitta, struct nodoPrenotazione* listaPrenotazioni, int ID, struct nodoUtente* listaUtenti)
 {
    int city=0; int city2=0; int city1=0; int operazione; int value=-1; int conferma=-1; results*prices=NULL; results*distances=NULL;
    int punti=leggiPuntiUtente(listaUtenti, ID); //CASE 4 DA AGGIUNGERE
    //StampaListaPrenotazione(listaPrenotazioni, 5); //NUOVO CASE
    do
    {
        printf("\n Seleziona un'operazione: \n 1) Visualizza opzioni di viaggio da A a B \n 2) Visualizza opzioni più convenienti con partenza da A\n");
        printf(" 3) Visualizza i codici relativi alle città \n 4) Visualizza i tuoi punti sconto \n 5) Visualizza prenotazioni attive \n 0) Esci\n");
        scanf("%d", &operazione);
        switch (operazione)
	{
		case 1: //due città
		printf("\n Inserisci la città di partenza: \n");
        scanf("%d", &city1);
        printf("\n Inserisci la città di arrivo: \n");
        scanf("%d", &city2);
        prices = dijkstraPrezzi(edges, size, order, city1);
        distances = dijkstraOre(edges, size, order, city1);
        if(prices->prices[city2] < INT_MAX && prices->distances[city2] < INT_MAX && distances->prices[city2] <INT_MAX && distances->distances[city2] < INT_MAX){
            trattaPiuEconomica(order, prices->prices, city1, city2, listaCitta, distances->distances);
            trattaPiuBreve(order, distances->prices, city1, city2, listaCitta, distances->distances);
        }else{
            printf("Tratta inestistente\n");
            break;
        } 
        printf("\n Quale si desidera prenotare? 0 per più economica, 1 per più breve \n");
        scanf("%d", &value);
        if(value){ //devo sapere la più breve quanto costa
        printf("\n Prenotazione viaggio da %s a %s, costo = %d, ore di volo = %d, digitare 1 per confermare \n 2 per confermare e utilizzare i punti sconto accumulati (%d$ di sconto). \n", contains(listaCitta, city1), contains(listaCitta, city2), distances->prices[city2], distances->distances[city2], punti );
        scanf("%d", &conferma); 
        if(conferma==1){
            listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city1, city2, distances->prices[city2]);
            incrementaPunteggioUtente(ID, distances->prices[city2], listaUtenti);
            } 
        else if(conferma==2){
            listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city1, city2, distances->prices[city2]);
            decrementaPunteggioUtente(ID, punti, listaUtenti);
            } 
        }
        else{ //più economica
        printf("\n Prenotazione viaggio da %s a %s, costo = %d, durata = %d digitare 1 per confermare. \n 2 per confermare e utilizzare i punti sconto accumulati (%d$ di sconto). \n", contains(listaCitta, city1), contains(listaCitta, city2), prices->prices[city2], prices->distances[city2], punti);
         scanf("%d", &conferma); //devo sapere quanto dura
            if(conferma==1){
               listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city1, city2, prices->distances[city2]);
               incrementaPunteggioUtente(ID, (prices->prices[city2]/10), listaUtenti);
            } //aggiungo i punti
            else if(conferma==2){
            listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city1, city2, prices->distances[city2]);
            decrementaPunteggioUtente(ID, punti, listaUtenti);
        }
        }
		break;
		
		
		case 2: //Una città
        printf("\nInserisci il numero relativo alla città di partenza: \n");
        scanf("%d", &city);
        prices = dijkstraPrezzi(edges, size, order, city);
        distances = dijkstraOre(edges, size, order, city);
      
        printf ("\n La meta più gettonata è %s\n", checkGettonata(listaCitta, city));
        metaPiuEconomica(order, prices->prices, listaCitta);
        printf("\nInserisci il numero relativo alla città di arrivo: \n");
        scanf("%d", &city2);
           if(prices->prices < INT_MAX && prices->distances < INT_MAX && distances->prices <INT_MAX && distances->distances < INT_MAX){
            trattaPiuEconomica(order, prices->prices, city1, city2, listaCitta, distances->distances);
            trattaPiuBreve(order, distances->prices, city1, city2, listaCitta, distances->distances);
        }else {
            printf("Tratta inestistente\n");
            break;
        }
      
        printf("\n Quale si desidera prenotare? 0 per più economica, 1 per più breve \n");
        scanf("%d", &value);
        if(value){ //devo sapere la più breve quanto costa
        printf("\n Prenotazione viaggio da %s a %s, costo = %d, ore di volo = %d, digitare 1 per confermare \n 2 per confermare e utilizzare i punti sconto accumulati (%d$ di sconto). \n", contains(listaCitta, city), contains(listaCitta, city2), distances->prices[city2], distances->distances[city2], punti );
        scanf("%d", &conferma); 
        if(conferma==1){
            listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city, city2, distances->prices[city2]);
            incrementaPunteggioUtente(ID, distances->prices[city2], listaUtenti);
            } 
        else if(conferma==2){
            listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city, city2, distances->prices[city2]);
            decrementaPunteggioUtente(ID, punti, listaUtenti);
            } 
        }
        else{ //più economica
        printf("\n Prenotazione viaggio da %s a %s, costo = %d, durata = %d digitare 1 per confermare. \n 2 per confermare e utilizzare i punti sconto accumulati (%d$ di sconto). \n", contains(listaCitta, city), contains(listaCitta, city2), prices->prices[city2], prices->distances[city2], punti);
        scanf("%d", &conferma); //devo sapere quanto dura
            if(conferma==1){
               listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city, city2, prices->distances[city2]);
               incrementaPunteggioUtente(ID, (prices->prices[city2]/10), listaUtenti);
            } //aggiungo i punti
            else if(conferma==2){
            listaPrenotazioni=InserisciCodaPrenotazione(listaPrenotazioni, ID, city, city2, prices->distances[city2]);
            decrementaPunteggioUtente(ID, punti, listaUtenti);
            }
        }
		break;
		
		case 3: //stampa codici
		StampaLista(listaCitta);
		break;

        case 4: //punti utente
        printf("Punti sconto accumulati : %d\n", punti);
        break;


        case 5: //prenotazioni attive
        StampaListaPrenotazione(listaPrenotazioni, ID);
        break;


		default:
        printf(" Scelta invalida\n");
	    //scegliOperazioneUtente(distances, prices, edges, order, size, listaCitta, listaPrenotazioni, ID, listaUtenti);
		break;
	} //fine switch
    } while (operazione != 0);

}
 
weighted_edge* rimuoviTratta(weighted_edge *edges, int city1, int city2, int size)
{
     for(int i=0; i<size; i++){
     if(edges[i].prima==city1 && edges[i].seconda==city2){
     edges[i].prima=NULL;
     edges[i].seconda=NULL;
     edges[i].prezzo=NULL;
     edges[i].ore=NULL;
     }
     }
     return edges;
}

void login(int*distances, int*prices, weighted_edge*edges, int order, int size, struct nodoCitta* listaCitta, struct nodoUtente* listaUtenti, struct nodoPrenotazione* listaPrenotazioni)
{
    int ID=0; int i=0;
        /*weighted_edge_connect(edges, 0, 1, 2, 10, &i);
        weighted_edge_connect(edges, 0, 2, 4, 15, &i);
        weighted_edge_connect(edges, 1, 2, 1, 20, &i);
        weighted_edge_connect(edges, 1, 3, 4, 30, &i);
        weighted_edge_connect(edges, 1, 4, 2, 40, &i);
        weighted_edge_connect(edges, 2, 4, 3, 50, &i);
        weighted_edge_connect(edges, 3, 4, 3, 60, &i);
        weighted_edge_connect(edges, 3, 5, 2, 17, &i);
        weighted_edge_connect(edges, 4, 5, 2, 11, &i);*/
    FILE *fp = fopen("tratte.txt", "r");
    int city1, city2, ore, prezzo;
    while(!feof(fp)){
        if(fscanf(fp, "%d %d %d %d", &city1,&city2, &ore, &prezzo)==4)
        weighted_edge_connect(edges, city1, city2, ore, prezzo, &i);
    }
     fclose(fp);   
        
    printf("\nBenvenuto/a, inserisci le tue credenziali: \n ID Utente:\n");
    scanf("%d", &ID);


    if(ID>1 && containsUtente(listaUtenti, ID)) scegliOperazioneUtente(distances, prices, edges, order, size, listaCitta, listaPrenotazioni, ID, listaUtenti);
    else if(ID<=1){
        //Accesso admin
        int operazione;
        do{
            int city1, city2, ore, prezzo, ID2; char city3[20]; char cityGettonata[20];
            printf("\n Seleziona un'operazione: \n 1) Aggiungi tratta \n 2) Rimuovi tratta\n 3) Aggiungi città\n 0) Esci\n");
            scanf("%d", &operazione);
            switch (operazione)
            {
            case 1: //Aggiungi tratta
            system("cls");
            puts(""); 
            StampaLista(listaCitta);
            printf("\n Inserisci la città di partenza: \n"); scanf("%d", &city1);
            printf("\n Inserisci la città di arrivo: \n"); scanf("%d", &city2);
            printf("\n Inserisci le ore di volo: \n"); scanf("%d", &ore);
            printf("\n Inserisci il prezzo: \n"); scanf("%d", &prezzo);
            weighted_edge_connect(edges, city1, city2, ore, prezzo, &i);
            break;

            case 2: //rimuovi tratta
            system("cls");
            puts(""); 
            StampaLista(listaCitta);
            printf("\n Inserisci la città di partenza: \n"); scanf("%d", &city1);
            printf("\n Inserisci la città di arrivo: \n"); scanf("%d", &city2);
            edges = rimuoviTratta(edges, city1, city2, size);
            
            case 3: //aggiungi città
            system("cls");
            puts(""); 
            StampaLista(listaCitta);
            printf("\n Inserisci la città da inserire: \n"); scanf("%s", &city3);
            printf("\n Inserisci la città gettonata da inserire: \n"); scanf("%s", &cityGettonata);
            ID2=LunghezzaLista(listaCitta);
            listaCitta=InserisciCoda(listaCitta, ID2, city3, cityGettonata);
            break;
            

            case 4:
            system("cls");
            puts("");
            stampaTratte(edges);
            break;
        
            default:
            puts(" Scelta invalida");
            //scegliOperazioneUtente(distances, prices, edges, order, size, listaCitta, listaPrenotazioni, ID, listaUtenti);
            break;
            } //fine switch
        }while(operazione != 0);
   
        }//fine if
        else{//if id >1
            registraNuovoUtente(listaUtenti);
            scegliOperazioneUtente(distances, prices, edges, order, size, listaCitta, listaPrenotazioni, ID, listaUtenti);
        }
}
