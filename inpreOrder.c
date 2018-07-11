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

struct Stack* createStack(unsigned capacity);
void push(struct Stack* stack, struct Node* item);
struct Node* pop(struct Stack* stack);
void visit(struct Node* current );

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

//T1
P=root;
//push (stack, P);//dfs
while(1){
	if(P!=NULL){//T2
		push(stack,P);			//	--
		//visit(P);//T5 preOrder     	//       |T3
		P=P->left;			//	--
	}else if(stack->top>=0){        //     --
		P=pop(stack);		//	|
		visit(P); //T5 inOrder  //	|T4
		P=P->right;	        //      |
	}else break;		        //     --
		
/*
if(stack->top==-1)break;
P=pop(stack);
visit(P);
if (P->left!=NULL)push(stack, P->left);
if (P->right!=NULL)push(stack, P->right);
*/

}       

return 0;
}
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

void visit(struct Node* current ) {
        printf("%c ", current->data);
}




