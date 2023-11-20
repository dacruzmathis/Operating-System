#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "sjf.h"
#include "rr.h"

/**
  * Programme principale
  */

int main(void){

    NODE *head = NULL;
    NODE *fifo = NULL;
    NODE *sjf = NULL;
    NODE *cpy = NULL;
    int process,i,quantum;
    float arrival_time,burst_time,first_response,pc=0,pc2=0;

    printf("Enter the no. of Process: ");
    scanf("%d",&process);
    for(i=1; i<= process; i++){
        printf("\nEnter the Details for Process %d: \n",i);
        printf("\tArrival Time: ");
        scanf("%f",&arrival_time);
        printf("\tBurst Time: ");
        scanf("%f",&burst_time);
        if(i==1)
            first_response = arrival_time;
        insert_fifo(&fifo,i,arrival_time,burst_time,&pc2,&first_response);
        insert(&head,i,arrival_time,burst_time,&pc,&first_response);        
        insert(&cpy,i,arrival_time,burst_time,&pc,&first_response);
    }
    
    printf("\nEnter the quantum: \n");
    scanf("%d",&quantum);

    printf("\n<-------------------------------------------------  START ------------------------------------->\n");
    convert_to_fifo(fifo, process);
    convert_to_sjf(&head, &sjf, process);
    convert_to_round_robin(&cpy, process, quantum);
    printf("\n<-------------------------------------------------  END ------------------------------------->\n");
    return 0;
}
