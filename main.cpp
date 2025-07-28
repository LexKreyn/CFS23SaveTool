#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<uint8_t> xor_data(const vector<uint8_t>& data, const string& key) {
    vector<uint8_t> result;
    result.reserve(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.push_back(data[i] ^ key[i % key.size()]);
    }
    return result;
}

string process_path(string path) {
    path.erase(path.begin(), find_if(path.begin(), path.end(), [](int ch) { return !isspace(ch) && ch != '"'; }));
    path.erase(find_if(path.rbegin(), path.rend(), [](int ch) { return !isspace(ch) && ch != '"'; }).base(), path.end());

    if (path.empty() || path == "." || path.back() == '/' || path.back() == '\\') {
        path += "gamesaves.cfs23";
    }

    return path;
}

int main(int argc, char* argv[]) {
    const string key = "4282840";
    string path;

    if (argc > 1) {
        path = process_path(argv[1]);
        argc--;
    }

    while (true) {
        if (path.empty()) {
            cout << "Enter save path (to gamesaves.cfs23) >> ";
            getline(cin, path);
            path = process_path(path);
        }

        ifstream file(path, ios::binary);
        if (file.good()) {
            vector<uint8_t> data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            vector<uint8_t> result = xor_data(data, key);
            ofstream(path, ios::binary).write((char*)result.data(), result.size());
            cout << "File processed successfully!\n";
            return 0;
        }

        cout << "Path does not exist, please try again\n";
 
        path.clear();
    }
}