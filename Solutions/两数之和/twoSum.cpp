#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
	std::vector<int> twoSumS1(std::vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					return std::vector<int> {i, j};
				}
			}
		}
		return std::vector<int>();
	}

	std::vector<int> twoSumS2(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m.insert(std::make_pair(nums[i], i));
		}

		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (m.find(complement) != m.end() && m.find(complement)->second != i) {
				return std::vector<int> {i, m.find(complement)->second};
			}
		}
		return std::vector<int>();
	}

	std::vector<int> twoSumS3(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (m.find(complement) != m.end()) {
				return std::vector<int> {m.find(complement)->second, i};
			}
			m.insert(std::make_pair(nums[i], i));
		}
		return std::vector<int>();
	}
};

int main() {
	Solution solution;
	std::vector<int> nums = { 2, 7, 11, 15};
	int target = 9;

	std::cout << "nums are: ";
	for (int i : nums)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "target is: " << target << std::endl;

	std::cout << "twoSumS1: ";
	for (int i : solution.twoSumS1(nums, target))
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "twoSumS2: ";
	for (int i : solution.twoSumS2(nums, target))
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "twoSumS3: ";
	for (int i : solution.twoSumS3(nums, target))
		std::cout << i << " ";
	std::cout << std::endl;

	system("PAUSE");
	return 0;
}