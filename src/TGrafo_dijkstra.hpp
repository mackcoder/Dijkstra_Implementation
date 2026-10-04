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

/*
Implementação de uma Classe para grafos denominada TGrafo,
usando Matriz de Adjacência
*/
#ifndef ___GRAFO_MATRIZ_ADJACENCIA___
#define ___GRAFO_MATRIZ_ADJACENCIA___

#include <vector>
#include <limits>

// definição de uma estrutura para armezanar um grafo
// Também seria possível criar um arquivo grafo.h 
// e fazer a inclusão "#include <grafo.h>"
class TGrafo{
    private:
        int n; // quantidade de vértices
        int m; // quantidade de arestas
        float **adj; //matriz de adjacência
        static const float INF;
    public:
        TGrafo(int n);
        void insereA(int v, int w, int p);
        void removeA(int v, int w);
        void show();
        void show_();
        bool arestaTrue(int v, int w);
        std::vector<int> dijkstra(int start, std::vector<std::vector<float>>& dist, std::vector<int>& rot);
        std::vector<int> cam_min(int origin, int dest);
        ~TGrafo();
};

#endif
