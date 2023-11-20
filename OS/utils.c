#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/**
  * Fonctions utiles au fonctionnement/parcours de la liste, aux differents ordonnencements... 
  */

/**
  * @fn fonction taille : Retourne la taille d'une liste chainée donnée
  * @param p Liste chainée des processus
  * @return int count
  */
int taille(NODE *p){
    int count = 0;
    while(p!=NULL){
        count +=1;
        p= p-> next;
    }
    return count;
}

/**
  * @fn fonction sum_bt : Retourne la somme des burst time d'une liste chainée donnée
  * @param p Liste chainée des processus
  * @return int sum
  */
int sum_bt(NODE *p){
    int sum = 0;
    while(p!=NULL){
        sum += p->bt;
        p= p-> next;
    }
    return sum;
}

/**
  * @fn fonction mini : Retourne le minimum entre 2 entiers
  * @param a Premier entier a comparer
  * @param b Second entier a comparer
  * @return int
  */
int mini(int a, int b){
    return a<b ? a : b;
}

/**
  * @fn fonction min_bt : Retourne le no du processus avec le burst time le + court d'une liste donnée
  * @param p Liste chainée des processus
  * @param process NB total processus
  * @return int min_proc
  */
int min_bt(NODE *p, int process){
    int min, cmp;
    int min_proc=1;
    for(int i=1; i<= process; i++){
        if(i==1){
            min = p->bt;
            min_proc= p->no;
        }
        cmp = mini(min, p->bt);
        if(cmp != min){
            min = cmp;
            min_proc= p->no;
        }
        p = p->next;
    }
    return min_proc;
}

/**
  * @fn fonction min_at : Retourne le no du processus avec le arrival time le + court d'une liste donnée
  * @param p Liste chainée des processus
  * @param process NB total processus
  * @return int min_proc
  */
int min_at(NODE *p, int process){
    int min, cmp;
    int min_proc=1;
    for(int i=1; i<= process; i++){
        if(i==1){
            min = p->at;
            min_proc= p->no;
        }
        cmp = mini(min, p->at);
        if(cmp != min){
            min = cmp;
            min_proc= p->no;
        }
        p = p->next;
    }
    return min_proc;
}