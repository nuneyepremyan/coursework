#include <iostream>
#include <chrono>
#include "Header1.h"

int main()
{

	

	g.addVertex("s");
	g.addVertex("a");
	g.addVertex("b");
	g.addVertex("c");
	g.addVertex("d");
	g.addVertex("e");
	g.addVertex("k");
	g.addVertex("f");
	g.addVertex("g");
	g.addVertex("k");
	g.addVertex("l");
	g.addVertex("m");
	g.addVertex("n");
	g.addVertex("t");
	g.addEdge("s", "a");
	g.addEdge("s", "b");
	g.addEdge("s", "c");
	g.addEdge("s", "d");
	g.addEdge("a", "e");
	g.addEdge("b", "k");
	g.addEdge("c", "g");
	g.addEdge("d", "f");
	g.addEdge("e", "l");
	g.addEdge("k", "e");
	g.addEdge("f", "m");
	g.addEdge("f", "t");
	g.addEdge("g", "m");
	g.addEdge("m", "n");
	g.addEdge("n", "t");
	g.addEdge("l", "t");*/
	
	

	std::cout << "Vertex connectivity is: " << g.vertexConnectivity() << std::endl;

	

}
