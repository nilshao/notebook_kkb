#include <iostream>
#include<iostream>

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
            std::cout << current_node->data << " ";
            current_node = current_node->next;
        }
        std::cout << std::endl;
    }
    
    int delete_node(int index) {
        if(head == NULL){
            std::cout << "success"<< std::endl;
        }
        Node<Type> *current_node = head;
        int count = 0;
        if(index==0){
            head = head->next;
            delete current_node;
        }
        while(current_node->next!=NULL && count < index-1){
            current_node = current_node->next;
            count++;
        }
        if(count==index-1&&current_node->next!=NULL){
            Node<Type> *delete_node=current_node->next;
            current_node->next=delete_node->next;
            delete delete_node;
            return 1;
        }else{
            //没删成功
        }
        return 0;

    }
    
    void reverse() {
        if(head==NULL){
            return;
        }
        Node<int> *next_node, *current_node;
        current_node = head->next;
        head->next = NULL;
        while(current_node!=NULL){
            next_node = current_node -> next;
            current_node -> next = head;
            head = current_node;
            current_node = next_node;
        }
        return;
    }
    
};
int main() {
    LinkedList<int> linkedlist;
    int t;
    std::cin >> t;
    for(int i=0;i<t;++i){
        int cmd;
        std::cin >> cmd;
        if(cmd==1){                             //insert
            int data,loc;
            std::cin >> loc >> data;
            Node<int> *n1= new Node<int>(data);
            if(linkedlist.insert(n1,loc)){
                std::cout << "success"<< std::endl;
            }else{
                std::cout << "failed" << std::endl;
            }
            linkedlist.output();
        }else if(cmd==2){                       //output
            linkedlist.output();
        }else if(cmd==3){                       //delete
            int loc;
            std::cin >> loc;
            if(linkedlist.delete_node(loc)){
                std::cout << "success"<< std::endl;
            }else{
                std::cout << "failed" << std::endl;
            }
        }else if(cmd==4){                       //reverse
            linkedlist.reverse();
        }
    }
    return 0;
}