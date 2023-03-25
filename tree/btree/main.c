#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

struct node_st
{
    struct score_st data;
    struct node_st *l, *r;

};

static int insert(struct node_st **root, struct score_st *data)
{

    struct node_st *node;
    if(*root == NULL)
    {
        node = malloc(sizeof(*node));
        if(node == NULL)
        {
            return -1;
        }

        node->data = *data;
        node->l = NULL;
        node->r = NULL;

        *root = node;
        return 0;
    }
    if(data->id <= (*root)->data.id)
    {
        return insert(&(*root)->l, data);  
    }
    else
    {
        return insert(&(*root)->r, data);
    }

}

static struct score_st *find(struct node_st *root, int id)
{
    if(root == NULL)
        return NULL;
    if(id == root->data.id)
        return &root->data;
    if(id < root->data.id)
        return find(root->l, id);
    else
        return find(root->r, id);

}

static void print_s(struct score_st *datap)
{
    printf("stu%d name %s math %d chinese %d\n", datap->id, datap->name, datap->math, datap->chinese);
}

void draw_(struct node_st *root, int level)
{
    int i = 0;
    if(root == NULL)
    {
        return;
    }
    draw_(root->r, level+1);

    for(i = 0; i < level; i++)
    {
        printf("    ");

    }
    printf("id %d\n", root->data.id);
    draw_(root->l, level + 1);

}

static void draw(struct node_st *root)
{
    draw_(root, 0);
}


int main()
{
    int arr[] = {1,2,3,7,6,5,9,8,4};
    int i =  0;
    struct node_st *tree = NULL;
    struct score_st tmp, *datap;

    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        tmp.id = arr[i];
        snprintf(tmp.name, NAMESIZE, "stu%d", arr[i]);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;

        insert(&tree, &tmp);
    }

#if 0
    int tmp_id = 2;
    datap = find(tree, tmp_id);
    if(datap == NULL)
        printf("find failed!!!");
    else    
        print_s(datap);
    
    exit(0);
#endif

draw(tree);

}