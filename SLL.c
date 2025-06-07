#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

node* insert_at_beg(node* head, int data){
    node *newnode;
    newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    return head;
}

node* insert_at_end(node* head, int data){
    node *newnode, *temp;
    newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

node* insert_at_pos(node* head, int data, int pos){
    node *newnode, *temp, *current;
    int idx = pos-1;
    newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    temp=head;
    for(int i=0; i<idx-1; i++){
        temp=temp->next;
    }
    current = temp->next;
    temp->next = newnode;
    newnode->next = current;
    return head;
}

node* delete_from_beg(node* head){
    node *temp, *current;
    temp = head;
    current = temp->next;
    free(temp);
    head = current;
    return head;
}

node* delete_from_end(node* head){
    node *temp, *current;
    temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    current = temp->next;
    free(current);
    temp->next = NULL;
    return head;
}

node* delete_at_pos(node* head, int pos){
    node *temp, *current, *next;
    int idx = pos-1;
    current = head;
    for(int i=0; i<idx-1; i++){
        current = current->next;
    }
    temp = current->next;
    next = temp->next;
    free(temp);
    current->next = next;
    return head;
}

void print_list(node* head){
    node* temp;
    temp = head;
    while(temp!=NULL){
        printf("%d \t", temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}

void free_list(node* head){
    node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
