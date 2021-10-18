#ifndef FLOYD_WARSHALL_FLOYDWARSHALL_H
#define FLOYD_WARSHALL_FLOYDWARSHALL_H

#include "Graph.h"


class FloydWarshall {
private:
    std::vector<std::vector<weight_t>> distance;
    std::vector<std::vector<id_t>> nodes;
    umap<id_t, int> idt_pos;
    umap<int, id_t> pos_idt;

public:
    explicit FloydWarshall(UnDirectedGraph const &graph);

    explicit FloydWarshall(DirectedGraph const &graph);

    ~FloydWarshall();

    void displayDistances();

    void displayPaths();

    void showPath(const id_t& a, id_t b);

};

FloydWarshall::FloydWarshall(const UnDirectedGraph &graph) {
    std::cout << "=========================" << std::endl;
    std::cout << "ALGORITMO FLOYD WARSHALL" << std::endl;
    std::cout << "=========================" << std::endl;

    distance.resize(graph.vertexes.size());
    nodes.resize(graph.vertexes.size());
    int i = 0;
    for (const auto &it : graph.vertexes) {
        idt_pos.insert(std::make_pair(it.first, i));
        pos_idt.insert(std::make_pair(i, it.first));
        distance[i] = std::vector<weight_t>(graph.vertexes.size(), inf);
        nodes[i] = std::vector<id_t>(graph.vertexes.size(), "-");
        i++;
    }

    for (const auto &it: graph.vertexes) {
        for (const auto &it2 : it.second->edges) {
            id_t j = it2->vertexes[0].id != it.first ? it2->vertexes[0].id : it2->vertexes[1].id;
            distance[idt_pos[it.first]][idt_pos[j]] = it2->weight;
            //nodes[idt_pos[it.first]][idt_pos[j]] = j;
        }
        distance[idt_pos[it.first]][idt_pos[it.first]] = 0;
    }
    for (i = 0; i < distance.size(); i++) {
        for (int j = 0; j < distance.size(); j++) {
            nodes[j][i] = pos_idt[i];
        }
    }

    std::cout << "K = 0\n";
    displayDistances();
    displayPaths();

    for (int k = 0; k < graph.vertexes.size(); ++k) {
        for (i = 0; i < graph.vertexes.size(); ++i) {
            for (int j = 0; j < graph.vertexes.size(); ++j) {
                if (distance[i][j] > (distance[i][k] + distance[k][j])) {
                    distance[i][j] = (distance[i][k] + distance[k][j]);
                    //nodes[i][j] = nodes[i][k];
                    nodes[i][j] = pos_idt[k];
                }
            }
        }
        std::cout << "\nK = " << k + 1 << "\n";
        displayDistances();
        displayPaths();

    }
    std::cout << "\n";
    for (i = 0; i < distance.size(); i++) {
        for (int j = 0; j < distance.size(); j++) {
            showPath(pos_idt[i], pos_idt[j]);
        }
        std::cout << "\n";
    }
}


FloydWarshall::FloydWarshall(const DirectedGraph &graph) {
    std::cout << "=========================" << std::endl;
    std::cout << "ALGORITMO FLOYD WARSHALL" << std::endl;
    std::cout << "=========================" << std::endl;

    distance.resize(graph.vertexes.size());
    nodes.resize(graph.vertexes.size());
    int i = 0;
    for (const auto &it : graph.vertexes) {
        idt_pos.insert(std::make_pair(it.first, i));
        pos_idt.insert(std::make_pair(i, it.first));
        distance[i] = std::vector<weight_t>(graph.vertexes.size(), inf);
        nodes[i] = std::vector<id_t>(graph.vertexes.size(), "-");
        i++;
    }
    for (const auto &it: graph.vertexes) {
        for (const auto &it2 : it.second->edges) {
            id_t j = it2->vertexes[0].id != it.first ? it2->vertexes[0].id : it2->vertexes[1].id;
            distance[idt_pos[it.first]][idt_pos[j]] = it2->weight;
            //nodes[idt_pos[it.first]][idt_pos[j]] = j;
        }
        distance[idt_pos[it.first]][idt_pos[it.first]] = 0;

    }
    std::cout << "\n";

    for (i = 0; i < distance.size(); i++) {
        for (int j = 0; j < distance.size(); j++) {
            nodes[j][i] = pos_idt[i];
        }
    }

    std::cout << "K = 0\n";
    displayDistances();
    displayPaths();

    for (int k = 0; k < graph.vertexes.size(); ++k) {
        for (i = 0; i < graph.vertexes.size(); ++i) {
            for (int j = 0; j < graph.vertexes.size(); ++j) {
                if (distance[i][j] > (distance[i][k] + distance[k][j])) {
                    distance[i][j] = (distance[i][k] + distance[k][j]);
                    //nodes[i][j] = nodes[i][k];
                    nodes[i][j] = pos_idt[k];
                }
            }
        }
        std::cout << "K =" << k + 1 << "\n";
        displayDistances();
        displayPaths();
    }
    for (i = 0; i < distance.size(); i++) {
        for (int j = 0; j < distance.size(); j++) {
            showPath(pos_idt[i], pos_idt[j]);
        }
        std::cout << "\n";
    }
}


FloydWarshall::~FloydWarshall() {
    for (int i = 0; i < idt_pos.size(); ++i) {
        distance[i].clear();
        nodes[i].clear();
    }
    distance.clear();
    nodes.clear();

}

void FloydWarshall::displayDistances() {
    std::cout << "MATRIZ DE DISTANCIAS";
    std::cout << "\n \t";
    for (int k = 0; k < pos_idt.size(); ++k)
        std::cout << pos_idt[k] << "\t";
    std::cout << "\n";
    for (int i = 0; i < pos_idt.size(); ++i) {
        std::cout << pos_idt[i] << ":\t";
        for (int j = 0; j < pos_idt.size(); ++j) {
            if (distance[i][j] == inf)
                std::cout << "INF";
            else
                std::cout << distance[i][j];
            std::cout << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}

void FloydWarshall::displayPaths() {
    std::cout << "MATRIZ DE RECORRIDO";
    std::cout << "\n \t";
    for (int k = 0; k < pos_idt.size(); ++k)
        std::cout << pos_idt[k] << "\t";
    std::cout << "\n";
    for (int i = 0; i < pos_idt.size(); ++i) {
        std::cout << pos_idt[i] << ":\t";
        for (int j = 0; j < pos_idt.size(); ++j) {
            if (nodes[i][j].empty())
                std::cout << "-";
            else
                std::cout << nodes[i][j];
            std::cout << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}

void FloydWarshall::showPath(const std::string& a, std::string b) {
    if (distance[idt_pos[a]][idt_pos[b]] == inf) {
        std::cout << "Imposible de llegar a " << b << " desde " << a << "\n";
        return;
    }
    std::vector<id_t> path;
    path.push_back(b);
    std::cout << "Enrutamiento de " << a << " hacia " << b << "\n";

    while (nodes[idt_pos[a]][idt_pos[b]] != b) {
        b = nodes[idt_pos[a]][idt_pos[b]];
        path.push_back(b);
    }
    double total = 0;
    if (a != b)
        path.push_back(a);
    for (auto i = path.size() - 1; i > 0; --i) {
        std::cout << "[" << path[i] << "] -- (" << distance[idt_pos[path[i]]][idt_pos[path[i - 1]]] << ") --> ";
        total += distance[idt_pos[path[i]]][idt_pos[path[i - 1]]];
    }
    std::cout << "[" << path[0] << "]\tTotal: " << total << "\n";
}

#endif //FLOYD_WARSHALL_FLOYDWARSHALL_H
