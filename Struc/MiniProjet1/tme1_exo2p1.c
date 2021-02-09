#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int   *alloue_tableau(int n){
  int *tab;
  tab = (int *)malloc(sizeof(int) * n);
  return tab;
}

void  desalloue_tableau(int *tab){
  free(tab);
}

void  remplir_tableau(int *tab, int n, int v){
  for (int i = 0; i < n; i++)
    tab[i] = (int)(rand() % v);
}

void  afficher_tableau(int *tab, int n){
  printf("[ ");
  for (int i = 0; i < n; i++)
    printf("%d ", tab[i]);
  printf(" ]");
}

int   power(int nb, int pow){
  if (pow <= 0)
    return 1;
  else 
    return nb * power(nb, pow - 1);
}

int somme_carres_1(int *tab, int n){
  int somme = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      somme += power(tab[i] - tab[j], 2);
  return somme;
}

int somme_carres_2(int *tab, int n)
{
  int somme = 0;
  for (int i = 0; i < n; i++)
    somme += tab[i];
  return power(somme, 2);
}

void  testFunc(){
  int *t = alloue_tableau(10);

  remplir_tableau(t, 2, 10);
  afficher_tableau(t, 2);
  printf("\n%d", somme_carres_1(t, 2));
  printf("\n%d", somme_carres_2(t, 2));
  desalloue_tableau(t);
}
int main(){
  srand(time(NULL));
  testFunc();
  // unsigned long temps_initial_1;
  // unsigned long temps_final_1;
  // unsigned long temps_initial_2;
  // unsigned long temps_final_2;
  // double temps_cpu_1;
  // double temps_cpu_2;
  // int n = 5000;
  // int *tab = alloue_tableau(n);
  // remplir_tableau(tab, n, n);
  // temps_initial_1 = clock();
  // int a = somme_carres_1(tab, n);
  // temps_final_1 = clock();
  // temps_initial_2 = clock();
  // int b = somme_carres_2(tab, n);
  // temps_final_2 = clock();

  // temps_cpu_1 = ((double)(temps_final_1 - temps_initial_1)) / CLOCKS_PER_SEC;
  // temps_cpu_2 = ((double)(temps_final_2 - temps_initial_2)) / CLOCKS_PER_SEC;
  // printf("%d %f\n", n, temps_cpu_1);
  // printf("%d %f", n, temps_cpu_2);
  // free(tab);
  // return 0;
}
