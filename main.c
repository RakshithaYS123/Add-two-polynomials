
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
int co, exp;
struct node* link;
}NODE;
NODE* create( NODE* head, int co, int exp)
{
 NODE *temp, *flag;
if(head == NULL)
{
temp = (NODE*) malloc (sizeof( NODE));
temp->co = co;
temp->exp = exp;
temp->link = NULL;
head = temp;
}
else
{
temp = head;
while(temp-> link != NULL)
temp = temp-> link;
flag = (NODE*)malloc(sizeof(NODE));
flag->co = co;
flag->exp = exp;
flag-> link = NULL;
temp-> link = flag;
}
return head;
}
 NODE* polyAdd(NODE *p1, NODE *p2, NODE *sum)
{
 NODE *poly1 = p1, *poly2 = p2, *res;
if(poly1 != NULL && poly2 == NULL)
{
sum = poly1;
return sum;
}
else if(poly1 == NULL && poly2 != NULL)
{
sum = poly2;
return sum;
}
while(poly1 != NULL && poly2 != NULL)
{
if(sum == NULL)
{
sum = ( NODE*)malloc(sizeof(NODE));
res = sum;
}
else
{
res->link = (NODE *)malloc(sizeof(NODE));;
res = res->link;
}
if(poly1->exp > poly2->exp)
{
res->co = poly1->co;
res->exp = poly1->exp;
poly1 = poly1->link;
}
else if(poly1->exp < poly2->exp)
{
res->co = poly2->co;
res->exp = poly2->exp;
poly2 = poly2->link;
} 
else if(poly1->exp == poly2->exp)
{
res->co = poly1->co + poly2->co; 
res->exp = poly1->exp; 
poly1 = poly1->link; 
poly2 = poly2->link;
}
}
while(poly1 != NULL) 
{
res->link = (NODE*)malloc(sizeof(NODE));; 
res = res->link; 
res->co = poly1->co;
res->exp = poly1->exp; 
poly1 = poly1->link; 
}
while(poly2 != NULL)
{
res->link = (NODE*)malloc(sizeof(NODE));;
res = res->link;
res->co = poly2->co;
res->exp = poly2->exp;
poly2 = poly2-> link;
}
res->link = NULL;
return sum;
  }
void display(NODE* head)
{
NODE *temp=head;
while(temp != NULL)
{
printf("%d^%d+", temp->co, temp->exp);
temp=temp->link;
}
printf("\n");
}
void main()
{
 NODE *p1 = NULL, *p2 = NULL, *sum = NULL;
int ch, co, exp;
int loop = 1;
while(loop)
{
printf("1. Add to Polynomial 1 \n 2.Add to polynomial 2 \n 3.Perform addition \n 4.Exit \n");
printf("Enter your choice:\n");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("Enter co-efficient:\n");
scanf("%d", &co);
printf("Enter exponent:\n");
scanf("%d", &exp);
p1 = create(p1, co, exp);
break;
case 2: printf("Enter co-efficient:\n");
scanf("%d", &co);
printf("Enter exponent:\n");
scanf("%d", &exp);
p2 = create(p2, co, exp);
break;
case 3: sum=polyAdd(p1,p2,sum);
printf("\nPolynomial 1\n");
display(p1);
printf("\nPolynomial 2\n");
display(p2);
printf("\nSum:\n");
display(sum);
break; 
case 4: loop = 0;
break;
default: printf("Wrong Choice! Re-enter\n");
break;
} 
}
}
