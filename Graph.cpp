// 211358486
// danielsamson10@gmail.com

#include "Graph.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    vector<vector<int>> g;
    size_t Graph::getSize()
    {
        return g.size();
    }
    int Graph::getWeight(size_t u, size_t v) const
    {
        return this->g[u][v];
    }
    void Graph::setWeight(size_t i, size_t j, int weight)
    {
        this->g[i][j] = weight;
    }

    Graph Graph::operator+(const Graph &g)
    {
        // Check_Error_Graph(g,this_g)

        Graph result = *this; // Copy of the original Graph

        int n = this->getSize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                int new_weight = this->getWeight(i, j) + g.getWeight(i, j);
                result.setWeight(i, j, new_weight);
            }
        }

        return result;
    }

    Graph Graph::operator+() // unari
    {
        return *this;
    }

    void Graph::operator+=(const Graph &g2)
    {
        *this = *this + g2;
    }

    Graph Graph::operator-(const Graph &g2)
    {
        return Graph();
    }

    Graph Graph::operator-() // unari
    {

        return *this=*this * (-1);
    }

    void Graph::operator-=(const Graph &g2)
    {
        *this = *this - g2;
    }

    bool Graph::operator>(const Graph &g2) const
    {
        return false;
    }

    bool Graph::operator>=(const Graph &g2) const
    {
        return false;
    }

    bool Graph::operator<(const Graph &g2) const
    {
        return false;
    }

    bool Graph::operator<=(const Graph &g2) const
    {
        return false;
    }

    bool Graph::operator==(const Graph &g2)
    {
        return false;
    }

    bool Graph::operator!=(const Graph &g2)
    {
        return false;
    }

    Graph Graph::operator++()
    {
        return Graph();
    }

    Graph Graph::operator++(int)
    {
        return Graph();
    }

    Graph Graph::operator--()
    {
        return Graph();
    }
    Graph Graph::operator--(int)
    {
        return Graph();
    }
    Graph Graph::operator*(const Graph &g2)
    {
        Graph result = *this;
        
        int n = this->getSize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                int new_weight = this->getWeight(i, j) * g2.getWeight(i, j);
                result.setWeight(i, j, new_weight);
            }
        }
        return result;
    }

    // Graph Graph::operator*(int num)
    // {
    //     return Graph();
    // }
    Graph operator*(Graph &g, int num)
    {
        // return g = g * num;
    }
    void Graph::operator*=(const Graph &g2)
    {
        *this = *this * g2;
    }

    void Graph::operator*=(int num)
    {
        //  Graph result = *this; // Copy of the original Graph

        int n = this->getSize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                int new_weight = this->getWeight(i, j) * num;
                this->setWeight(i, j, new_weight);
            }
        }
    }

    std::vector<int> Graph::getNeighbors(int v) const
    {
        vector<int> check(g.size(), -1);
        if (v < 0 || static_cast<size_t>(v) > g.size())
        {
            throw std::out_of_range("Vertex index out of range");
        }
        for (size_t i = 0; i < g.size(); i++)
        {
            if (g[(size_t)v][i] != 0)
                check[i] = i;
        }
        return check;
    }
    void Graph::loadGraph(const vector<vector<int>> &graph)
    {
        size_t n = graph.size();
        if (n == 0)
        {
            throw invalid_argument("Invalid graph: Empty graph.");
        }

        for (size_t i = 0; i < n; ++i)
        {
            if (graph[i].size() != n)
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        g = graph;
    }
    std::string Graph::printGraph()
    {
         string p = "";
    int n=this->getSize();
    for (size_t row = 0; row < n; row++) {
        p += "[";
        for (size_t col = 0; col < n; col++) {
            p += to_string(this->getWeight(row, col));
            if(col!=n-1)
            p+=", ";
            
        }
        p += "]\n";
    }
    return p;
    }
}
