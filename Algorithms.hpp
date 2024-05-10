//211358486
//danielsamson10@gmail.com
#include "Graph.hpp"
#include <string>
#include <unordered_map>


namespace ariel {
    // namespace Algorithms{
    class Algorithms {
    private:
        void DFS(int v, vector<bool>& visited, vector<vector<int>>& adj);
        void DFSReverse(int v, vector<bool>& visited, ariel::Graph& graph);
        bool detectCycleDFS(int v, vector<bool>& visited, vector<bool>& recStack, const Graph& g);
        static bool isDirectedGraph(const Graph& g);
    public:
        static bool isConnected(Graph g);
        static std::string shortestPath(Graph g, int start, int end);//מחזיר מסלול הקצר ביותר
        static bool isContainsCycle(Graph g);//מחזיר האם קיים מעגל 
        static std::string isBipartite(Graph g);//ומחזיר את החלוקה של הגרף לגרף דו-צדדי 
        static bool negativeCycle(Graph g);//מחזיר האם קיים מעגל עם משקלים שלילים
        static bool isBipartiteUtil(Graph& g, int src, unordered_map<int, int>& color);
        
};
// }
}