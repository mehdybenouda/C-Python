#include <stdio.h>
#include <locale.h>

struct Personne {
    char nom[30];
    char prenom[30];
    char sexe;
    int age;
};

struct Billet {
    float prix;
    double prixReduit;
};

int main() {
    setlocale(LC_ALL, "fr_FR.UTF-8"); // Définit le paramètre régional en français avec le codage UTF-8

    struct Personne personne;
    struct Billet billet = { 0 }; // Initialise billet avec des valeurs nulles

    // Saisie des informations de la personne
    printf("Entrez votre sexe (\"M\" ou \"F\"): ");
    scanf_s(" %c", &personne.sexe, (unsigned int)sizeof(personne.sexe));

    printf("Entrez votre âge: ");
    scanf_s("%d", &personne.age);

    printf("Entrez votre nom: ");
    scanf_s("%s", personne.nom, (unsigned int)sizeof(personne.nom));

    printf("Entrez votre prénom: ");
    scanf_s("%s", personne.prenom, (unsigned int)sizeof(personne.prenom));

    // Calcul de la réduction en fonction de l'âge et du sexe
    if (personne.age < 26) {
        if (personne.sexe == 'M' || personne.sexe == 'm') {
            billet.prixReduit = 0.7; // 30% de réduction pour les hommes de moins de 26 ans
        }
        else if (personne.sexe == 'F' || personne.sexe == 'f') {
            billet.prixReduit = 0.6; // 40% de réduction pour les femmes de moins de 26 ans
        }
    }
    else {
        if (personne.sexe == 'M' || personne.sexe == 'm') {
            billet.prixReduit = 0.85; // 15% de réduction pour les hommes de plus de 26 ans
        }
        else if (personne.sexe == 'F' || personne.sexe == 'f') {
            billet.prixReduit = 0.8; // 20% de réduction pour les femmes de plus de 26 ans
        }
    }

    double reduction = 100 - billet.prixReduit * 100; // Calcul du pourcentage de réduction

    // Saisie du prix du billet
    printf("Entrez le prix du billet: ");
    scanf_s("%f", &billet.prix);

    // Calcul du prix réduit
    billet.prixReduit = billet.prix * billet.prixReduit;

    // Affichage des informations de la personne et du billet
    printf("Bonjour %s, voici vos informations détaillées:\n", (personne.sexe == 'M' || personne.sexe == 'm') ? "Monsieur" : "Madame");
    printf("Sexe: %c\n", personne.sexe);
    printf("Âge: %d ans\n", personne.age);
    printf("Nom: %s\n", personne.nom);
    printf("Prénom: %s\n", personne.prenom);
    printf("Réduction: %.2f%%\n", reduction);
    printf("Prix réduit du billet: %.2f\n", billet.prixReduit);

    return 0;
}
