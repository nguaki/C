 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct CpuNode
 {   
    struct CpuNode *next;
    int cpuid;
 }CpuNode;

 typedef struct List
 {   
    struct CpuNode *HeadCpuNode;
    struct CpuNode *TailCpuNode;
 }List;

 inline static void push(List *q,CpuNode *n)
 {
   CpuNode *temp;                       

   temp= (CpuNode *)malloc(sizeof(CpuNode));
   temp->cpuid=n->cpuid;
   temp->next=NULL;
   if (q->HeadCpuNode==NULL) 
      q->HeadCpuNode=q->TailCpuNode=temp;
   else 
   {
      q->TailCpuNode=temp;
      q->TailCpuNode->next=temp;
   }   
 }

 void Discover(List *Acqcores)
 {
    CpuNode *temp;
    temp= (CpuNode *)malloc(sizeof(CpuNode));
    temp->cpuid=1;
    push(Acqcores,temp);
 }



 int 
 main(int argc, char **argv) 
 {
    List Acq_cores;
    Discover(&Acq_cores);
 }