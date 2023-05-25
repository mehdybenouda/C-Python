#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#define MAX_TITRE 50
#define MAX_GENRE 20
#define MAX_REALISATEUR 50
#define MAX_DESCRIPTION 200
#define MAX_FILMS 10

typedef struct {
    char titre[MAX_TITRE];
    char genre[MAX_GENRE];
    char realisateur[MAX_REALISATEUR];
    int annee;
    double note;
    char description[MAX_DESCRIPTION];
} Film;

typedef struct {
    Film films[MAX_FILMS];
    int nombreFilms;
} Catalogue;

void initialiserCatalogue(Catalogue* catalogue);
void ajouterFilm(Catalogue* catalogue, const char* titre, const char* genre, const char* realisateur, int annee, double note, const char* description);
void rechercherFilmParTitre(const Catalogue* catalogue, const char* titre);

#endif // FILM_H_INCLUDED
