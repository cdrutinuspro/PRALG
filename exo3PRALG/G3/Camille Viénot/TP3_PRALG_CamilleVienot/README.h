// // // Remarque 1 :
// A la place d'utiliser le std::reverse
// on aurait pu modifier directement l'operateur
// en changeant le > par <
// le retour aurait ete decroissant directement

// au regard de l'enoncé et de "en utilisant les iterateurs"
// j'ai supposé que la méthode demandé etait celle que j'ai mis en place

// // // Remarque 2 :
// il est demandé dans l'énoncé de mettre en place un seul compteur
// le resulat de la requete de tri par note en terme de compteur d'operation
// est donc par consequent
// la somme du tri par nom (qui pointe vers le meme pointeur)
// et la somme du tri par note
// et non pas le nombre d'operation du tri par note uniquement

// Si mon intepretation de l'enonce est fausse
// alors ce qu'il aurait fallu faire etait 2 initialisations
// de 2 compteurs différents
// pour que le tri par nom et le tri par note
// pointent vers 2 compteurs distincts
