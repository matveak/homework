#include <iostream>
#include <vector>
#include <numeric> 


template <typename T>
T calculateAverage(const std::vector<std::vector<T>>& data) {
    if (data.empty()) {
        return 0;
    }

    size_t totalElements = 0;
    T sum = 0;

    for (const auto& row : data) {
        totalElements += row.size();
        sum = std::accumulate(row.begin(), row.end(), sum);
    }

    if (totalElements == 0) {
        return 0;
    }
    return sum / totalElements;
}

int main() {
    std::vector<std::vector<int>> intData = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    };
    double intAverage = calculateAverage(intData);
    std::cout << intAverage << std::endl;

    std::vector<std::vector<double>> doubleData = {
      {1.5, 2.5, 3.5},
      {4.5, 5.5, 6.5},
      {7.5, 8.5, 9.5}
    };
    double doubleAverage = calculateAverage(doubleData);
    std::cout << doubleAverage << std::endl;


    std::vector<std::vector<int>> emptyData;
    double emptyAverage = calculateAverage(emptyData);
    std::cout << emptyAverage << std::endl;

    return 0;
}//простите 1 раз но так быстрее всего 