#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct node{
    int no; //Numéro de processus
    float at,bt,pc,tat,wt,rt,rd; //Arrival Time, Burst Time, Total Arrival Time, Wait Time, Response Time, Relative Delay
    struct node *next; //Noeud suivant
}NODE;

void insert(NODE **p, int no,float at,float bt, float *pc, float *fr);
void insert_fifo(NODE **p, int no,float at,float bt,float *pc,float *fr);
NODE * delete_node(NODE *p);
NODE * delete_list(NODE * list);
NODE * remove_from_list(NODE * list, int supp);
NODE * remove_from_list_for_rr(NODE * list, int supp);

#endif // NODE_H_INCLUDED
