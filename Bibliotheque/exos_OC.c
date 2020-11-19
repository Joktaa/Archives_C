#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "exos_OC.h"

#define TAILLE_MAX 500

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void calculImc()
{
    int age;
    int poids;
    float taille;

    printf("Votre age :");
    scanf("%d", &age);
    printf("\nVotre poids en kg :");
    scanf("%d", &poids);
    printf("\nVotre taille en m :");
    scanf("%f", &taille);

    float imc;
    imc = poids/pow(taille, 2);
    printf("\nVotre imc est de : %f\n\n", imc);


    if (imc < 18.5)
    {
        printf("Insuffisance ponderal");
    }
    else if (imc >= 18.5 && imc < 25)
    {
        printf("Corpulence normal");
    }
    else if (imc >= 25 && imc < 30)
    {
        printf("Surpoids");
    }
    else if (imc >= 30 && imc < 35)
    {
        printf("Obesite moderee");
    }
    else if (imc >= 35 && imc < 40)
    {
        printf("obesite severe");
    }
    else if (imc >= 40)
    {
        printf("obesite morbide");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tableMultiplication()
{
    int nbr1, nbr2, result;

    for(nbr1 = 1; nbr1<10; nbr1++){
        for(nbr2 = 0; nbr2<10; nbr2++){
            result = nbr1*nbr2;
            printf("%d ", result);
        }
        printf("\n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuMcdo()
{
    int choix;

    printf("1.BigMac\n2.McPauvre\n3.royal cheese\n4.Signature\nQue choissisez vous ?(indiquez le nombre correspondant) ");
    scanf("%d", &choix);
    printf("\n");

    switch (choix)
    {
     case 1:
        printf("vous avez choisi le Bigmac");
        break;
    case 2:
        printf("vous avez choisi le McPauvre");
        break;
    case 3:
        printf("vous avez choisi le royal cheese");
        break;
    case 4:
        printf("vous avez choisi le Signature");
        break;
    default :
        printf("faute detectee");
        break;
    }

    printf("\n\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void plusOuMoins()
{

    srand(time(NULL));
    int recommencer;
    printf("***** BIENVENUE *****\n");

    do{
        const int MIN = 1;
        int nbrChoisi, niveau;
        int MAX = 99;
        int nbrEssai = 1;

        printf("Choisis un niveau :\n 1.Moyen\n 2.Difficile\n 3.Tres difficile\nChoix : ");
        scanf("%d", &niveau);

        while(MAX < 100 || MAX > 10000){
            do{
                switch(niveau)
                {
                case 1:
                    MAX = 100;
                    break;
                case 2:
                    MAX = 1000;
                    break;
                case 3:
                    MAX = 10000;
                    break;
                default:
                    printf("choisis un nombre entre 1 et 3 : ");
                    scanf("%d", &niveau);
                    break;
                }
            }while(niveau < 1 || niveau > 3);
        }

        int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
        printf("J'ai choisi un nombre entre %d et %d, a toi de trouver lequel.\n\n**A TOI DE JOUER**\n\n", MIN, MAX);

        printf("Choisis un nombre : ");
        scanf("%d", &nbrChoisi);

        while(nbrChoisi != nombreMystere)
        {
            if(nbrChoisi < nombreMystere && nbrChoisi > 0)
            {
                printf("\n-Plus grand-\n\nNouveau nombre : ");
                nbrEssai++;
            }
            else if(nbrChoisi > nombreMystere && nbrChoisi < 101)
            {
                printf("\n-Plus petit-\n\nNouveau nombre : ");
                nbrEssai++;
            }
            else if(nbrChoisi < 1 || nbrChoisi > 100)
            {
                printf("\nJ'ai dis entre %d et %d\n\nNouveau nombre : ", MIN, MAX);
            }

            scanf("%d", &nbrChoisi);
        }

        if(nbrChoisi == nombreMystere)
        {
            printf("\n\n******* WIN ! *******\n\nNombre d'essai : %d\n", nbrEssai);
            printf("Souhaite tu recommencer ? (1.Oui 0.Non) ");
            scanf("%d", &recommencer);
            printf("\n\n");
        }
    }while(recommencer == 1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main_convHeure()
{
    int heure, minute = 0;

    printf("Entrez le nombre d'heures : ");
    scanf("%d", &heure);
    printf("\nEntrez le nombre de minutes : ");
    scanf("%d", &minute);

    int *pheure = &heure;
    int *pminute = &minute;

    convHeure(pheure, pminute);


    printf("\n\n%d", heure);
    printf("\n%d", minute);
}

void convHeure(int *a, int *b)
{
    *a = *b/60;
    *b = *b%60;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main_copie()
{
    int taille = 6;
    int table1[6] = {1,2,3,4,5,6};
    int table2[6] = {0};
    int i = 0;

    
    lire(table1, taille);
    printf("\n");
    lire(table2, taille);

    printf("\n\n\n");

    copie(table1, table2, taille);

    lire(table1, taille);
    printf("\n");
    lire(table2, taille);
}

void copie(int a[], int b[], int taille)
{
    int i = 0;
    for(i=0; i<taille; i++)
    {
        b[i] = a[i];
    }


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void lire(int tableau[], int taille)
{
    int i =0; 
    for(i=0; i<taille; i++)
    {
        printf("%d\n", tableau[i]);
    }
    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main_max()
{
    int taille = 6;
    int tableMax[6] = {1,11,2,12,26,7};
    int max = 10;

    lire(tableMax, taille);

    maxTable(tableMax, taille, max);

    lire(tableMax, taille);
}

void maxTable(int table[], int taille, int max)
{
    int i = 0;
    for(i=0; i<taille; i++)
    {
        if(table[i] > max)
        {
            table[i] = 0;
        }
        else
        {
            table[i] = table[i];
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main_ordreTable()
{
    int taille = 6;
    int tableauOrdre[6] = {6,1,5,2,4,3};

    lire(tableauOrdre, taille);

    ordreTableau(tableauOrdre, taille);

    lire(tableauOrdre, taille);
}

void ordreTableau(int table[], int taille)
{
    int i, j, r = 0;
    for(i=0; i<taille; i++)
    {
        for(j=i; j<taille; j++)
        {
            if(table[i] > table[j])
            {
                r = table[i];
                table[i] = table[j];
                table[j] = r;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void stringCopy(char chaine1[], char chaine2[])
{
    int i = 0;
    
    while(chaine1[i] != 0)
    {
        chaine2[i] = chaine1[i];
        i++;
    }

    while(chaine2[i] != 0)
    {
        chaine2[i] = 0;
        i++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int stringComparaison(char chaine1[], char chaine2[])
{
    int i = 0, j = 0;
    while(chaine1[i] != 0 && chaine2 !=0 && j == 0)
    {
        if (chaine1[i] == chaine2[i]) {
            i++;
        }
        else if(chaine1[i] != chaine2[i] && i != 0)
        {
            j = i+1;
        }
        else if(chaine1[i] != chaine2[i] && i == 0)
        {
            j = 1;
        }
    }

    return j;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int comp_len_main()
{
    char *a = "Salut";
    char *b = "Hello";

    printf("Le retour de la fonction est : %d \n",comp_len(a, b));
    return 0;
}

int comp_len (char *a, char *b)
{
    int lenA = 0;
    int lenB = 0;
    int oui = 0;
    int non = 1;

    while (a[lenA] != '\0'){
        lenA += 1;
    }

    while (b[lenB] != '\0'){
        lenB += 1;
    }
    if (lenA == lenB){
        return (oui);
        comp_letter(a, b, lenA);
    } else {
        return(non);
    }
}

int comp_letter (char *a, char *b, int lenA)
{
    int oui = 0;
    int non = 1;
    int i = 0;

    for(i = 0; i < lenA; i++){
        if (a[i] == b[i]){
            return (oui);
        }
        else {
            return(non);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main_nbr_de_caract()
{
    char *a = "Hello";
    int b = 0;
    b = nbr_de_caract(a);
    printf("%d\n", b);
    return 0;
}

int nbr_de_caract(char * a)
{
    int nbr = 0;

    while(a[nbr] != '\0'){
        printf("c = %c\n", a[nbr]);
        nbr += 1;
    }
    return (nbr);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informationJoueur()
{
    Personne joueur[100];
    int nbrJoueur, i = 0;
    
    printf("Combien de joueurs ? : ");
    scanf("%d", &nbrJoueur);

    for(i=0; i<nbrJoueur; i++)
    {
        printf("Quel est le pseudo du joueur %d? \n", i+1);
        scanf("%s", joueur[i].pseudo);

        printf("Quel est l'age du joueur %d? \n", i+1);
        scanf("%d", &joueur[i].age);

        printf("Quel est le sexe du joueur %d? \n", i+1);
        scanf("%s", joueur[i].sexe);
    }

    
    for(i=0; i<nbrJoueur; i++)
    {
        printf("Le pseudo du joueur %d est %s\n", i+1, joueur[i].pseudo);
        printf("Le joueur %d a %d ans\n", i+1, joueur[i].age);
        printf("Le joueur %d est un(e) %s\n", i+1, joueur[i].sexe);
    }
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void creerUnPoint()
{
    Coordonnees point1 = {1, 1};
    Coordonnees *ppoint1 = &point1;

    printf("x = %d\ny = %d\n", point1.x, point1.y);

    initialiserLesCoordonnees(ppoint1);

    printf("x = %d\ny = %d\n", point1.x, point1.y);
}

void initialiserLesCoordonnees(Coordonnees *point)
{
    (*point).x = 0;
    point->y = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reglageVolume()
{
    Volume musique = Moyen;
    
    if (musique == Faible) {
        printf("Volume a %d%%", musique);
    }
    else if (musique == Moyen) {
        printf("Volume a %d%%", musique);
    }
    else if (musique == Fort) {
        printf("Volume a %d%%", musique);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//fonction renvoyant le nom du fichier ouvert 
FILE *ouvrir()
{
    FILE *fichier = NULL;
    fichier = fopen("fichier.txt", "r+");
    
    
    if (fichier != NULL) {
        printf("Le fichier c'est bien ouvert\n");
        return fichier;
    }
    else {
        printf("Erreur : le fichier test.txt ne c'est pas ouvert");
    }
}


void ecrire(FILE *fichier)
{
    fputs("Ecriture avec fputs", fichier);
    fprintf(fichier,"\nEcriture avec fprintf");
}


void lireCaractere(FILE *fichier)
{
    int charActuel = 0;
        
        do
        {
            charActuel = fgetc(fichier);
            printf("%c", charActuel);
        } while (charActuel != EOF);
}


void lirePhrase(FILE *fichier)
{
    char chaine[TAILLE_MAX] = "";
    char *i = fgets(chaine, TAILLE_MAX, fichier);

    while(i != NULL){
        printf("%s", chaine);
        i = fgets(chaine, TAILLE_MAX, fichier);
    }
    
}

// lis deux nombre séparés d'un espace
//probleme !!
void lireScore(FILE *fichier)
{
    int score[1] = {0};

    fscanf(fichier, "%d %d", &score[0], &score[1]);
    printf("Les scores sont : %d %d\n", score[0], score[1]);
}

void fermer(FILE *fichier)
{
    fclose(fichier);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void demanderAgeAmis()
{
    int nbrAmis = 0, i = 0;
    int *ageAmis = NULL;

    printf("combien d'amis avez vous ?\n");
    scanf("%d", &nbrAmis);

    ageAmis = malloc(nbrAmis * sizeof(int));

    for(i = 0; i < nbrAmis; i++)
    {
        printf("Quel age a l'ami numero %d ? ", i+1);
        scanf("%d", &ageAmis[i]);
    }
    
    printf("\n\n");

    for(i = 0; i < nbrAmis ; i++)
    {
        printf("L'amis %d a %d ans\n", i+1, ageAmis[i]);
    }
    
    free(ageAmis);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void lireSaisi(char* chaine, int taille)
{
    char* position = NULL;
    
    if (fgets(chaine, taille, stdin) != NULL)
    {
        position = strchr(chaine, '\n');

        if (position != NULL)
        {
            *position = '\0';
        }
        else
        {
            char c = 0;

            while (c != '\n' && c != EOF)
            {
                c = getchar();
            }  
        }
    }
    else 
    {
        char c = 0;

            while (c != '\n' && c != EOF)
            {
                c = getchar();
            }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

