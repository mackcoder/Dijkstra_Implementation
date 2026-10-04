/**
 * Implementação:
 * Algoritmo de Dijkstra  (Grupo do Projeto)
 * 
 * Integrantes:
 * |=================================|==========|
 * |               Nome              |    RA    |
 * |---------------------------------|----------|
 * | André Doerner Duarte            | 10427938 |
 * | Matheus Leonardo Cardoso Kroeff | 10426434 |
 * | Naoto Ushizaki                  | 10437445 |
 * |=================================|==========|
 */

#include <iostream>
#include <vector>
#include "TGrafo_dijkstra.hpp"
#include "utils_dijkstra.hpp"

void preencher_grafos(TGrafo& g1, TGrafo& g2) {
    // Criando vertices para G1
    g1.insereA(0, 1, 1);   // 1->2
    g1.insereA(0, 4, 1);   // 1->5
    g1.insereA(1, 2, 1);   // 2->3
    g1.insereA(1, 3, 2);   // 2->4
    g1.insereA(2, 3, 4);   // 3->4
    g1.insereA(2, 4, 2);   // 3->5
    g1.insereA(3, 0, 3);   // 4->1
    g1.insereA(4, 0, 2);   // 5->1
    g1.insereA(4, 3, 1);   // 5->4

    // Montando Grafo g2 da atividade solicitada:
    int pesos[4][4] = {
        { 0, 20, 30, 50},
        {20,  0, 40, 15},
        {30, 40,  0, 15},
        {50, 15, 15,  0}
    };


    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            if(a != b){
                g2.insereA(a, b, pesos[a][b]);
            }
        }
    }
}

void print_vertices(const std::vector<int>& v){
    if(v.empty()){ std::cout << "[]" << std::endl; return; }
    std::cout << "[";
    for(size_t i = 0; i < v.size(); i++){
        std::cout << v[i] + 1;
        if(i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void testDijkstra(TGrafo& g, int n, int origin, const char* titulo){
    std::cout << titulo << " | origem = vertice " << origin + 1 << std::endl;

    std::cout << "\nMatriz de adjacencia:" << std::endl;
    g.show();

    std::vector<std::vector<float>> dist;
    std::vector<int> rot;
    std::vector<int> ordem = g.dijkstra(origin, dist, rot);

    std::cout << "\nOrdem de finalizacao (F): ";
    print_vertices(ordem);

    std::cout << "\nDistancias e rotulos:" << std::endl;
    for(int t = 0; t < n; t++){
        std::cout << "d[" << t + 1 << "] = " << dist.back()[t]
                  << "  | rot[" << t + 1 << "] = "
                  << (rot[t] == -1 ? 0 : rot[t] + 1) << std::endl;
    }

    std::cout << "\nCaminhos minimos:" << std::endl;
    for(int destino = 0; destino < n; destino++){
        std::cout << origin + 1 << " -> " << destino + 1 << ": ";
        print_vertices(g.cam_min(origin, destino));
    }
}
