#include <stdio.h>
#include "node.h"


int main() {

    Node node; 
// Étape 1 : Lire le graphe à partir du fichier binaire
readingmap2readbin("andorra.csv.bin", &Node);

// Étape 2 : Mettre en place l'algorithme A*
AStarPath PathData[GraphOrder];

// Étape 3 : Exécuter l'algorithme A*
unsigned node_start = FindNodeByName(Graph, 'A');
unsigned node_goal = FindNodeByName(Graph, 'B');
bool result = AStar(Graph, PathData, GraphOrder, node_start, node_goal);

if (result) {
    // Étape 4 : Afficher le chemin résultant
    PrintOptimalPath(Graph, PathData, node_start, node_goal);
} else {
    printf("Pas de chemin trouvé.\n");
}

}
