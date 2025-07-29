#include <stdio.h>
#define MAX 100
typedef struct {
int row;
int col;
int val;
} Term;
Term mat[MAX], trans[MAX];
// Function to read a sparse matrix in tuple format
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
// Function to display a sparse matrix in tuple format
void displayMatrix(Term mat[], int size) {
printf("Row\tCol\tVal\n");
for (int i = 0; i < size; i++) {
printf("%d\t%d\t%d\n", mat[i].row, mat[i].col, mat[i].val);
}
}
// Function to compute transpose of a sparse matrix
void transposeMatrix(Term mat[], Term trans[]) {
int i, j, k = 1;
trans[0].row = mat[0].col;
trans[0].col = mat[0].row;
trans[0].val = mat[0].val;
for (i = 0; i < mat[0].col; i++) {
for (j = 1; j <= mat[0].val; j++) {
if (mat[j].col == i) {
trans[k].row = mat[j].col;
trans[k].col = mat[j].row;
trans[k].val = mat[j].val;
k++;
}
}
}
}
// Main function
int main() {
int size;
// Read input matrix
readSparseMatrix(mat, &size);
// Display original matrix
printf("\nOriginal Sparse Matrix (Tuple Form):\n");
displayMatrix(mat, size);
// Transpose the matrix
transposeMatrix(mat, trans);
// Display transpose
printf("\nTranspose of Sparse Matrix:\n");
displayMatrix(trans, size);
return 0;
}