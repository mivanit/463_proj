//program with functions to generate valid text files for use by impl_thresh/net.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "net.cpp"
//#include "../util.cpp"

//prototyping
void net_square(int size, fstream file);
string rand_node(int size);



//randomize all note types, values, and connections
//void fill_rand()



int main()
{
	cout << "only square nets for now sorry :(" << endl;
	cout << "size of input layer?" << endl;
	int size_input;
	cin >> size_input;

	fstream file;
	file.open("../nets/test_net_1.txt");

	net_square(size_input, file);

	cout << "done!" << endl;

	return 1;
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
		//iterate through each node
		//there should be "size" nodes in each layer
		for (int num_node = 0; num_node < size; num_node++)
		{
			file << rand_node(size);
		}
		//newline after each layer
		file << endl;
	}
}

string rand_node(int size)
{
	string output;

	//2 bytes of type, inital data
	//subsequently there come %size% bytes of connection data
	for (int num_byte = 0; num_byte < size + 2; num_byte++)
	{
		output += to_string(rand() % 511) + "\t";
	}

	return output;
}
