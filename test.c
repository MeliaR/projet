#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Définition de la structure utilisateur
// Cette structure contient les informations de l'utilisateur : nom, points, date et heure de connexion.
struct utilisateur {
    char nom[50];   // Nom de l'utilisateur
    int points;     // Points accumulés par l'utilisateur
    char date[20];  // Date de la dernière connexion (format : YYYY-MM-DD)
    char heure[20]; // Heure de la dernière connexion (format : HH:MM:SS)
};

// Fonction pour effectuer une addition
// Elle génère deux nombres aléatoires, demande à l'utilisateur le résultat et vérifie sa réponse.
void addtion(int a, int b, int *points) {
    int res;
    int i = 1;
    while((a + b) != res && i < 4){   // Permet de calculer le nombre d'essais, il n'y a que trois essais
        printf("%d + %d = ?\n", a, b);
        printf("Entrez le resultat : ");
        scanf("%d", &res);
        printf("Vous avez entré %d\n", res);
        i ++;
    }
    // On regarde combien d'essais a été utilisé et donne les points en fonction
    if(i == 1){ 
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 10 points !!\n", i);
        (*points) = (*points) + 10; // Incrémente les points en cas de bonne réponse
    }
    else if(i == 2){
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 5 points !!\n", i);
        (*points) = (*points) + 5;
    }
    else if(i == 3){
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 1 point !!\n", i);
        (*points) ++;
    }
    else{
        printf("Vous n'avez pas trouvé le bon résulat qui est : %d et vous ne gagnez pas de point. \n", a + b);
    }
}

// Fonction pour effectuer une multiplication
void multiplication(int a, int b, int *points) {
    int res;
    int i = 1;
    while((a * b) != res && i < 4){   // Permet de calculer le nombre d'essais, il n'y a que trois essais
        printf("%d * %d = ?\n", a, b);
        printf("Entrez le resultat : ");
        scanf("%d", &res);
        printf("Vous avez entré %d\n", res);
        i ++;
    }
    // On regarde combien d'essais a été utilisé et donne les points en fonction 
    if(i == 1){ 
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 10 points !!\n", i);
        (*points) = (*points) + 10; // Incrémente les points en cas de bonne réponse
    }
    else if(i == 2){
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 5 points !!\n", i);
        (*points) = (*points) + 5;
    }
    else if(i == 3){
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 1 point !!\n", i);
        (*points) ++;
    }
    else{
        printf("Vous n'avez pas trouvé le bon résulat qui est : %d et vous ne gagnez pas de point. \n", a + b);
    }
}

// Fonction pour effectuer une soustraction
void soustraction(int a, int b, int *points) {
    int res;
    int i = 1;
    if (a < b) { // Permet de toujours soustraire le plus grand nombre par le plus petit
        int z = a;
        a = b;
        b = z;
    }
    while((a - b) != res && i < 4){   // Permet de calculer le nombre d'essais, il n'y a que trois essais
        printf("%d - %d = ?\n", a, b);
        printf("Entrez le resultat : ");
        scanf("%d", &res);
        printf("Vous avez entré %d\n", res);
        i ++;
    }
    // On regarde combien d'essais a été utilisé et donne les points en fonction 
    if(i == 1){ 
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 10 points !!\n", i);
        (*points) = (*points) + 10; // Incrémente les points en cas de bonne réponse
    }
    else if(i == 2){
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 5 points !!\n", i);
        (*points) = (*points) + 5;
    }
    else if(i == 3){
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 1 point !!\n", i);
        (*points) ++;
    }
    else{
        printf("Vous n'avez pas trouvé le bon résulat qui est : %d et vous ne gagnez pas de point. \n", a + b);
    }
}

// Fonction pour travailler sur les tables de multiplication
void tables_multi(int a, int *points) {
    int res;
    int res1;
    int erreur = 0;
    for (int i = 0; i <= 10; i++) { // Boucle pour afficher la table de multiplications
        printf("%d * %d = %d \n", a, i, a * i);
    }
    printf("\n");
    for (int i = 0; i <= 10; i++) { // Boucle pour afficher et demander les résultats des multiplications
        res = a * i;
        printf("%d * %d = ", a, i);
        scanf("%d", &res1); // L'utilisateur entre sa réponse
        if (res == res1) { // Vérification de la réponse
            printf("Gagné\n");
        } else {
            printf("Perdu\n");
            erreur ++;
        }
    }
    // on regarde le nombre d'erreur et on met les points en fonction
    if(erreur == 0){
        printf("Vous avez eu tout bon, vous gagnez 10 points ! \n");
        (*points) = (*points) + 10;
    }
    else if(erreur == 2){
        printf("Vous avez fait 2 erreurs, vous gagnez 5 points ! \n");
        (*points) = (*points) + 5;
    }
    else if (erreur == 3){
        printf("Vous avez fait 3 erreurs, vous gagnez 1 point ! \n");
        (*points) ++;
    }
    else{
        printf("Vous ne gagnez pas de point car il y eu plus de 3 erreurs. \n");
    }
}

// Fonction pour effectuer une division
void division(int a, int b, int *points) {
    int res;
    int i = 1;
    if (a < b) { // Permet d'éviter les divisions où le résultat serait une fraction
        int z = a;
        a = b;
        b = z;
    }
    while((a / b) != res && i < 4){   // Permet de calculer le nombre d'essais, il n'y a que trois essais
        printf("%d / %d = ?\n", a, b);
        printf("Entrez le resultat : ");
        scanf("%d", &res);
        printf("Vous avez entré %d\n", res);
        i ++;
    }
    // On regarde combien d'essais a été utilisé et donne les points en fonction 
    if(i == 1){ 
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 10 points !!\n", i);
        (*points) = (*points) + 10; // Incrémente les points en cas de bonne réponse
    }
    else if(i == 2){
        printf("Bravo, vous avez réussi du %d coup et vous gagnez 5 points !!\n", i);
        (*points) = (*points) + 5;
    }
    else if(i == 3){
        printf("Bravo, vous avez réussi du %d coup vous gagnez 1 point !!\n", i);
        (*points) ++;
    }
    else{
        printf("Vous n'avez pas trouvé le bon résulat qui est : %d et vous ne gagnez pas de point. \n", a + b);
    }
}

int main(void) {
    struct utilisateur user; // Création d'une instance de la structure utilisateur

    // Ouverture du fichier contenant les données des utilisateurs
    FILE *fichier = fopen("utilisateurs.txt", "a+");
    if (fichier == NULL) { // Vérification que le fichier s'est ouvert correctement
        printf("Erreur d'ouverture du fichier.");
        return 1; // Fin du programme en cas d'erreur
    }

    // Demande du nom d'utilisateur à la connexion
    printf("Entrez votre nom d'utilisateur : ");
    scanf("%s", user.nom);

    // Recherche de l'utilisateur dans le fichier pour récupérer ses données existantes
    fseek(fichier, 0, SEEK_SET); // Repositionne le curseur au début du fichier
    char ligne[256];
    int utilisateur_trouve = 0; // Indicateur pour savoir si l'utilisateur existe déjà dans le fichier

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) { 
        char nom_fichier[50];
        
        /* sscanf permet de lire les données formatées dans une chaîne.
           Ici, on extrait les informations sur l'utilisateur depuis une ligne du fichier. */
        sscanf(ligne, "%[^,],%d,%[^,],%s", nom_fichier, &user.points, user.date, user.heure);

        /* strcmp compare deux chaînes de caractères.
           Si elles sont identiques (retourne 0), cela signifie que l'utilisateur existe déjà. */
        if (strcmp(nom_fichier, user.nom) == 0) {
            utilisateur_trouve = 1; 
            break; 
        }
    }

    // Si l'utilisateur n'est pas trouvé dans le fichier, initialiser ses points à 0.
    if (!utilisateur_trouve) {
        user.points = 0;
        strcpy(user.date, "N/A"); // Initialise la date et l'heure si aucune donnée n'existe.
        strcpy(user.heure, "N/A");
    }

    // Mise à jour de la date et de l'heure actuelles pour cette session.
    time_t now = time(NULL); 
   
    /* localtime convertit un timestamp en une structure `tm` contenant des informations sur la date et l'heure. */
    struct tm *t = localtime(&now); 

    /* strftime formate la date et l'heure sous forme de chaîne selon un format donné.
      Ici "%Y-%m-%d" correspond au format Année-Mois-Jour et "%H:%M:%S" au format Heure:Minute:Seconde. */
    strftime(user.date, sizeof(user.date), "%Y-%m-%d", t); 
    strftime(user.heure, sizeof(user.heure), "%H:%M:%S", t);

    // Affiche les informations actuelles de l'utilisateur.
    printf("Bienvenue %s! Dernière connexion : %s à %s. Points actuels : %d\n",  user.nom, user.date, user.heure, user.points);

    int choix;
    int a, b;
    do{
        //Menue pricipal avec les options de jeu 
        printf(" +-------------------------------+ \n");
        printf(" |1 : Addition                   | \n");
        printf(" |2 : Soustraction               | \n");
        printf(" |3 : Multiplications            | \n");
        printf(" |4 : Tables des multiplications | \n");
        printf(" |5 : Divisions                  | \n");
        printf(" |6 : Jeu des opérations         | \n");
        printf(" |0 : Sortir du jeu              | \n");
        printf(" +-------------------------------+ \n");
        printf(" Quel est votre choix ? ");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                break;
            case 1:
                printf("Addition \n");
                a = rand() % 101;
                b = rand() % 100 + 1;
                addtion(a, b, &user.points);
                break;
            case 2:
                printf("Soustraction \n");
                a = rand() % 101;
                b = rand() % 100 + 1;
                soustraction(a, b, &user.points);
                break;
            case 3:
                printf("Multiplications \n");
                a = rand() % 10 + 1;
                b = rand() % 10 + 1;
                multiplication(a, b, &user.points);
                break;
            case 4:
                printf("Tables de Multiplications \n");
                printf("Quel tables de multiplications veux-tu travailler de 1 à 10 : ");
                scanf("%d", &a);
                tables_multi(a, &user.points);
                break;
            case 5:
                printf("Divisions \n");
                a = rand() % 10 + 1;
                b = rand() % 10 + 1;
                division(a, b, &user.points);
                break;
            case 6:
                printf("Jeu des opérations \n");
                
            default:
                printf("Erreur : le choix doit être compris entre 0 et 5 \n");
        }
    } while (choix != 0);

    printf("Merci de votre visite. Vous avez gagné %d points.\n", user.points);

    // Mise à jour ou ajout de l'utilisateur dans le fichier
    fseek(fichier, 0, SEEK_SET);
    FILE *temp = tmpfile();
    int utilisateur_mis_a_jour = 0;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char nom_fichier[50];
        sscanf(ligne, "%[^,]", nom_fichier);
        if (strcmp(nom_fichier, user.nom) == 0) {
            fprintf(temp, "%s,%d,%s,%s\n", user.nom, user.points, user.date, user.heure);
            utilisateur_mis_a_jour = 1;
        } else {
            fputs(ligne, temp);
        }
    }
    if (!utilisateur_mis_a_jour) {
        fprintf(temp, "%s,%d,%s,%s\n", user.nom, user.points, user.date, user.heure);
    }

    fclose(fichier);
    fichier = fopen("utilisateurs.txt", "w");
    rewind(temp);
    while (fgets(ligne, sizeof(ligne), temp) != NULL) {
        fputs(ligne, fichier);
    }

    fclose(fichier);
    fclose(temp);

    return 0;
}