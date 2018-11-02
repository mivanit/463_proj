//Michael Ivanitskiy
//dicking around with trying to make a neural net from a bunch of nodes


//#include "node.h"
//#include "layer.h"

using namespace std;

class Node
{
public:
	//node data

	//node threshold: if over this value, this neuron will fire
	uint8_t type = 0;

	//data: initial value of node
	uint8_t data = 0;

	//connection data to next layer
	uint8_t * links;

	//size of next layer
	int next_size;

	//zero argument constructor for array creation
	Node() {}

	//construct using Node type, data, size of next layer
	Node(uint8_t in_type, uint8_t in_data, uint8_t * in_link_data, int in_next_size)
		: type(in_type), data(in_data), next_size(in_next_size)
	{
		parse_link_data(in_link_data, next_size);
	}

	//construct using one array for all data
	//with first two bytes being type and value ("data") respectively
	Node(uint8_t * in_data, int in_next_size)
		: next_size(in_next_size)
	{
		type = in_data[0];
		data = in_data[1];

		parse_link_data((in_data + 2), next_size);
	}

	void parse_link_data(uint8_t * in_link_data, int next_size)
	{
		//write connection input data to node
		links = new uint8_t[next_size];

		for (int i = 0; i < next_size; i++)
		{
			links[i] = in_link_data[i];
		}
	}

	//function for adding to data
	//add more node functionality here i guess idk
	void add(uint8_t value_add)
	{
		if (type == 0)
		{
			data += value_add;
		}
		else if (type == 1)
		{
			//DONT FORGET TO CHANGE THIS IF LINK DATA FORMAT CHANGE
			if ( (int)data + (int)value_add >= 255)
			{
				data = 255;
			}
			else
			{
				data += value_add;
			}
		}
	}

	uint8_t get_val()
	{
		return data;
	}

	bool will_fire()
	{
		return (data > type);
	}

	Node& operator=(Node * rhs)
	{
		type = rhs->type;
		data = rhs->data;
		next_size = rhs->next_size;

		for (int i = 0; i < next_size; i++)
		{
			links[i] = (rhs->links)[i];
		}

	}

//end of Node class
};







/*


Notes:

copy constructor for changing layer size?
bottom up layer construction

function for adding to node,
said function should refer to node type


*/




//end of Node class
//};

















//class Node
//{
	//node type, value
	//uint8_t data = 0;

	//connection data to next layer
	//bin_arr connections;

	//1s place handles value
	//2s place handles node type
	//modular addition means no change, if not +2








	//DEPRECATED AND ALL FUNCTION MOVED TO LAYER PUSH FUNCTION
	//done due to inclusion issues

	//function for adding to following nodes
	//returns true if this layer is the last layer
	//the check should be deprecated, as this is now checked in the layer class

	/*
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
	*/
