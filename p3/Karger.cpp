// Karger's algorithm to find Minimum Cut in an
// undirected, unweighted and connected graph.
// Based https://www.geeksforgeeks.org/kargers-algorithm-for-minimum-cut-set-1-introduction-and-implementation/
#include <iostream>
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
 
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
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
       // Pick a random edge
       float rand = fRand(0.0,1.0);
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
 
       // Find vertices (or sets) of two corners
       // of current edge
    //   int subset1 = find(subsets, edge[arista].src);
    //   int subset2 = find(subsets, edge[arista].dest);
 
       // If two corners belong to same subset,
       // then no point considering this edge
    //   if (subset1 == subset2) {
        //    std::cout << "me atasque" << std::endl;
    //        continue;
    //   }
 
       // Else contract the edge (or combine the
       // corners of edge into one vertex)
          printf("Contracting edge %d-%d\n",
                 edge[arista].src, edge[arista].dest);
          vertices--;
          edge[arista].prob = 0;
          Union(graph, edge[arista].src, edge[arista].dest);
    }
 
    // Now we have two vertices (or subsets) left in
    // the contracted graph, so count the edges between
    // two components and return the count.
  /*  int cutedges = 0;
    for (int i=0; i<E; i++)
    {
        int subset1 = find(subsets, edge[i].src);
        int subset2 = find(subsets, edge[i].dest);
        if (subset1 != subset2)
          cutedges++;
    }*/
 
    return graph->E;
}


 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i
    // (path compression)
    if (subsets[i].parent != i)
      subsets[i].parent =
             find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
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
        std::cout << "prob " << i << " " << g->edge[i].prob << std::endl;
    }
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct Graph* g, int x, int y)
{
    for(int i = 0; i < g->E; i ++){
        if(g->edge[i].src == y && ! g->edge[x].dest == x){
            g->edge[i].src = x;
        } else if(g->edge[i].dest == y && ! g->edge[x].src == x){
            g->edge[i].src = x;
        } else {
            auto it = g->edge.begin()+i;
            g->edge.erase(it);
            g->E --;
           // g->V --;
        }
    }
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
int main()
{
    /* Let us create following unweighted graph
        0------1
        | \    |
        |   \  |
        |     \|
        2------3   */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 5;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 1;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 2;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 7;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 3;
 
    calcularProbabilidad(graph);

 
    // Use a different seed value for every run.
    srand(time(NULL));
 
    printf("\nCut found by Karger's randomized algo is %d\n",
           kargerMinCut(graph));
 
    return 0;
}