#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph {
    int numVertices;
    unordered_map<char, list<char>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
    }

    void addEdge(char from, char to) {
        adjList[from].push_back(to);
    }

    void BFS(char start, char destination) {
        unordered_map<char, bool> visited;
        unordered_map<char, char> parent;
        queue<char> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal Order: " << endl;

        bool found = false;
        while (!q.empty()) {
            char current = q.front();
            q.pop();
            cout << current << " ";

            if (current == destination) {
                found = true;
                break;
            }

            for (char neighbor : adjList[current]) {
                if (!visited[neighbor]) { // Fix: Correct variable spelling
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;

        if (found) {
            // Reconstruct the shortest path
            cout << "Shortest Path using BFS (by edges) from " << start << " to " << destination << ": ";
            stack<char> path;
            char temp = destination;

            while (temp != start) {
                path.push(temp);
                temp = parent[temp];
            }
            path.push(start);

            while (!path.empty()) {
                cout << path.top();
                path.pop();
                if (!path.empty()) cout << " -> ";
            }
            cout << endl;
        } else {
            cout << "No path found from " << start << " to " << destination << endl;
        }
    }

    // DFS 
    void DFS(char start) {
        unordered_map<char, bool> visited;
        stack<char> s;

        s.push(start);
        cout << "DFS Traversal Order: ";

        while (!s.empty()) {
            char current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            // Add neighbors to the stack manually
            for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'F');
    g.addEdge('D', 'C');
    g.addEdge('D', 'F');
    g.addEdge('E', 'F');

    cout << "BFS Shortest Path Search from A to F:" << endl;
    g.BFS('A', 'F');
    cout << endl;

    cout << "DFS Exploration from A:" << endl;
    g.DFS('A');

    return 0;
}

