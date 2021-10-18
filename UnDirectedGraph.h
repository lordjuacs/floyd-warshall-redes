#ifndef FLOYD_WARSHALL_UNDIRECTEDGRAPH_H
#define FLOYD_WARSHALL_UNDIRECTEDGRAPH_H


#include "Graph.h"
/////////////////////////////////////////
#define undiGraph_t UnDirectedGraph
/////////////////////////////////////////

class UnDirectedGraph : public Graph {
private:
    friend
    class FloydWarshall;
public:
    UnDirectedGraph();

    ~UnDirectedGraph();

    bool insertVertex(id_t id) override;

    bool createEdge(id_t id1, id_t id2, weight_t w) override;

    bool deleteVertex(id_t id) override;

    bool deleteEdge(id_t id1, id_t id2) override;

    bool findVertex(id_t id) override;

    void clear() override;

    void display() override;

};

undiGraph_t::UnDirectedGraph():Graph() {
}

undiGraph_t::~UnDirectedGraph() {
    if (!this->vertexes.empty())
        clear();
}

bool undiGraph_t::insertVertex(id_t id) {
    if (!findVertex(id)) {
        vertex_t *v = new vertex_t;
        v->id = id;
        this->vertexes[id] = v;
        return true;
    }
    return false;
}

bool undiGraph_t::createEdge(id_t id1, id_t id2, weight_t w) {
    //si son los mismos
    if (id1 == id2)
        return false;
    //si alguno no existe
    if (!findVertex(id1) || !findVertex(id2))
        return false;
    auto edges = this->vertexes[id1]->edges;
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        //si la arista ya existe
        if ((*it)->vertexes[0].id == id2 || (*it)->vertexes[1].id == id2)
            return false;
    }
    vertex_t *v = new vertex_t[2];
    v[0] = *this->vertexes.at(id1);
    v[1] = *this->vertexes.at(id2);
    edge_t *edge = new edge_t(v, w);
    this->vertexes.at(id1)->edges.push_back(edge);
    this->vertexes.at(id2)->edges.push_back(edge);
    this->totEdges++;
    return true;
}

bool undiGraph_t::deleteVertex(id_t id) {
    if (!findVertex(id))
        return false;
    auto &edges = this->vertexes[id]->edges;
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        auto &other_edges = (*it)->vertexes[0].id != id ? this->vertexes[(*it)->vertexes[0].id]->edges
                                                        : this->vertexes[(*it)->vertexes[1].id]->edges;
        for (auto it2 = other_edges.begin(); it2 != other_edges.end(); ++it2) {
            if ((*it)->vertexes[0].id == id || (*it)->vertexes[1].id == id) {
                (*it2)->killSelf();
                other_edges.erase(it2);
                break;
            }
        }
    }
    edges.clear();
    this->vertexes.erase(id);
    return true;
}

bool undiGraph_t::deleteEdge(id_t id1, id_t id2) {
    if (id1 == id2)
        return false;
    if (!findVertex(id1))
        return false;
    auto &edges = this->vertexes[id1]->edges;
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        if ((*it)->vertexes[0].id == id2 || (*it)->vertexes[1].id == id2) {
            auto &other_edges = (*it)->vertexes[0].id != id1 ? this->vertexes[(*it)->vertexes[0].id]->edges
                                                             : this->vertexes[(*it)->vertexes[1].id]->edges;
            for (auto it2 = other_edges.begin(); it2 != other_edges.end(); ++it2) {
                if ((*it2)->vertexes[0].id == id1 || (*it2)->vertexes[1].id == id1) {
                    (*it2)->killSelf();
                    other_edges.erase(it2);
                    this->totEdges--;
                }
                edges.erase(it);
                return true;
            }
        }
    }
    return false;
}

void undiGraph_t::clear() {
    uset<edge_t *> deleted;
    for (auto &it_vertex: this->vertexes) {
        for (auto &it_edge: it_vertex.second->edges) {
            if (deleted.find(it_edge) == deleted.end()) {
                it_edge->killSelf();
                deleted.insert(it_edge);
            }
        }
        //it_vertex.second->edges.clear();
    }
    for (auto &it_vertex: this->vertexes)
        if (it_vertex.second != nullptr) {
            it_vertex.second->killSelf();
            it_vertex.second = nullptr;
        }
    this->vertexes.clear();
    deleted.clear();
}


bool undiGraph_t::findVertex(id_t id) {
    return this->vertexes.find(id) != this->vertexes.end();
}


void undiGraph_t::display() {
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



#endif //FLOYD_WARSHALL_UNDIRECTEDGRAPH_H
