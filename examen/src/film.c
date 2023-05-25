#include <stdio.h>
#include "film.h"

void initialiserCatalogue(Catalogue* catalogue) {
    catalogue->nombreFilms = 0;
}

void ajouterFilm(Catalogue* catalogue, const char* titre, const char* genre, const char* realisateur, int annee, double note, const char* description) {
    if (catalogue->nombreFilms >= MAX_FILMS) {
        printf("Le catalogue est plein. Impossible d'ajouter un nouveau film.\n");
        return;
    }

    Film nouveauFilm;
    strcpy(nouveauFilm.titre, sizeof(nouveauFilm.titre), titre);
    strcpy(nouveauFilm.genre, sizeof(nouveauFilm.genre), genre);
    strcpy(nouveauFilm.realisateur, sizeof(nouveauFilm.realisateur), realisateur);
    nouveauFilm.annee = annee;
    nouveauFilm.note = note;
    strcpy(nouveauFilm.description, sizeof(nouveauFilm.description), description);

    catalogue->films[catalogue->nombreFilms] = nouveauFilm;
    catalogue->nombreFilms++;

    printf("Film ajouté avec succès !\n");
}

void rechercherFilmParTitre(const Catalogue* catalogue, const char* titre) {
    printf("---- Résultats de la recherche ----\n");

    int i;
    for (i = 0; i < catalogue->nombreFilms; i++) {
        const Film* film = &catalogue->films[i];
        if (strcmp(film->titre, titre) == 0) {
            printf("Titre : %s\n", film->titre);
            printf("Genre : %s\n", film->genre);
            printf("Réalisateur : %s\n", film->realisateur);
            printf("Année : %d\n", film->annee);
            printf("Note : %.1f\n", film->note);
            printf("Description : %s\n", film->description);
            printf("\n");
        }
    }
}
