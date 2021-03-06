//Michael Ivanitskiy
//dicking around with trying to make a neural net from a bunch of nodes


#include "node.cpp"

//#include "layer.h"
//#include "node.h"

//#include "util.cpp"

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
	Layer(int in_size, Layer * in_layer_next, uint8_t & layer_data)
		: size(in_size), next(in_layer_next)
		//set layer size, set next layer address
	{
		//dynamically assign array with pointers to nodes in its layer
		arr_nodes = new Node[size];

		//construct each node
		parse_layer_data(layer_data);
	}

	//function to parse node data and push it to nodes
	void parse_layer_data(uint8_t & layer_data)
	{
		//calculate bytes for each node
		//always at least 1 byte for node data
		node_size = 1;

		//if next layer exists, then add more
		if (next != nullptr)
		{
			node_size +=  bit_size_calc(next->size);
		}

		//create uint8_t array to store bytes for each node
		uint8_t int_data = new uint8_t[node_size];

		//fill each node
		for (int i = 0; i < data_size; i += node_size)
		{
			//copy data to the array
			//overwrites memory
			for (int k = 0; k < node_size; k++)
			{
				//cycle through to end, overwriting old data
				//but for layer_data start at
				// (node number) * (bytes in a node)
				int_data[k] = layer_data[(i*node_size) + k];
			}

			//the first byte of int_data has the node data
			//remaining bytes are connection data for that node

			//create binary array from int_data
			bin_arr pass_data = bin_arr((node_size - 1), (int_data+1));

			//create node, pass data to it, store it in array
			arr_nodes[i] = new Node(int_data, pass_data, next.size);
		}
		//delete array with data
		delete int_data;
	}


	//operator to get nodes from layer
	//used inside node to access next layer quickly
	Node& operator[](int i)
	{
		return arr_nodes[i];
	}

	//funtion to push everything in layer
	void push_layer()
	{
		if (next != nullptr)
		{
			for (int i = 0, i < size; i++)
			{
				this.push_node(i);
			}
		}
	}

	//pushes the specified node in this layer
	void push_node(int num_node)
	{
		//get the node in question
		Node * node = arr_nodes[i];
		//check that this node is "on"
		if (node.get_val())
		{
			//cycle through all connections
			for (int i = 0; i < (next->size; i++)
			{
				//if connection exists, add to that node in next layer
				if ((node.connections).at(i))
				{
					//if it does, add to that node
					next[i]->add();
				}
			}
		}
	}


//end of Layer class
};

/*
to create special output layer that writes to an array,
does not require next layer
need to set "next" (next layer) to nullptr
*/












/*
class Layer
{
public:
	//initialize size of this layer
	int size = 0;
	//initialize size of input data for this layer
	int data_size;
	//initialize byte size of each node
	int node_size;

	//address to next layer
	Layer * next;
*/
