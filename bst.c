#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *lchild;
	struct Node *rchild;
	int data;
};
struct Node *root=NULL;
struct Queue
{
	int size;
	int front;
	int rear;
	struct Node **Q;
};
void createQueue(struct Queue *q,int size)
{
	q->size=size;
	q->front=q->rear=-1;
	q->Q=(struct Node**)malloc(q->size*sizeof(struct Node*));
}
void enqueue(struct Queue *q,struct Node *x)
{
	if((q->rear+1)%q->size==q->front)
	{
		printf("Queue is full");
	}
	else
	{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
		
	}
}
Node *dequeue(struct Queue *q)
{
	Node * x=NULL;
	if(q->front==q->rear)
	{
		printf("queue is empty");
	}
	else
	{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
}
int isEmpty(struct Queue q)
{
	return q.front==q.rear;
}
void creates()
{
	struct Node *p,*t;
	int x;
	struct Queue q;
	createQueue(&q,100);
	printf("enter root value:");
	scanf("%d",&x);
	root=(struct Node*)malloc(sizeof(struct Node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!isEmpty(q))
	{
		p=dequeue(&q);
		printf("enter the left child %d",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct Node*)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("enter the rigth child %d",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct Node*)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
		
	}
	
}
void preorder(struct Node *p)
{
	if(p)
	{
		printf("%d",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(struct Node *p)
{
	if(p)
	{
		inoder(p->lchild);
		printf("%d",p->data);
		inorder(p->rchild);
	}
}
void postorder(struct Node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d",p->data);
	}
}
int main()
{
	creates();
	printf("preorder is ......\n");
	preorder(root);
	printf("inorder is ......\n");
	inorder(root);
	printf("postorder is .....\n");
	postorder(root);
}
