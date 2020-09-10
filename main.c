#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  /*** On initialise les variables utiles ***/
  // La taille de la grille
  int taille = 2;
  while (taille % 2 == 0 && taille > 1) {
    printf("Rentrez un chiffre impair et supérieur ou égal à 3 pour le carré magique : ");
    scanf("%d", &taille);
  }
  // La grille
  int **carreMagique = malloc(sizeof(int*) * taille);
  for (int i = 0; i < taille; i++) {
      carreMagique[i] = malloc(sizeof(int) * taille);
  }  
  // Le numéro de la ligne actuelle
  int ligne = (taille/2)-1;
  // Le numéro de la colonne actuelle
  int colonne = (taille/2);
  // Le numéro à placer actuel
  int nb = carreMagique[ligne][colonne] = 1;
  // L'état de la condition de la case supérieure droite
  int state = 0;


  // Tant que la grille n'est pas remplie
  while (nb < pow(taille, 2)) {
    nb++;

    // On vérifie si le cas de la case supérieure droite est présent et si l'on ne l'a pas déjà fait
    if (carreMagique[ligne][colonne] == carreMagique[0][taille-1] && state == 0) {
      // On regarde quelles cases de la dernière colonne sont vides et on garde la dernière 0;2
      int derniereCase = 0;
      for (int i = 0; i < taille; i++) {
        derniereCase = (carreMagique[i][taille-1] == 0) ? i : derniereCase;
      }
      
      // On place le bon nombre à la dernière case
      ligne = derniereCase;
      colonne = taille-1;
      carreMagique[derniereCase][taille-1] = nb;

      state = 1;
    } // Sinon on applique la règle
    else {
      // On modifie la ligne et la colonne pour qu'elles soient toujours entre 0 et la taille maximum
      ligne = (ligne == 0) ? taille-1 : ligne-1; // 1 -> 0
      colonne = (colonne == taille-1) ? 0 : colonne+1; // 0 -> 1

      // On vérifie si la case est libre
      if (carreMagique[ligne][colonne] == 0) {
        // On place le bon nombre
        carreMagique[ligne][colonne] = nb;

      } // Sinon on choisi la case en haut à gauche
      else {
        // On modifie la ligne et la colonne pour qu'elles soient toujours entre 0 et la taille maximum
        ligne = (ligne == 0) ? taille-1 : ligne-1;
        colonne = (colonne == 0) ? taille-1 : colonne-1;

        // On place le bon nombre
        carreMagique[ligne][colonne] = nb;

      }
    }
  }

  // On affiche la grille entière une fois que toutes les cases sont remplies
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      printf("[%3d]", carreMagique[i][j]);

    }
    printf("\n");

  }

  return 0;
}