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
//     ariel::ariel::Graph g1;
//     // 3x3 matrix that represents a connected ariel::Graph.
//     vector<vector<int>> ariel::Graph = {
//         {0, 0, 0, 0},
//         {0, 0, 0, 0},
//         {0, 0, 0, 3},
//         {0, 0, 2, 3}};
//     g1.loadGraph(ariel::Graph); // Load the ariel::Graph to the object.

//     cout << g1 << endl; // Should print the matrix of the ariel::Graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

//     // 3x3 matrix that represents a weighted connected ariel::Graph.
//     vector<vector<int>> weightedGraph = {
//         {0, 3},
//         {2, 3},
//     };
//     ariel::ariel::Graph g2;
//     g2.loadGraph(weightedGraph); // Load the ariel::Graph to the object.
//     cout << g2 << endl;

//     cout << (g1 < g2) << endl;
//     // ariel::ariel::Graph g3 = g1 + g2; // Add the two graphs together.
//     // cout<<g3;           // Should print the matrix of the ariel::Graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

//     // // g1 *= -2;        // Multiply the ariel::Graph by -2.
//     // cout<<g1; // Should print the matrix of the ariel::Graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

//     // // g1 /= -2;
//     // ariel::ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
//     // cout<<endl;
//     // cout<<g4;           // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]

//     // // 5x5 matrix that represents a connected ariel::Graph.
//     // vector<vector<int>> graph2 = {
//     //     {0, 1, 0, 0, 1},
//     //     {1, 0, 1, 0, 0},
//     //     {0, 1, 0, 1, 0},
//     //     {0, 0, 1, 0, 1},
//     //     {1, 0, 0, 1, 0}};
//     // ariel::ariel::Graph g5;
//     // g5.loadGraph(graph2); // Load the ariel::Graph to the object.
//     // try
//     // {
//     //     ariel::ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
//     // }
//     // catch (const std::invalid_argument &e)
//     // {
//     //     cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
//     // }
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