#ifndef FLOYD_WARSHALL_DIRECTEDGRAPH_H
#define FLOYD_WARSHALL_DIRECTEDGRAPH_H

#include "Graph.h"
/////////////////////////////////////////
#define diGraph_t DirectedGraph
/////////////////////////////////////////

class DirectedGraph : public graph_t {
private:
    friend
    class FloydWarshall;
public:
    DirectedGraph();

    ~DirectedGraph();

    bool insertVertex(id_t id) override;

    bool createEdge(id_t id1, id_t id2, weight_t w) override;

    bool deleteVertex(id_t id) override;

    bool deleteEdge(id_t id1, id_t id2) override;

    bool findVertex(id_t id) override;

    void clear() override;

    void display() override;

};

diGraph_t::DirectedGraph() : Graph() {
}

diGraph_t::~DirectedGraph() {
    if (this->vertexes.size() != 0)
        clear();
}

bool diGraph_t::insertVertex(id_t id) {
    if (!findVertex(id)) {
        vertex_t *v = new vertex_t;
        v->id = id;
        this->vertexes[id] = v;
        return true;
    }
    return false;
}

bool diGraph_t::createEdge(id_t id1, id_t id2, weight_t w) {
    if (id1 == id2)
        return false;
    if (!findVertex(id1) || !findVertex(id2))
        return false;
    auto edges = this->vertexes[id1]->edges;
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        if ((*it)->vertexes[0].id == id2 || (*it)->vertexes[1].id == id2)
            return false;
    }
    vertex_t *v = new vertex_t[2];
    v[0] = *this->vertexes.at(id1);
    v[1] = *this->vertexes.at(id2);
    edge_t *edge = new edge_t(v, w);
    this->vertexes.at(id1)->edges.push_back(edge);
    this->totEdges++;
    return true;
}

bool diGraph_t::deleteVertex(id_t id) {
    if (!findVertex(id))
        return false;
    for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
        if (it->first != id) {
            for (auto it2 = (it->second)->edges.begin(); it2 != (it->second)->edges.end(); ++it2) {
                if ((*it2)->vertexes[0].id == id || (*it2)->vertexes[1].id == id) {
                    (*it2)->killSelf();
                    (it->second)->edges.erase(it2);
                    this->totEdges--;
                    break;
                }
            }
        }
    }
    this->vertexes[id]->edges.clear();
    this->vertexes.erase(id);
    return true;
}

bool diGraph_t::deleteEdge(id_t id1, id_t id2) {
    if (id1 == id2)
        return false;
    if (!findVertex(id1))
        return false;
    auto &edges = this->vertexes[id1]->edges;
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        if ((*it)->vertexes[0].id == id2 || (*it)->vertexes[1].id == id2) {
            (*it)->killSelf();
            edges.erase(it);
            this->totEdges--;
            return true;
        }
    }
    return false;
}

void diGraph_t::clear() {
    for (auto it_vertex: this->vertexes) {
        for (auto it_edge: (*it_vertex.second).edges) {
            (*it_edge).killSelf();
        }
        (*it_vertex.second).killSelf();
    }
    this->vertexes.clear();
}

bool diGraph_t::findVertex(id_t id) {
    return this->vertexes.find(id) != this->vertexes.end();
}

void diGraph_t::display() {
    for (auto it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
        std::cout << it->second->id << ": ";
        for (auto it2 = it->second->edges.begin(); it2 != it->second->edges.end(); ++it2) {
            auto val = (*it2)->vertexes[0].id;
            if ((*it2)->vertexes[0].id == it->second->id)
                val = (*it2)->vertexes[1].id;
            std::cout << val << '(' << (*it2)->weight << ')';
            if (*it2 != *it->second->edges.rbegin())
                std::cout << ", ";
        }
        std::cout << std::endl;
    }
}


#endif //FLOYD_WARSHALL_DIRECTEDGRAPH_H
