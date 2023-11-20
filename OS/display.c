#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/**
  * Création du graphe et affichage dans le terminale
  */

/**
  * @fn fonction gantt_chart : Affichage de la liste chainée dans le terminal
  * @param p Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void gantt_chart(NODE *p, int process){
    int i;
    NODE *r = p;
    printf("\n\nGannt Chart:\n");
    for(i=1;i<= process; i++)
        printf("----------------");
    printf("\n");

    for(i=1; i<= process; i++){
        printf("|\tP%d\t",p->no);
        p = p->next;
    }
    printf("|\n");

    for(i=1; i<= process; i++)
        printf("----------------");

    printf("\n");
    printf("%.1f      \t",r->at);
    for(i=1; i<= process; i++){
        printf("%.1f      \t",r->pc);
        r = r->next;
    }
}

/**
  * @fn fonction display : Affichage processus par processus, de l'ensemble des données relatives aux processus
  * @param p Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void display(NODE *p,int process){
    float ttat,twt,trd,trt,tbt;
    ttat = twt = trd = trt = tbt = 0;
    printf("\n\n\nProcess Details:");
    while(p!=NULL){
        printf("\n Process %d: \n",p->no);
        printf("Arrival Time: %.2f\n",p->at);
        printf("Burst Time: %.2f\n",p->bt);
        printf("Turn Around Time: %.2f\n",p->tat);
        printf("Waiting Time: %.2f\n",p->wt);
        printf("Relative Delay: %.2f\n",p->rd);
        printf("Response Time: %.2f\n",p->rt);
        printf("Count : %.2f\n",p->pc);
        ttat += p->tat;
        twt += p->wt;
        trd += p->rd;
        trt += p->rt;
        tbt += p->bt;

        p = p->next;

    }
    printf("\n\n\nOverall Details:\n");
    printf(" Throughput: %.2f\n",process/tbt);
    printf(" Average Turn Around Time: %.2f\n",ttat/process);
    printf(" Average Waiting Time: %.2f\n",twt/process);
    printf(" Average Relative Delay: %.2f\n",trd/process);
    printf(" Average Response Time: %.2f\n",trt/process);
}

/**
  * @fn fonction gantt_chart_fifo : Affichage de la liste chainée dans le terminal de type FIFO
  * @param p Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void gantt_chart_fifo(NODE *p, int process){
    int i;
    NODE *r = p;
    printf("\n\nGannt Chart:\n");
    for(i=1;i<= process; i++)
        printf("----------------");
    printf("\n");

    for(i=1; i<= process; i++){
        printf("|\tP%d\t",p->no);
        p = p->next;
    }
    printf("|\n");

    for(i=1; i<= process; i++)
        printf("----------------");

    printf("\n");
    printf("%.1f      \t",r->at);
    for(i=1; i<= process; i++){
        printf("%.1f      \t",r->pc);
        r = r->next;
    }
}

/**
  * @fn fonction display_fifo : Affichage processus par processus, de l'ensemble des données relatives aux processus (FIFO)
  * @param p Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void display_fifo(NODE *p,int process){
    float ttat,twt,trd,trt,tbt;
    ttat = twt = trd = trt = tbt = 0;
    printf("\n\n\nProcess Details:");
    while(p!=NULL){
        printf("\n Process %d: \n",p->no);
        printf("Arrival Time: %.2f\n",p->at);
        printf("Burst Time: %.2f\n",p->bt);
        printf("Turn Around Time: %.2f\n",p->tat);
        printf("Waiting Time: %.2f\n",p->wt);
        printf("Relative Delay: %.2f\n",p->rd);
        printf("Response Time: %.2f\n",p->rt);
        ttat += p->tat;
        twt += p->wt;
        trd += p->rd;
        trt += p->rt;
        tbt += p->bt;

        p = p->next;

    }
    printf("\n\n\nOverall Details:\n");
    printf(" Throughput: %.2f\n",process/tbt);
    printf(" Average Turn Around Time: %.2f\n",ttat/process);
    printf(" Average Waiting Time: %.2f\n",twt/process);
    printf(" Average Relative Delay: %.2f\n",trd/process);
    printf(" Average Response Time: %.2f\n",trt/process);
}