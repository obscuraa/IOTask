#include <algorithm>
#include <fstream>
#include <ios>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::string inputfile = argv[1];
    std::string outputfile = argv[2];

    std::ifstream input_file(inputfile, std::ios_base::binary);
    std::ofstream output_file(outputfile, std::ios_base::binary);

    std::vector<std::string> data;
    if (std::ifstream in{ inputfile })
    {
        std::string item;
        while (in >> item)
        {
            data.push_back(item);
        }
    }
    else
    {
        std::cout << "Failed to open file!";
    }

    std::reverse(data.begin(), data.end());
    
    data.back().pop_back();
    data.front().append(",");

    std::ostream_iterator<std::string> output_iterator(output_file, " ");
    std::copy(std::begin(data), std::end(data), output_iterator);
}
