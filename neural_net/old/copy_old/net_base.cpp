//Michael Ivanitskiy
//dicking around with trying to make a neural net from a bunch of nodes

//DEPRECATED
//combination of node and layer classes

//#include "node.h"
//#include "layer.h"


/*

using namespace std;



/*
		███    ██  ██████  ██████  ███████
		████   ██ ██    ██ ██   ██ ██
		██ ██  ██ ██    ██ ██   ██ █████
		██  ██ ██ ██    ██ ██   ██ ██
		██   ████  ██████  ██████  ███████
*//*

	//construct using Node type, reference to container layer
	Node::Node(uint8_t in_data, bin_arr in_conn_data, Layer * in_container)
		: data(in_data), connections(in_conn_data), container(in_container)
		//data only should have first 2 bits (value between 0 & 3)
	{
		//connection boolean uses uint8_t to save memory
		//calculation for memory to allocate
		//add 1 if not a multiple of 8
		if ((this->container)->next != nullptr)
		{
			//create array with connection data
			//pointers taken from container, not stored in each node
			this->connections = bin_arr((container->next)->size);
		}
		else
		{
			//if it is a nullptr, connections should be empty
			this->connections = bin_arr(0);
		}
	}

	//function for adding to data
	void Node::add()
	{
		if (this->data == 0)
		{
			this->data = 1; //adding 1 to 0 goes to 1
			return;
		}
		else if (this->data == 1)
		{
			this->data = 0; //adding 1 to 1 goes to 0 (mod arithmetic)
			return;
		}
		else if (this->data == 2)
		{
			this->data = 3; //adding 1 to 0 goes to 1, preserve node type
			return;
		}
		else if (this->data == 3)
		{
			this->data = 3; //adding 1 to 1 keeps us at 1, preserve node type
			return;
		}
	}

	//function for adding to following nodes
	//returns true if this layer is the last layer
	//the check should be deprecated, as this is now checked in the layer class
	bool Node::push()
	{
		//check if next layer is nullptr
		if (((this->container)->next) != nullptr)
		{
			//check that this node is "on"
			if ((this->data % 2) != 0)
			{
				//cycle through all connections
				for (int i = 0; i < ((this->container)->next)->size; i++)
				{
					//if connection exists, add to that node in next layer
					if ((this->connections).at(i))
					{
						//if it does, add to that node
						((this->container)->next)[i]->add();
					}
				}
			}

			//return false, as there is still a next layer
			return false;
		}
		else
		{
			//if next layer is nullptr, return true
			return true;
		}
	}

	bool Node::get_val()
	{
		return (bool)(this->data % 2);
	}









/*
		██       █████  ██    ██ ███████ ██████
		██      ██   ██  ██  ██  ██      ██   ██
		██      ███████   ████   █████   ██████
		██      ██   ██    ██    ██      ██   ██
		███████ ██   ██    ██    ███████ ██   ██
*//*



	//constructor:
	//pass layer size, address of next layer, data for nodes in this layer
	//layer_data points to the first element of an array
	Layer::Layer(int in_size, Layer & in_layer_next, uint8_t & layer_data)
		: size(in_size), next(in_layer_next)
		//set layer size, set next layer address
	{
		//dynamically assign array with pointers to nodes in its layer
		arr_nodes = new Node[size];

		//construct each node
		this.parse_layer_data(layer_data);
	}

	//function to parse node data and push it to nodes
	void Layer::parse_layer_data(uint8_t & layer_data)
	{
		//calculate bytes for each node
		//always at least 1 byte for node data
		node_size = 1;

		//if next layer exists, then add more
		if (next != nullptr)
		{
			node_size +=  bit_size_calc((this->next)->size);
		}

		//create uint8_t array to store bytes for each node
		uint8_t int_data = new uint8_t[node_size];

		//fill each node
		for (int i = 0; i < this->data_size; i += node_size)
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
			arr_nodes[i] = new Node(int_data, pass_data, this);
		}
		//delete array with data
		delete int_data;
	}


	//operator to get nodes from layer
	//used inside node to access next layer quickly
	Node& Layer::operator[](int i)
	{
		return arr_nodes[i];
	}

	//funtion to push everything in layer
	void Layer::push()
	{
		if (next != nullptr)
		{
			for (int i = 0, i < size; i++)
			{
				arr_nodes[i].push();
			}
		}
	}







































/*
		     ██ ██    ██ ███    ██ ██   ██
		     ██ ██    ██ ████   ██ ██  ██
		     ██ ██    ██ ██ ██  ██ █████
		██   ██ ██    ██ ██  ██ ██ ██  ██
		 █████   ██████  ██   ████ ██   ██
*/





/*


Notes:

copy constructor for changing layer size?
bottom up layer construction

function for adding to node,
said function should refer to node type


*/








//class Node
//{
	//node type, value
	//uint8_t data = 0;

	//connection data to next layer
	//bin_arr connections;

	//1s place handles value
	//2s place handles node type
	//modular addition means no change, if not +2



	//end of Node class
	//};







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

	//end of Layer class
	//};
