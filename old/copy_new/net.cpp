#include <fstream>

#include "layer.cpp"
//#include "node.cpp"

//build network from bottom up
class Neural_net
{
public:
	//initialize number of layers
	int num_layers = 0;
	//initialize vector to hold size of each layer
	std::vector<int> layer_sizes;
	//array to hold address of layers
	Layer * layers;

	//constructor
	//takes file name as input
	Neural_net(fstream in_data)
	{
		//read in ints at start of file until endl, store to vector
		//string and stream to store first line
		string str_line_first;
		std::stringstream line_first;
		//read in first line
		getline(in_data, line_first, '\n');
		line_first.str(str_line_first);
		//iterate through and store to vector
		int int_temp = 0;
		while (line_first >> int_temp)
		{
			//push to vector
			layer_sizes.push_back(int_temp);
		}
		//set number of layers
		num_layers = layer_sizes.size();

		//update layers array
		layers = new Layer[num_layers];

		//to create layer, need size, ptr to next layer, and data in an uint8_t array

		//create remaining layers
		for (int i = 0; i < num_layers; i++)
		{
			//parse each line
			uint8_t parsed_line_data = parse_line(in_data, i);

			//test if first line
			if (i == 0)		//if yes, points to nullptr
			{
				//first layer (0) points to empty layer
				//has nodes without connections
				layers[0] = Layer(layer_sizes[0], nullptr, &parsed_line_data);
			}
			else			//if not, points to previously put in layer
			{
				//store each regular parsed line to its respective layer
				layers[i] = Layer(layer_sizes[i], &(layers[i-1]), parsed_line_data);
			}
		}
	}

	//function to parse a line of the input file, to an array readable by Layer constructor
	//data and line number is needed to know size of array to declare
	uint8_t parse_line(fstream & in_data, int layer_reading)
	{
		//declare array to hold data
		uint8_t line_data = new uint8_t(layer_sizes[layer_reading]);
		//read data into an int
		uint8_t int_temp = 0;
		int counter = 0;
		while (in_data >> int_temp)
		{
			//put into array
			line_data[counter] = int_temp;
			//iterate counter
			counter++;
		}
	}

	//function for actually computing array
	//takes array of uint8_t as input
	//returns array of uint8_t as output
	uint8_t * calc(uint8_t * input_layer_data)
	{
		//set input
		set_input(input_layer_data);

		//push all layers
		for (int i = 0; i < num_layers; i++)
		{
			layers[i].push_layer();
		}

		//return output data
		return read_output();
	}

	//function to add input array to first layer
	void set_input(uint8_t * input)
	{
		//iterate through first layer
		//add to nodes if value is true in input array
		for (int i = 0; i < layers[0].size; i++)
		{
			//TODO
			//check that size are the same
			//need to write exception

			//add to node value at i

			((layers[0])[i])->add(input[i]);
		}
	}


	//outputs numerical uint8_t weight value at each final node
	uint8_t * read_output()
	{
		//get ref to final layer
		Layer * fin = &layers[num_layers-1];

		uint8_t * output = new uint8_t[fin->size];

		//store output values of final layer of nodes
		for (int i = 0; i < fin->size; i++)
		{
			//get value from every node
			//copy into array
			output[i] = ((*fin)[i])->get_val();
		}
	}

	//outputs boolean value of whether threshold is crossed at each final node
	bool * read_output_bool()
	{
		//get ref to final layer
		Layer * fin = &layers[num_layers-1];

		bool * output = new bool[fin->size];

		//store output values of final layer of nodes
		for (int i = 0; i < fin->size; i++)
		{
			//get value from every node
			//copy into array
			output[i] = ((*fin)[i])->will_fire();
		}
	}


};//end of net class







/*
node data file format
first line contains (int) sizes of each layer, starting with 0, delimited by tabs
every following line contains data for each layer, starting with layer 0
starts with (uint8_t) data for first node, followed by (uint8_t) connection data
then prints every node in the same fashion, everything tab delimited with an extra tab between nodes
*/
