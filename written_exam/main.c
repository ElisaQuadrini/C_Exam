//
//  main.c
//  esame_febbraio
//
//  Created by Elisa Quadrini on 13/02/2023.
//



/* 2.Si consideri una lista definita come sotto che contiene i punti ottenuti da clienti durante vari acquisti (ovviamente lo stesso cliente, quindi lo stesso codice, sarà presente più volte nella lista)
 
 typedef struct nodo{
     char codice[100];
     int punteggio;
     struct nodo * next;
 } nodo;
 typedef nodo * Lista;
  
 Scrivere una funzione aggrega che, data una lista di nodi, genera una nuova lista con la stessa struttura, ma in cui ogni codice appare una volta sola avendo come punteggio la somma dei punteggi dei nodi della lista di partenza.
  
 Coi dati del main allegato verrà generata una lista contenente i seguenti elementi (non importa in che ordine)
 (c1,764) --->  (c2,882) --->  (c3,834) --->  (c4,634) --->  (c5,661) --->  ---|

 Si parta da questo file: */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct n{
    char codice[100];
    int punteggio;
    struct n * next;
} nodo;
typedef nodo * Lista;



Lista InsInFondo(Lista lista,char c[],int p);
void VisualizzaLista(Lista lista );
Lista costruisci();
Lista caux(Lista lista,int i);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
Lista Aggrega(Lista lista);


int main(){
    Lista lis,risultato;
    lis=costruisci();
    VisualizzaLista(lis);
    printf("\n\n");

    //TODO: invocazione funzione e visualizzazione risultato

    printf("risulato: \n");

    risultato = Aggrega(lis);
    VisualizzaLista(risultato);

    return 0;
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//


Lista InsInFondo(Lista lista,char c[],int p) {

    Lista nuovo = malloc(sizeof(nodo));
    int i=0;

    while(c[i]!='\0') {
        nuovo->codice[i] = c[i];
        i++;
    } nuovo->codice[i] = c[i];

    nuovo->next = NULL;
    nuovo->punteggio = p;

    Lista temp;
    temp = lista;

    if( lista==NULL ) {
        return nuovo;
    } else {
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = nuovo;
    }

    return lista;
}


Lista Aggrega(Lista lista) {

    Lista temp,succ,nuova;
    temp = lista;

    nuova = malloc(sizeof(nodo));

    while(temp->next!=NULL) {
        succ = lista->next;

        while(succ->next!=NULL) {
            if(strcmp(succ->codice, temp->codice) == 0) {
                nuova = InsInFondo(nuova, temp->codice, temp->punteggio+succ->punteggio);
                succ = succ->next;

            } else nuova = InsInFondo(nuova, temp->codice, temp->punteggio);
            succ = succ->next;
        }
        temp = temp->next;
    }

    return nuova;
}



Lista costruisci(){ return caux(NULL,0);}
Lista caux(Lista lista,int i){
    int p[50]={57, 63, 70, 88, 91, 97, 57, 59, 66, 88, 94, 92, 77, 61, 68, 75, 85, 94, 68, 77, 63, 89, 85, 100, 57, 77, 59, 97, 68, 60, 87, 92, 94, 66, 61, 68, 75, 63, 89, 68, 75, 94, 57, 63, 75, 66, 92, 61, 77, 70};
    char c[50][20]={"c2", "c1", "c3", "c1", "c5", "c2", "c5", "c4", "c5", "c1", "c3", "c4", "c4", "c5", "c1", "c5", "c2", "c2", "c5", "c2", "c3", "c1", "c5", "c3", "c1", "c3", "c3", "c2", "c2", "c1", "c3", "c3", "c1", "c4", "c3", "c4", "c4", "c4", "c1", "c1", "c2", "c2", "c4", "c2", "c2", "c5", "c5", "c3", "c4", "c3"};
    if(i==50) return NULL;
    lista= (Lista)malloc( sizeof(nodo) );    lista->codice[0]=c[i][0]; lista->codice[1]=c[i][1]; lista->codice[2]=c[i][2]; lista->punteggio = p[i];    lista->next = caux(lista->next,i+1); return lista;
}

void VisualizzaLista(Lista lista ){
    if (lista==NULL) printf(" ---| \n");
    else{printf(" (%s,%i) ---> ", lista->codice, lista->punteggio); VisualizzaLista( lista->next );}
}






/*3.Si consideri la seguente definizione di un albero binario
 
 typedef struct t {
     int val;
     struct t * left, *right;
 } Nodo;

 typedef Nodo * Tree;
  
 Scrivere una funzione percorsoMediaMinima che prende in ingresso un albero binario e calcolando, per ogni percorso dalla radice alle foglie, la media dei valori (nei nodi) che compongono il percorso restituisce un unico valore che rappresenta il minimo tra le medie dei valori di ciascun percorso.
  
 Si consiglia molto fortemente l’uso di funzioni ausiliarie con parametri aggiuntivi che “trasportino” nelle chiamate informazioni utili.
  
 Con gli alberi di esempio del codice fornito l’output deve essere:
 Il percorso in T1 con media di valori minima ha media: 6.333333
 Il percorso in T2 con media di valori minima ha media: 6.500000
 Il percorso in T3 con media di valori minima ha media: 3.000000

 Si parta dal file: */


//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct n {
//    int val;
//    struct n *left;
//    struct n *right;
//} nodo;
//typedef nodo *albero;
//
//albero createVal(int val);
//albero creaAlbero1();
//albero creaAlbero2();
//albero creaAlbero3();
//
//void print(albero t);
//void stampa(albero T);
//float costoMinimoMedio(albero T);
//int Valore(albero T);
//int Depth(albero T);
//
//int main() {
//    albero T1, T2, T3;
//    T1 = creaAlbero1();
//    T2 = creaAlbero2();
//    T3 = creaAlbero3();
//
//    printf("\nT1: ");
//    stampa(T1);
//    printf("\nT2: ");
//    stampa(T2);
//    printf("\nT3: ");
//    stampa(T3);
//
//    // visualizzazione risultati e invocazione funzione
//    printf("Il percorso di T1 con media di valori minima ha media: %f\n", costoMinimoMedio(T1));
//    printf("Il percorso di T2 con media di valori minima ha media: %f\n", costoMinimoMedio(T2));
//    printf("Il percorso di T3 con media di valori minima ha media: %f\n", costoMinimoMedio(T3));
//
//    return 0;
//}
//
//float costoMinimoMedio(albero T){
//    //TODO: return da cancellare
//    albero temp;
//    temp = T;
//    float media, tot = 0;
//    int n=0;
//
//    if(temp == NULL) {
//        return 0;
//    }
//
//    tot = Valore(temp);
//
//    printf("\n tot = %f", tot);
//
//    n = Depth(temp);
//
//    media = tot/n;
//    return media;
//}
//
//
//int Valore(albero T) {
//    if(T->right == NULL && T->left == NULL) {
//        return T->val;
//    }
//
//        if(T->right->val <= T->left->val) {
//            return T->val + Valore(T->right);
//        } else return T->val + Valore(T->left);
//}
//
//int Depth(albero T) {
//    int l=0;
//
//    if(T->left==NULL && T->right==NULL) {
//        return 1;
//    } else { if(T->right->val >= T->left->val) {
//        l = 1+Depth(T->left);
//    }else l = 1+Depth(T->right);
//    }
//    return l;
//}
//
//albero creaAlbero1() {
//    albero tmp = createVal(7);
//    tmp->left = createVal(3);
//    tmp->left->left = createVal(9);
//    tmp->left->right = createVal(10);
//    tmp->right = createVal(8);
//    tmp->right->left = createVal(5);
//    tmp->right->right = createVal(12);
//    tmp->right->right->left = createVal(11);
//    tmp->right->right->right = createVal(6);
//    return tmp;
//}
//
//albero creaAlbero2() {
//    albero tmp = createVal(8);
//    tmp->left = createVal(5);
//    tmp->right = createVal(12);
//    tmp->right->left = createVal(11);
//    tmp->right->right = createVal(6);
//    return tmp;
//}
//
//albero creaAlbero3() {
//    albero tmp = createVal(8);
//    tmp->left = createVal(5);
//    tmp->right = createVal(0);
//    tmp->right->left = createVal(1);
//    tmp->right->right = createVal(5);
//    return tmp;
//}
//
//void print(albero t) {
//    if (t == NULL)return;
//    else {
//        printf(" (");
//        print(t->left);
//        printf(" %d ", t->val);
//        print(t->right);
//        printf(") ");
//    }
//}
//
//void stampa(albero T) {
//    print(T);
//    printf("\n");
//}
//
//albero createVal(int val) {
//    albero tmp = (albero)malloc(sizeof(nodo));
//    tmp->val = val;
//    tmp->left = NULL;
//    tmp->right = NULL;
//    return tmp;
//}
