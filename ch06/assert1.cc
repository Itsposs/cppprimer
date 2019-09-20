

#include <iostream>


int main(int argc, char *argv[])
{
	constexpr int threshold = 6;
	std::string word;
	std::cin >> word;

	if(word.size() < threshold)
	{
		std::cerr << "Error: " << __FILE__
				  << " : in function " << __func__
				  << " at line " << __LINE__ << std::endl
				  << "   Compiled on " << __DATE__
				  << " at " << __TIME__ << std::endl
				  << "   Word read was \"" << word
				  << "\": Length too short " << std::endl;
	}
	return 0;
}
