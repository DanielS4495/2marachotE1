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
        int countWeights() const;
        bool isSubgraph(const Graph& g1, const Graph& g2) const;

    public:
        void loadGraph(const vector<vector<int>> &graph);
        std::string printGraph() const;
        size_t getsize() const;
        std::vector<int> getNeighbors(int v) const;
        int getWeight(size_t u, size_t v) const;

        Graph operator+(const Graph &g);

        Graph operator+(); // unari

        void operator+=(const Graph &g);

        Graph operator-(const Graph &g);

        Graph operator-(); // unari

        void operator-=(const Graph &g);

        /* comparison operators Declarations */
        bool operator>(const Graph &g) const;

        bool operator>=(const Graph &g) const;

        bool operator<(const Graph &g) const;

        bool operator<=(const Graph &g) const;

        bool operator==(const Graph &g) const;

        // friend bool operator==(const Graph &g1, const Graph &g2);

        bool operator!=(const Graph &g);

        /* Increment operations Declarations */
        Graph operator++();
        Graph operator++(int);

        /* Decrement operations Declarations */
        Graph operator--();
        Graph operator--(int);

        /* Multiplication operations Declarations */
        Graph operator*(const Graph &g);

        // Graph operator*(int num);

        friend Graph operator*(int num, Graph &g);

        friend Graph operator*(Graph &g, int num);

        void operator*=(const Graph &g);

        void operator*=(int num);

        // friend istream &operator>>(istream &in, const Graph &g);
        friend ostream &operator<<(ostream &out, const Graph &g);

        friend void CHECK_FOR_SIZE(const Graph &g1, const Graph &g2);

        // friend pair<double, double> sum_of_Graph(const Graph &g1, const Graph &g2);
    };
}