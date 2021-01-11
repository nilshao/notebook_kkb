/*
#include <iostream>
#include<iostream>

using namespace std;

template <typename Type> class Node {
public:
    Type data;
    Node<Type> *next;
    Node(const Type &_data) {
        data = _data;
        next = NULL;
    }
};
template <typename Type> class LinkedList {
private:
    Node<Type> *head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return false;
            }
            head = node;
            return true;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return true;
        }
        Node<Type> *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
            return true;
        }
        return false;
    }
    void output() {
        if (head == NULL) {
            return;
        }
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    bool delete_node(int index) {
        if(head == NULL){
            return 1;
        }
        Node<Type> *current_node = head;
        int count = 0;
        if(index==0){
            head = head->next;
            free(current_node);
            printf("success\n");
            return 1;
        }
        while(current_node->next!=NULL && count < index-1){
            current_node = current_node->next;
            count++;
        }
        if(count==index-1&&current_node->next!=NULL){
            Node<Type> *delete_node=current_node->next;
            current_node->next=delete_node->next;
            free(delete_node);
            printf("success\n");
            return 1;
        }else{
            printf("failed\n");
            return 0;
        }
        return 1;
    }
    void reverse() {
        if(head==NULL){
            return;
        }
        Node<Type> *next_node, *current_node;
        current_node = head->next;
        head->next = NULL;
        while(current_node!=NULL){
            next_node = current_node -> next;
            current_node -> next = head;
            head = current_node;
            current_node = next_node;
        }
    }
};

int main() {
    LinkedList<int> linkedlist;
    
    int t;
    scanf("%d",&t);    
    for(int i=0;i<t;++i){
        int cmd;
        scanf("%d",&cmd);
        switch(cmd){
            case 1:{
                //insert
                int loc,val;
                
                scanf("%d%d",&loc,&val);
                Node<int> *node;
                node->data = val;
                node->next = NULL;
                
                if(linkedlist.insert(node,loc)){
                    printf("success\n");
                }else{
                    printf("failed\n");
                }
                break;
            }
            case 2:{ 
                //print
                linkedlist.output();
                break;
            }
            case 3:{
                //delete
                int index;
                scanf("%d",&index);
                if(linkedlist.delete_node(index)==0){
                    printf("failed\n");
                }else{
                    printf("success\n");
                }
                break;
            }
            case 4:{
                //reverse;
                linkedlist.reverse();
                break;
            }
        }
    }
    linkedlist.output();
    return 0;
}
*/
#include <iostream>
#include<iostream>

using namespace std;

template <typename Type> class Node {
public:
    Type data;
    Node<Type> *next;
    Node(const Type &_data) {
        data = _data;
        next = NULL;
    }
};
template <typename Type> class LinkedList {
private:
    Node<Type> *head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return false;
            }
            head = node;
            return true;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return true;
        }
        Node<Type> *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
            return true;
        }
        return false;
    }
    void output() {
        if (head == NULL) {
            return;
        }
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    /*
    int delete_node() {

    }
    void reverse() {

    }
    */
};
int main() {
    LinkedList<int> linkedlist;

    return 0;
}