//
//  main.c
//  esame_orale
//
//  Created by Elisa Quadrini on 13/03/2023.
//


/* Definire una struttura dati per la gestione dell’economia personale. Tale struttura dati deve poter consentire la gestione di tutte le entrate e tutte le uscite che una persona può avere. Una spesa, così come un’entrata, è costituita dai seguenti campi:
 Data
 Descrizione (causale)
 Ammontare
 Si definisca anche una struttura che rappresenti una lista di entrate/uscite.
 
 
 Esercizio 3
 Implementare una funzione che preso in ingresso la struttura dati rappresentante le spese di una persona, restituisca la lista delle entrate o uscite che corrispondono ad una determinata descrizione specificata come parametro.
 Si scriva un’ulteriore funzione che elimini tutte le strutture dati con una descrizione che inizia con una stringa specificata come parametro.


*/

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

typedef struct {
    int num;
    char mese[50];
    int anno;
}Data;

typedef struct dati {
    
    Data giorno;
    char descrizione[50];
    int ammontare;
    
    struct dati * next;
} Spesa;

typedef Spesa * bilancio;


bilancio Trova(bilancio a, char causale[]);
void Elimina(bilancio a, char causale[]);

bilancio InsInFondo(bilancio nuovo, bilancio attuale);


int main() {
    
}



bilancio Trova(bilancio a, char causale[]) {
    
    bilancio temp;
    bilancio nuovo;
    
    nuovo = NULL;
    
    temp = a;
    
    while(temp!= NULL) {
        
        if(strcmp(temp->descrizione, causale) == 0) {
            nuovo = InsInFondo(nuovo, temp);
            
        }
        
        temp = temp->next;
    }
    
    return nuovo;
    
}


bilancio InsInFondo(bilancio nuovo, bilancio attuale) {
    
    if(nuovo == NULL) {
        nuovo
    }
}



void Elimina(bilancio a, char causale[]) {
    
    bilancio prec, temp;
    
    prec = a;
    temp = a;
    
    int len = strlen(causale);
    
    int i=0, k=0;
    char copia[50];
    
    while(temp!=NULL) {
        
        while(temp->descrizione[i] != '\0' && i<=len) {
            copia[k] = temp->descrizione[i];
            k++;
            
            i++;
        }
        
        if(strcmp(copia, causale) == 0) {
            
            prec = temp->next;
            free(temp);
            temp = prec;
            
        } else {
            temp = temp->next;
        }
        
        
    }
    
}
