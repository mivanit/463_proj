//program with functions to generate valid text files for use by net.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "net.cpp"
//#include "../util.cpp"

//prototyping
fstream net_square(int size, fstream file);
string rand_node(int size);





//randomize all note types, values, and connections
//void fill_rand()



void main()
{
	cout << "only square nets for now sorry :(" << endl;
	cout << "size of input layer?" << endl;
	int size_input;
	cin >> size_input;

	fstream file;
	file.open("../nets/test_net_1.txt")

	net_square(size_input, file);

	cout << "done!" << endl;
}

//create a square neural net
//using the specified size
//random connection and node data for now
void net_square(int size, fstream file)
{
	//fill the first row with size, size times
	//creates the base for a square net
	for (int i = 0; i < size; i++)
	{
		file << size << "\t";
	}
	//newline
	file << endl;

	//iterate through each layer
	for (int num_layer = 0; num_layer < size; num_layer++)
	{
		//calculate number of connection data bytes for nodes in this layer
		//actually same for each layer for a square net,
		//but put in here for easier extensibility later
		int num_conn_bytes = bit_size_calc(size);

		//iterate through each node
		//there should be "size" nodes in each layer
		for (int num_node = 0; num_node < size; num_node++)
		{
			file << rand_node(size);
		}
		//newline after each layer
		net << endl;
	}

}

string rand_node(int size)
{
	//the first byte is the note data
	string output = to_string(rand() % 4) + "\t";
	//subsequently there come bytes of connection data
	for (int num_byte = 0; num_byte < num_conn_bytes; num_byte++)
	{
		output += to_string(rand() % 255) + "\t"
	}

}
