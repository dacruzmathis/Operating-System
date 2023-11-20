#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "utils.h"

/**
  * Fonctions d'insertions de noeuds en queue de liste et de suppression de noeuds données
  */

/**
  * @fn fonction insert : Insertion d'un noeud donnée dans une liste donnée
  * @param p Liste chainée des processus
  * @param no Numéro de processus
  * @param at Arrival Time processus
  * @param bt Burst Time processus
  * @param pc Time insertion processus
  * @param fr Adresse precedent
  */
void insert(NODE **p, int no,float at,float bt, float *pc, float *fr){
    NODE *q,*r = *p;
    q = (NODE*)malloc(sizeof(NODE));
    q->no = no;
    q->at = at;
    q->bt = bt;
    q->rt = *fr - at;
    if(*pc==0){
        *pc = q->at + q->bt;
    }
    else{
        *pc += q->bt;
    }
    q->pc = *pc;
    q->tat = q->pc - at;
    q->wt = q->tat - bt;
    if(q->wt<0)
        *pc -= q->wt;
    q->pc = *pc;
    q->rd = q->tat / bt;
    *fr = *fr + bt;
    q->next = NULL;
    if(*p == NULL)
        *p = q;
    else{
        while(r->next != NULL)
            r = r->next;
        r->next = q;
    }
}

/**
  * @fn fonction insert : Insertion d'un noeud donnée dans une liste donnée
  * @param p Liste chainée des processus
  * @param no Numéro de processus
  * @param at Arrival Time processus
  * @param bt Burst Time processus
  * @param pc Time insertion processus
  * @param fr Adresse precedent
  */
void insert_fifo(NODE **p, int no,float at,float bt, float *pc, float *fr){
     // CREATE NODE
    NODE *q,*r = *p;
    q = (NODE*)malloc(sizeof(NODE));
    q->no = no;
    q->at = at;
    q->bt = bt;
    q->rt = *fr - at;
    if(*pc==0){
        *pc = q->at + q->bt;
    }
    else{
        *pc += q->bt;
    }
    q->pc = *pc;//*fr + bt;
    q->tat = q->pc - at;
    q->wt = q->tat - bt;
    if(q->wt<0)
        *pc -= q->wt;
    q->pc = *pc;
    q->rd = q->tat / bt;
    *fr = *fr + bt; // Update First Response for next NODE

    // INSERT NODE AT END
    q->next = NULL;
    if(*p == NULL)
        *p = q;
    else{
        while(r->next != NULL)
            r = r->next;
        r->next = q;
    }
}

/**
  * @fn fonction delete_node : Supprime un noeud donnée
  * @param p Liste chainée des processus
  * @return NODE p
  */
NODE * delete_node(NODE *p){
	NODE *supp = p;
	if (p){
		p = p->next;
		free(supp);
	}
	return p;
}

/**
  * @fn fonction delete_list : Supprime une liste entière
  * @param list Liste chainée des processus
  * @return NODE list
  */
NODE * delete_list(NODE * list){
	int i;
	int length = taille(list);
	NODE* pos = list;

	if (length == 1){
		delete_node(pos);
		return NULL;
	}
	else if (list != NULL){					
		for (i = 1; i < length; i++){
			pos = delete_node(pos);
			pos = pos->next;
		}
		pos = delete_node(pos);			
		return pos;
	}
	else
        return list;			
}

/**
  * @fn fonction remove_from_list : Supprime une liste entière
  * @param list Liste chainée des processus
  * @param supp Numéro du processus a supprimer
  * @return NODE list
  */
NODE * remove_from_list(NODE * list, int supp){
	int length = taille(list);
	int i;
	NODE* pos = list;
	NODE* prev = list;
	NODE* hold;
	NODE *start = list;
	int temp;

	if (length == 0){
		return list;				
	}
	else if (length == 1){
		temp = pos->no;
		if (temp == supp)
			return delete_list(pos);						
		else
            return list;
	}
	else{
		temp = pos->no;
		for(i=1; i<length; i++){
			if (i == 1 && (temp == supp)){
				start = pos->next;
			}
			else if (i > 0 && temp == supp){
				hold = pos->next;
				prev->next = delete_node(pos);
				pos = hold;
				temp = pos->no;
			}
			else{
				prev = pos;
				pos = pos->next;
				temp = pos->no;
			}
		}
		if (temp == supp){
			prev->next = NULL;
			delete_node(pos);
		}
		return start;
	}
}

/**
  * @fn fonction remove_from_list_for_rr : Supprime une liste entière dans le cas de round robbin
  * @param list Liste chainée des processus
  * @param supp Numéro du processus a supprimer
  * @return NODE list
  */
NODE * remove_from_list_for_rr(NODE * list, int supp){
	int length = taille(list);
	int i, over=0;
	NODE* pos = list;
	NODE* prev = list;
	NODE* hold;
	NODE *start = list;
	int temp;

	if (length == 0){
		return list;				
	}
	else if (length == 1){
		temp = pos->no;

		if (temp == supp)
			return delete_list(pos);						
		else
            return list;
	}
	else{
		temp = pos->no;
		for(i=1; i<length; i++)
		{
			if (i == 1 && (temp == supp) && !over){
				start = pos->next;
				over = 1;
			}
			else if (i > 0 && temp == supp && !over){
				hold = pos->next;
				prev->next = delete_node(pos);
				pos = hold;
				temp = pos->no;
				over = 1;
			}
			else{
				prev = pos;
				pos = pos->next;
				temp = pos->no;
			}
		}
		if (temp == supp && !over){
			prev->next = NULL;
			delete_node(pos);
		}
		return start;
	}
}
