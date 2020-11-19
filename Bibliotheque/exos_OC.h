#ifndef DEF_EXOS_OC_H
#define DEF_EXOS_OC_H

typedef struct Personne Personne;
typedef struct Coordonnees Coordonnees;
typedef enum Volume Volume;


struct Personne
{
    char pseudo[100];
    char sexe[100];
    int age;
};

struct Coordonnees
{
    int x;
    int y;
}; 

enum Volume
{
    Faible = 25, Moyen = 50, Fort = 75
};


void calculImc();
void tableMultiplication();
void menuMcdo();
void plusOuMoins();

void main_convHeure();
void convHeure(int *a, int *b);

void main_copie();
void copie(int a[], int b[], int taille);

void lire(int *tableau, int taille);

void main_max();
void maxTable(int table[], int taille, int max);

void main_ordreTable();
void ordreTableau(int table[], int taille);

void stringCopy(char chaine1[], char chaine2[]);

int stringComparaison(char chaine1[], char chaine2[]);

int comp_len_main();
int comp_len (char *a, char *b);
int comp_letter (char *a, char *b, int lenA);

int main_nbr_de_caract();
int nbr_de_caract(char * a);

void informationJoueur();

void creerUnPoint();
void initialiserLesCoordonnees(Coordonnees *point);

void reglageVolume();

FILE *ouvrir();
void ecrire(FILE *fichier);
void lireCaractere(FILE *fichier);
void lirePhrase(FILE *fichier);
void lireScore(FILE *fichier);
void fermer(FILE *fichier);

void demanderAgeAmis();

void lireSaisi(char* chaine, int taille);
#endif