//idée : mode deux joueurs

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //utilisation de srand
#include <ctype.h> // utilisation de toupper()
#include "module.h"


//PROTOTYPES
char lireCaractere();
void comp(char caractere, char motSecret[], char position[], char lenghtMotSecret);
int lenghtString(char motSecret[]);
int testComplete(char motSecret[], char motSecret2[], char lenghtMotSecret);
int nbrMot();
int randNbr(int a, int b);


int main(int argc, char const *argv[])
{
    char caractere = 0; //stocke le caractere actuel saisi 
    char motSecret[100] = {0}; //stocke le mot secret
    int lenghtMotSecret = 0; //stocke la longueur du mot secret
    char *position = NULL; //pointeur sur position
    char *motSecret2 = NULL; //pointeur sur le mot secret caché
    int nbrCoup = 10; //stocke le nombre de coup disponible
    int isComplete = 0; //stocke la reussite ou non du jeu
    int fini = 0; //stovke la fin du jeu
    int i = 0; //variable utile
    FILE *fichier = NULL; //stocke le pointeur du fichier mot
    int c = 0; //stocke un caractere
    int nbrCrct = 0; //stocke le nombre de caractere d'ecart
    int mot = 0; //stocke le nombre de mot d'ecart
    int nbrHasard = 0; //stocke un nombre au hasard
    int nbrMots = nbrMot(); //stocke le nombre de mot dans le fichier mot

    nbrHasard = randNbr(0, (nbrMots - 2)); //choisis un nombre au hasard
    fichier = fopen("mot.txt", "r"); //ouvre le fichier mot

    //calcule le nombre de mot et de caractere entre le debut et le mot choisi
    while(mot != nbrHasard)
    {
        c = fgetc(fichier);

        if (c != '\n') {
            nbrCrct++;
        }
        else
        {
            mot++;
        }
    }

    fseek(fichier, (nbrCrct + nbrHasard * 2), SEEK_SET); //se positionne au bon mot dans le fichier

    c = 0;
    
    //rentre le mot choisi dans la chaine motSecret
    while (c != '\n')
    {
        c = fgetc(fichier);
        if (c != '\n')
        {
            motSecret[i] = c;
        }
        
        i++;
    }

    //lit le mot juste
    /*i = 0;
    while (c != '\0')
    {
        c = motSecret[i];
        printf("%c", c);
        i++;
    }*/
    
    

    fclose(fichier); //ferme le fichier

    //creation du tableau position et motSecret2
    lenghtMotSecret = lenghtString(motSecret);
    position = malloc(sizeof(char)*lenghtMotSecret);
    motSecret2 = malloc(sizeof(char)*lenghtMotSecret);
    
    //initialisation de motSecret2
    i = 0;
    for(i = 0; i < lenghtMotSecret; i++)
    {
        motSecret2[i] = '*';
    }

    printf("BIENVENUE\n\n");

    //compte a rebours
    while(nbrCoup != 0 && fini == 0)
    {
        printf("\n\nIL VOUS RESTE %d ESSAIS\n", nbrCoup);
        i = 0;
        for (i = 0; i < lenghtMotSecret; i++)
        {
            printf("%c", motSecret2[i]);
        }
        printf("\nCHOISISSEZ UNE LETTRE : ");
        
        int isJuste = 0; //variable stockant la justesse du caractere
        caractere = lireCaractere(); //recupere la saisie
        comp(caractere, motSecret, position, lenghtMotSecret); //compare 

        //revele les caracteres justes 
        int j = 0;
        for(j = 0; j < lenghtMotSecret; j++)
        {
            if (position[j] == 1) {
                motSecret2[j] = motSecret[j];
                isJuste = 1;
            }
        }

        //enleve un coup si aucun caractere juste
        if (isJuste == 0) {
            nbrCoup--;
        }
        
        //test le nombre de coup
        if(nbrCoup == 0)
        {
            printf("DEFAITE");
            exit(0);
        }

        isComplete = testComplete(motSecret, motSecret2, lenghtMotSecret);
        if (isComplete == 1) {
            fini = 1;
        }
    }

    if (fini == 1) {
        printf("\nBRAVO VOUS AVEZ GAGNE, LE MOT EST : ");
        
        int k = 0;
        for(k = 0; k < lenghtMotSecret; k++)
        {
            printf("%c", motSecret[k]);
        }
        exit(0);
    }
    return 0;
}


//fonction permettant de lire la saisie utilisateur
char lireCaractere()
{   
    char choix = 0;
    
    choix = getchar();
    choix = toupper(choix);

    while(getchar() != '\n');

    return choix;
}


//fonction permettant le caractere saisi et le mot secret
void comp(char caractere, char motSecret[], char position[], char lenghtMotSecret)
{
    //remet position a 0
    int j = 0;
    for(j = 0 ; j < lenghtMotSecret ; j++)
    {
        position[j] = 0;
    }

    //compare
    int i = 0;
    for(i = 0 ; i < lenghtMotSecret ; i++){
        
        if (motSecret[i] == caractere) {
            position[i] = 1;
        }
    }
}


//fonction permettant de connaitre la longueur d'une chaine 
int lenghtString(char motSecret[])
{
    int i = 0;
    while(motSecret[i] != '\0')
    {
        i++;
    }

    return i;
}

int testComplete(char motSecret[], char motSecret2[], char lenghtMotSecret)
{
    int juste = 0;
    
    int i = 0;
    for(i = 0; i < lenghtMotSecret; i++)
    {
        if (motSecret[i] == motSecret2[i]) {
            juste++;
        }  
    }

    if (juste == lenghtMotSecret) {
        return 1;
    }
    else
    {
        return 0;
    } 
}

//compte le nombre de mot dans le fichier
int nbrMot()
{
    FILE *fichier = NULL;
    int c = 0;
    int i = 1;

    fichier = fopen("mot.txt", "r");
    rewind(fichier);

    while(c != EOF)
    {
        c = fgetc(fichier);
        if (c == '\n') {
            i++;
        }
    }

    return i;

    fclose(fichier);
}

//choisi un nombre au hasard entre a et b
int randNbr(int a, int b){
    int nbr = 0;
    int MIN = a;
    int MAX = b;
    srand(time(NULL));

    nbr = (rand() % (MAX - MIN + 1) + MIN);

    return nbr;
}