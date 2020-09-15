//1905622 - NITISH KUMAR SONTHALIA
//Linked list
#include<stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node *next;
};



void creat_list(struct node ** ,int n);
void display_list(struct node ** );
void insert_at_position_n(struct node ** ,int n,int p);
void deleteNode(struct node **, int p);
void add_first_node(struct node ** ,int n);
void del_first_node(struct node ** );
void ins_node_after_data(struct node ** ,int n,int data1);
void ins_node_before_data(struct node ** ,int n,int data1);
void del_node_with_data(struct node ** ,int n);
void del_node_after_data(struct node ** ,int n);
void del_last_node(struct node ** );
void del_node_before_data(struct node ** ,int n);
void sort(struct node ** );
void merg_2_sorted_list(struct node **,struct node **,struct node **);
void rev(struct node **st);


int main(){

    struct node *start = NULL;

    struct node *start1 = NULL;

    struct node *start2 = NULL;

    int t;

    int f=1;

    while(f){
    printf("\n MENU ");
    printf("\n 1. Enter An Element ");
    printf("\n 2. Display The List ");
    printf("\n 3. Insert At Position ");
    printf("\n 4. Deletion of Elements ");
    printf("\n 5. Add First Node ");
    printf("\n 6. Delete First Node ");
    printf("\n 7. Insert Node After Data ");
    printf("\n 8. Insert Node Before Data ");
    printf("\n 9. Deletion of Node With Data ");
    printf("\n 10. Deletion of Node After Data ");
    printf("\n 11. Deletion of Last Node ");
    printf("\n 12. Deletion of Node Before Data ");
    printf("\n 13. Sort ");
    printf("\n 14. Merge Two Sorted List ");
    printf("\n 15. Reverse the list ");
    printf("\n 16. EXIT ");
    scanf("%d",&t);
    int e,p;

    switch (t)
    {

    case 1:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        creat_list(&start,e);
        break;

    case 2:
        display_list(&start);
        break;

    case 3:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        printf("\n Enter The Element position: ");
        scanf("%d",&p);
        insert_at_position_n(&start,e,p);
        break;

    case 4:
        printf("\n Enter The Element position: ");
        scanf("%d",&p);
        deleteNode(&start,p);
        break;

    case 5:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_first_node(&start,e);
        break;

    case 6:
        del_first_node(&start);
        break;

    case 7:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        ins_node_after_data(&start,p,e);
        break;

    case 8:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        ins_node_before_data(&start,p,e);
        break;

    case 9:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_with_data(&start,p);
        break;

    case 10:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_after_data(&start,p);
        break;

    case 11:
        del_last_node(&start);
        break;

    case 12:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_before_data(&start,p);
        break;

    case 13:
        sort(&start);
        break;

    case 14:
        merg_2_sorted_list(&start,&start1,&start2);
        break;

    case 15:
        rev(&start);
        break;

    case 16:
        f=0;
        break;

    default:
        break;
    }
    }
}



void creat_list(struct node **st ,int n){

    struct node *temp;

    struct node *new1 = (struct node *)malloc(sizeof(struct node));

    new1->data=n;

    new1->next=NULL;

    if(*st==NULL){
        *st=new1;
    }
    else{
        temp=*st;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = new1;
    }
}



void display_list(struct node **st){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*st;
        printf("Elements in LIST are:");

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}



void insert_at_position_n(struct node **st ,int n,int p){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data=n;	

    int i;

    struct node *temp=*st;

    printf("\n Enter 1 for entering before the given position and 2 for entering after given position");

    int e;

    scanf("%d",&e);

    if(e==1){
    if(p==1)
    {
        ptr->next=*st;
        *st=ptr;
    }
    else{
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    }
    }
    if(e==2){
        p=p+1;
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    }
}



void deleteNode(struct node **st, int p) 
{

   if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    printf("\n Enter 1 for deleting the given position and 2 for deletion before given position and 3 for deletion after given position");

    int e;

    scanf("%d",&e);

   struct node* temp = *st; 

    if(e=1){
    if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }
    }
    else if(e=2){
        p=p-1;
        if(p=0){
            return;
        }
     if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }   
    }
    else if(e=3){
        p=p+1;
     if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }   
    }
}



void add_first_node(struct node **st ,int n){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = n;
    ptr->next=*st;
    *st=ptr;
}



void del_first_node(struct node **st ){

    struct node *ptr=*st;

    *st=ptr->next;
    free(ptr);
}



void ins_node_after_data(struct node **st ,int n,int data1){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    struct node *t=*st;

    while(t->data!=n){
        t=t->next;
    }

    ptr->data = data1;

    ptr->next=t->next;

    t->next=ptr;
}



void ins_node_before_data(struct node **st ,int n,int data1){

    struct node *t1,*t2;

    t1=t2=*st;

    while (t2->data!=n)
    {
        t1=t2;
        t2=t2->next;
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = data1;

    t1->next=ptr;

    ptr->next=t2;
}



void del_node_with_data(struct node **st ,int n){

    struct node *t1,*t2;

    t1=t2=*st;

    while (t2->data!=n)
    {
        t1=t2;
        t2=t2->next;
    }

    t1->next=t2->next;
    free(t2);
}



void del_node_after_data(struct node **st ,int n){

    struct node *t=*st;

    while(t->data!=n){
        t=t->next;
    }

    struct node *t1=t->next;

    t->next=t1->next;

    free(t1);
}



void del_last_node(struct node **st ){

    struct node *t1,*t2;

    t1=t2=*st;

    while (t2->next!=NULL)
    {
        t1=t2;
        t2=t2->next;
    }

    t1->next=NULL;

    free(t2);
}



void del_node_before_data(struct node **st ,int n){

    struct node *t1,*t2;

    t1=t2=*st;

    while (t2->next->data!=n)
    {
        t1=t2;
        t2=t2->next;
    }

    t1->next=t2->next;
    free(t2);
}

void sort(struct node **st ){

    struct node *t1=*st;

    struct node *t2;

    int k;

    while (t1!=NULL)
    {
        for(t2=t1->next;t2!=NULL;t2=t2->next){
            if(t1->data>t2->data){
                k=t1->data;
                t1->data = t2->data;
                t2->data=k;
            }
        }
        t1=t1->next;
    }
    
}

void merg_2_sorted_list(struct node **st1,struct node **st2,struct node **st3){

    struct node *t1=*st1;

    struct node *t2=*st2;

    while(t1!=NULL&&t2!=NULL){
        if(t1->data>t2->data){
            creat_list(st3,t2->data);
            t2=t2->next;
        }
        else if(t1->data<t2->data){
            creat_list(st3,t1->data);
            t1=t1->next;
        }
        else{
            creat_list(st3,t1->data);
            t1=t1->next;
            t2=t2->next;
        }
    }
    while(t1!=NULL){
        creat_list(st3,t1->data);
        t1=t1->next;
    }
    while(t2!=NULL){
        creat_list(st3,t2->data);
        t2=t2->next;
    }
}


void rev(struct node **st){
    struct node *t2,*t1,*p;
    p=NULL;
    t1=*st;
    while(t1!=NULL){
        t2=t1->next;
        t1->next=p;
        p=t1;
        t1=t2;
    }
    *st=p;
    display_list(st);
}