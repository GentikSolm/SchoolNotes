#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <numeric>

struct follows
{
    std::string id;
    int num;
    bool operator<(follows& rhs) { return num < rhs.num; };
    operator int(){return num;}
};

using adjacency_list = std::map<std::string, std::list<std::string>>;
void adj_list_insert(adjacency_list& adj, std::string u, std::string v)
{
    adj[u].push_back(v);
}

auto median(std::vector<follows>& len)
{
    return len[len.size()/2 -1];
}

auto mean(std::vector<follows>& len)
{
    return std::accumulate(len.begin(), len.end(), 0)/len.size();
}

std::vector<follows> set_up_vec(adjacency_list& adj)
{
    static std::vector<follows> vec;
    for(auto i : adj) vec.push_back( {i.first, int(i.second.size())} );

    std::sort(std::begin(vec), std::end(vec));
    return vec;

}
void print_top_ten(std::vector<follows>& vec)
{
    for(auto i : vec) std::cout << i.num << std::endl;
}



int main()
{
    std::string str, atr;
    adjacency_list adj;
    std::fstream file{"input.txt"};

    file >> str >> atr;
    while(file >> str >> atr) adj_list_insert(adj, str, atr);
    std::cout << adj["1570"].size() << std::endl;
    auto v = set_up_vec(adj);
    //print_top_ten(v);
    std::cout << median(v);
    std::cout << "|";

}
