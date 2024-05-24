// 211358486
// danielsamson10@gmail.com

#include "Graph.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    vector<vector<int>> g;
    size_t Graph::getsize() const
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
    int Graph::countWeights() const
    {
        int n = this->getsize(), count = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (this->getWeight(i, j) != 0)
                    count++;
            }
        }
        return count;
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

        for (size_t i = 0; i < n; i++)
        {
            if (graph[i].size() != n)
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        g = graph;
    }
    std::string Graph::printGraph() const
    {
        string p = "";
        int n = this->getsize();
        for (size_t i = 0; i < n; i++)
        {
            p += "[";
            for (size_t j = 0; j < n; j++)
            {
                p += to_string(this->getWeight(i, j));
                if (j != n - 1)
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

        int n = this->getsize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
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

        int n = this->getsize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
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
    bool isSubgraph(const Graph& g1, const Graph& g2) const{
        if (g1.getsize() > g2.getsize()) {
            return false;
        }

        size_t g2Size = g2.getsize();
        size_t g1Size = g1.getsize();
        
            
        // Iterate through all possible sizes of subgraphs of g2
        for (size_t size = g2Size; size >= g1Size; --size) {
            // Iterate through all possible starting positions in g2
            for (size_t row = 0; row <= g2Size - size; ++row) {
                for (size_t col = 0; col <= g2Size - size; ++col) {
                    bool isSub = true;
                    // Check if the subgraph matches g1
                    for (size_t i = 0; i < g1Size; ++i) {
                        for (size_t j = 0; j < g1Size; ++j) {
                            if (g1.getWeight(i, j) != g2.getWeight(row + i, col + j)) {
                                isSub = false;
                                break;
                            }
                        }
                        if (!isSub) break;
                    }
                    // If the subgraph matches g1, return true
                    if (isSub) {
                        return true;
                    }
                }
            }
        }

        // If no matching subgraph is found, return false
        return false;
    }
    bool Graph::operator>(const Graph &g) const //need to change
    {
        if (Graph::isSubgraph(*this, g)) {
            return true; 
        }
        if (this->countWeights() != g.countWeights()) {
            return this->countWeights() > g.countWeights();
        }
        return this->getsize() > g.getsize(); 
    }

    bool Graph::operator>=(const Graph &g) const //need to change
    {
        if (*this > g)
            return true;
        else
            return false;
    }

    bool Graph::operator<(const Graph &g) const //what happend if its equal?
    {
        return !(*this > g);
    }

    bool Graph::operator<=(const Graph &g) const //need to change
    {
        return false;
    }

    bool Graph::operator==(const Graph &g) const
    {
        if (this->getsize() != g.getsize())
            return false;
        else
        {
            for (size_t i = 0; i < this->getsize(); i++)
            {
                for (size_t j = 0; j < this->getsize(); j++)
                    if (this->getWeight(i, j) != g.getWeight(i, j))
                        return false;
            }
        }
        return true;
    }
    bool Graph::operator!=(const Graph &g)
    {
        return !(*this == g);
    }
    Graph Graph::operator++()
    {
        for (size_t i = 0; i < this->getsize(); i++)
        {
            for (size_t j = 0; j < this->getsize(); j++)
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
        for (size_t i = 0; i < this->getsize(); i++)
        {
            for (size_t j = 0; j < this->getsize(); j++)
            {
                if (this->getWeight(i, j) != 0)
                    this->setWeight(i, j, this->getWeight(i, j) + 1);
            }
        }
        return copy;
    }
    Graph Graph::operator--()
    {
        for (size_t i = 0; i < this->getsize(); i++)
        {
            for (size_t j = 0; j < this->getsize(); j++)
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
        for (size_t i = 0; i < this->getsize(); i++)
        {
            for (size_t j = 0; j < this->getsize(); j++)
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

        int n = this->getsize();

        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                int new_weight = 0;
                for (size_t k = 0; k < n; k++)
                {
                    new_weight += this->getWeight(i, k) * g.getWeight(k, j);
                }
                result.setWeight(i, j, new_weight);
            }
        }
        return result;
    }
    Graph operator*(Graph &g, int num)
    {
        int n = g.getsize();
        // Loop through each pair of nodes and sum their weights
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
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
        if (g1.getsize() != g2.getsize())
            throw invalid_argument("The two Graph are with different size");
    }
}
