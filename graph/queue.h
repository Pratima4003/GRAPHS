/** QUEUE.H FILE **/

//structure of node
typedef struct node{
	int data;
	struct node *next;
}node;

//structure of queue
typedef struct queue{
	node*front;
	node*rear;
	int count;
}queue;

//functions
void initQ(queue *Q);
int isEmpty(queue Q);
void enQ(queue *Q, int k);
int deQ(queue *Q);
