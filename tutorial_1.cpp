#include <iostream>
#include <fstream>
#include "json.hpp"
#include <map>
using namespace std;

using json = nlohmann::json;

int main()
{
    const string search_query = "hello";

    ifstream f("./database.json");
    const json db = json::parse(f);

    map<string, int> hashmap;

    for (const auto &single_object : db)
    {
        int score = 0;
        const string title = single_object["title"];
        const string description = single_object["description"];
        const string content = single_object["content"];

        const size_t titleFound = title.find(search_query);
        const size_t descriptionFound = description.find(search_query);
        const size_t contentFound = content.find(search_query);

        if (titleFound != string::npos)
        {
            score += 20;
        }
        if (descriptionFound != string::npos)
        {
            score += 10;
        }
        if (contentFound != string::npos)
        {
            score += 5;
        }

        hashmap.insert({title, score});
    }

    for (const auto &pair : hashmap)
    {
        cout << "Title: " << pair.first << endl
             << "Score: " << pair.second << endl
             << endl;
    }

    return 0;
}