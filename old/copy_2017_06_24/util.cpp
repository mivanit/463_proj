#include <cstdint>
#include <iostream>
#include <string>

//helper functions not bound to class
int bit_size_calc(int size_bits)
{
	// divide to get floored int | add 1 if not mult of 8
	//			  v				       v
	int calc_size = (size_bits / 8) + ((size_bits % 8) != 0);
	return calc_size;
}


//class for holding boolean array using unsigned 8 bit integer
//meant to reduce memory usage,
//but mostly for me to practice low level memory management
class bin_arr
{
public:
	//constructors

	//takes number of bool values, not size of "data"
	bin_arr(int size_in) : size(size_in)
	{
		//only do this if next layer is not a nullptr
		data_size = bit_size_calc(size);

		//create array of proper size, set data to that
		data = new uint8_t[data_size];
	}

	//takes array of uint8_t with data already inside
	bin_arr(int size_in, uint8_t * data_in)
		: size(size_in), data(data_in)
	{
		//only do this if next layer is not a nullptr
		data_size = bit_size_calc(size);

		//data array is already created
	}

	//destructor
	~bin_arr()
	{
		delete[] data;
	}

	//getters and setters

	//get value
	bool at(int i)
	{
		//copy byte holding data
		uint8_t byte = data[loc_arr(i)];

		//shift right by bitwise location
		byte >> loc_bit(i);

		//take mod 2, cast to boolean
		bool value = (bool) (byte % 2);

		//cast to boolean and return
		return value;
	}

	//set value
	void set(int i, bool value)
	{
		//get current value
		bool current = at(i);

		//if value is already correct, exit
		if (current == value)
		{
			return;
		}
		else
		{
			//otherwise, change it
			if (current)
			{
				data[loc_arr(i)] -= loc_bit(i);
			}
			else
			{
				data[loc_arr(i)] += loc_bit(i);
			}
		}
	}

	//BRACKET OPERATOR IS GETTER ONLY
	bool operator [](int i)
	{
		return at(i);
	}

	//get size
	int get_size()
	{
		return size;
	}


	//helper functions to get the location of a bit of memory in "data"
	//both take location boolwise as input

	//location in array
	int loc_arr(int i)
	{
		return (i/8);
	}

	//location bitwise
	int loc_bit(int i)
	{
		return (2^(i%8));
	}

private:
	//number of boolean values, given in constructor
	int size;
	//array holding booleans in bit values
	uint8_t * data;
	//calculated size of 8 bit int array
	int data_size;
};










//old getter
/*
std::cout << "test 1\n";

int place = loc_bit(i);

std::cout << "test 2\n";

std::cout << "loc_arr\tdata\t"
std::cout << loc_arr(i) << "\t" << (int) data[loc_arr(i)] << "\t" << place << "\n";

//value of bit containing connection data
int subtotal = ( (int) data[loc_arr(i)] ) % ( place * 2);

std::cout << "total up to place:\t" << subtotal << "\n";

std::cout << "getting val @ " << i << " to be " << (place >= subtotal) << "\n";

//if remainder is less than the value at the place,
//then the bit val at the place is 0
//if greater than or equal to, then 1
return (place >= subtotal);
*/






/*

//print function
//takes char format, delimeter format
//char can be int, string, or char (1/0, t/f, true/false)
//delimeter can be none, space, tab, or comma
string print_arr()//string format_ch = "int", string format_dl = "space")
{
	string output = "";
	if (format_ch == "int")
	{
		if (format_dl == "space")
		{

	for (int i = 0; i < size; i++)
	{
		output += (string) at(i);
		output += " ";
	}
}

*/
