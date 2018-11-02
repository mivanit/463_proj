/*
#ifndef NODE_H
#define NODE_H



#include "node.h"
//#include "util.cpp"

//instead of including node.cpp, declare blank "Node" class
//which we use only as a pointers

using namespace std;

class Layer
{
public:
	//size of this layer
	int size;
	//size of input data for this layer
	int data_size;
	//byte size of each node
	int node_size;
	//adresses of all nodes
	Node * arr_nodes;

	//address to next layer
	Layer * next;

	//constructor:
	//pass layer size, address of next layer, data for nodes in this layer
	//layer_data points to the first element of an array
	Layer(int in_size, Layer & in_layer_next, uint8_t & layer_data);

	//function to parse node data and push it to nodes
	void parse_layer_data(uint8_t & layer_data);

	//operator to get nodes from layer
	//used inside node to access next layer quickly
	Node& operator[](int i);

	//funtion to push everything in layer
	void push();

//end of Layer class
};

/*
to create special output layer that writes to an array
does not require next layer
need to set "next" (next layer) to nullptr
*/




/*
#endif
