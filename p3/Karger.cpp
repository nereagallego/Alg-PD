// Karger's algorithm to find Minimum Cut in an
// undirected, unweighted and connected graph.
// Based https://www.geeksforgeeks.org/kargers-algorithm-for-minimum-cut-set-1-introduction-and-implementation/
#include <iostream>
#include <fstream>
//#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <random>
#include <vector>

using namespace std;
 
// a structure to represent a unweighted edge in graph
struct Edge
{
    int src, dest, weight;
    double prob;
};
 
// a structure to represent a connected, undirected
// and unweighted graph as a collection of edges.
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E, maxIndex;
 
    // graph is represented as an array of edges.
    // Since the graph is undirected, the edge
    // from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    std::vector<Edge> edge;
};
 
 
// Function prototypes for union-find (These functions are defined
// after kargerMinCut() )
int find(struct subset subsets[], int i);
void Union(struct Graph* g, int x, int y);

double fRand(double fMin,double fMax){
   std::uniform_real_distribution<double> unif(fMin,fMax);
   std::default_random_engine re;
   re.seed(rand()%10000);
   double a_random_double = unif(re);
   return a_random_double;
}

double fRandBiased(double fMin, double fMax) {
    srand((unsigned)time(NULL));
    return ((double)rand()/(double)RAND_MAX);
}
 
// A very basic implementation of Karger's randomized
// algorithm for finding the minimum cut. Please note
// that Karger's algorithm is a Monte Carlo Randomized algo
// and the cut returned by the algorithm may not be
// minimum always
int kargerMinCut(struct Graph* graph)
{
    // Get data of given graph
    int V = graph->V, E = graph->E;
    vector<Edge> edge = graph->edge;
 
    // Initially there are V vertices in
    // contracted graph
    int vertices = V;
 
    // Keep contracting vertices until there are
    // 2 vertices.
    while (vertices > 2)
    {
        fprintf(stdout, "----------------------------------\n");
        // Pick a random edge
        //float rand = fRand(0.0,1.0);
        float rand = fRandBiased(0.0,1.0);
        int arista = 0;
        float probAcum = 0.0;
        for(int j = 0; j < E; j ++){
            if(rand < probAcum + edge[j].prob){
                arista = j; 
                break;
            } else {
                probAcum += edge[j].prob;
            }
        }
        fprintf(stdout, "Contracting edge %d-%d\n", edge[arista].src, edge[arista].dest);
        vertices--;
        edge[arista].prob = 0;
        Union(graph, edge[arista].src, edge[arista].dest);
        edge = graph->edge;
    }
 
    return graph->E;
}


void calcularProbabilidad(struct Graph* g){
    int E = g->E;
    int pesoTotal = 0;
    for(int i = 0; i < E; i ++){
        pesoTotal += g->edge[i].weight;
    }
    std::cout << "peso total " << pesoTotal << std::endl;
    for(int i = 0; i < E; i++){
        g->edge[i].prob = float((float)g->edge[i].weight / (float)pesoTotal);
        std::cout << g->edge[i].src << "-" << g->edge[i].dest << " prob: " << g->edge[i].prob << " weight: " << g->edge[i].weight << std::endl;
    }
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct Graph* g, int x, int y)
{
  //  vector<Edge> edge = g->edge;

    int eliminadas = 0;
    for(int i = 0; i < g->E; i ++){

        if((g->edge[i].src == x && g->edge[i].dest == y ) || (g->edge[i].dest == x && g->edge[i].src == y)){
       
        } else if(g->edge[i].src == y && g->edge[i].dest != x){

            g->edge[i].src = x;

        } else if(g->edge[i].dest == y && g->edge[i].src != x){

            g->edge[i].dest = x;

        }
    }

    for(int i = 0; i < g->E; i ++){
        if((g->edge[i].src == x && g->edge[i].dest == y ) || (g->edge[i].dest == x && g->edge[i].src == y)){
            auto it = g->edge.begin()+i;
            g->edge.erase(it);
            eliminadas ++;
        } 
    }
    g->E -= eliminadas;

    for(int i = 0; i < g->E; i++){
        int suma = 1;
        for(int j = 0; j < g->E; j++){
            if(j != i && (((g->edge[i].src == g->edge[j].src) && (g->edge[i].dest == g->edge[j].dest)) || ((g->edge[i].src == g->edge[j].dest) && (g->edge[i].dest == g->edge[j].src)))) {
                g->edge[i].weight += g->edge[j].weight;
                auto it = g->edge.begin()+j;
                g->edge.erase(it);
                g->E--;
            }
        }
    }
    calcularProbabilidad(g);
}


 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = vector<Edge>(E);
    graph->maxIndex = V;
    return graph;
}
 
// Driver program to test above functions
int main(int argc, char *argv[])
{

    ifstream fin;
    fin.open(argv[1], ios::in);

    if(!fin.is_open()){
        cerr << "No se abre el fichero" << endl;
        exit(1);
    }
    int V, E, a, b, w;
    std::vector<Edge> aux_edges;
    fin >> V;
    while (fin >> a >> b >> w)
    {
        Edge e;
        e.src = a;
        e.dest = b;
        e.weight = w;
        e.prob = 0.0;
        aux_edges.push_back(e);
        E++;
    }

    struct Graph* graph = createGraph(V, E);
    graph->edge = aux_edges;

    calcularProbabilidad(graph);

 
    // Use a different seed value for every run.
    srand(time(NULL));
 
    printf("\nCut found by Karger's randomized algo is %d\n",
           kargerMinCut(graph));
 
    return 0;
}