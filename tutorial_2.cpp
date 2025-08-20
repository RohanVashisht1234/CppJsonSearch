#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main() {
    ifstream f("./corpus_data/associations.csv");

    string line;
    vector<vector<string>> entire_parsed_csv;

    while(getline(f, line)) {

        vector<string> tokens;

        stringstream ss(line);
        string token;

        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        entire_parsed_csv.push_back(tokens);
    }

    for(const auto& line_as_tokens:  entire_parsed_csv) {
        for(const auto& token: line_as_tokens) {
            cout << token << ",";
        }
        cout << endl;
    }

    return 0;
}