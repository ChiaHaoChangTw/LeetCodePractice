class Solution:
	def twoSum(self, nums, target):
		hashMap = {}
		for i in range(len(nums)):
			if target - nums[i] in hashMap:
				return [hashMap[target - nums[i]], i]
			hashMap[nums[i]] = i

if __name__ == "__main__":
	solution = Solution()
	print(solution.twoSum([3, 2, 4], 6), "[expected: [1, 2]]")
	print(solution.twoSum([2, 7, 11, 15], 9), "[expected: [0, 1]]")
	print(solution.twoSum([3, 3], 6), "[expected: [0, 1]]")
