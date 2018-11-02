/*
#ifndef NODE_H
#define NODE_H


#include "util.cpp"

using namespace std;

class Node
{
	//node type, value
	uint8_t data;

	//connection data to next layer
	bin_arr connections;

	//1s place handles value
	//2s place handles node type
	//modular addition means no change, if not +2

	//construct using Node type, reference to container layer
	Node(uint8_t in_data, bin_arr in_conn_data);

	//function for adding to data
	void add();

	//function for adding to following nodes
	//returns true if this layer is the last layer
	//the check should be deprecated, as this is now checked in the layer class
	bool push();

	bool get_val();

//end of Node class
};








/*


Notes:

copy constructor for changing layer size?
bottom up layer construction

function for adding to node,
said function should refer to node type


*/


//DEPRECATED:
//instead of including layer.cpp, declare blank "Layer" class
//which we use only as a pointers
//class Layer;

//DEPRECATED
//pointer to container layer
//Layer * container;


/*
#endif
