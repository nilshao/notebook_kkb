#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *circle_create(int n);
void count_off(Node *head, int n, int k, int m);

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    Node *head = circle_create(n);
    count_off(head, n, k, m);
    return 0;
}

Node *circle_create(int n) {
    Node *temp, *new_node, *head;
    int i;

    // 创建第一个链表节点并加数据
    temp = (Node *) malloc(sizeof(Node));
    head = temp;
    head->data = 1;

    // 创建第 2 到第 n 个链表节点并加数据
    for(i = 2; i <= n; i++) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }

    // 最后一个节点指向头部构成循环链表
    temp->next = head;

    return head;
}

void count_off(Node *head, int n, int k, int m) {
    int start = 0;
    int current = 1;
    while(1){
        if(head->next == head){
            printf("%d\n",head->data);
            return ;
        }
        while(start==0){
            if(head->data!=k){
                head = head->next;
            }else{
                start = 1;
            }
            
        }
    //    printf("%d",head->data);// 起始地址移到了k
        if(m==1){
            Node* tmp = head;
            printf("%d ", head->data);
            head = head->next;
            while(head->data != tmp ->data ){
                printf("%d", head->data);
                head = head->next;
                if(head->data!=k){
                    printf(" ");
                }else{printf("\n");}
            }
            return;
        }
        else{
            if(current == m-1){
                printf("%d ", head->next->data);
                head->next = head->next->next;
                current = 0;
            }else{
                head = head->next;
                current++;
            }
        }
    }
    

    return;
}