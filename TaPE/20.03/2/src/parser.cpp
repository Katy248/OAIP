#include "parser.h"

vector<int> parse(char *arg, int len)
{
    vector<int> result{};
    int cur_num = 0;
    bool is_empty = true;
    for (int i = 0; i < len; i++)
    {
        if ((int)arg[i] >= 48 && (int)arg[i] <= 57)
        {
            cur_num *= 10;
            cur_num += (int)arg[i] - 48;
            is_empty = false;
        }
        else
        {
            if (!is_empty)
            {
                result.push_back(cur_num);
                cur_num = 0;
                is_empty = true;
            }
        }
    }
    if (!is_empty)
    {
        result.push_back(cur_num);
    }

    return result;
}
