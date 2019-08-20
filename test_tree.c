#include <stdio.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node * create_tree(int *p,int *pos,int len){
    struct node * head = NULL;
    //printf("p[%d]:%d\r\n",*pos,p[*pos]);
    if(len == 0)return NULL;
    if(p[*pos] == 0)return NULL;
    head = (struct node *)malloc(sizeof(struct node));
    if(!head)return head;
    head->val = p[*pos];
    (*pos)++;
    head->left = create_tree(p,pos,len);
    (*pos)++;
    head->right = create_tree(p,pos,len);
    return head;
}

void display_tree(struct node * tree){
    if(NULL == tree){
        printf("NULL,");
        return;
    }
    printf("%d,",tree->val);
    display_tree(tree->left);
    display_tree(tree->right);
}

void display_tree_1(struct node * tree){
    struct node * tree_parent = tree;
    int child = -1;//0:left 1:right
    while(1){
        if(tree) printf("%d,",tree->val);
        else printf("NULL,");
        if(child != 0 && tree->left){
            tree_parent = tree;
            tree = tree->left;
            child = 0;
        }
        else if(child != 1 && tree->right){
            tree_parent = tree;
            tree = tree->right;
            child = 1;
        }
        else tree = tree_parent;
    }
}

int isSameTree(struct node* p, struct node* q){
      
  
}


int main(){
    int pa[] = {1,2,0,0,3,0,0};
    int pb[] = {1,2,3,0,0};
    int lena = sizeof(pa)/sizeof(pa[0]);
    int lenb = sizeof(pb)/sizeof(pb[0]);
    struct node * ha = NULL;
    struct node * hb = NULL;
    int pos = 0;
    int result = 0;
    ha = create_tree(pa,&pos,lena);
    //display_tree(ha);
    display_tree_1(ha);
    printf("\r\n");
    pos = 0;
    hb = create_tree(pb,&pos,lenb);
    //display_tree(hb);
    //display_tree_1(hb);
    printf("\r\n");

    
    //result = isSameTree(ha,hb);
    printf("%d\r\n",result);
}
