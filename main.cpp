#include <iostream>
#include <vector>
#include <utility>
#include "graph.hpp"

int main()
{
        size_t vertexNumber;
        std::pair<int, int> vertexPair;
        std::vector<std::pair<int, int> > arrayOfEdges;
        std::cin>>vertexNumber;
        while(std::cin>>vertexPair.first>>vertexPair.second)
                arrayOfEdges.push_back(vertexPair);
        if(arrayOfEdges.size() == vertexNumber*(vertexNumber-1)/2) // if complete graph then finish
                return 0;
        Graph testClass{std::move(arrayOfEdges), vertexNumber};
        testClass.constructneighbourhoodList();
        testClass.findExtensiveBridges();
        return 0;
}
