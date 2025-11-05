#include <iostream>
#include <vector>
#include <stdexcept>


class Graph {
private:
    int numVertices;
    int numAristas = 0;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    //Crear conexión de u a v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
        numAristas++;

    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {
        return numAristas;//devolver la cantidad de conexiones insertadas
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {

        int indegree = 0;//variable contadora
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
        for (int i = 0; i < numVertices; ++i) { //recorrer la columna del nodo
                if(adjMatrix[i][u] != 0) indegree++; //si el nodo tiene alguna conexión contarla
            }
        }
        return indegree;//regresar el conteo
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {

        int nodo_max = u;//decimos que el máximo es u para comparar si hay alguno más alto
        for (int i = 0; i < numVertices; ++i) { //recorremos cada columna
            if(inDegree(i) > inDegree(u)) nodo_max = i; //de haber uno más grande que u, ese será el nuevo máximo
            //de ser igual, u sigue siendo el máximo
            }
        if(nodo_max != u) return false;//si u no es el máximo devolver falso
        return true;//de no cumplirse lo anterior es cierto

    }
};

