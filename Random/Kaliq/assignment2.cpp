#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;  // To store numbers and their indices

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if the complement is in the map and its index is not the same as the current index
        if (numMap.find(complement) != numMap.end() && numMap[complement] != i) {
            return {numMap[complement], i};
        }

        numMap[nums[i]] = i;  // Store the current number and its index
    }

    // If no solution is found, return an empty vector
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices of the two numbers: " << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}