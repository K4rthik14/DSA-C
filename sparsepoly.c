#include <stdio.h>
#define MAX 100
typedef struct {
int coeff;
int expo;
} Term;
Term terms[MAX];
int avail = 0;
// Function to read a polynomial
void readPolynomial(int *start, int *finish) {
int n, coeff, expo;
printf("Enter number of terms: ");
scanf("%d", &n);
*start = avail;
printf("Enter terms (coeff expo) in descending order:\n");
for (int i = 0; i < n; i++) {
scanf("%d%d", &coeff, &expo);
if (avail >= MAX) {
printf("Term limit exceeded.\n");
return;
}
terms[avail].coeff = coeff;
terms[avail].expo = expo;
avail++;
}
*finish = avail - 1;
}
// Function to display a polynomial
void displayPolynomial(int start, int finish) {
for (int i = start; i <= finish; i++) {
if (i > start && terms[i].coeff > 0)
printf(" + ");
printf("%dx^%d", terms[i].coeff, terms[i].expo);
}
printf("\n");
}
// Function to add two polynomials
void addPolynomials(int startA, int finishA, int startB, int finishB, int *startD, int *finishD) {
int i = startA, j = startB;
*startD = avail;
while (i <= finishA && j <= finishB) {
if (terms[i].expo == terms[j].expo) {
int sum = terms[i].coeff + terms[j].coeff;
if (sum != 0) {
terms[avail].coeff = sum;
terms[avail].expo = terms[i].expo;
avail++;
}
i++;
j++;
} else if (terms[i].expo > terms[j].expo) {
terms[avail] = terms[i];
avail++;
i++;
} else {
terms[avail] = terms[j];
avail++;
j++;
}
}
while (i <= finishA) {
terms[avail] = terms[i];
avail++;
i++;
}
while (j <= finishB) {
terms[avail] = terms[j];
avail++;
j++;
}
*finishD = avail - 1;
}
// Main function
int main() {
int startA, finishA, startB, finishB, startD, finishD;

printf("Enter first polynomial:\n");
readPolynomial(&startA, &finishA);
printf("Enter second polynomial:\n");
readPolynomial(&startB, &finishB);
addPolynomials(startA, finishA, startB, finishB, &startD, &finishD);
printf("\nPolynomial 1: ");
displayPolynomial(startA, finishA);
printf("Polynomial 2: ");
displayPolynomial(startB, finishB);
printf("Sum: ");
displayPolynomial(startD, finishD);
return 0;
}