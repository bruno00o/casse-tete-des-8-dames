# casse-tete-des-8-dames
Jeu du casse-têtes des 8 dames en C avec ncurses

Ce TP réalisé à l'Université en cours de programmation en C avait pour but de se familiariser avec les opérations bit à bit ainsi qu'avec la libraire graphique `ncurses`.

## But du jeu

Le but du jeu est de placer ses 8 dames sur la plateau en faisant attention qu'aucune d'entres elles ne puissent s'attaquer.
Elles attaques sur toute une ligne vers le haut, vers le bas et en diagonale.

## Fonctionnement du jeu

- Placez les dames avec la souris dans les cases du plateau
- Vous pouvez annuler le dernier placement avec `a`
- Vous pouvez quitter le jeu à tout moment avec `q`
- Une fois les 8 dames posées, vous ne pouvez plus revenir en arrière, votre grille finale est affichée, un clic n'importe où vous affichera si vous avez gagner ou non
- Cliquez pour quitter

## Exemple de combinaison gagnante

![image](https://user-images.githubusercontent.com/77984019/181786528-3aa4015f-b22c-4250-9f25-7e47965824a2.png)
