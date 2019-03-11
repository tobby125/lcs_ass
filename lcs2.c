#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int lcs2(int *a, int n,  int *b, int m) {
	int grid[n+1][m+1];
	for(int i = 0; i <= m; i++) {
		grid[0][i] = 0;
	}
	for(int i = 0; i <= n; i++) {
		grid[i][0] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int count = 0;
			if(a[i-1] == b[j-1]) {
				count = grid[i-1][j-1] + 1;
			}
			if(grid[i][j-1] > count) {
				count = grid[i][j-1];
			}
			if(grid[i-1][j] > count) {
				count = grid[i-1][j];
			}
			grid[i][j] = count;
		}
	}
	return grid[n][m];
}

int main() {
	int n, m;  
  
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
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);
	
	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);
	
	return 0;
}