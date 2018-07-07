typedef struct node{
char *name;
struct node *next;
}NodeT;

int hashfunction(char *name);
void insert(NodeT **Bucket, char *name);
//void insert(NodeT *Bucket, char *name);
NodeT *findNode(NodeT **buckets, char *str);
void deleteNode(NodeT **buckets, char *str);
void printNodes(NodeT **buckets);