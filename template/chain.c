#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if(head == NULL){
        if(index!=0){
            return head;
        }
        head = node;
        return head;
    }
    if(index==0){
        node->next = head;
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while(current_node->next!=NULL && count<index-1){
        
        current_node = current_node->next;
        count++;
        
    }
    if(count == index-1){
    	node->next = current_node->next;
        current_node->next = node;
    }else{
        //没插上
    }
    return head;
}
//delete_node
LinkedList delete_node(LinkedList head, int index){
    if(head == NULL){
        return head;
    }
    Node *current_node = head;
    int count = 0;
    if(index==0){
    	head = head->next;
        free(current_node);
        return head;
    }
    while(current_node->next!=NULL && count < index-1){
        current_node = current_node->next;
        count++;
    }
    if(count==index-1&&current_node->next!=NULL){
    	Node *delete_node=current_node->next;
        current_node->next=delete_node->next;
        free(delete_node);
    }
    return head;
}
void output(LinkedList head) {
    if(head == NULL){
        return ;
    }
    Node *current_node = head;
    while(current_node!=NULL){
        if(current_node!=head){
            printf("->",current_node->data);
        }
        printf("%d",current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}
//reverse
LinkedList reverse(LinkedList head){
    if(head==NULL){
        return head;
    }
    Node *next_node, *current_node;
	current_node = head->next;
    head->next = NULL;
    while(current_node!=NULL){
        next_node = current_node -> next;
        current_node -> next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

int main() {
    LinkedList linkedlist = NULL;
    int cmd;
    scanf("%d",&cmd);
    int len =0;
    int loc,val;
    for(int i=0;i<cmd;++i){
        scanf("%d%d",&loc,&val);
        if(loc>len){
            printf("failed\n");
        }else{
            Node *node = (Node *)malloc(sizeof(Node));
            node->data = val;
            node->next = NULL;
            linkedlist = insert(linkedlist,node,loc);
            len++;
            printf("success\n");
        }
        
    }
    output(linkedlist);
    clear(linkedlist);
    return 0;
}



