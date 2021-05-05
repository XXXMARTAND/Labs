#include<stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node *left,*right;
} ;
typedef struct node *NODE;

//NODE head = NULL;

NODE CreateTree(int val){
	NODE nd;
	
		nd=(NODE)malloc(sizeof(struct node));
		nd->left=nd->right=NULL;
		nd->value = val;
		
	
	return nd;
}

NODE InsertIntoTree(NODE root,int val){
	if (!root)			
	{	
		NODE nd = (NODE)malloc(sizeof(struct node));
		nd->value = val;
		nd->left=nd->right=NULL;
		root = nd;
	}
	
		if (val>root->value){
			root->right = InsertIntoTree(root->right,val);
		}
		else if (val<root->value){
			root->left=InsertIntoTree(root->left,val);
		}


	return root;

}

int totalNodes(NODE node){
	if (node)
	{
		return(totalNodes(node->left)+totalNodes(node->right) + 1);
	}
}

int main(){
	int a,e,i;
	NODE root = NULL;
	
	
	while(i!=-1){
		printf("Choose from the following\n");
		printf("1. Create Tree\n");
		printf("2. Insert Elements\n");
		printf("3. sum of nodes\n");
		
		printf("7. End\n");

		scanf("%d",&a);
		if (a==-1){
			i=-1;
		}
		switch(a){
		case 1: printf("Insert root\n" );
				scanf("%d",&e);
				root = CreateTree(e);
				break;
		case 2:printf("Insert element\n" );
				scanf("%d",&e);
				InsertIntoTree(root,e);
				break;
		case 3:printf("Total no. of nodes is %d \n",totalNodes(root));
				
				break;
	
				break;
		default: i=-1;
	}
	}


}