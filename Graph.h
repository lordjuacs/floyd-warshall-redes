#ifndef FLOYD_WARSHALL_GRAPH_H
#define FLOYD_WARSHALL_GRAPH_H

#include "utilityTypes.h"


class Graph {
protected:
    umap<id_t, vertex_t *> vertexes;
    int totEdges = 0;
public:

    Graph() {}

    virtual ~Graph() {}

    virtual bool insertVertex(id_t id) = 0;

    virtual bool createEdge(id_t id1, id_t id2, weight_t w) = 0;

    virtual bool deleteVertex(id_t id) = 0;

    virtual bool deleteEdge(id_t id1, id_t id2) = 0;

    virtual void clear() = 0;

    virtual void display() = 0;

    virtual bool findVertex(id_t id) = 0;


};


#endif //FLOYD_WARSHALL_GRAPH_H
