#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	int grid[n+1][m+1][l+1];
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= l; j++) {
			grid[0][i][j] = 0;
		}
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= l; j++) {
			grid[i][0][j] = 0;
		}
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			grid[i][j][0] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= l; k++) {
				int count = 0;
				if(a[i-1] == b[j-1] && a[i-1] == c[k-1]) {
					count = grid[i - 1][j - 1][k - 1] + 1;
				}
				if(grid[i-1][j][k] > count) {
					count = grid[i-1][j][k];
				}
				if(grid[i][j-1][k] > count) {
					count = grid[i][j-1][k];
				}
				if(grid[i][j][k-1] > count) {
					count = grid[i][j][k-1];
				}
				grid[i][j][k] = count;
			}
		}
	}
	return grid[n][m][l];
}

int main() {
	int n, m, l;  
  
	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);
	
	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	
	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}
	
	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array b:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);
	
	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);
	
	return 0;
}