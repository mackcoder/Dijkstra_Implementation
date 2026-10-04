/**
 * Implementação:
 * Algoritmo de Dijkstra (Grupo do Projeto)
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

// |!| Como compilar: g++ -Wall -o program dijsktraMain.cpp TGrafo_Dijkstra.cpp dijkstra_utils.cpp
// Executar (cmd): programa.exe
// Executar (powershell): ./programa.exe

#include <stdio.h>
#include "TGrafo_dijkstra.hpp"
#include "utils_dijkstra.hpp"

int main(){
    TGrafo g1(5);   // grafo do material da aula
    TGrafo g2(4);   // grafo da atividade anterior
    preencher_grafos(g1, g2);

    // Teste 1: grafo do material da aula
    testDijkstra(g1, 5, 0, "TESTE 1 - Grafo do Material da Aula - origem 1");

    // Teste 2: grafo da atividade solicitada
    testDijkstra(g2, 4, 0, "TESTE 2 - Grafo da Atividade Solicitada - origem 1");

    // Teste 3 com origem em 3 - Grafo material da aula
    testDijkstra(g1, 5, 2, "TESTE 3 - G1, origem 3");

    // Teste 4 com origem em 4 - Grafo da atividade solicitada

    testDijkstra(g2, 4, 3, "TESTE 4 - G2, origem 4");

    return 0;
}
