#include "Tester.h"

int main() {
    //Tester::executeExamples();
    /*UnDirectedGraph graph;
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
*/
    DirectedGraph graph;
    graph.insertVertex("1");
    graph.insertVertex("2");
    graph.insertVertex("3");
    graph.insertVertex("4");
    graph.createEdge("1", "2", 8);
    graph.createEdge("2", "3", 1);
    graph.createEdge("3", "1", 4);
    graph.createEdge("4", "3", 9);
    graph.createEdge("4", "2", 2);
    graph.createEdge("1", "4", 1);
    FloydWarshall floyd(graph);
    return 0;
}