#include <iostream>
#include <string>
#include <map>

using std::string;

int solution(string, string);
std::map<char, int> frequencyByChar(string s);

int main(int argc, char const *argv[])
{
    int test;
    std::cin >> test;

    while (test--)
    {
        string a;
        string b;
        std::cin >> a >> b;
        std::cout << solution(a, b) << '\n';
    }

    return 0;
}

int solution(string a, string b)
{
    int count = 0;
    auto aCharFrequency = frequencyByChar(a);
    auto bCharFrequency = frequencyByChar(b);
    
    for (auto it = aCharFrequency.begin(); it != aCharFrequency.end(); it++)
    {
        std::map<char, int>::iterator it_x = bCharFrequency.find(it->first);
        if (it_x == bCharFrequency.end())
            count += it->second;
        else if (it->second > it_x->second)
            count += it->second - it_x->second;
    }

    for (auto it = bCharFrequency.begin(); it != bCharFrequency.end(); it++)
    {
        std::map<char, int>::iterator it_x = aCharFrequency.find(it->first);
        if (it_x == bCharFrequency.end())
            count += it->second;
        else if (it->second > it_x->second)
            count += it->second - it_x->second;
    }
    
    return count;
}

std::map<char, int> frequencyByChar(string s)
{
    std::map<char, int> res;
    std::map<char, int>::iterator it;
    for (char c : s)
    {
        it = res.find(c);
        if (it == res.end())
            res.insert(it, std::pair<char, int>(c, 1));
        else
        {
            it->second++;
        }
    }
    return res;
}
