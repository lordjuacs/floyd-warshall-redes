#include <list>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iostream>

struct Edge;
struct Vertex;
class Graph;

/////////////define types////////////////////////
#define umap std::map
#define uset std::unordered_set
#define id_t std::string
#define vertex_t Vertex
#define weight_t double
#define edge_t Edge
#define graph_t Graph

#define inf 999

/////////////structures//////////////////////////
struct Edge {
    vertex_t *vertexes;//dynamic array
    weight_t weight;

    void killSelf() {
        delete this;
    }

    Edge(vertex_t *v, weight_t w) {
        vertexes = v;
        weight = w;
    }
};

struct Vertex {
    id_t id;
    std::list<edge_t *> edges;


    bool operator==(vertex_t other) { return this->id == other.id; }

    bool operator==(vertex_t *other) { return this->id == other->id; }

    void killSelf() {
        delete this;
    }
};



