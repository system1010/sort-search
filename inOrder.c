#include<stdio.h>
#include<stdlib.h>

struct Node 
{
char data;
struct Node *left, *right;
};

struct Node* newNode(char data)
{
	struct Node* Node = (struct Node*)malloc(sizeof(struct Node));

        Node->data = data;
        Node->left = NULL;
        Node->right = NULL;

        return(Node);
}

struct Stack
{
	int top;
	struct Node* array[100];
};

struct Stack* createStack(unsigned capacity)
{
struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
stack->top = -1;
return stack;
}
void push(struct Stack* stack, struct Node* item)
{
stack->array[++stack->top] = item;
}
struct Node* pop(struct Stack* stack)
{
return stack->array[stack->top--];
}

int main()
{

struct Node* root=newNode('A');
root->left=newNode('B');
root->right=newNode('C');
root->left->left=newNode('D');
root->right->left=newNode('E');
root->right->right=newNode('F');
root->right->left->right=newNode('G');
root->right->right->left=newNode('H');
root->right->right->right=newNode('J');

struct Stack* stack = createStack(100);

struct Node* P=newNode('P');;

P=root;

int x=-1;
while(1){
	if(P!=NULL){
		push(stack, P);
		P=P->left;
	}else{
		if(stack->top>=0){
		P=pop(stack);
		printf("%c\n", P->data);
		P=P->right;
		
		
		
		}else break;

		/*
               		printf("%c\n", P->data);
	        	if (P->right!=NULL)printf("%c\n", P->right->data);
			if(stack->top==-1)break;
                	P=pop(stack);
                	while(P->left!=NULL){
				printf("%c\n", P->data);
				if(stack->top==-1)break;
				P=pop(stack);
				x=1;
			}       
			if (x=1){
				P=P->right;
				x=-1;
			}
		*/
	}
}       

return 0;
}
