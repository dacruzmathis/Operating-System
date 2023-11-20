#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "utils.h"
#include "display.h"

/**
  * Conversion normal liste en FIFO list et conversion FIFO list en CSV
  */

/**
  * @fn fonction fifo_to_txt : Extraction des données générées par chaque processus de la simulation vers un fichier CSV
  * @param head Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void fifo_to_csv(NODE* head, int process){
    FILE *f = NULL;
    f = fopen("excel/fifo.csv","w+");
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
  * @fn fonction convert_to_fifo : Conversion des processus rentrés par l'utilisateur en une liste chainée de processus 
  * de type FIFO (First In First Out)
  * @param head Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void convert_to_fifo(NODE* head, int process){
    printf("\n<-------------------------------------------------  FIFO ------------------------------------->\n");
    gantt_chart_fifo(head,process);
    display_fifo(head,process);
    fifo_to_csv(head,process);
}
