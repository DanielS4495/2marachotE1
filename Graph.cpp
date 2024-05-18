// 211358486
// danielsamson10@gmail.com

#include "Graph.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    vector<vector<int>> g;
    size_t Graph::getSize() const
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
    std::string Graph::printGraph() const
    {
        string p = "";
        int n = this->getSize();
        for (size_t row = 0; row < n; row++)
        {
            p += "[";
            for (size_t col = 0; col < n; col++)
            {
                p += to_string(this->getWeight(row, col));
                if (col != n - 1)
                    p += ", ";
            }
            p += "]\n";
        }
        return p;
    }
    Graph Graph::operator+(const Graph &g)
    {
        CHECK_FOR_SIZE(*this, g);

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

    void Graph::operator+=(const Graph &g)
    {
        *this = *this + g;
    }

    Graph Graph::operator-(const Graph &g)
    {
        CHECK_FOR_SIZE(*this, g);

        Graph result = *this; // Copy of the original Graph

        int n = this->getSize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                int new_weight = this->getWeight(i, j) - g.getWeight(i, j);
                result.setWeight(i, j, new_weight);
            }
        }

        return result;
    }

    Graph Graph::operator-() // unari
    {

        return *this = *this * (-1);
    }

    void Graph::operator-=(const Graph &g)
    {
        *this = *this - g;
    }

    bool Graph::operator>(const Graph &g) const
    {
        return false;
    }

    bool Graph::operator>=(const Graph &g) const
    {
        return false;
    }

    bool Graph::operator<(const Graph &g) const
    {
        return false;
    }

    bool Graph::operator<=(const Graph &g) const
    {
        return false;
    }

    bool Graph::operator==(const Graph &g) const
    {
        if (this->getSize() != g.getSize())
            return false;
        else
        {
            for (size_t i = 0; i < this->getSize(); i++)
            {
                for (size_t j = 0; j < this->getSize(); j++)
                    if (this->getWeight(i, j) != g.getWeight(i, j))
                        return false;
            }
        }
        return true;
    }
    // bool operator==(const Graph &g1, const Graph &g2)
    // {
    //     if (g1.getSize() != g2.getSize())
    //         return false;
    //     else
    //     {
    //         bool flag = true;
    //         for (size_t i = 0; i < g1.getSize(); i++)
    //         {
    //             for (size_t j = 0; j < g1.getSize(); j++)
    //                 if (g1.getWeight(i, j) != g2.getWeight(i, j))
    //                     flag = false;
    //         }
    //         return flag;
    //     }
    // }
    bool Graph::operator!=(const Graph &g)
    {
        return !(*this == g);
    }
    Graph Graph::operator++()
    {
        for (size_t i = 0; i < this->getSize(); i++)
        {
            for (size_t j = 0; j < this->getSize(); j++)
            {
                if (this->getWeight(i, j) != 0)
                    this->setWeight(i, j, this->getWeight(i, j) + 1);
            }
        }
        return *this;
    }

    Graph Graph::operator++(int)
    {
        Graph copy = *this;
        for (size_t i = 0; i < this->getSize(); i++)
        {
            for (size_t j = 0; j < this->getSize(); j++)
            {
                if (this->getWeight(i, j) != 0)
                    this->setWeight(i, j, this->getWeight(i, j) + 1);
            }
        }
        return copy;
    }
    Graph Graph::operator--()
    {
        for (size_t i = 0; i < this->getSize(); i++)
        {
            for (size_t j = 0; j < this->getSize(); j++)
            {
                if (this->getWeight(i, j) != 0)
                    this->setWeight(i, j, this->getWeight(i, j) - 1);
            }
        }
        return *this;
    }
    Graph Graph::operator--(int)
    {
        Graph copy = *this;
        for (size_t i = 0; i < this->getSize(); i++)
        {
            for (size_t j = 0; j < this->getSize(); j++)
            {
                if (this->getWeight(i, j) != 0)
                    this->setWeight(i, j, this->getWeight(i, j) - 1);
            }
        }
        return copy;
    }
    Graph Graph::operator*(const Graph &g)
    {
        CHECK_FOR_SIZE(*this, g);
        Graph result = *this;

        int n = this->getSize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                int new_weight = this->getWeight(i, j) * g.getWeight(i, j);
                result.setWeight(i, j, new_weight);
            }
        }
        return result;
    }
    Graph operator*(Graph &g, int num)
    {
        int n = g.getSize();
        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                int new_weight = g.getWeight(i, j) * num;
                g.setWeight(i, j, new_weight);
            }
        }
        return g;
    }
    Graph operator*(int num, Graph &g)
    {
        return g * num;
    }
    void Graph::operator*=(const Graph &g)
    {
        *this = *this * g;
    }
    void Graph::operator*=(int num)
    {
        *this = *this * num;
    }
    // istream &operator>>(istream &in, const Graph &g)
    // {
    //     // TODO: insert return statement here
    //     return in;
    // }
    ostream &operator<<(ostream &out, const Graph &g)
    {
        // TODO: insert return statement here
        string s = "";
        s = g.printGraph();
        return out << s;
    }
    void CHECK_FOR_SIZE(const Graph &g1, const Graph &g2)
    {
        if (g1.getSize() != g2.getSize())
            throw invalid_argument("The two Graph are with different size");
    }
}
