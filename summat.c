#include <stdio.h>
#define MAX 100
typedef struct {
int row;
int col;
int val;
} Term;
Term a[MAX], b[MAX], sum[MAX];
// Function to read a sparse matrix
void readSparseMatrix(Term mat[], int *size) {
int i;
printf("Enter number of rows, columns, and non-zero elements: ");
scanf("%d%d%d", &mat[0].row, &mat[0].col, &mat[0].val);
printf("Enter the non-zero elements (row col value):\n");
for (i = 1; i <= mat[0].val; i++) {
scanf("%d%d%d", &mat[i].row, &mat[i].col, &mat[i].val);
}
*size = mat[0].val + 1;
}
// Function to display a sparse matrix
void displayMatrix(Term mat[], int size) {
printf("Row\tCol\tVal\n");
for (int i = 0; i < size; i++) {
printf("%d\t%d\t%d\n", mat[i].row, mat[i].col, mat[i].val);
}
}
// Function to add two sparse matrices
int addSparseMatrices(Term a[], Term b[], Term sum[]) {
if (a[0].row != b[0].row || a[0].col != b[0].col) {
printf("Matrix dimensions do not match. Cannot add.\n");
return 0;
}
int i = 1, j = 1, k = 1;
sum[0].row = a[0].row;
sum[0].col = a[0].col;

while (i <= a[0].val && j <= b[0].val) {
if (a[i].row < b[j].row ||
(a[i].row == b[j].row && a[i].col < b[j].col)) {
sum[k++] = a[i++];
} else if (b[j].row < a[i].row ||
(a[i].row == b[j].row && b[j].col < a[i].col)) {
sum[k++] = b[j++];
} else { // same position
int added = a[i].val + b[j].val;
if (added != 0) {
sum[k].row = a[i].row;
sum[k].col = a[i].col;
sum[k].val = added;
k++;
}
i++;
j++;
}
}
while (i <= a[0].val) sum[k++] = a[i++];
while (j <= b[0].val) sum[k++] = b[j++];
sum[0].val = k - 1;
return k;
}
// Main function
int main() {
int sizeA, sizeB, sizeSum;
printf("Enter Sparse Matrix A:\n");
readSparseMatrix(a, &sizeA);
printf("\nEnter Sparse Matrix B:\n");
readSparseMatrix(b, &sizeB);
printf("\nMatrix A:\n");
displayMatrix(a, sizeA);
printf("\nMatrix B:\n");
displayMatrix(b, sizeB);
sizeSum = addSparseMatrices(a, b, sum);
if (sizeSum > 0) {
printf("\nSum of Matrix A and B:\n");
displayMatrix(sum, sizeSum);
}
return 0;
}