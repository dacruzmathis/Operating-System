#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "utils.h"
#include "display.h"

/**
  * Conversion normal liste en RR list et conversion RR list en CSV
  */

/**
  * @fn fonction rr_to_txt : Extraction des données générées par chaque processus de la simulation vers un fichier CSV (rr.csv)
  * @param head Liste chainée des processus
  * @param process Nb total de processus dans la liste
  */
void rr_to_csv(NODE* head, int process){
    FILE *f = NULL;
    f = fopen("excel/rr.csv","w+");
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
  * @fn fonction convert_to_round_robin : Conversion des processus rentrés par l'utilisateur en une liste chainée de processus 
  * de type RR (Round robbin)
  * @param p Liste chainée des processus saisie par l'utilisateur
  * @param process Nb total de processus dans la liste
  * @param quantum Nombre du quantum
  */
void convert_to_round_robin(NODE **p, int process, int quantum){
    int i,j,bt,tot=0;
    float pc = 0;
    NODE *q = NULL;
    NODE *r = *p;
    NODE *f = NULL;
    NODE *parcours;
    NODE *first;

    if(process != 1){
        for(i=1; i<=process; i++){
            bt = r->bt;
            j = 1;
            while(j <= bt){
                if(j%quantum == 0){
                    insert(&q,r->no,r->at,quantum,&pc,&(r->at));
                    tot += 1;
                }
                j++;
            }
            if(bt%quantum != 0){
                insert(&q,r->no,r->at,bt%quantum,&pc,&(r->at));
                tot += 1;
            }
            r = r->next;
        }

        first = q;
        parcours = q;
        pc=0;
        int count = 0;
        int nbp = 1,no,is_last;

        while(taille(q)!=0){
            is_last = 0;
            no = q->no;
            while(no != nbp){
                q = q->next;
            }
            insert(&f,no,q->at,q->bt,&pc,&(q->at));
            q = remove_from_list_for_rr(q, no);
            count ++;
            if(nbp == first->no){
                first = first->next;
            }
            if(nbp == process){
                nbp = first->no;
                is_last = 1;
            }
            else
                nbp++;

            if(is_last == 1)
                q = first;
            else
                q = q->next;
        }
        printf("\n<-------------------------------------------------  ROUND-ROBIN ------------------------------------->\n");
        gantt_chart(f,count);
        display(f,count);
        rr_to_csv(f,count);
    }
    else{
        printf("\n<-------------------------------------------------  ROUND-ROBIN ------------------------------------->\n");
        gantt_chart(r,1);
        display(r,1);
        rr_to_csv(r,1);
    }
    
}
