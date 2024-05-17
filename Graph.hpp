// 211358486
// danielsamson10@gmail.com

#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> g;
        std::vector<std::vector<int>> weights;
        void setWeight(size_t i, size_t j, int weight);

    public:
        void loadGraph(const vector<vector<int>> &graph);
        std::string printGraph();
        size_t getSize();
        std::vector<int> getNeighbors(int v) const;
        int getWeight(size_t u, size_t v) const;

        Graph operator+(const Graph &g);

        Graph operator+(); // unari

        void operator+=(const Graph &g2);

        Graph operator-(const Graph &g2);

        Graph operator-(); // unari

        void operator-=(const Graph &g2);

        /* comparison operators Declarations */
        bool operator>(const Graph &g2) const;

        bool operator>=(const Graph &g2) const;

        bool operator<(const Graph &g2) const;

        bool operator<=(const Graph &g2) const;

        bool operator==(const Graph &g2);

        friend bool operator==(const Graph &g1, const Graph &g2);

        bool operator!=(const Graph &g2);

        /* Increment operations Declarations */
        Graph operator++();
        Graph operator++(int);

        /* Decrement operations Declarations */
        Graph operator--();
        Graph operator--(int);

        /* Multiplication operations Declarations */
        Graph operator*(const Graph &g2);
        
        // Graph operator*(int num);

        friend Graph operator*(int num, Graph &g);

        friend Graph operator*(Graph &g, int num);

        void operator*=(const Graph &g2);

        void operator*=(int num);

        // friend void CHECK_FOR_ERROR(const Graph &g1, const Graph &g2);

        // friend void CHECK_MULTIPLICATION(const Graph &g1, const Graph &g2);

        // friend pair<double, double> sum_of_Graph(const Graph &g1, const Graph &g2);
    };
}