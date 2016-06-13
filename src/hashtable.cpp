#include <iostream>
#include <unordered_map>
#include <string>
#include <cassert>
using namespace std;

int main() {
    unordered_map<string, string> hashmap;
    hashmap = {{"a", "A"}, {"b", "B"}, {"c", "C"}, {"d", "D"}, {"dsfasdf", "ddd"}};
    cout << "Log data:" << endl;
    for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
        cout << it->first << ":" << it->second << endl;
    }

    cout << "Hash table buckets: " << hashmap.bucket_count() << endl;
    for (unsigned i = 0; i < hashmap.bucket_count(); ++i) {
        auto l_it = hashmap.begin(i);
        cout << "Bucket #" << i << ": " << endl;
        for (auto sub_it = hashmap.begin(i); sub_it != hashmap.end(i); ++sub_it) {
            cout << sub_it->first << " -> " << sub_it->second << endl;
        }
        cout << endl;
    }
    return 0;
}
