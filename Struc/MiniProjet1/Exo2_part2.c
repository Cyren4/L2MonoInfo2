#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int ** alloue_matrice(int n){
  int ** tab=malloc(n*sizeof(int));
    for (int i = 0 ; i < n ; i++){
        tab[i]=malloc(n*sizeof(int));
    }
    return tab;
}

void desalloue_matrice(int** tab,int n){
  for(int i = 0 ; i < n ; i++){
    free(tab[i]);
  }
  free(tab);
}

void remplir_matrice(int ** tab, int n,int v){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ;j++){
      tab[i][j]=(int)(rand()%v);
    }
  }
}

void afficher_matrice(int** tab,int n){
  printf("[ ");
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ;j++){
      printf("%d",tab[i][j]);
    }
  printf("\n");
  }
  printf("]");
}
int tous_diff(int ** tab,int n){
  for(int a=0;a<n;a++){
    for(int b=0;b<n;b++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if((a!=i&&b!=j)&&(tab[a][b]==tab[i][j])){
            return 0; //return 0 si c'est faux
          }
        }
      }
    }
  }
  return 1; // return 1 si c'est vrai
}
void prod_matrice_1(int **tab1,int **tab2,int** tab_retour,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        tab_retour[i][j]+=tab1[i][k]*tab2[k][j];
      }
    }
  }
}
void prod_matrice_2(int ** tab1,int **tab2,int**tab_retour,int n){

}
int main(){
  int n=2;
  int v=100;
  int** tab1=alloue_matrice(n);
  int** tab2=alloue_matrice(n);
  int** tab_retour=alloue_matrice(n);
  remplir_matrice(tab1,n,v);
  remplir_matrice(tab2,n,v);
  remplir_matrice(tab_retour,n,0);
  for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d\n",tab_retour[i][j]);
        printf("\n");
    }
  desalloue_matrice(tab1,n);
  desalloue_matrice(tab2,n);
  desalloue_matrice(tab_retour,n);

  return 0;
}
