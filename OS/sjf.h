#ifndef SJF_H_INCLUDED
#define SJF_H_INCLUDED
#include "node.h"

void convert_to_sjf(NODE **p, NODE **t, int process);
void sjf_to_csv(NODE* head, int process);

#endif // SJF_H_INCLUDED
