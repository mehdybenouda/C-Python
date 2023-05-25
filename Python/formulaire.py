class Personne:
    def __init__(self, nom, prenom, sexe, age):
        self.nom = nom
        self.prenom = prenom
        self.sexe = sexe
        self.age = age


class Billet:
    def __init__(self, prix):
        self.prix = prix
        self.prix_reduit = 0.0


def main():
    personne = saisir_informations_personne()  # Saisie des informations de la personne
    billet = saisir_informations_billet()  # Saisie des informations du billet

    calculer_reduction(personne, billet)  # Calcul de la réduction applicable
    reduction = calculer_pourcentage_reduction(billet.prix_reduit)  # Calcul du pourcentage de réduction

    afficher_informations(personne, billet, reduction)  # Affichage des informations


def saisir_informations_personne():
    nom = input("Entrez votre nom: ")
    prenom = input("Entrez votre prénom: ")
    sexe = input("Entrez votre sexe (M ou F): ")
    age = int(input("Entrez votre âge: "))

    return Personne(nom, prenom, sexe, age)  # Création et retour de l'objet Personne


def saisir_informations_billet():
    prix = float(input("Entrez le prix du billet: "))

    return Billet(prix)  # Création et retour de l'objet Billet


def calculer_reduction(personne, billet):
    if personne.age < 26:  # Si l'âge de la personne est inférieur à 26 ans
        if personne.sexe.upper() == "M":
            billet.prix_reduit = 0.7  # Réduction de 30% pour les hommes de moins de 26 ans
        elif personne.sexe.upper() == "F":
            billet.prix_reduit = 0.6  # Réduction de 40% pour les femmes de moins de 26 ans
    else:
        if personne.sexe.upper() == "M":
            billet.prix_reduit = 0.85  # Réduction de 15% pour les hommes de 26 ans et plus
        elif personne.sexe.upper() == "F":
            billet.prix_reduit = 0.8  # Réduction de 20% pour les femmes de 26 ans et plus


def calculer_pourcentage_reduction(prix_reduit):
    return 100 - prix_reduit * 100  # Calcul du pourcentage de réduction


def afficher_informations(personne, billet, reduction):
    genre = "Monsieur" if personne.sexe.upper() == "M" else "Madame"  # Détermination du genre en fonction du sexe

    print(f"Bonjour {genre}, voici vos informations détaillées:")
    print(f"Sexe: {personne.sexe}")
    print(f"Âge: {personne.age} ans")
    print(f"Nom: {personne.nom}")
    print(f"Prénom: {personne.prenom}")
    print(f"Réduction: {reduction:.2f}%")
    print(f"Prix réduit du billet: {billet.prix_reduit:.2f}")


if __name__ == "__main__":
    main()  # Appel de la fonction principale
