#include <iostream>
#include <vector>
#include <string>

using namespace std;
int serial_is_valid(std::string serial)
{
	// do some of the easy checks

	// serial has to be between 10 and 12 chars
	if (serial.size() > 12 || serial.size() < 10)
	{
		return false;
	}

	// last character has to be an upper case letter
	if (serial.back() < 'A' || serial.back() > 'Z')
	{
		return false;
	}

	size_t idx = 0;

	// 26 letters. all distinct. we will mark them as we go
	std::vector<bool> dinstinct_check(26, true);

	// go through the serial to check against the rules
	for (; idx < 3; ++idx)
	{
		if (serial[idx] < 'A' || serial[idx] > 'Z')
		{
			return false;
		}

		// first three chars has to be DISTINCT upper chase english letters
		if (dinstinct_check[serial[idx] - 'A'] == false)
		{
			return false;
		}

		// mark as seen
		dinstinct_check[serial[idx] - 'A'] = false;
	}

	std::string year_str = serial.substr(3, 4);

	char* endptr = nullptr;
	auto year = std::strtol(year_str.data(), &endptr, 10);

	// endptr will point to the next char in year_str if the conversion was valid
	if (endptr == nullptr || year_str.data() == endptr)
	{
		return false;
	}

	// year has to be between 1900 and 2019
	if (year < 1900 || year > 2019)
	{
		return false;
	}

	// first 7 characters and the last character are for identification. the remaining characters
	// must be the denomination
	auto denomination_size = serial.size() - 7 - 1;

	// get the substring 

	std::string denomination_str = serial.substr(7, denomination_size);

	// check the value of the denomination
	endptr = nullptr;
	auto denomination_value = std::strtol(denomination_str.data(), &endptr, 10);

	// endptr will point to the next char in year_str if the conversion was valid
	if (endptr == nullptr || denomination_str.data() == endptr)
	{
		return false;
	}

	if (denomination_value == 10 || \
		denomination_value == 20 || \
		denomination_value == 50 || \
		denomination_value == 100 || \
		denomination_value == 200 || \
		denomination_value == 500 || \
		denomination_value == 1000)
	{
		return denomination_value;
	}

	return -1;
}


int countCounterfeit(vector<string> serialNumber)
{
	int sum = 0;

	for (const auto& serial : serialNumber)
	{
		auto value = serial_is_valid(serial);
		if ( value != -1)
		{
			sum += value;
		}
	}

	return sum;
}