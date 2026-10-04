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

#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include "TGrafo_dijkstra.hpp"
#include "utils_dijkstra.hpp"

const float TGrafo::INF = std::numeric_limits<float>::infinity();

/*
    Construtor do TGrafo, responsável por 
    Criar a matriz de adjacência v x v do Grafo
*/
TGrafo::TGrafo( int n ){
    this->n = n;

    // No início dos tempos não há arestas
    this->m = 0; 

    // aloca da matriz do TGrafo
    float **adjac = new float*[n];

    for(int i = 0; i < n; i++)
        adjac[i]= new float[n];

    adj = adjac;

    // Inicia a matriz com zeros
    for(int i = 0; i< n; i++)
        for(int j = 0; j< n; j++)
            adj[i][j]=INF;    
}

/*
    Destructor, responsável por
    liberar a memória alocada para a matriz
*/
TGrafo::~TGrafo(){
    for(int a = 0; a < n; a++){
        delete[] adj[a];
    }
    delete [] adj;
    
    n = 0;
    m = 0;

    std::cout << "espaco liberado" << std::endl;
}

/*
    Insere uma aresta no Grafo tal que
    v é adjacente a w
*/
void TGrafo::insereA( int v, int w, int p){
    // testa se nao temos a aresta
    if(adj[v][w] == INF){
        m++; // atualiza qtd arestas
    }
    adj[v][w] = p;
}

/*
    Remove uma aresta v->w do Grafo
*/
void TGrafo::removeA(int v, int w){
    // testa se temos a aresta
    if(adj[v][w] == 1){
        adj[v][w] = INF;
        m--; // atualiza qtd arestas
    }
}

bool TGrafo::arestaTrue(int v, int w){
    return adj[v][w] != INF;
}

/*
    Apresenta o Grafo contendo
    número de vértices, arestas
    e a matriz de adjacência obtida
*/
void TGrafo::show_(){
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;

    for (int i=0; i < n; i++){
        std::cout << "\n";

        for (int w=0; w < n; w++)
            if (adj[i][w] == 1)
                std::cout << "Adj[" << i<< "," << w << "]= 1" << " ";
            else
                std::cout << "Adj[" << i<< "," << w << "]= 0" << " ";
    }
    std::cout << "\nfim da impressao do grafo." << std::endl;
}

/*
    Apresenta a matriz de adjacencia em formato tabular
*/
void TGrafo::show(){
    std::cout << "   ";

    for(int w = 0; w < n; w++){
        if(w > 0)
            std::cout << " ";
        std::cout << w;
    }

    std::cout << std::endl;

    for(int i = 0; i < n; i++){
        std::cout << i << " [";

        for(int w = 0; w < n; w++){
            if(w > 0){
                std::cout << " ";
                if(adj[i][w] == INF){
                    std::cout << "inf";
                } else {
                    std::cout << adj[i][w];
                }
            }
        }
        std::cout << "]" << std::endl;
    }
}

std::vector<int> TGrafo::dijkstra(int start, std::vector<std::vector<float>>&dist, std::vector<int>&rot){

    // Setup inicial
    /*
    d11 <- 0; d1i <- + ∞, qualquer i pertence V - { 1 }; S <- {1}; A <- V; F <- nao existe; 
     k = 0;
    */
    dist.clear();
    dist.push_back(std::vector<float>(n, INF));
    dist[0][start] = 0;
    std::vector<int> S;
    std::vector<int> A;

    S.push_back(start);
    
    for(int vert = 0; vert < n; vert++){
        A.push_back(vert);  // A <- V (pega os vertices)
    }

    rot.assign(n, -1); // rot(i) <- 0 para qualquer i;
    int k = 0;

    std::vector<int> F;
    //-----------------------------------------------------------------------------------------------//
    while(!A.empty()){
        k++;
        dist.push_back(dist[k-1]);

        int pos = 0;
        for(size_t y = 1; y < A.size(); y++){
            if(dist[k - 1][A[y]] < dist[k - 1][A[pos]])
                pos = (int)y;
        }
        int r = A[pos];
        F.push_back(r);           // F <- F U {r}
        A.erase(A.begin() + pos); // A <- A - {r}
        S.clear(); // esse junta o A com N(r), atualizando S
        
        for(size_t y = 0; y < A.size(); y++){
            if(adj[r][A[y]] != INF)
                S.push_back(A[y]);
        }
        // Loop do i que contém no S:
        for(int i_do_slide : S){
            // Conta: p <- min [ dk-11i, (d1r+ vri) ]
            float p = std::min(dist[k-1][i_do_slide], dist[k-1][r] + adj[r][i_do_slide]);
            /*
            se (p < dk-11i ) então 
                dk1i <- p; rot(i) <- r;
            */
            if(p < dist[k-1][i_do_slide]){
                dist[k][i_do_slide] = p;
                rot[i_do_slide] = r;
            }
        }
    }
    return F;
}

std::vector<int> TGrafo::cam_min(int origin, int dest){
    std::vector<std::vector<float>> dist;
    std::vector<int> rot;
    dijkstra(origin, dist, rot);

    std::vector<int> theWay;
    if(dist.back()[dest] == INF) 
        return theWay;
    
    // Usa a técnica do prof de reconstruir a rota de trás para frente:
    for(int v = dest; v != -1; v = rot[v]){
        theWay.insert(theWay.begin(), v);
    }

    return theWay;
}
