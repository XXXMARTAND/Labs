#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

typedef enum { NO, YES } BOOL;

typedef struct hnode {
	int data;
	struct hnode *next;
} HNODE_t, *HNODE_p_t;

typedef struct hash {
	HNODE_p_t *heads;
	int count[10];
	int totalcount;
} HASH_t, *HASH_p_t;

int get (int data) {
	return (data % 10);
}

HNODE_p_t inithnode (int data) {
	HNODE_p_t hnode = (HNODE_p_t)malloc(sizeof(HNODE_t));
	hnode->data = data;
	hnode->next = NULL;
	return hnode;
}

HASH_p_t initHashTable () {
	HASH_p_t ht = (HASH_p_t)malloc(sizeof(HASH_t));
	ht->totalcount = 0;
	ht->heads = (HNODE_p_t *)calloc(10, sizeof(HNODE_p_t));
	int i;
	for (i = 0; i < 10; ++i) {
		ht->count[i] = 0;
		*((ht->heads) + i) = inithnode(i);
	}
	return ht;
}

BOOL insertToHash (HASH_p_t hash, int data) {
	if (hash->totalcount == 50) // Max MAX exceeded
		return NO;
	int ht = get(data);
	int ct = hash->count[ht];
	while (ct == MAX) { // Linear probe it
		ht = (ht + 1) % 10;
		ct = hash->count[ht];
	}
	HNODE_p_t *heads = hash->heads;
	HNODE_p_t head = *(heads + ht);
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = inithnode(data);
	hash->count[ht] += 1;
	hash->totalcount += 1;
	return YES;
}

int searchHash (HASH_p_t hash, int key, int *kc) {
	int ht = get(key);
	int zt = ht;
	HNODE_p_t *heads = hash->heads;
	do {
		HNODE_p_t head = *(heads + ht);
		head = head->next;
		while (head != NULL) {
			*kc += 1;
			if (head->data == key) {
				return ht;
			}
			head = head->next;
		}
		ht = (ht + 1) % 10;
	} while (ht != zt);
	return -1;
}

void printHashTable (HASH_p_t hashtable) {

	printf("Htable %d:\n", hashtable->totalcount);

	HNODE_p_t *heads = hashtable->heads;

	int i;
	for (i = 0; i < 10; ++i) {
		printf("%d  ", i);
		HNODE_p_t head = *(heads + i);
		head = head->next;
		while (head->next != NULL) {
			printf("%3d ---> ", head->data);
			head = head->next;
		}
		printf("%d\n", head->data);
	}

	printf("\n");

}

void main () {
	
	HASH_p_t hashtable = initHashTable();
	int arr[1024];
	int k = 0;

	int i;
	// 

	printHashTable(hashtable);

	int kc;
	float ac = 0.0;

	for (i = 0; i < k; ++i) {
		int key = arr[i];
		kc = 0;
		searchHash(hashtable, key, &kc);
		ac += kc;
		
	}

	ac /= k;
	printf("Avg %.2lf\n\n", ac);

}