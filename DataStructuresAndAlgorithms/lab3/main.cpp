#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

class Graph {
private:
    int vertices;                              
    std::vector<std::vector<int>> adjMatrix;    
    std::vector<std::vector<int>> adjList;      
    std::vector<char> vertexLetters;            

public:

    Graph(int v) : vertices(v) {
        adjMatrix.resize(v, std::vector<int>(v, 0));
        adjList.resize(v);
        vertexLetters.resize(v, ' ');
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; 
        adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void displayIncidenceMatrix() {
        std::cout << "Incidence Matrix:\n   ";
        for (int i = 0; i < vertices; ++i)
            std::cout << std::setw(2) << i << " ";
        std::cout << "\n";

        for (int i = 0; i < vertices; ++i) {
            std::cout << std::setw(2) << i << " ";
            for (int j = 0; j < vertices; ++j) {
                std::cout << std::setw(2) << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void displayAdjList() {
        std::cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }

    void assignLetters(const std::string& letters) {
        for (int i = 0; i < vertices && i < letters.length(); ++i) {
            vertexLetters[i] = letters[i];
        }
    }

    void BFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        q.push(start);
        visited[start] = true;

        std::cout << "\nBFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << vertexLetters[node] << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }
};

int main() {
    int vertices = 12;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 6);
    g.addEdge(6, 9);
    g.addEdge(7, 11);
    g.addEdge(8, 9);
    g.addEdge(9, 10);

    std::string letters = "JAKUNINSANDR";
    g.assignLetters(letters);

    g.displayIncidenceMatrix();
    g.displayAdjList();

    std::cout << "\nInitial BFS Traversal:\n";
    g.BFS(0);

    std::string rearrangedLetters = "ANDREJSJAKUNI";
    g.assignLetters(rearrangedLetters);

    std::cout << "\nBFS Traversal After Rearrangement:\n";
    g.BFS(0);

    return 0;
}