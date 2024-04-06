/*----
  header file for class: UndirectedGraph

  by: Dakota Donner
  last modified:
----*/

#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <string>
using namespace std;

class UndirectedGraph
{
public:

// constructors

    UndirectedGraph();
    UndirectedGraph(int initVerts);

// accessors

    int vertexCount() const;
    bool edgeExists(int x, int y) const;

// mutators

    bool addEdge(int x, int y);
    bool removeEdge(int x, int y);

// misc methods

    bool graphConnected();


private:

    int vertCount;
    int *adjMat;

    void graphConnectedRecurs(int indexX, int indexY, bool visStatArr[])
    {
        visStatArr[indexX] = true;

        if (adjMat[indexX] == 0)
        {
            return;
        }
    }
};

#endif