#include"linkedList.h"
struct node *head=NULL;
void reverseList(struct node *this,struct node *prev){
    if(this->next==NULL){
        head=this;
        return;
    }
    reverseList(this->next,this);
    //reverse the part behind this
    this->next->next=this;
    this->next=prev;
    //reverse this
}
void insertList(int value){
	//insert to end 
    struct node* now=findEnd(head);
    if(NULL==now){
    	//empty list
        head=(struct node*)malloc(sizeof(struct node));
        head->value=value;
        head->next=NULL;
        return;
    }
    now->next=(struct node*)malloc(sizeof(struct node));
    now->next->value=value;
    now->next->next=NULL;
}
struct node* findEnd(){
    struct node * now=head;
    if(NULL==now)return NULL;
    while(now->next)now=now->next;
    return now;
}
void showList(){
    struct node* now =head;
    while(now){
        printf("%d ",now->value);
        now=now->next;
    }
    printf("\n");
}
int findNext(int target,int pos){
    if(head==NULL)return -1;
    static int ptr=0;
    //save old moves
    if(pos>=0)ptr=pos;
    struct node* now=head;
    int i;
    for(i=1;i<=ptr;++i)now=now->next;
   	//repeat old moves and skip the old values
    while(now){
        ++ptr;
        if(now->value==target){
            return ptr;
        }
        now=now->next;
    }
    return -1;
}
void makeList(){ 
    int num;
    puts("Please input the number of elements");
    scanf("%d",&num);
    puts("Pleae input elements:");
    int i,tmp;
    for(i=0;i<num;++i){
        scanf("%d",&tmp);
        insertList(tmp);
    }
}
