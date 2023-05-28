#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s("hello world");
    std::cout << s << std::endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::cout << v.size() << std::endl;
}