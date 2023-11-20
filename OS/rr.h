#ifndef RR_H_INCLUDED
#define RR_H_INCLUDED
#include "node.h"

void convert_to_round_robin(NODE **p, int process, int quantum);
void rr_to_csv(NODE* head, int process);

#endif // RR_H_INCLUDED
