# __MiniProjet 1__


## __Exercice 1__ 

### __Partie 1__ : 

### Question 1

- Le programme est cense allouer un tableau de 10 cases avec des int dans l'ordre decroissant (de 9 a 0). 
- Or on obtient un segfault


### Question 2

- Comme i est un unsigned int il ne peut pas prendre de valeur negative. 
- La condition ``i >= 0 `` dans la boucle for fait que i prend la valeur de INT_MAX (4294967295) après l'itération dans laquelle i valait 0
	-	Pour sortir de la boucle i devrait prendre une valeur négative.
- On essaye donc d'accéder à la case du tableau 4294967295, or nous avons alloue uniquement 10 cases, on essaye alors d'atteindre une memoire qui ne nous appartient d'ou l'erreur de segmentation.

- GDB affiche alors : 
```text
(gdb) r
Program received signal SIGSEGV, Segmentation fault.
0x00005555555551bf in main () at tme1_exo1p1.c:13
13			tab[i] = i;
(gdb) p i
$1 = 4294967295
```


### Question 3
- Il suffit de ne pas initialiser i comme étant un unsigned int mais un int simple
- Ou ajouter l'instruction a la fin de la boucle for :
```C
if (i == 0)
	break;
```

### __Partie 2__ : 

### Question 4

- À la lecture du code, le programme est censé créé un pointeur vers une adresse qui le met dans maison, et affiche les 3 champs de cette adresse.
- Lorsque l'on compile et que l'on lance le programme, on obtient une erreur de segmentation.e

### Question 5

- Lorsque l'on affiche la valeur de new-rue on a :
```text
(gdb) p new->rue
$1 = 0x0
```
Ce qui correspond a une adresse NULL car lors de l'appel de fonction ``creer_adresse`` on ne lui alloue pas de memoire. 

- En continuant l'exécution pour arriver au deuxième point d'arrêt remarque que l'erreur apparaît
- L'erreur provient de la ligne 15 ``strcpy(new->rue, r);`` En effet, la variable ``new->rue`` n'est pas initialise, donc la fonction copie r dans une adress aleatoire.
	- Pour corriger cette erreur on peut, soit allouer dynamiquement avec l'instruction ``new->rue=strdup(r);`` dans la fonction ``creer_addresse``
	- Ou on declare un tableau statique ``new->rue`` dans la structure (par exemple : ``char rue[100];``) 

### __Partie 3__ : 


### Question 6

Le programme est censé faire une structure tableau, d'ajouter des éléments à cette structure, et à les afficher. Lorsque l'on lance le programme, on a :
``t->position = 5 ``
[ 5 18 99999 -452 4587 ] 
d'afficher

### Question 7
le problème de ce programme est que l'on alloue une taille au tableau qui est la taille max, mais que l'on utilisera peut-être pas toute la mémoire allouée comme dans notre exemple

## __Exercice__ 2

