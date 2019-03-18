#include <iostream>
#include <chrono>

void elimDups(std::vector<std::string> &words)
{
	std::sort(words.begin(),words.end());
	auto end_unique = std::unique(words.begin(),words.end());

	words.erase(end_unique,words.end());
}


inline void output_words(std::vector<std::string> &words)
{
	for(const auto word : words)
	{
		std::cout << word << " ";
	}
	std::cout << std::endl;
}

int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
