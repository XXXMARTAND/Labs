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
int ElementExists(NODE root,int val){
	if(root){
			if (val>root->value){
			return ElementExists(root->right,val);
			
		}
		else if (val<root->value){
			return ElementExists(root->left,val);
			
		}
		else if(val == root->value){
		return 1;

	}
	else return 0;

}
}
void SearchInsert(NODE root, int val){
	if (ElementExists(root,val)){
		printf("key found\n");
	}
	else {
		InsertIntoTree(root,val);
		printf("Element added\n");
	}
}
void InOrder(NODE root){
	if(root){
		InOrder(root->left);
		printf("%d\n",root->value );
		InOrder(root->right);
	}
}
void PreOrder(NODE root){
	if(root){
		printf("%d\n",root->value );
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void PostOrder(NODE root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d\n",root->value );
	}
}
int main(){
	int a,e,i;
	NODE root = NULL;
	
	
	while(i!=-1){
		printf("Choose from the following\n");
		printf("1. Create Tree\n");
		printf("2. Insert Elements\n");
		printf("3. Search/Insert Element\n");
		printf("4. Inorder Traversal\n");
		printf("5. Preorded Traversal\n");
		printf("6. Postorder Traversal\n");
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
		case 3:printf("Insert element to search/Insert\n" );
				scanf("%d",&e);
				SearchInsert(root,e);
				break;
		case 4: InOrder(root);
				break;
		case 5: PreOrder(root);
				break;
		case 6: PostOrder(root);
				break;
		default: i=-1;
	}
	}


}