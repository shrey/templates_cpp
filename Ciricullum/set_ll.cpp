#include<iostream>
using namespace std;

struct node{
    int val;
    struct node *next;
};


struct node* SetUnion(struct node *s1, struct node *s2){
    struct node * newnode = NULL;
    struct node* t1 = s1;
    struct node *t2 = s2;
    struct node *t3 = newnode;
    while(t1!=NULL && t2!=NULL){
        if(t1->val<t2->val){
            struct node *q = (struct node*)malloc(sizeof(node));
            q->val = t1->val;
            t3 = q;
            t3->next = NULL;
            t3 = t3->next;
            t1 = t1->next;
        }
        else if(t1->val>t2->val){
            struct node *q = (struct node*)malloc(sizeof(node));
            q->val = t2->val;
            t3 = q;
            t3->next = NULL;
            t3 = t3->next;
            t2 = t2->next;
        }
        else{
            struct node *q = (struct node*)malloc(sizeof(node));
            q->val = t2->val;
            t3 = q;
            t3->next = NULL;
            t3 = t3->next;
            t2 = t2->next;
            t1 = t1->next;
        }
    }
    while(t1!=NULL){
        struct node *q = (struct node*)malloc(sizeof(struct node));
        q->val = t1->val;
        t3 = q;
        t3->next = NULL;
        t3 = t3->next;
        t1 = t1->next;
    }
    while(t2!=NULL){
        struct node *q = (struct node*)malloc(sizeof(struct node));
        q->val = t2->val;
        t3 = q;
        t3->next = NULL;
        t3 = t3->next;
        t2 = t2->next;
    }
    return newnode;
}


struct node* SetDifference(struct node *s1, struct node *s2){
    struct node *newnode = NULL;
    struct node *t1 = s1;
    struct node *t2 = s2;
    struct node *t3 = newnode;
    while(t1!=NULL && t2!=NULL){
        if(t1->val<t2->val){
            struct node *q = (struct node*)malloc(sizeof(node));
            q->val = t1->val;
            t3 = q;
            t3->next = NULL;
            t3 = t3->next;
            t1 = t1->next;
        }
        else if(t1->val>t2->val){
            struct node *q = (struct node*)malloc(sizeof(node));
            q->val = t2->val;
            t3 = q;
            t3->next = NULL;
            t3 = t3->next;
            t2 = t2->next;
        }
        else{
            t2 = t2->next;
            t1 = t1->next;
        }
    }
    while(t1!=NULL){
        struct node *q = (struct node*)malloc(sizeof(node));
        q->val = t1->val;
        t3 = q;
        t3->next = NULL;
        t3 = t3->next;
        t1 = t1->next;
    }
    while(t2!=NULL){
        struct node *q = (struct node*)malloc(sizeof(node));
        q->val = t2->val;
        t3 = q;
        t3->next = NULL;
        t3 = t3->next;
        t2 = t2->next;
    }
    return newnode;
}

struct node* SetIntersection(struct node *s1, struct node *s2){
    struct node *newnode = NULL;
    struct node *t1 = s1;
    struct node *t2 = s2;
    struct node *t3 = newnode;
    while(t1!=NULL && t2!=NULL){
        if(t1->val<t2->val){
            t1 = t1->next;
        }
        else if(t1->val>t2->val){
            t2 = t2->next;
        }
        else{
            struct node *q = (struct node*)malloc(sizeof(node));
            q->val = t2->val;
            t3 = q;
            t3->next = NULL;
            t3 = t3->next;
            t2 = t2->next;
            t1 = t1->next;
        }
    }
    return newnode;
}


int member(struct node *s, int x){
    struct node *t = s;
    while(t!=NULL){
        if(t->val == x) return 1;
        if(t->val>x) return 0;
        t = t->next;
    }
    return 0;
}