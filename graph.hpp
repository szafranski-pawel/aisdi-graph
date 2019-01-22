#include <vector>
#include <utility>

class Graph
{
private:
std::vector<std::vector<std::pair<int, int> > > arrayOfNeighborhoodArrays;
public:
Graph(std::vector<std::vector<std::pair<int, int> > >&& inputVector)
{
        arrayOfNeighborhoodArrays = std::move(inputVector);
};
void findExtensiveBridges()
{

};
};
