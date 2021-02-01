#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av){
    int N_MAX = atoi(av[1]);
    printf("Valeur N_Max :\n");

    int nombre;
    srand(time(NULL));
    nombre = rand() % (N_MAX + 1);
    printf("%d\n", nombre);

    return 0;
}