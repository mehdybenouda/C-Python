#include <stdio.h>
#include "film.h"

int main() {
    Catalogue catalogue;
    initialiserCatalogue(&catalogue);

    // Ajout de 10 films
    ajouterFilm(&catalogue, "Inception", "Science-fiction", "Christopher Nolan", 2010, 8.8, "Un voleur spécialisé dans l'extraction d'informations via les rêves est chargé d'implanter une idée dans l'esprit d'une personne.");
    ajouterFilm(&catalogue, "Le Seigneur des Anneaux : La Communauté de l'Anneau", "Aventure", "Peter Jackson", 2001, 8.8, "Frodon, un hobbit, entreprend un voyage pour détruire un anneau magique et ainsi empêcher Sauron de prendre le contrôle de la Terre du Milieu.");
    ajouterFilm(&catalogue, "La Ligne Verte", "Drame", "Frank Darabont", 1999, 8.6, "Un gardien de prison découvre qu'un homme condamné à mort possède un don surnaturel.");
    ajouterFilm(&catalogue, "Pulp Fiction", "Action", "Quentin Tarantino", 1994, 8.9, "Une série d'histoires entrelacées sur la violence et la rédemption.");
    ajouterFilm(&catalogue, "Interstellar", "Science-fiction", "Christopher Nolan", 2014, 8.6, "Un groupe d'explorateurs voyage à travers un trou de ver pour rechercher une nouvelle planète habitable.");
    ajouterFilm(&catalogue, "Indiana Jones et les Aventuriers de l'Arche Perdue", "Aventure", "Steven Spielberg", 1981, 8.4, "L'archéologue Indiana Jones part à la recherche de l'Arche de l'Alliance.");
    ajouterFilm(&catalogue, "Fight Club", "Drame", "David Fincher", 1999, 8.8, "Un homme déçu de sa vie rencontre un mystérieux individu avec qui il crée un club de combats clandestin.");
    ajouterFilm(&catalogue, "Matrix", "Science-fiction", "The Wachowski Brothers", 1999, 8.7, "Un programmeur découvre que le monde dans lequel il vit est en réalité une simulation informatique.");
    ajouterFilm(&catalogue, "Star Wars : Épisode V - L'Empire contre-attaque", "Science-fiction", "Irvin Kershner", 1980, 8.7, "L'Alliance rebelle lutte contre l'Empire galactique dans cette suite de Star Wars.");
    ajouterFilm(&catalogue, "The Dark Knight : Le Chevalier Noir", "Action", "Christopher Nolan", 2008, 9.0, "Batman affronte le Joker, un criminel psychotique qui souhaite semer le chaos à Gotham City.");

    // Recherche d'un film par titre
    char titreRecherche[MAX_TITRE];
    printf("Entrez le titre du film que vous recherchez : ");
    scanf_s("%s", titreRecherche, (unsigned int)sizeof(titreRecherche));
    rechercherFilmParTitre(&catalogue, titreRecherche);

    return 0;
}
