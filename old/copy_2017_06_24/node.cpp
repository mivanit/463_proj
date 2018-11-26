//Michael Ivanitskiy
//dicking around with trying to make a neural net from a bunch of nodes


//#include "node.h"
//#include "layer.h"

#include "util.cpp"

using namespace std;

class Node
{
public:
	//node type, value
	//TODO -  this is the wrong type
	uint8_t data;

	//connection data to next layer
	bin_arr connections;

	//zero argument constructor for array creation
	Node() {}

	//construct using Node type, data, size of next layer
	//TODO:
	//do i need size of next layer? should be in conn data
	Node(uint8_t in_data, bin_arr in_conn_data, int next_size)
		: data(in_data), connections(in_conn_data)
	{	//data only should have first 2 bits (value between 0 & 3)

		//connection boolean uses uint8_t to save memory
		//calculation for memory to allocate
		//add 1 if not a multiple of 8
		//DEPRECATED
		//if ((this->container)->next != nullptr)

		//create array with connection data
		//pointers taken from container, not stored in each node
		connections = bin_arr(next_size);

		//else{	//if it is a nullptr, connections should be empty
		//connections = bin_arr(0);}
	}

	//function for adding to data
	void add()
	{
		if (data == 0)
		{
			data = 1; //adding 1 to 0 goes to 1
			return;
		}
		else if (data == 1)
		{
			data = 0; //adding 1 to 1 goes to 0 (mod arithmetic)
			return;
		}
		else if (data == 2)
		{
			data = 3; //adding 1 to 0 goes to 1, preserve node type
			return;
		}
		else if (data == 3)
		{
			data = 3; //adding 1 to 1 keeps us at 1, preserve node type
			return;
		}
	}

	bool get_val()
	{
		return (bool)(data % 2);
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
