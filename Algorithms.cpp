//211358486
//danielsamson10@gmail.com
#include "Algorithms.hpp"
#include <climits>
#include <queue> 
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <unordered_map>


using namespace std;
namespace ariel{

    void DFS(int v, vector<bool>& visited, ariel::Graph& graph) {
        visited[(size_t)v] = true;
        vector<int> neighbors = graph.getNeighbors(v);
        int n = neighbors.size();
        for (size_t i = 0; i < neighbors.size(); ++i) {
            if (!visited[static_cast<size_t>(neighbors[i])]) {
                DFS(static_cast<size_t>(neighbors[i]), visited, graph);
            }
        }
    }
    void DFSReverse(int v, vector<bool>& visited, ariel::Graph& graph) {
        visited[(size_t)v] = true;
        vector<int> reverseNeighbors = graph.getReverseNeighbors(v);
         int n = reverseNeighbors.size();
        for (size_t i = 0; i < reverseNeighbors.size(); ++i) {
            if (!visited[static_cast<size_t>(reverseNeighbors[i])]) {
                DFSReverse(static_cast<size_t>(reverseNeighbors[i]), visited, graph);
            }
        }
    }
    
    static bool isConnected(Graph& graph) {
        size_t V = graph.getsize();
        
        // Perform DFS traversal from each vertex
        vector<bool> visited(V, false);
        DFS(0, visited, graph);

        // Check if all vertices are reachable from the first vertex
        bool connectedFromFirst = true;
        for (size_t i = 0; i < V; ++i) {
            if (!visited[i]) {
                connectedFromFirst = false;
                break;
            }
        }
        
        // If not connected from the first vertex, no need to check for strong connectivity
        if (!connectedFromFirst) {
            return 0;
        }

        // Reset visited array
        visited.assign((size_t)V, false);

        // Check if all vertices can reach the first vertex
        DFSReverse(0, visited, graph);
        bool connectedToFirst = true;
        for (size_t i = 0; i < V; ++i) {
            if (!visited[i]) {
                connectedToFirst = false;
                break;
            }
        }
        
        // If connected from and to the first vertex, graph is strongly connected
        if (connectedFromFirst && connectedToFirst) {
            return 1;
        } else {
            return 0;
        }
    }
    bool detectCycleDFS(int v, vector<bool>& visited, vector<bool>& recStack, const Graph& g) {
        if (!visited[(size_t)v]) {
            visited[(size_t)v] = true; // Mark the current node as visited
            recStack[(size_t)v] = true; // Add it to the recursion stack

            // Recur for all adjacent vertices
            vector<int> neighbors = g.getNeighbors(v);
            for (size_t i = 0; i < neighbors.size(); ++i) {
                if (!visited[i] && detectCycleDFS(i, visited, recStack, g)) {
                    return true; // If the adjacent vertex is not visited and there is a cycle
                } else if (recStack[i]) {
                    return true; // If the adjacent vertex is already in the recursion stack, there is a cycle
                }   
            }
        }
        recStack[(size_t)v] = false; // Remove the vertex from the recursion stack before returning
        return false; // If no cycle is found from this vertex, return false
    }
    static bool isDirectedGraph(Graph& g) {
        // Iterate through each vertex in the graph
        for (int v = 0; v < g.getsize(); ++v) {
            // Get the neighbors of the current vertex
            std::vector<int> neighbors = g.getNeighbors(v);
            // Iterate through the neighbors
            for (int neighbor : neighbors) {
                // Check if the current vertex is also a neighbor of its neighbor
                std::vector<int> reverseNeighbors = g.getReverseNeighbors(neighbor);
                if (std::find(reverseNeighbors.begin(), reverseNeighbors.end(), v) == reverseNeighbors.end()) {
                    // If the current vertex is not a neighbor of its neighbor, the graph is directed
                    return true;
                }
            }
        }
        // If no such case is found, the graph is undirected
        return false;
    }
    static std::string shortestPath(Graph& g, int start, int end) {
            // Check if the graph is directed
            bool isDirected = isDirectedGraph(g); // Assuming the graph is undirected by default
            // Insert logic to determine if the graph is directed or not

            // Check if there is a negative cycle
            if (Algorithms::negativeCycle(g)) {
                return "Negative cycle detected. Shortest path cannot be determined.";
            }

            // Initialize distances with infinity
            size_t V = g.getsize();
            std::vector<int> dist(V, std::numeric_limits<int>::max());
            dist[(size_t)start] = 0; // Distance from start node to itself is 0

            // Priority queue to store vertices based on their distances
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
            pq.push({0, start}); // Push the start node with distance 0

            // Array to store the shortest path
            std::vector<int> parent(V, -1);

            // Dijkstra's algorithm
            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();

                // Visit each neighbor of u
                for (int v : g.getNeighbors(u)) {
                    int weight = g.getWeight((size_t)u,(size_t) v);
                    if (dist[(size_t)u] != std::numeric_limits<int>::max() && dist[(size_t)u] + weight < dist[(size_t)v]) {
                        dist[(size_t)v] = dist[(size_t)u] + weight;
                        parent[(size_t)v] = u;
                        pq.push({dist[(size_t)v], v});
                    }
                }
            }

            // Construct the shortest path
            std::string shortestPath;
            for (int v = end; v != -1; v = parent[(size_t)v]) {
                shortestPath = std::to_string(v) + " -> " + shortestPath;
            }

            return shortestPath;
    }
    bool Algorithms::isContainsCycle(Graph g) {
        // First, check if the graph contains a negative cycle
        if (negativeCycle(g)) {
            return true; // If there's a negative cycle, there's definitely a cycle in the graph
        }

        // If no negative cycle is found, perform cycle detection using DFS
        vector<bool> visited(g.getsize(), false); // Mark all vertices as not visited
        vector<bool> recStack(g.getsize(), false); // Stack to keep track of the vertices in the current recursion stack

        // DFS function to detect cycles
        

        // Iterate over all vertices to detect cycles
        for (int i = 0; i < g.getsize(); ++i) {
            if (detectCycleDFS(i,visited, recStack, g)) {
                return true; // If cycle is detected, return true
            }
        }

        return false; // If no cycle is detected, return false
    }
    static bool isBipartiteUtil(Graph& g, int src, unordered_map<int, int>& color) {
        // Assign initial color to source vertex
        color[src] = 0;

        // Create a queue for BFS
        queue<int> q;
        q.push(src);

        // Run BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Traverse all adjacent vertices of u
            for (int v : g.getNeighbors(u)) {
                // If v is not colored yet
                if (color.find(v) == color.end()) {
                    // Assign alternate color to this adjacent vertex
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                // If v is already colored and has the same color as u, the graph is not bipartite
                else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        // If no conflicts found, the graph is bipartite
        return true;
    }
    static std::string isBipartite(Graph& g) {
        unordered_map<int, int> color; // Map to store vertex-color pairs

        // Iterate over all vertices to check if the graph is bipartite
        for (int i = 0; i < g.getsize(); ++i) {
            if (color.find(i) == color.end()) {
                // If the current vertex is not colored yet, run BFS from it
                if (!isBipartiteUtil(g, i, color)) {
                    return "Graph is not bipartite.";
                }
            }
        }
        return "Graph is bipartite.";
    }
    static bool negativeCycle(Graph& g) {
        size_t V = g.getsize();

        // Initialize distances with infinity
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Source vertex is at distance 0

        // Relax edges repeatedly
        for (size_t i = 0; i < V - 1; ++i) {
            for (size_t u = 0; u < V; ++u) {
                vector<int> neighbors = g.getNeighbors(u);
                for (size_t j = 0; j < neighbors.size(); ++j) {
                    size_t v = static_cast<size_t>(neighbors[j]); // Ensure that the index is of type size_t
                    int weight = g.getWeight(u, v);
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Check for negative weight cycle
        for (size_t u = 0; u < V; ++u) {
            vector<int> neighbors = g.getNeighbors(u);
            for (size_t j = 0; j < neighbors.size(); ++j) {
                size_t v = static_cast<size_t>(neighbors[j]); // Ensure that the index is of type size_t
                int weight = g.getWeight(u, v);
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    return true; // Negative cycle found
                }
            }
        }

        return false; // No negative cycle found
    }

        
}

