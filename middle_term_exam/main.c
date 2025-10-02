//
//  main.c
//  Esame
//
//  Created by Elisa Quadrini on 05/11/2022.
//

/* 1.Definiamo percorso all'interno di una matrice una sequenza di lunghezza nota di coordinate (x,y) in cui x indica la riga e y la colonna. Gli indici del percorso partono da 0.
 
 Per rappresentare il percorso si utilizzi la seguente definizione:

 typedef struct {int x,y;} Punto;

 e due variabili:
 - un vettore di Punti
 - una variabile intera che ne indica le dimensioni effettive

 Si considerino le seguenti dichiarazioni:

 #define N 100
 #define M 8

 Punto per1[N] = {{0,0},{0,-4},{2,6},{4,5},{3,1},{7,2},{8,2},{2,-4}}; // inizializzazione di un percorso
 Punto per2[N];
 int lung1 = 8, lung2 = 0; // variabili che contengono le dimensioni effettive dei percorsi
 char mat[M][M]={'B','R','S','P','E','E','F','A',
                              'Y','V','K','W','F','H','H','W',
                              'J','C','S','I','E','R','R','F',
                              'F','V','C','P','L','N','B','Q',
                              'P','C','D','F','Y','A','O','P',
                              'C','G','W','S','C','Q','O','O',
                              'D','H','H','S','L','L','U','I',
                              'X','R','O','L','E','N','T','Y'};
 Stringa str;

 Nel file
 https://www.dropbox.com/s/np3h592pn1ng8no/testo.c?dl=0

 trovate (nel main) la definizione ed inizializzazione di un percorso: per1 e lung1, nonchè la definizione di un secondo percorso per2 e lung2. Si noti che per2 non è inizializzata e quindi lung2 viene coerentemente inizializzata a 0. Nel file viene anche dichiarata ed inizializzata una matrice mat di caratteri 8x8 e dichiarata una stringa str non inizializzata.
 Si noti anche che il percorso non è valido rispetto alla matrice perché contiene due punti con coordinate negative e un punto con riga=8 (che non esiste).

 Si chiede di:
 - scrivere una funzione stampaPercorso che ricevuto in ingresso un percoso e la sua lunghezza stampa le sue coordinate. Ad esempio, se invocata avendo come parametro per1 e lung1 stamperà (0,0) (0,-4) (2,6) (4,5) (3,1) (7,2) (8,2) (2,-4)
 - scrivere una funzione pulisci che ricevendo in ingresso e restituendo gli opportuni parametri riporta al chiamante e faccia in modo che siano contenuti in per2 i punti del percorso con le sole coordinate ammissibili per una matrice 8x8 e che lung2 contenga la lunghezza di tale percorso. Si invocherà poi stampaPercorso anche per per2 e verrà stampato (0,0) (2,6) (4,5) (3,1) (7,2)
 - infine si scriva una funzione che, usando un percorso e una matrice, inserisce in una stringa (che dovrà essere ben formata) i caratteri della matrice contenuti nelle caselle indicate dal percorso. La funzione dovrà essere usata per inserire in str il risultato della sua esecuzione usando il percorso in per2 e mat. Nel main si dovrà poi stampare la stringa str e con i valori nel file fornito verrà stampato BRAVO.*/



#include <stdio.h>

#define N 100
#define M 8

typedef struct {int x,y;} Punto;

//scrivere qui i prototipi delle funzioni richieste

void StampaPercorso(Punto per[], int len);
int Pulisci(Punto p1[], Punto p2[], int len, int dim);
int Scrivi(Punto p[], char mat[][M], char str[], int len);


int main(){
    Punto per1[100]={{0,0},{0,-4},{2,6},{4,5},{3,1},{7,2},{8,2},{2,-4}};
    Punto per2[100];
    int lung1=8,lung2=0;
    char mat[M][M]={'B','R','S','P','E','E','F','A',
                    'Y','V','K','W','F','H','H','W',
                    'J','C','S','I','E','R','R','F',
                    'F','V','C','P','L','N','B','Q',
                    'P','C','D','F','Y','A','O','P',
                    'C','G','W','S','C','Q','O','O',
                    'D','H','H','S','L','L','U','I',
                    'X','R','O','L','E','N','T','Y'};
    
    char str[N];
    int k,i;
    
    //scrivere qui le chiamate a funzione
    
    StampaPercorso(per1, lung1);
    lung2 = Pulisci(per1, per2, lung1, M);
    
    k = Scrivi(per2, mat, str, lung2);
    
    printf("\nParola: \n");
    for(i=0; i<k; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

//scrivere qui le funzioni richieste


void StampaPercorso(Punto per[], int len) {
    int i;
    
    for(i=0; i<len; i++) {
        printf("(%d, %d) ", per[i].x, per[i].y);
    }
}


int Pulisci(Punto p1[], Punto p2[], int len, int dim) {
    
    int i,j=0;
    
    for(i=0; i<len; i++) {
        
        if((p1[i].x>=0 && p1[i].x<dim) && (p1[i].y>=0 && p1[i].y<dim)) {
            p2[j].x = p1[i].x;
            p2[j].y = p1[i].y;
            
            j++;
        }
    }
    
    StampaPercorso(p2, j);
    return j;
}


int Scrivi(Punto p[], char mat[][M], char str[], int len) {

    int i,k=0;
    for(i=0; i<len; i++) {
        str[k] = mat[p[i].x][p[i].y];
        k++;
    }
    return k;
}


