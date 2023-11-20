#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "utils.h"
#include "display.h"

/**
  * Conversion normal liste en SJF list et conversion SJF list en CSV
  */

/**
  * @fn fonction sjf_to_txt : Extraction des données générées par chaque processus de la simulation vers un fichier CSV (sjf.csv)
  * @param head Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void sjf_to_csv(NODE* head, int process){
    FILE *f = NULL;
    f = fopen("excel/sjf.csv","w+");
    fprintf(f,"processus;arrival time;burst time;total arrival time;waiting time;relative delay;response time\n");
    if(f!=NULL){
        while(head!=NULL){
            fprintf(f,"%d;%f;%f;%f;%f;%f;%f\n",head->no,head->at,head->bt,head->tat,head->wt,head->rd,head->rt);
            head = head->next;
        }
    }
    else{
        printf("Fail to open text file");
    }
    fclose(f);
}

/**
  * @fn fonction convert_to_sjf : Conversion des processus rentrés par l'utilisateur en une liste chainée de processus 
  * de type SJF (Shortest Job First)
  * @param p Liste chainée des processus saisie par l'utilisateur
  * @param t Liste chainée des processus de type SJF
  * @param process Nb total de processus dans la liste
  */
void convert_to_sjf(NODE **p, NODE **t, int process){
    int min;
    int count = 0;
    float pc = 0;
    NODE *r = *p;
    NODE *q = *t;
    NODE *parcours = r;
    NODE *first = r;

    while(taille(r)!=0){
        min = min_bt(r, (process-count));
        count +=1;

        while(parcours->no != min){
            parcours = parcours->next;
        }
        if(parcours == first){
            first = parcours->next;
        }
        insert(&q,min,parcours->at,parcours->bt,&pc,&(parcours->at));
        r = remove_from_list(r, min);
        parcours = first;
    }

    printf("\n<-------------------------------------------------  SJF ------------------------------------->\n");
    gantt_chart(q,count);
    display(q,count);
    sjf_to_csv(q,count);
}
