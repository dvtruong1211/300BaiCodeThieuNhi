#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

struct list{
    Node *pHead;
    Node *pTail;
};
typedef struct list List;

void Khoitao(List *l){
    l->pHead = NULL;
    l->pTail = NULL;
}
Node *KhoitaoNode(int x){
    Node *a = (Node *)malloc(sizeof(Node));
    if(a == NULL){
        printf("over load memory\n");
    }
    a->data = x;
    a->next = NULL;
    return a;
}
void Themvaodau(List *l,Node *x){
    if(l->pHead == NULL){
        l->pHead = l->pTail = x;
    }else{
        x->next = l->pHead;
        l->pHead = x;
    }
}
void ThemVaoCuoi(List *l, Node *x){
    if(l->pHead == NULL){
        l->pHead = l->pTail = x;
    }else{
        l->pTail->next = x;
        l->pTail = x;
    }
}
void display(List l,int n){
    while(l.pHead != NULL){
        printf("%d ",l.pHead->data);
        l.pHead = l.pHead->next;
    }
    printf("\n");
}

List *Merge(List a,List b, int n, int m){
    List *tmp = (List *)malloc(sizeof(Node)*(n+m));
    Khoitao(tmp);
    while(a.pHead != NULL  && b.pHead != NULL){
        if(a.pHead->data <= b.pHead->data){
            ThemVaoCuoi(tmp,a.pHead);
            a.pHead = a.pHead->next;
        }else{
            ThemVaoCuoi(tmp,b.pHead);
            b.pHead = b.pHead->next;
        }
    }
    while(a.pHead != NULL){
        ThemVaoCuoi(tmp,a.pHead);
        a.pHead = a.pHead->next;
    }
    while(b.pHead != NULL){
        ThemVaoCuoi(tmp,b.pHead);
        b.pHead = b.pHead->next;
    }

    return tmp;
}

int main(){
    List a;
    Khoitao(&a);
    int n;
    printf("Nhap so luong phan tu cua list a: \n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        Node *nodeA;
        int dt;
        printf("Nhap gia tri cua Node %d: \n",i);
        scanf("%d",&dt);
        nodeA = KhoitaoNode(dt);
        ThemVaoCuoi(&a,nodeA);
    }

    List b;
    Khoitao(&b);
    int m;
    printf("Nhap so luong phan tu cua list b: \n");
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        Node *nodeA;
        int dt;
        printf("Nhap gia tri cua Node %d: \n",i);
        scanf("%d",&dt);
        nodeA = KhoitaoNode(dt);
        ThemVaoCuoi(&b,nodeA);
    }

    List *kq = Merge(a,b,n,m);
    display(*kq,n+m);

    return 0;
}