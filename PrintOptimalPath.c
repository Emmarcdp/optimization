#include <stdio.h>
#include "node.h"

// Function to print the optimal path
void PrintOptimalPath(AStarPath *PathData, unsigned startNode, unsigned goalNode, node *nodes) {
    unsigned currentNode = goalNode;
    unsigned pathLength = 0;
    unsigned path[100]; // Assuming a maximum path length of 100, you can adjust this number

  // Définir une fonction nommée PrintOptimalPath qui prend quatre paramètres : PathData, un pointeur vers un tableau de structures AStarPath, startNode et goalNode, des entiers non signés représentant respectivement le nœud de départ et le nœud d'arrivée, et nodes, un tableau de structures node contenant des informations sur les nœuds.
// Déclarer ici trois variables non signées : currentNode est initialisée avec le nœud d'arrivée, pathLength est initialisée à zéro, et path est un tableau pouvant contenir jusqu'à 100 éléments. Ce tableau sera utilisé pour stocker le chemin optimal.
    // Backtrack from the goal node to the start node
    while (currentNode != startNode) {
        path[pathLength] = currentNode;
        currentNode = PathData[currentNode].parent;
        pathLength++;
    }

// Cette boucle while effectue une recherche arrière à partir du nœud d'arrivée jusqu'au nœud de départ en utilisant les informations contenues dans PathData. À chaque itération, elle ajoute le nœud actuel (dans currentNode) au tableau path, met à jour currentNode avec le nœud parent et incrémente pathLength pour suivre la longueur du chemin.

  
    // Print the optimal path in reverse order
    printf("Optimal Path from Node %u to Node %u:\n", startNode, goalNode);
    for (int i = pathLength - 1; i >= 0; i--) {
        unsigned nodeIndex = path[i];
        node currentNode = nodes[nodeIndex];

        printf("Node %u (%s) -> ", currentNode.id, currentNode.name);
    }

    // Print the goal node
    printf("Node %u (%s)\n", nodes[goalNode].id, nodes[goalNode].name);
}

int main() {
    // ...
    // Assuming that you have defined AStarPath PathData, unsigned node_start, and unsigned node_goal

    // Call the PrintOptimalPath function
    PrintOptimalPath(PathData, node_start, node_goal, nodes);

    return 0;
}
