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

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include "TGrafo_dijkstra.hpp"

void preencher_grafos(TGrafo& g1, TGrafo& g2);
void print_vertices(const std::vector<int>& v);
void testDijkstra(TGrafo& g, int n, int origem, const char* titulo);

#endif
