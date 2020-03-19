/*--------------------------------------------------------*
 * 		Creación de una estructura de datos tipo pila     *
 * 	  Autor: Alvarado Díaz Marco Antonio : Maranvaraiaz   *
 * -------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE=0, TRUE= !FALSE} Bool;

struct typeNode
{
    int ID;
    char *data;
    struct typeNode *next;
};

typedef struct typeNode node;

struct typeStack
{
    int size;
    node *top;
    node *bottom;
};

typedef struct typeStack stack;

node *createNode(int ID, char *data)
{
    node *n =(node*) malloc (sizeof(node));
    n->ID=ID;
    n->data=(char*) malloc (sizeof(char)*strlen(data));
    n->data=data;
    n->next=NULL;
    return n;
}

static void deleteNode(node *n)
{
    free (n);
}

stack *newStack()
{
    stack *s=(stack*) malloc(sizeof(stack));
    s->size=0;
    s->top=NULL;
    s->bottom=NULL;
    return s;
}

Bool isEmpty(stack *s)
{
    if (s->size==0 || s->top==NULL)
    {
        return TRUE;
    }
    return FALSE;
}

void insertNode(stack *s,int ID, char *data)
{
    node *n = createNode(ID,data);
    if (isEmpty(s))
    {
        s->top=n;
        s->bottom=n;
    }
    else
    {
        s->top->next=n;
        s->top=n;
    }
    s->size+=1;
}

void removeNode(stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty stack\n");
    }
    else
    {
        node *tmp = s->bottom;
        if (s->size == 1)
        {
            s->top=NULL;
            s->bottom=NULL;
        }
        else
        {
            int i;
            for (i=0;i<(s->size)-1;i++)
            {
                s->top=tmp;
                tmp=tmp->next;
            }
            s->top->next=NULL;
        }
        deleteNode(tmp);
        s->size-=1;
    }
}

void printStack(stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty stack\n");
    }
    else
    {
        node *tmp = s->bottom;
        int i;
        printf("Id\tData\n");
        for (i=0;i<s->size;i++)
        {
            printf("%d\t%s\n",tmp->ID,tmp->data);
            tmp=tmp->next;
        }
    }
}

int main ()
{
    stack *testStack = newStack();
    insertNode(testStack,1,"Hola");
    insertNode(testStack,2,"M");
    insertNode(testStack,3,"A");
    insertNode(testStack,4,"R");
    insertNode(testStack,5,"I");
    printStack(testStack);
    removeNode(testStack);
    printStack(testStack);
    removeNode(testStack);
    printStack(testStack);
    removeNode(testStack);
    printStack(testStack);
    removeNode(testStack);
    printStack(testStack);
    removeNode(testStack);
    insertNode(testStack,1000,"HOLA WE");
    printStack(testStack);
    removeNode(testStack);
    return 0;
}
