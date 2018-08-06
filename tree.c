#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int op_preced(const char c)
{
    switch(c)
    {
        case '!':
        return 4;

        case '*':
        case '/':
        case '%':
        return 3;

        case '+':
        case '-':
        return 2;

        case '=':
        return 1;
    }
    return 0;
}

bool op_left_assoc(const char c)
{
    switch(c)
    {

        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
        case '=':
        return true;

        case '!':
        return false;
    }
    return false;
}

unsigned int op_arg_count(const char c)
{
    switch(c)
    {
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
        case '=':
        return 2;
        case '!':
        return 1;

	default:
	return c - 'A';
    }
	return 0;
}

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=')
#define is_function(c) (c >= 'A' && c <= 'Z')
#define is_ident(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))

bool shunting_yard(const char *input, char *output)
{
    const char *strpos = input, *strend = input + strlen(input);
    char c, stack[32], sc, *outpos = output;
    unsigned int sl = 0;
    while(strpos < strend)
    {
        c = *strpos;
        if(c != ' ')
        {

            if(is_ident(c))
            {
                *outpos = c; ++outpos;
		*outpos = ' '; ++outpos;
            }

            else if(is_function(c))
            {
                stack[sl] = c;
                ++sl;
            }

            else if(c == ',')
            {
                bool pe = false;
                while(sl > 0)
                {
                    sc = stack[sl - 1];
                    if(sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        *outpos = sc; ++outpos;
			*outpos = ' '; ++outpos;
                        sl--;
                    }
                }
                if(!pe)
                {
                    printf("Error: separator or parentheses mismatched\n");
                    return false;
                }
            }
            else if(is_operator(c))
            {
                while(sl > 0)
                {
                    sc = stack[sl - 1];
                    if(is_operator(sc) &&
                        ((op_left_assoc(c) && (op_preced(c) <= op_preced(sc))) ||
                           (!op_left_assoc(c) && (op_preced(c) < op_preced(sc)))))
                    {

                        *outpos = sc; ++outpos;
			*outpos=' '; ++outpos;
                        sl--;
                    }
                    else
                    {
                        break;
                    }
                }

                stack[sl] = c;
                ++sl;
            }

            else if(c == '(')
            {
                stack[sl] = c;
                ++sl;
            }

            else if(c == ')')
            {
                bool pe = false;
 
                while(sl > 0)
                {
                    sc = stack[sl - 1];
                    if(sc == '(')
                    {
                        pe = true;
                        break;
                    }
                    else
                    {
                        *outpos = sc; ++outpos;
			*outpos=' '; ++outpos;
                        sl--;
                    }
                }

                if(!pe)
                {
                    printf("Error: parentheses mismatched\n");
                    return false;
                }
 
                sl--;
 
                if(sl > 0)
                {
                    sc = stack[sl - 1];
                    if(is_function(sc))
                    {
                        *outpos = sc; ++outpos;
			*outpos = ' '; ++outpos;
                        sl--;
                    }
                }
            }
            else
            {
                printf("Unknown token %c\n", c);
                return false; // Unknown token
            }
        }
        ++strpos;
    }
 
    while(sl > 0)
    {
        sc = stack[sl - 1];
        if(sc == '(' || sc == ')')
        {
            printf("Error: parentheses mismatched\n");
            return false;
        }
        *outpos = sc; ++outpos;
	*outpos=' '; ++outpos;
        --sl;
    }

    *outpos = 0;
    return true;
}


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



struct Stack* createStack();
void push(struct Stack* stack, struct Node* item);
struct Node* pop(struct Stack* stack);

void visit(struct Node* current);

int main(int argc, char* argv[])
{

struct Stack* s =createStack(100);
struct Stack* s1=createStack(100);
struct Stack* s2=createStack(100);

struct Node* r=newNode('c');
struct Node* r1=newNode('A');


const char *input = argv[1];
char output[128];
shunting_yard(input, output);

for (int i=0; output[i] != '\0';i++)push(s, newNode(output[i]));
for (int i=s->top;i>-1;i--)push(s1, pop(s));






/*
int pushed=-1;
for (int i=s1->top;i>-1;i--){
r=pop(s1);
if (is_ident(r->data))printf("%c", r->data);
if(pushed==1){
	for (int i=s->top;i>-1;i--){
		printf("%c", pop(s)->data);
	}
	pushed=-1;
}

	if (is_operator(r->data)){
		if(s->top>-1){
			if(op_preced(s->array[s->top]->data)<op_preced(r->data)){
				push(s,r);
				pushed=1;
		}else printf("%c", pop(s)->data);
	}else push(s,r);
}

}
for (int i=s->top;i>-1;i--)printf("%c", pop(s)->data);
*/


/*

bool pushed=false;
for (int i=s1->top;i>-1;i--){
r=pop(s1);
if (is_ident(r->data))push(s2,r);
if(pushed){
for (int i=s->top;i>-1;i--){
push(s2, pop(s));
}
pushed=false;
}

if(is_operator(r->data)){
if(s->top>-1){
if(op_preced(s->array[s->top]->data)<op_preced(r->data)){
push(s,r);
pushed=true;
}else push(s2, pop(s));
}else push(s,r);

}
for (int i=s->top;i>-1;i--)push(s2, pop(s));																			
*/

//for (int i=s2->top;i>-1;i--)push(s1, pop(s2));
//for (int i=s1->top;i>-1;i--)printf("%c",s1->array[i]->data);
	    
struct Node* root=newNode('A');

for (int i=s1->top;i>-1;i--){
	if (is_operator(s1->array[i]->data)){
	s1->array[i]->right=pop(s2);
	s1->array[i]->left=pop(s2);
	push(s2, s1->array[i]);
	}else if(is_ident(s1->array[i]->data))push(s2, s1->array[i]);
}

root=pop(s2);

struct Stack* stack = createStack(100);

struct Node* P=newNode('P');;

//T1
P=root;
while(1){
	if(P){//T2
		push(stack,P);			//	--
		visit(P);//T5 preOrder     	//       |T3
		P=P->left;			//	--
	}else if(stack->top>=0){        //     --
		P=pop(stack);		//	|
		//visit(P); //T5 inOrder  //	|T4
		P=P->right;	        //      |
	}else break;		        //     --
		
}
P=root;
printf("%c\n", ' ');
while(1){
        if(P){//T2
                push(stack,P);                  //      --
                //visit(P);//T5 preOrder        //       |T3
                P=P->right;                      //      --
	}else if(stack->top>=0){        //     --
	        P=pop(stack);           //      |
	        visit(P); //T5 inOrder  //      |T4
	        P=P->left;             //      |
	}else break;                    //     --
	                                                                              
}


P=root;
printf("%c\n", ' ');
do
{
// Move to leftmost node
while (P)
{
// Push root's right child and then root to stack.
if (P->right)
push(stack, P->right);
push(stack, P);
// Set root as root's left child 
P = P->left;
}
// Pop an item from stack and set it as root 
P = pop(stack);
// If the popped item has a right child and the right child is not
// processed yet, then make sure right child is processed before root
if (P->right && stack->array[stack->top] == P->right)
{
pop(stack); // remove right child from stack
push(stack, P); // push root back to stack
P = P->right; // change root so that the right 
// child is processed next
}
else // Else print root's data and set root as NULL
{
visit(P);
P = NULL;
}
} while (stack->top>=0);

P=root;
printf("%c\n", ' ');
push(stack, P);
while(stack->top>=0){
	P=pop(stack);
	visit(P);
	if (P->right)push(stack, P->right);
	if (P->left)push(stack, P->left);
}    

return 0;
}
struct Stack* createStack()
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




