#include <iostream>
#include <chrono>
#include "Header1.h"

int main()
{

	Graph g("C:/Users/nunda/OneDrive/Desktop/a");
	/*
	g.addVertex("V1");
	g.addVertex("V2");
	g.addVertex("V3");
	g.addVertex("V4");
	g.addVertex("V5");
	g.addVertex("V6");
	g.addEdge("V1", "V2");
	g.addEdge("V1", "V3");
	g.addEdge("V2", "V5");
	g.addEdge("V3", "V4");
	g.addEdge("V3", "V5");
	*/

	/*
	g.addVertex("s");
	g.addVertex("e");
	g.addVertex("c");
	g.addVertex("d");
	g.addVertex("b");
	g.addVertex("a");
	g.addVertex("t");
	
	g.addEdge("s", "e");
	g.addEdge("s", "c");
	g.addEdge("e", "c");
	g.addEdge("c", "d");
	g.addEdge("c", "b");
	g.addEdge("d", "a");
	g.addEdge("b", "t");
	g.addEdge("a", "t");

	*/
	/*
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
	
	



	//std::cout <<"Is graph connected? "<< std::boolalpha << g.isConnected() << std::endl;

	std::cout << g.locVertexCon("a", "b")<<std::endl;
	std::cout << "Vertex connectivity is: " << g.vertexConnectivity() << std::endl;

	

}