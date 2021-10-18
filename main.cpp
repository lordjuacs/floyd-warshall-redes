#include "Tester.h"
int main() {
    //Tester::executeExamples();
    UnDirectedGraph graph;
    graph.insertVertex("A");
    graph.insertVertex("B");
    graph.insertVertex("C");
    graph.insertVertex("D");
    graph.insertVertex("E");
    graph.createEdge("A", "B", 2);
    graph.createEdge("A", "C", 1);
    graph.createEdge("A", "D", 4);
    graph.createEdge("C", "D", 2);
    graph.createEdge("B", "D", 3);
    graph.createEdge("B", "E", 4);
    graph.createEdge("D", "E", 2);

    FloydWarshall floyd(graph);
    return 0;
}