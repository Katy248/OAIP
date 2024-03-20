#include "parser.h"

int main(int argc, char **argv)
{
    vector<int> nums;
    if (argc > 1)
    {
        nums = parse(argv[1], sizeof(argv[1]) / sizeof(char));
    }
    else
    {
        std::string str;
        getline(cin, str);
        nums = parse((char *)str.c_str(), str.size());
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "\n";
    }

    return 0;
}
