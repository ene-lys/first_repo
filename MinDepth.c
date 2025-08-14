#include<stdio.h>
#include<stdlib.h>
#define MAX 100001

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}Node;

Node *makeNode(int v){
    if(v == -1) return NULL;

    Node *p = (Node *)malloc(sizeof(Node));
    p->val = v;
    p->left = NULL;
    p->right = NULL;

    return p;
}

int n;
int pre[MAX];
Node *root = NULL;

Node *buildTree(int *index){
    Node *r = makeNode(pre[(*index)++]);
    if(r == NULL) return NULL;

    if(*index == n) return r;

    r->left = buildTree(index);

    r->right = buildTree(index);

    return r;

}

int minDepth(Node *r){
    //Base case
    if(r == NULL) {
        return 0;
    }

    //Case 1 child is NULL
    int leftD = minDepth(r->left);
    int rightD = minDepth(r->right);

    if(r->left == NULL) return 1 + rightD;
    if(r->right == NULL) return 1 + leftD;

    return 1 + (leftD < rightD ? leftD : rightD);

}

void postOrder(Node *r){
    if(r == NULL) return;

    postOrder(r->left);

    postOrder(r->right);

    printf("%d ", r->val);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }

    int start = 0;
    root = buildTree(&start);
    printf("%d\n", minDepth(root));
    //postOrder(root);
}

//3 9 -1 -1 20 15 -1 -1 7 -1 -1
