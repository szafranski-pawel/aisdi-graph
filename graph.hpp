#include <vector>
#include <utility>
#include <stack>
#include <iostream>

class Graph
{
private:
std::vector<std::vector<int> > neighbourhoodList{};
std::vector<std::pair<int, int> > arrayOfEdges{};
size_t vertexNumber{};
public:
Graph()
{
}
Graph(std::vector<std::pair<int, int> >&& inputVector, size_t vertexNumberTemp)
{
        arrayOfEdges = std::move(inputVector);
        vertexNumber = vertexNumberTemp;
}
void constructneighbourhoodList()
{
        std::pair<int, int> temporaryPair;
        neighbourhoodList.resize(vertexNumber);
        for(auto it = 0; it < arrayOfEdges.size(); it++)
        {
                temporaryPair = arrayOfEdges.at(it);
                (neighbourhoodList.at(temporaryPair.first)).push_back(temporaryPair.second);
                (neighbourhoodList.at(temporaryPair.second)).push_back(temporaryPair.first);
        }
}
void findExtensiveBridges()
{
        std::stack<int> vertexStack{};
        std::vector<bool> visitedVector{};
        size_t vertexCount, temporaryVariable;
        visitedVector.resize(vertexNumber);
        int vertex, neighbour;
        for(auto it = 0; it < arrayOfEdges.size(); it++)
        {
                vertexCount = 0;
                temporaryVariable = 0;
                visitedVector.assign(visitedVector.size(), false);
                visitedVector.at((arrayOfEdges.at(it)).first) = true;
                visitedVector.at((arrayOfEdges.at(it)).second) = true;
                while(temporaryVariable < vertexNumber)
                {
                        if(temporaryVariable != (arrayOfEdges.at(it)).first && temporaryVariable != (arrayOfEdges.at(it)).second)
                                break;
                        temporaryVariable++;
                }
                vertexStack.push(temporaryVariable);
                visitedVector.at(temporaryVariable) = true;
                while(vertexStack.empty() == false)
                {
                        vertex = vertexStack.top();
                        vertexStack.pop();
                        vertexCount++;
                        for(auto iterator = (neighbourhoodList.at(vertex)).begin(); iterator < (neighbourhoodList.at(vertex)).end(); iterator++)
                        {
                                neighbour = *iterator;
                                if(visitedVector.at(neighbour) == false)
                                {
                                        visitedVector.at(neighbour) = true;
                                        vertexStack.push(neighbour);
                                }
                        }
                }
                if(vertexCount != vertexNumber - 2)
                        printf("%d %d\n", (arrayOfEdges.at(it)).first, (arrayOfEdges.at(it)).second);
        }
}
};
