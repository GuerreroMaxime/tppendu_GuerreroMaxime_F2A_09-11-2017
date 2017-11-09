#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char Mot[10];		//Le mot qu'on devras trouver
    char Lettre;		//Voici la lettre que l'on rentre
    int  Vie;	        //Le nombre de vie que possède le joueur
    int  Findegame;     //Si le joueur perd ou gagne la partie
    int  Compteur;  	//Pour l'affichage du jeu
    int Quitter;	    //Si le joueur veux partir du jeux
    char tableMot[10];  //Pour stocker les valuers du mots
    int Confirm;		//Permet de taper un mot
    int Mot2[10];			//Permet a l'utilisateur de deviner le mot
    int Check;			//Si check est superieur a 1 alors la lettre ce trouve dans le mot sinon on perd une vie

    do{
    //On set la valeur de Vie et de Findegame puis on demande a l'utilisateur de choisir un mot//
            Vie=10;
			Findegame=0;
			Compteur=0;
			Confirm=0;
			puts("Entrer votre Mot\n");
			fflush(stdin);
			gets(Mot);
			tableMot[Compteur]='\0';
			system("@cls||clear");

            for (Compteur=1; Compteur<=strlen(Mot); Compteur++){
				printf("... ");
				tableMot[Compteur]='.';
			}
			puts("\n");



    //On fait la boucle du jeu //

        do{
                Check=0;
				Compteur=1;
				puts("Ecrire une lettre\n");
				fflush(stdin);
				Lettre = getchar();


	//Voici la boucle pour savoir si la lettre est dans le mot//

				for (Compteur=0; Compteur<strlen(Mot); Compteur++){
					if (Lettre==Mot[Compteur]){
					    printf("%c ", Lettre);
                        tableMot[Compteur]=Lettre;
						Check=1;
					}else if (Lettre!=Mot[Compteur]){
						printf("... ");
					}
				}


    //Si aucune lettre ce trouve dans le mot alors on perd une vie//

				if (Check==0){
					Vie=Vie-1;
				}


	//On demande a l'utilisateur de rentrer un mot si il a deviner//


                printf("\nLe Mot actuelle %s",tableMot);
				puts("\n Avez vous trouver le mot ? (1 pour confirmer)\n");
                fflush(stdin);
                scanf("%d",&Confirm);

				if ((Confirm==1) && (Vie!=0)){
                    puts("Entrer votre Mot\n");
                    fflush(stdin);
					gets(Mot2);

					if (strcmp(Mot2,Mot)==0){
						Findegame=1;
					}
				}


	//Voici l'affichage de la vie et de verifier si il reste des vie au joueur ou si il a trouver le mot

				printf("Il vous reste %i vie\n", Vie);

				if (Vie==0){
					Findegame=2;
                }

			}while(Findegame==0);


	//En fonction de la valeur de Findegame on choisi une condition de victoire//

			if (Findegame==1){
				printf("Vous avez gagner \n");
			}else{
				printf("Vous avez perdu \n");
			}

			printf("Le mot est %s \n", Mot);


	//En fonction de la valeur de Quitter on choisi si le joueur veux continuer a jouer//

			printf("Voulez vous recommencer ? (appuyer sur 1 pour recommancer \n");
			fflush(stdin);
			scanf("%d",&Quitter);

        }while(Quitter==1);

		printf("Aurevoir");

   system("pause");
   return 0;
}
