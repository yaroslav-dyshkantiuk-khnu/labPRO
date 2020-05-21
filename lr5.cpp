#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
int n;
#pragma omp parallel private(n)
 {
 n = omp_get_thread_num();
 #pragma omp sections
 {
#pragma omp section
 {
 printf("1 sekcija, proces %d\n", n);
 }
#pragma omp section
 {
 printf("2 sekcija, proces %d\n", n);
 }
#pragma omp section
 {
 printf("3 sekcija, proces %d\n", n);
 }
 }
 printf("Paralel'na diljanka, proces %d\n", n);
 }
} 