#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int   **alloue_matrice(int n){
  int **tab = malloc(sizeof(int*) * n);

  for (int i = 0; i < n; i++)
    tab[i] = malloc(sizeof(int) * n);
  return tab;
}

void  desalloue_matrice(int **tab, int n){
  for (int i = 0; i < n; i++)
    free(tab[i]);
  free(tab);
}

void  remplir_matrice(int **tab, int n, int borne){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      tab[i][j] = (int)(rand() % borne);
}

void  afficher_matrice(int **tab, int n)
{
  printf("{\n");
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      printf("%d ", tab[i][j]);
    printf("\n");
  }
  printf("}\n");
}

int   tous_diff(int **tab, int n){//a rep

  for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if ((a != i || b != j) && (tab[a][b] == tab[i][j]))
            return 0; //return 0 si c'est faux
  return 1; // return 1 si c'est vrai
}

int   tous_diff2(int **tab, int n, int borne){
  int *t = calloc(sizeof(int), borne);
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (t[tab[i][j]-1] == 1){
        free(t);
        return 0;
      }
      else
        t[tab[i][j]-1] = 1;
    }
    free(t);
    return 1;
}

void prod_matrice_1(int **tab1, int **tab2, int **tab_retour, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      tab_retour[i][j]=0;
      for (int k = 0; k < n; k++)
        tab_retour[i][j] += tab1[i][k] * tab2[k][j];
    }
}

void prod_matrice_2(int **tab1, int **tab2, int **tab_retour, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      tab_retour[i][j]=0;
      for (int k = i; k < n; k++)
        tab_retour[i][j] += tab1[i][k] * tab2[k][j];
    }
}

void  testDiff(){
  int taille = 3, borne = 10;
  int **tab = alloue_matrice(taille);
  remplir_matrice(tab, taille, borne);
  afficher_matrice(tab, taille);
  printf("La matrice a des valeurs differentes %s\n", tous_diff(tab,taille) == 1 ? "yes": "no");
  printf("La matrice a des valeurs differentes %s\n", tous_diff2(tab,taille, borne == 1)? "yes": "no");
  desalloue_matrice(tab, taille);
}

void  testProd(){
  int taille = 3, borne = 10;
  int **tab = alloue_matrice(taille);
  int **prod = alloue_matrice(taille);

  remplir_matrice(tab, taille, borne);
  printf("La matrice AVANT produit:\n");
  afficher_matrice(tab, taille);

  prod_matrice_1(tab,tab,prod, taille);
  printf("La matrice APRES produit\n");
  afficher_matrice(prod, taille);

  desalloue_matrice(tab, taille);
  desalloue_matrice(prod, taille);
}

void  remplir_triangleSup(int **tab, int n, int borne){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (i > j)
        tab[i][j] = 0;
      else
        tab[i][j] = (int)(rand() % borne);
    }
}

void  remplir_triangleInf(int **tab, int n, int borne){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (i < j)
        tab[i][j] = 0;
      else
        tab[i][j] = (int)(rand() % borne);
    }
}

void  testSmartProd(){
  int taille = 3, borne = 50;
  int **tab1 = alloue_matrice(taille);
  int **tab2 = alloue_matrice(taille);
  int **prod = alloue_matrice(taille);
  remplir_triangleSup(tab1, taille, borne);
  remplir_triangleInf(tab2, taille, borne);

  // remplir_matrice(tab, taille, borne);
  printf("La matrice AVANT produit:\n");
  afficher_matrice(tab1, taille);
  afficher_matrice(tab2, taille);

  prod_matrice_1(tab1,tab2,prod, taille);
  printf("La matrice APRES produit1\n");
  afficher_matrice(prod, taille);

  prod_matrice_2(tab1,tab2,prod, taille);
  printf("La matrice APRES produit2\n");
  afficher_matrice(prod, taille);

  desalloue_matrice(tab1, taille);
  desalloue_matrice(tab2, taille);
  desalloue_matrice(prod, taille);
}

int main(){
  srand(time(NULL));
  // int size = 3, borne = 100;
  // int **tab = alloue_matrice(size);
  // remplir_matrice(tab, size, borne); 
  // desalloue_matrice(tab, size);
  testSmartProd();


  return 0;
}

  // int size = 3, borne = 100;
  // int **tab1 = alloue_matrice(n);
  // int **tab2 = alloue_matrice(n);
  // int **tab_retour = alloue_matrice(n);
  // remplir_matrice(tab1, n, v);
  // remplir_matrice(tab2, n, v);
  // remplir_matrice(tab_retour, n, 0);
  // for (int i = 0; i < 2; i++)
  // {
  //   for (int j = 0; j < 2; j++)
  //     printf("%d\n", tab_retour[i][j]);
  //   printf("\n");
  // }
  // desalloue_matrice(tab1, n);
  // desalloue_matrice(tab2, n);
  // desalloue_matrice(tab_retour, n);