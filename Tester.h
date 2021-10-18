#ifndef FLOYD_WARSHALL_TESTER_H
#define FLOYD_WARSHALL_TESTER_H

#include "UnDirectedGraph.h"
#include "DirectedGraph.h"
#include "FloydWarshall.h"


class Tester {
private:
    static void unDirectedExample();

    static void unDirectedSwitch(UnDirectedGraph &graph, int input);

    static void directedExample();

    static void directedSwitch(DirectedGraph &graph, int input);


public:
    Tester() = default;

    static void executeExamples();

};

void Tester::executeExamples() {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "Build Graph:\n1. UnDirected Graph\n2. Directed Graph\n";
    std::string input;
    while (true) {
        std::cout << "\nChoose:";
        std::cin >> input;
        if (input == "1" || input == "2")
            break;
    }
    input == "1" ? unDirectedExample() : directedExample();
}

void Tester::unDirectedExample() {
    UnDirectedGraph graph;
    int input = 1;
    while (input != 0) {
        std::cout
                << "Options\n1. Add Vertex\t2. Add Edge\t3. Delete Vertex\n4. Delete Edge\t6. Floyd-Warshall\t7. Clear\n0. Finish\nChoose:";
        std::cin >> input;
        if (input == 0)
            break;
        if (input > 15)
            continue;
        unDirectedSwitch(graph, input);
    }
    std::cout << "Finished!\n";
}

void Tester::unDirectedSwitch(UnDirectedGraph &graph, int input) {
    int n;
    switch (input) {
        case 1: {
            std::cout << "1. Add Vertex\n";
            std::cout << "Choose number of vertexes:";
            std::cin >> n;
            id_t id;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id:";
                std::cin >> id;
                if (!graph.insertVertex(id))
                    std::cout << "Vertex already exists!\n";
                else
                    std::cout << "Vertex added!\n";
            }
            std::cout << "\n";
            break;
        }
        case 2: {
            std::cout << "2. Add Edge\n";
            std::cout << "Choose number of edges:";
            std::cin >> n;
            id_t id1, id2;
            weight_t weight;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id (from):";
                std::cin >> id1;
                std::cout << i + 1 << ". id (to):";
                std::cin >> id2;
                std::cout << i + 1 << ". weight:";
                std::cin >> weight;
                if (!graph.createEdge(id1, id2, weight))
                    std::cout << "Edge already exists!\n";
                else
                    std::cout << "Edge added!\n";
            }
            std::cout << "\n";
            break;
        }
        case 3: {
            std::cout << "3. Delete Vertex\n";
            std::cout << "Choose number of vertexes:";
            std::cin >> n;
            id_t id;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id:";
                std::cin >> id;
                if (!graph.deleteVertex(id))
                    std::cout << "Vertex does not exist\n";
                else
                    std::cout << "Vertex deleted!\n";
            }
            std::cout << "\n";
            break;
        }
        case 4: {
            std::cout << "4. Delete Edge\n";
            std::cout << "Choose number of edges:";
            std::cin >> n;
            id_t id1, id2;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id (from):";
                std::cin >> id1;
                std::cout << i + 1 << ". id (to):";
                std::cin >> id2;
                if (!graph.deleteEdge(id1, id2))
                    std::cout << "Edge does not exist!\n";
                else
                    std::cout << "Edge deleted!\n";
            }
            std::cout << "\n";
            break;
        }
        case 5: {
            std::cout << "5. Display\n";
            graph.display();
            std::cout << "\n";
            break;
        }
        case 6: {
            std::cout << "6. Floyd Warshall\n";
            FloydWarshall floyd(graph);
            floyd.displayDistances();
            floyd.displayPaths();
            std::cout << "\n";
            break;
        }
        case 7: {
            std::cout << "7. Clear\n";
            graph.clear();
            std::cout << "Graph cleared!\n\n";
            break;
        }
        default:
            break;
    }
}

void Tester::directedExample() {
    DirectedGraph graph;
    int input = 1;
    while (input != 0) {
        std::cout
                << "Options\n1. Add Vertex\t2. Add Edge\t3. Delete Vertex\n4. Delete Edge\t5. Display\t6. Floyd-Warshall\t7. Clear\n0. Finish\nChoose:";
        std::cin >> input;
        if (input == 0)
            break;
        if (input > 15)
            continue;
        directedSwitch(graph, input);
    }

    std::cout << "Finished!\n";

}

void Tester::directedSwitch(DirectedGraph &graph, int input) {
    int n;
    switch (input) {
        case 1: {
            std::cout << "1. Add Vertex\n";
            std::cout << "Choose number of vertexes:";
            std::cin >> n;
            id_t id;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id:";
                std::cin >> id;
                if (!graph.insertVertex(id))
                    std::cout << "Vertex already exists!\n";
                else
                    std::cout << "Vertex added!\n";
            }
            std::cout << "\n";
            break;
        }
        case 2: {
            std::cout << "2. Add Edge\n";
            std::cout << "Choose number of edges:";
            std::cin >> n;
            id_t id1, id2;
            weight_t weight;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id (from):";
                std::cin >> id1;
                std::cout << i + 1 << ". id (to):";
                std::cin >> id2;
                std::cout << i + 1 << ". weight:";
                std::cin >> weight;
                if (!graph.createEdge(id1, id2, weight))
                    std::cout << "Edge already exists!\n";
                else
                    std::cout << "Edge added!\n";
            }
            std::cout << "\n";
            break;
        }
        case 3: {
            std::cout << "3. Delete Vertex\n";
            std::cout << "Choose number of vertexes:";
            std::cin >> n;
            id_t id;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id:";
                std::cin >> id;
                if (!graph.deleteVertex(id))
                    std::cout << "Vertex does not exist\n";
                else
                    std::cout << "Vertex deleted!\n";
            }
            std::cout << "\n";
            break;
        }
        case 4: {
            std::cout << "4. Delete Edge\n";
            std::cout << "Choose number of edges:";
            std::cin >> n;
            id_t id1, id2;
            for (int i = 0; i < n; ++i) {
                std::cout << i + 1 << ". id (from):";
                std::cin >> id1;
                std::cout << i + 1 << ". id (to):";
                std::cin >> id2;
                if (!graph.deleteEdge(id1, id2))
                    std::cout << "Edge does not exist!\n";
                else
                    std::cout << "Edge deleted!\n";
            }
            std::cout << "\n";
            break;
        }
        case 5: {
            std::cout << "5. Display\n";
            graph.display();
            std::cout << "\n";
            break;
        }

        case 6: {
            std::cout << "6. Floyd Warshall\n";
            FloydWarshall floyd(graph);
            floyd.displayDistances();
            floyd.displayPaths();
            std::cout << "\n";
            break;
        }
        case 7: {
            std::cout << "7. Clear\n";
            graph.clear();
            std::cout << "Graph cleared!\n\n";
            break;
        }
        default:
            break;
    }

}


#endif //FLOYD_WARSHALL_TESTER_H
