#ifndef SLL_H
#define SLL_H

typedef struct node{
    int data;
    struct node* next;
}node;

node* insert_at_beg(node* head, int data);
node* insert_at_end(node* head, int data);
node* insert_at_pos(node* head, int data, int pos);

node* delete_from_beg(node* head);
node* delete_from_end(node* head);
node* delete_at_pos(node* head, int pos);

void print_list(node* head);

void free_list(node* head);

#endif
