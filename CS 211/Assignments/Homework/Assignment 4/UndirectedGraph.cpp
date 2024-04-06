/*----
  purpose: implementation file for class UndirectedGraph

  by: Dakota Donner
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "UndirectedGraph.h"

using namespace std;

// constructors

UndirectedGraph::UndirectedGraph()
{
    adjMat = new int[25];
    vertCount = 5;

    for(int i = 0; i < vertCount; i++)
    {
      adjMat[i] = 0;
    }
}

UndirectedGraph::UndirectedGraph(int initVerts)
{
    adjMat = new int[(initVerts * initVerts)];
    vertCount = initVerts;

    for(int i = 0; i < (initVerts * initVerts); i++)
    {
      adjMat[i] = 0;
    }
}

// accessors

int UndirectedGraph::vertexCount() const
{
    return vertCount;
}

bool UndirectedGraph::edgeExists(int x, int y) const
{
    return (adjMat[(x*vertCount)+y] == 1);
}

// mutators

bool UndirectedGraph::addEdge(int x, int y)
{
    if (x == y)
        return false;

    else if (adjMat[(x*vertCount)+y] == 1)
        return false;

    else
    {
        adjMat[(x*vertCount)+y] = 1;
        return true;
    }
}

bool UndirectedGraph::removeEdge(int x, int y)
{
    if (adjMat[(x*vertCount)+y] == 0)
        return false;

    else
    {
        adjMat[(x*vertCount)+y] = 0;
        return true;
    }
}

// others

bool UndirectedGraph::graphConnected()
{
    bool visStatArr[vertCount];

    for(int i = 0; i < vertCount; i++)
    {
        visStatArr[i] = false;
    }

    
}