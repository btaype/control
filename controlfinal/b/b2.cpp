#include <iostream>
#include <vector>
#include <set>

using namespace std;


struct Edge {
    int u, v;

    Edge(int a, int b) : u(a), v(b) {}
};


set<int> greedyCover(vector<Edge>& edges) {
    set<int> cover;  

    while (!edges.empty()) {

        Edge currentEdge = edges.back();
        edges.pop_back();

    
        cover.insert(currentEdge.u);
        cover.insert(currentEdge.v);

      
        auto it = remove_if(edges.begin(), edges.end(), [&](const Edge& e) {
            return e.u == currentEdge.u || e.u == currentEdge.v || e.v == currentEdge.u || e.v == currentEdge.v;
            });

        edges.erase(it, edges.end());
    }

    return cover;
}

int main() {
  
    vector<Edge> edges = { {1, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6} };

    set<int> minimalCover = greedyCover(edges);

   
    cout << "Recubrimiento minimal: ";
    for (int node : minimalCover) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
