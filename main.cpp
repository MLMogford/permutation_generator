#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

//The numbers within the vector are permuted
bool permutations(std::vector<int> &vec) {
    // the point of transition from increment to decrement is found
    if (vec.empty()) {
        return false;
    }
    auto i = vec.end() - 1;
    while (i > vec.begin() && *(i - 1) >= *i) {
        --i;
    }
    if (i == vec.begin()) {
        return false;
    }

    // determine the point to pivot the vector and swap these values
    auto j = vec.end() - 1;
    while (*j <= *(i - 1)) {
        --j;
    }

    std::swap(*(i - 1), *j);

    // Arrange suffix into ascending order
    std::reverse(i, vec.end());
    return true;
}

//calls the permutations function for vector v
//returns number of permutations generated from initial vector
void printPermutations(std::vector<int> &v) {
    int count;
    for (count = 0; permutations(v); ++count) {

        for (int i = 0; i < 9; i++) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    }
    std::cout << count << std::endl;
}

//entry point, records and prints time for function to complete
//return 0 on success
//defines vector v of ints
int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto clock_begin = std::chrono::steady_clock::now();
    printPermutations(v);
    auto clock_end = std::chrono::steady_clock::now();
    std::chrono::steady_clock::duration time_span = clock_end - clock_begin;
    double useconds = std::chrono::duration_cast<std::chrono::milliseconds>(time_span).count();
    std::cout << useconds << "ms" << std::endl;

    return EXIT_SUCCESS;
}