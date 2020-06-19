#pragma once

#include <exception>
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <vector>



struct vertex {
	std::string name;
	bool visited;
	std::string prev;
	int k;
	std::map<std::string, vertex*> adjList;
	vertex(std::string s) :name(s), visited(false), k(1) {}
	
};



class Graph {
public:
	
	//constructors
	Graph() {}
	//constructor for a file name
	Graph(std::string);
	//destructor
	~Graph();
	//function for adding edges
	void addEdge(const std::string&, const std::string&);
	//function for adding vertices
	void addVertex(const std::string&);
	//function for checking whether graph is connected or not
	bool isConnected();
	//function for checking whether graph is complete or not
	bool iscomplete();
	//function for finding out vertex connectivity
	int vertexConnectivity();
	//function for finding out local vertex connectivity
	int locVertexCon(std::string, std::string);
	//function for finding disjoint path between two vertices
	std::pair<std::vector<vertex*>, bool> vertexDisjointPath(std::string, std::string);


private:
	int locVertexCon(vertex*, vertex*);
	std::pair<std::vector<vertex*>, bool> vertexDisjointPath(vertex*, vertex*);
	std::map<std::string, vertex*> Vertexes_;

};


Graph::~Graph() {
	for (auto& x : Vertexes_) {
		delete x.second;
	}

}

Graph::Graph(std::string name) {
	std::ifstream myfile;
	std::string filename = name + ".txt";
	myfile.open(filename, std::ios::in);
	if (myfile) {
		std::string vname1;
		std::string vname2;
		while (myfile>>vname1) {
			myfile >> vname2;
			addEdge(vname1, vname2);
		}
	}
	else {
		throw std::runtime_error("Could not open file");
	}
}



void Graph::addVertex(const std::string& v_name) {
	std::map<std::string, vertex*>::iterator it = Vertexes_.find(v_name);

	if (it == Vertexes_.end()) {
		vertex* new_v = new vertex(v_name);
		Vertexes_.insert(std::pair<std::string, vertex*>(v_name, new_v));

	}
}



void Graph::addEdge(const std::string& v1, const std::string& v2) {
	std::map<std::string, vertex*>::iterator it1 = Vertexes_.find(v1);
	std::map<std::string, vertex*>::iterator it2 = Vertexes_.find(v2);

	if (it1 == Vertexes_.end()) {
		vertex* new_v1 = new vertex(v1);
		Vertexes_.insert(std::pair<std::string, vertex*>(v1, new_v1));


	}

	if (it2 == Vertexes_.end()) {

		vertex* new_v2 = new vertex(v2);
		Vertexes_.insert(std::pair<std::string, vertex*>(v2, new_v2));
	}

	Vertexes_[v1]->adjList.insert(std::make_pair(v2,Vertexes_[v2]));
	Vertexes_[v2]->adjList.insert(std::make_pair(v1,Vertexes_[v1]));
}



bool Graph::isConnected() {

	std::queue<vertex*> q;
	q.push(Vertexes_.begin()->second);
	while (!q.empty()) {
		vertex* ptr = q.front();
		q.pop();
		if (ptr->visited == false) {
			ptr->visited = true;
			for (auto &x: ptr->adjList) {
				if (x.second->visited == false) {
					q.push(x.second);
				}

			}
		}

	}
	for (auto& x : Vertexes_) {
		if (x.second->visited == false)
			return false;
	}
	return true;

}



bool Graph::iscomplete() {
	int k = Vertexes_.size();
	for (auto& x : Vertexes_) {
		if (x.second->adjList.size() != k - 1) {
			return false;
		}
	}

	return true;
}



std::pair<std::vector<vertex*>, bool> Graph::vertexDisjointPath(vertex* source, vertex* sink) {

	std::vector<vertex*> v;
	std::queue<vertex*> q;
	source->visited = false;
	vertex* ptr;
	q.push(sink);
	while (!q.empty()) {
		ptr = q.front();
		ptr->visited = true;
		q.pop();
		if (ptr->name == source->name) {
			break;
		}
		for (auto& x : ptr->adjList) {
			if (x.second->visited == false && x.second->k == 1) {
				x.second->visited = true;
				x.second->prev = ptr->name;
				q.push(x.second);

			}

		}
	}
	if (source->visited == true) {

		ptr = source;
		while (ptr != sink) {
			v.push_back(ptr);
			ptr->k = 2;
			ptr = Vertexes_[ptr->prev];


		}
		source->k = 1;
		sink->k = 1;
		v.push_back(sink);
		
		return std::make_pair(v, true);
	}
	else
		return std::make_pair(v, false);

}



int Graph::locVertexCon(vertex* source, vertex* sink) {
	int kappa = 0;
	std::pair<std::vector<vertex*>, bool> path = vertexDisjointPath(source, sink);
	while (path.second == true) {
		kappa++;
		for (auto& x : Vertexes_) {

			x.second->visited = false;

		}
		path = vertexDisjointPath(source, sink);
	}

	for (auto& x : Vertexes_) {

		x.second->visited = false;
		x.second->k = 1;


	}
	return kappa;

}



int Graph::vertexConnectivity() {
	if (isConnected() == false) {
		return 0;
	}
	if (iscomplete()) {
		return Vertexes_.size() - 1;
	}

	for (auto& x : Vertexes_) {
		x.second->visited = false;
	}
	
	std::vector<int> maxflows;
	std::map<std::string, vertex*>::iterator it1;
	std::map<std::string, vertex*>::iterator it2;
	for (it1 = Vertexes_.begin();it1 != std::prev(Vertexes_.end());++it1) {
		for (it2 = std::next(it1);it2 != Vertexes_.end();++it2) {
			if (it1->second->adjList.find(it2->first) == it1->second->adjList.end()) {
				maxflows.push_back(locVertexCon(it1->second, it2->second));
			}
		}
	}


	return *(std::min_element(maxflows.begin(), maxflows.end()));

}



int Graph::locVertexCon(std::string s1, std::string s2)
{
	if (Vertexes_.find(s1) == Vertexes_.end() || Vertexes_.find(s2) == Vertexes_.end()) {
		throw std::invalid_argument("invalid vertex name");
	}
	else {
		return locVertexCon(Vertexes_[s1], Vertexes_[s2]);
	}
	
}



std::pair<std::vector<vertex*>, bool> Graph::vertexDisjointPath(std::string s1, std::string s2) {

	if (Vertexes_.find(s1) == Vertexes_.end() || Vertexes_.find(s2) == Vertexes_.end()) {
		throw std::invalid_argument("invalid vertex name");
	}
	else {
		return vertexDisjointPath(Vertexes_[s1], Vertexes_[s2]);
	}
}


