#ifndef NEURON
#define NEURON

#include <vector>

using namespace std;

const float V_THRESHOLD = -50.0;
const float V_REST = -70.0;

class vwf
{
	// start time from sim start, in ms/10
	size_t start_time;
	// difference in time between each float is 1/10 of a ms
	vector < float > wave;

	// adds the input to "this"
	// REQUIRES: input.start_time >= this->start_time
	void add_waveform(vwf * input, float in_strength = 1)
	{
		// loop through all spots in waveform
		for (int i = input->start_time - start_time; i < input->start_time + input->wave.size() - start_time; i++ )
		{
			// add to current value
			// if greater than V_THRESHOLD after addition and less than threshold before, then 

		}
	}
	// TODO: overloaded addition operator, adds two waveforms together

	// TODO: find next threshold crossing
};

class neuron
{
private:
	// node data
	class synapse
	{
		// outbound neuron the synapse is with
		neuron * out;
		// strength of connection
		float strength;
		// time delay, in tenths of a millisecond
		// for the human brain, a myelin-sheathed signal should cross the brain in ~0.8ms.
		size_t dist;
	};

	// initial value of node
	vwf V;

	// axon for outbound connections
	vector < synapse > axon;


	//zero argument constructor for array creation
	neuron() {}

	//construct using Node type, data, size of next layer
	


};






#endif







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
