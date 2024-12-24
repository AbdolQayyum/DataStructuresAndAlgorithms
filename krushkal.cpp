#include <iostream>

#define I 32767  // Infinity
#define V 7  // Number of vertices in Graph
#define E 9  // Number of edges in Graph

using namespace std;

// Function to print the Minimum Cost Spanning Tree
void PrintMCST(int T[][V-1], int A[][E]) {
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    int sum = 0;
    for (int i = 0; i < V - 1; i++) {
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
        sum += A[2][i]; // Add the edge cost to the total sum
    }
    cout << "\nTotal Cost of MST: " << sum << endl;
}

// Union operation for the disjoint-set (union-find)
void Union(int u, int v, int s[]) {
    if (s[u] < s[v]) {
        s[u] += s[v]; // Union by rank
        s[v] = u;
    } else {
        s[v] += s[u]; // Union by rank
        s[u] = v;
    }
}

// Find operation with path compression
int Find(int u, int s[]) {
    if (s[u] < 0) return u;
    s[u] = Find(s[u], s);  // Path compression
    return s[u];
}

// Kruskal's Minimum Cost Spanning Tree (MCST) algorithm
void KruskalsMCST(int A[3][E]) {
    int T[2][V - 1];  // Solution array to store the MST edges
    int track[E] = {0};  // Track edges that are included in the MST
    int set[V + 1] = {-1, -1, -1, -1, -1, -1, -1, -1};  // Array for union-find
    
    int i = 0;
    while (i < V - 1) {
        int min = I;
        int u = 0;
        int v = 0;
        int k = 0;

        // Find the minimum cost edge not yet included in the MST
        for (int j = 0; j < E; j++) {
            if (track[j] == 0 && A[2][j] < min) {
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }

        // Check if adding this edge would form a cycle
        if (Find(u, set) != Find(v, set)) {
            T[0][i] = u;
            T[1][i] = v;
            Union(Find(u, set), Find(v, set), set);  // Union the sets
            i++;
        }

        track[k] = 1;  // Mark the edge as included
    }

    PrintMCST(T, A);  // Print the MST
}

int main() {
    int edges[3][E] = {
        {1, 1, 2, 2, 3, 4, 4, 5, 5},  // u vertices
        {2, 6, 3, 7, 4, 5, 7, 6, 7},  // v vertices
        {25, 5, 12, 10, 8, 16, 14, 20, 18}  // Edge weights
    };

    KruskalsMCST(edges);  // Call Kruskal's algorithm to find the MST

    return 0;
}

