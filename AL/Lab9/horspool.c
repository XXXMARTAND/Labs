
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * string;

string main1, P;
int n, m;

int i, j;

void input () {
	main1 = (string)malloc(1024 * sizeof(char));
	P = (string)malloc(256 * sizeof(char));
	printf("Enter main string ");
	scanf(" %s", main1);
	n = strlen(main1);
	printf("Enter substring ");
	scanf(" %s", P);
	m = strlen(P);
}

int horspool (int *kc) {

	int shift[128];
	for (i = 0; i < 128; ++i) {
		shift[i] = m;
	}

	for (i = 0; i < m - 1; ++i) {
		shift[P[i]] = m - 1 - i;
	}



	j = 0;
	while (j + m <= n) {
		*kc += 1;
		if (P[m-1] == main1[j+m-1]) {
			i = m - 2;
			while (i >= 0 && P[i] == main1[j+i]) {
				*kc += 1;
				i -= 1;
			}
			if (i == -1)
				return j;
		}
		j += shift[main1[j+m-1]];
	}
	return -1;

}

int main (int argc, char const * argv []) {
	input();
	int kc = 0;//this is comparison count
	int hs = horspool(&kc);
	printf("  main string %s \n", main1);
	printf(" sub string %s \n", P);
	printf("found at location %d\n", hs+1);
	return 0;
}