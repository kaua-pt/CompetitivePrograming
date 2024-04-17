#include <bits/stdc++.h>

using namespace std;

class Graph
{
    using pii = pair<int, int>;
    vector<vector<pii>> adj;
    int size;

public:
    Graph(int n, vector<vector<int>> &edges) : size(n)
    {
        adj.resize(n);
        for (auto &edge : edges)
            adj[edge[0]].emplace_back(edge[2], edge[1]);
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].emplace_back(edge[2], edge[1]);
    }

    struct CompareFirst
    {
        bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const
        {
            return a.first > b.first; // Retorna true se o primeiro elemento de 'a' for maior que o primeiro elemento de 'b'
        }
    };

    int shortestPath(int node1, int node2)
    {
        priority_queue<pii, vector<pii>, CompareFirst> pq;
        vector<int> dist(size, INT_MAX);
        dist[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (u == node2)
            {
                addEdge({node1, node2, d});
                return d;
            }

            for (auto &edge : adj[u])
            {
                if (dist[edge.second] > dist[u] + edge.first)
                {
                    dist[edge.second] = dist[u] + edge.first;
                    pq.push({dist[edge.second], edge.second});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */