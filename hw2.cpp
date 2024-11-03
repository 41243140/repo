#include <iostream>
#include <vector>
#include <set>

std::set<std::set<char>> powerset(const std::set<char>& S) {
    if (S.empty()) {
        return { {} };
    }

    std::set<char> S_copy = S;

    char first = *S_copy.begin();
    S_copy.erase(S_copy.begin());

    std::set<std::set<char>> subsets = powerset(S_copy);

    std::set<std::set<char>> result = subsets;

    for (const auto& subset : subsets) {
        std::set<char> new_subset = subset;
        new_subset.insert(first); 
        result.insert(new_subset);
    }

    return result;
}

int main() {
    std::set<char> S = { 'a', 'b', 'c' };
    std::set<std::set<char>> result = powerset(S);

    std::cout << "{ ";
    for (const auto& subset : result) {
        std::cout << "{ ";
        for (char elem : subset) {
            std::cout << elem << " ";
        }
        std::cout << "} ";
    }
    std::cout << "}" << std::endl;

    return 0;
}