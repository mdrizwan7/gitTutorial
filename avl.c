#include<stdio.h>
#include<stdlib.h>
struct Node
{
int num;
struct Node *left;
struct Node *right;
};
struct Node *start;
struct StackNode
{
struct Node *ptr;
struct StackNode *next;
};
struct StackNode *stackStart;
struct QueueNode
{
struct Node *ptr;
struct QueueNode *next;
};
struct QueueNode *queueStart;
struct QueueNode *queueEnd;
int isStackEmpty()
{
return stackStart==NULL;
}
int isQueueEmpty()
{
return queueStart==NULL;
}
struct Node * elementAtTop()
{
return stackStart->ptr;
}
void push(struct Node *elem)
{
struct StackNode *t;
t=(struct StackNode *)malloc(sizeof(struct StackNode));
t->ptr=elem;
t->next=stackStart;
stackStart=t;
}
struct Node * pop()
{
struct StackNode *t;
struct Node *elem;
t=stackStart;
elem=t->ptr;
stackStart=stackStart->next;
free(t);
return elem;
}
void addToQueue(struct Node *elem)
{
struct QueueNode *t;
t=(struct QueueNode *)malloc(sizeof(struct QueueNode));
t->ptr=elem;
t->next=NULL;
if(queueStart==NULL)
{
queueStart=t;
queueEnd=t;
}
else
{
queueEnd->next=t;
queueEnd=t;
}
}
struct Node * removeFromQueue()
{
struct QueueNode *t;
struct Node *elem;
t=queueStart;
elem=t->ptr;
queueStart=queueStart->next;
if(queueStart==NULL) queueEnd=NULL;
free(t);
return elem;
}
void balanceIt();
int getHeightOfTreeUsingRecursion(struct Node *);
int insertInAVLTree(int num)
{
struct Node *t,*j;
if(start==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=NULL;
t->right=NULL;
start=t;
return 1;
}
j=start;
while(1)
{
if(num==j->num) return 0;
push(j);
if(num<j->num)
{
if(j->left==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=NULL;
t->right=NULL;
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=NULL;
t->right=NULL;
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
balanceIt();
return 1;
}
void balanceIt()
{
struct Node **p2p;
struct Node *root,*parent,*rc,*rclc,*lc,*lcrc;
int lch,rch,diff;
while(!isStackEmpty())
{
root=pop();
lch=getHeightOfTreeUsingRecursion(root->left);
rch=getHeightOfTreeUsingRecursion(root->right);
diff=lch-rch;
if(diff>=-1 && diff<=1)
{
continue;
}
if(root==start)
{
p2p=&start;
}
else
{
parent=elementAtTop();
if(root==parent->left)
{
p2p=&(parent->left);
}
else
{
p2p=&(parent->right);
}
}
if(diff<0)
{
rc=root->right;
if(getHeightOfTreeUsingRecursion(rc->left)>getHeightOfTreeUsingRecursion(rc->right))
{
rclc=rc->left;
rc->left=rclc->right;
rclc->right=rc;
root->right=rclc;
rc=root->right;
}
root->right=rc->left;
rc->left=root;
*p2p=rc;
}
else
{
lc=root->left;
if(getHeightOfTreeUsingRecursion(lc->right)>getHeightOfTreeUsingRecursion(lc->left))
{
lcrc=lc->right;
lc->right=lcrc->left;
lcrc->left=lc;
root->left=lcrc;
lc=root->left;
}
root->left=lc->right;
lc->right=root;
*p2p=lc;
}
}
}
int searchInAVLTree(int num)
{
struct Node *t;
if(start==NULL) return 0;
t=start;
while(t!=NULL)
{
if(num==t->num) return 1;
if(num<t->num) t=t->left;
else t=t->right;
}
if(t==NULL) return 0;
return 1;
}
int removeFromAVLTree(int num)
{
struct Node *t,*j;
struct Node *e,*f;
if(start==NULL) return 0;
t=start;
while(t!=NULL)
{
if(num==t->num) break;
j=t;
push(j);
if(num<t->num) t=t->left;
else t=t->right;
}
if(t==NULL) return 0;
if(t->right==NULL && t->left==NULL) //Leaf Node
{
if(t==start)
{
start=NULL;
}
else
{
if(j->left==t)
{
j->left=NULL;
}
else
{
j->right=NULL;
}
}
free(t);
balanceIt();
return 1;
}
if(t->right!=NULL)
{
for(e=t->right; e->left!=NULL; e=e->left)
{
f=e;
addToQueue(f);
}
push(e);
while(!isQueueEmpty())
{
push(removeFromQueue());
}
if(e==t->right)
{
e->left=t->left;
}
else
{
f->left=e->right;
e->left=t->left;
e->right=t->right;
}
if(t==start) start=e;
else if(j->left==t) j->left=e;
else j->right=e;
}
else
{
for(e=t->left; e->right!=NULL; e=e->right)
{
f=e;
addToQueue(f);
}
push(e);
while(!isQueueEmpty())
{
push(removeFromQueue());
}
if(e==t->left)
{
e->right=t->right;
}
else
{
f->right=e->left;
e->left=t->left;
e->right=t->right;
}
if(t==start) start=e;
else if(j->left==t) j->left=e;
else j->right=e;
}
free(t);
balanceIt();
return 1;
}
void traverseInOrderWithoutRecursion()
{
struct Node *t,*j;
if(start==NULL)
{
printf("No Element in AVL Tree\n");
return;
}
for(j=start; j!=NULL; j=j->left) push(j);
while(!isStackEmpty())
{
t=pop();
printf("%d\n",t->num);
if(t->right!=NULL)
{
for(j=t->right; j!=NULL; j=j->left) push(j);
}
}
}
void traversePreOrderWithoutRecursion()
{
struct Node *t;
if(start==NULL)
{
printf("No Elements in AVL Tree\n");
return;
}
push(start);
while(!isStackEmpty())
{
t=pop();
printf("%d\n",t->num);
if(t->right!=NULL) push(t->right);
if(t->left!=NULL) push(t->left);
}
}
void traversePostOrderWithoutRecursion()
{
struct Node *t;
if(start==NULL)
{
printf("No Elements in AVL Tree\n");
return;
}
t=start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL) push(t->right);
push(t);
t=t->left;
}
t=pop();
if(!isStackEmpty() && t->right!=NULL && t->right==elementAtTop())
{
pop();
push(t);
t=t->right;
}
else
{
printf("%d\n",t->num);
t=NULL;
}
if(isStackEmpty()) break;
}
}
void traverseLevelOrderWithoutRecursion()
{
struct Node *t;
int levelNumber;
int insertionCount;
int j,x;
if(start==NULL)
{
printf("No Elements in AVL Tree\n");
return;
}
levelNumber=0;
addToQueue(start);
insertionCount=1;
while(!isQueueEmpty())
{
levelNumber++;
printf("-----------------\n");
printf("Level Number %d\n",levelNumber);
printf("-----------------\n");
j=1;
x=0;
while(j<=insertionCount)
{
t=removeFromQueue();
printf("%d\n",t->num);
if(t->left!=NULL)
{
addToQueue(t->left);
x++;
}
if(t->right!=NULL)
{
addToQueue(t->right);
x++;
}
j++;
}
insertionCount=x;
}
}
int getHeightOfTree()
{
struct Node *t;
int insertionCount;
int j,x,h;
if(start==NULL) return 0;
addToQueue(start);
insertionCount=1;
h=0;
while(!isQueueEmpty())
{
j=1;
x=0;
h++;
while(j<=insertionCount)
{
t=removeFromQueue();
if(t->left!=NULL)
{
addToQueue(t->left);
x++;
}
if(t->right!=NULL)
{
addToQueue(t->right);
x++;
}
j++;
}
insertionCount=x;
}
return h;
}
void traverseInOrderUsingRecursion(struct Node *t)
{
if(t==NULL) return;
traverseInOrderUsingRecursion(t->left);
printf("%d\n",t->num);
traverseInOrderUsingRecursion(t->right);
}
void traversePreOrderUsingRecursion(struct Node *t)
{
if(t==NULL) return;
printf("%d\n",t->num);
traversePreOrderUsingRecursion(t->left);
traversePreOrderUsingRecursion(t->right);
}
void traversePostOrderUsingRecursion(struct Node *t)
{
if(t==NULL) return;
traversePostOrderUsingRecursion(t->left);
traversePostOrderUsingRecursion(t->right);
printf("%d\n",t->num);
}
int getHeightOfTreeUsingRecursion(struct Node *t)
{
int lch,rch;
if(t==NULL) return 0;
lch=getHeightOfTreeUsingRecursion(t->left);
rch=getHeightOfTreeUsingRecursion(t->right);
if(lch>rch) return lch+1;
else return rch+1;
}
int main()
{
int num,ch;
start=NULL;
stackStart=NULL;
queueStart=NULL;
queueEnd=NULL;
while(1)
{
printf("1. Insert in AVL Tree\n");
printf("2. Search in AVL Tree\n");
printf("3. Remove From AVL Tree\n");
printf("4. Traverse InOrder (Without Recursion)\n");
printf("5. Traverse InOrder (Using Recursion)\n");
printf("6. Traverse PreOrder (Without Recursion)\n");
printf("7. Traverse PreOrder (Usinng Recursion)\n");
printf("8. Traverse PostOrder (Without Recursion)\n");
printf("9. Traverse PostOrder (Using Recursion)\n");
printf("10. Traverse Level Order (Without Recursion)\n");
printf("11. Traverse Level Order (Using Recursion)\n");
printf("12. Get Height of AVL Tree (Without Recursion)\n");
printf("13. Get Height of AVL Tree (Using Recursion)\n");
printf("14. Exit\n");
printf("Enter Your Choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch<=0 || ch>=15)
{
printf("Wrong Option Choosen\n");
continue;
}
if(ch==1)
{
printf("Enter a Number to Insert in AVL Tree : ");
scanf("%d",&num);
fflush(stdin);
if(insertInAVLTree(num)) printf("%d Inserted in AVL Tree\n",num);
else printf("%d Already exist in AVL Tree, Hence Not Added\n",num);
}
if(ch==2)
{
printf("Enter a Number to Search in AVL Tree : ");
scanf("%d",&num);
fflush(stdin);
if(searchInAVLTree(num)) printf("%d Found in AVL Tree\n",num);
else printf("%d Not Found in AVL Tree\n",num);
}
if(ch==3)
{
printf("Enter a Number to Remove From AVL Tree : ");
scanf("%d",&num);
fflush(stdin);
if(removeFromAVLTree(num)) printf("%d Removed From AVL Tree\n",num);
else printf("%d Not Removed From AVL Tree\n",num);
}
if(ch==4)
{
traverseInOrderWithoutRecursion();
}
if(ch==5)
{
traverseInOrderUsingRecursion(start);
}
if(ch==6)
{
traversePreOrderWithoutRecursion();
}
if(ch==7)
{
traversePreOrderUsingRecursion(start);
}
if(ch==8)
{
traversePostOrderWithoutRecursion();
}
if(ch==9)
{
traversePostOrderUsingRecursion(start);
}
if(ch==10)
{
traverseLevelOrderWithoutRecursion();
}
if(ch==11)
{}
if(ch==12)
{
printf("Height of AVL Tree is %d\n",getHeightOfTree());
}
if(ch==13)
{
printf("Height Of AVL Tree is %d\n",getHeightOfTreeUsingRecursion(start));
}
if(ch==14) break;
}
return 0;
}