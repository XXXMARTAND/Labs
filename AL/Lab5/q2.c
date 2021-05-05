#include <stdio.h> 
#include <stdlib.h> 
  
struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 
  
struct node* newNode(int data); 
  
int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
}

int height(struct node* node) 
{ 
   if(node == NULL) 
       return 0; 
  
   return 1 + max(height(node->left), height(node->right)); 
}  
  
int diameter(struct node * tree) 
{ 
   if (tree == NULL) 
     return 0; 
  
  int lh = height(tree->left); 
  int rh = height(tree->right); 
  
  int ld = diameter(tree->left); 
  int rd = diameter(tree->right); 
  
  return max(lh + rh + 1, max(ld, rd)); 
}  
  
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
}      
  
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
  
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    return node;
} 



int main() 
{ 
  int x;
  printf("Enter nodes: ");

  struct node *root = newNode(1); 
  while(x!=-1)
  {
      scanf("%d", &x);
      insert(root, x);
  }
  
  printf("Diameter: %d\n", diameter(root)); 
  
  getchar();
  return 0; 
}