/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{


    // ariel::Graph g;
    // // 3x3 matrix that represents a connected graph.
    // vector<vector<int>> graph = {
    //     {0, 1, 0},
    //     {1, 0, 1},
    //     {0, 1, 0}};
    // g.loadGraph(graph); // Load the graph to the object.

    // g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    // cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    // cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    // cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    // cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    // // 5x5 matrix that represents a non-connected graph with a cycle.
    // vector<vector<int>> graph22 = {
    //     {0, 1, 1, 0, 0},
    //     {1, 0, 1, 0, 0},
    //     {1, 1, 0, 1, 0},
    //     {0, 0, 1, 0, 0},
    //     {0, 0, 0, 0, 0}};

    // g.loadGraph(graph22); // Load the graph to the object.

    // g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    // cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    // cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    // cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).

    // // 5x5 matrix that reprsents a connected weighted graph.
    // vector<vector<int>> graph33 = {
    //     {0, 1, 2, 0, 0},
    //     {1, 0, 3, 0, 0},
    //     {2, 3, 0, 4, 0},
    //     {0, 0, 4, 0, 5},
    //     {0, 0, 0, 5, 0}};
    // g.loadGraph(graph33); // Load the graph to the object.

    // g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    // cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    // cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
    // cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0 -> 1 -> 2 -> 0" (false).
    // cout << Algorithms::isBipartite(g) << endl;        // Should print: "The Graph is not bipartite"

    // // 5x4 matrix that reprsents invalid graph.
    // vector<vector<int>> graph44 = {
    //     {0, 1, 2, 0},
    //     {1, 0, 3, 0},
    //     {2, 3, 0, 4},
    //     {0, 0, 4, 0},
    //     {0, 0, 0, 5}};
    // try
    // {
    //     g.loadGraph(graph44); // Load the graph to the object.
    // }
    // catch (const std::invalid_argument &e)
    // {
    //     cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    // }

 // Test Case 1: Basic Graphs
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 3},
        {0, 0, 2, 3}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 3},
        {0, 1, 2, 3}
    };
    g2.loadGraph(graph2);

    cout << "ariel::Graph g1:\n" << g1 << endl;
    cout << "ariel::Graph g2:\n" << g2 << endl;

    cout << "g1 > g2: " << (g1 > g2) << endl;
    cout << "g1 >= g2: " << (g1 >= g2) << endl;
    cout << "g1 < g2: " << (g1 < g2) << endl;
    cout << "g1 <= g2: " << (g1 <= g2) << endl;
    cout << "g1 == g2: " << (g1 == g2) << endl;
    cout << "g1 != g2: " << (g1 != g2) << endl;

    // Test Case 2: Subgraph
    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 0},
        {2, 3}
    };
    g3.loadGraph(graph3);

    cout << "ariel::Graph g3:\n" << g3 << endl;

    cout << "g1 is subgraph of g2: " << (g1<g2) << endl;
    cout << "g3 is subgraph of g2: " << (g3<g2) << endl;

    // Test Case 3: Identical Graphs
    ariel::Graph g4;
    g4.loadGraph(graph2);

    cout << "ariel::Graph g4:\n" << g4 << endl;

    cout << "g2 == g4: " << (g2 == g4) << endl;
    cout << "g2 != g4: " << (g2 != g4) << endl;

    // Test Case 4: Different Sized Graphs
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 0, 0},
        {0, 0, 3},
        {0, 2, 3}
    };
    g5.loadGraph(graph5);

    cout << "ariel::Graph g5:\n" << g5 << endl;

    cout << "g1 > g5: " << (g1 > g5) << endl;
    cout << "g1 >= g5: " << (g1 >= g5) << endl;
    cout << "g1 < g5: " << (g1 < g5) << endl;
    cout << "g1 <= g5: " << (g1 <= g5) << endl;
    cout << "g1 == g5: " << (g1 == g5) << endl;
    cout << "g1 != g5: " << (g1 != g5) << endl;

    // Test Case 5: Empty ariel::Graph
    ariel::Graph g6;
    cout << "ariel::Graph g6 (empty):\n" << g6 << endl;

    cout << "g1 > g6: " << (g1 > g6) << endl;
    cout << "g1 >= g6: " << (g1 >= g6) << endl;
    cout << "g1 < g6: " << (g1 < g6) << endl;
    cout << "g1 <= g6: " << (g1 <= g6) << endl;
    cout << "g1 == g6: " << (g1 == g6) << endl;
    cout << "g1 != g6: " << (g1 != g6) << endl;

    return 0;
}