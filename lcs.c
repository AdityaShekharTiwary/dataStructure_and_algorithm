#include<stdio.h>
#include <string.h>

int min(int a, int b) {return (a < b) ? a : b;}
int max(int a, int b) {return (a > b) ? a : b;}

int lcs( char *X, char *Y, char *Z, int m, int n, int *ops)
{
	int L[m + 1][n + 1];
	int i, j;

	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			*ops += 1;
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	int res = L[m][n];
	int index = res;

	Z[index] = '\0';

	i = m, j = n;
	while (i > 0 && j > 0)
	{
		*ops += 1;
		if (X[i - 1] == Y[j - 1])
		{
			Z[index - 1] = X[i - 1];
			i--; j--; index--;
		}

		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	return res;

}

void printSeq(char* a, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%c", a[i]);
	printf("\n");
}

int main()
{
	char X[] = "TECHAAANO";
	char Y[] = "BIOTECHNOLOGY";



	int m = strlen(X);
	int n = strlen(Y);
	char Z[min(m, n)];
	int ops = 0;



	printf("\n\nThe input sequences are:\n");
	printSeq(X, m);
	printSeq(Y, n);
	int lcs_len = lcs( X, Y, Z, m, n, &ops);
	printf("\nLength of LCS is %d ops is %d", lcs_len, ops );
	printf("\nThe LCS is:\n");
	printSeq(Z, lcs_len);



	char X2[] = "ABCBDBBCDEFFRE";
	char Y2[] = "RFFWDDBCEFFFFRWWS";



	int m2 = strlen(X2);
	int n2 = strlen(Y2);
	char Z2[min(m2, n2)];
	int ops2 = 0;



	printf("\n\nThe input sequences are:\n");
	printSeq(X2, m2);
	printSeq(Y2, n2);
	int lcs_len2 = lcs( X2, Y2, Z2, m2, n2, &ops2);
	printf("\nLength of LCS is %d ops is %d", lcs_len2, ops2 );
	printf("\nThe LCS is:\n");
	printSeq(Z2, lcs_len2);



	char X3[] = "ATGCAGTCATATGCGCATGAGATCCTGCAGT";
	char Y3[] = "GTCACGCATGCAGTA";



	int m3 = strlen(X3);
	int n3 = strlen(Y3);
	char Z3[min(m3, n3)];
	int ops3 = 0;



	printf("\n\nThe input sequences are:\n");
	printSeq(X3, m3);
	printSeq(Y3, n3);
	int lcs_len3 = lcs( X3, Y3, Z3, m3, n3, &ops3);
	printf("\nLength of LCS is %d ops is %d", lcs_len3, ops3 );
	printf("\nThe LCS is:\n");
	printSeq(Z3, lcs_len3);



	char X4[] = "SUPERCALIFRAGILISTICEXPIALIDOCIOUS";
	char Y4[] = "SUPERMAN IS NOT FRAGILE";



	int m4 = strlen(X4);
	int n4 = strlen(Y4);
	char Z4[min(m4, n4)];
	int ops4 = 0;



	printf("\n\nThe input sequences are:\n");
	printSeq(X4, m4);
	printSeq(Y4, n4);
	int lcs_len4 = lcs( X4, Y4, Z4, m4, n4, &ops4);
	printf("\nLength of LCS is %d ops is %d", lcs_len4, ops4 );
	printf("\nThe LCS is:\n");
	printSeq(Z4, lcs_len4);



	char X5[] = "pneumonoultramicroscopicsilicovolcanoconiosis";
	char Y5[] = "pneumonia is due to cold, silicon is used for making microchips";



	int m5 = strlen(X5);
	int n5 = strlen(Y5);
	char Z5[min(m5, n5)];
	int ops5 = 0;



	printf("\n\nThe input sequences are:\n");
	printSeq(X5, m5);
	printSeq(Y5, n5);
	int lcs_len5 = lcs( X5, Y5, Z5, m5, n5, &ops5);
	printf("\nLength of LCS is %d ops is %d", lcs_len5, ops5 );
	printf("\nThe LCS is:\n");
	printSeq(Z5, lcs_len5);



	return 0;
}