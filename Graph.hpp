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
        bool isSubgraph(const Graph &g1, const Graph &g2) const;

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

        bool operator>(const Graph &g) const;

        bool operator>=(const Graph &g) const;

        bool operator<(const Graph &g) const;

        bool operator<=(const Graph &g) const;

        bool operator==(const Graph &g) const;

        bool operator!=(const Graph &g) const;

        Graph operator++();
        Graph operator++(int);

        Graph operator--();
        Graph operator--(int);

        Graph operator*(const Graph &g);

        friend Graph operator+(int num, Graph &g);

        friend Graph operator+(Graph &g, int num);

        friend Graph operator-(int num, Graph &g);

        friend Graph operator-(Graph &g, int num);

        friend Graph operator*(int num, Graph &g);

        friend Graph operator*(Graph &g, int num);

        void operator*=(const Graph &g);

        void operator*=(int num);

        friend ostream &operator<<(ostream &out, const Graph &g);

        friend void CHECK_FOR_SIZE(const Graph &g1, const Graph &g2);
    };
}