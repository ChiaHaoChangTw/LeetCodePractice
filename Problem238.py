class Solution(object):
	def productExceptSelf(self, nums):
        	left, right = 1, 1
        	result = [1] * len(nums)
        	for i in range(1, len(nums)):
            		left *= nums[i - 1]
            		right *= nums[len(nums) - i]
            		result[i] *= left
            		result[len(nums) - i - 1] *= right
        	return result

if __name__ == "__main__":
	solution = Solution()
	print(solution.productExceptSelf([1,2,3,4]), "[expected: [24,12,8,6]]")
	print(solution.productExceptSelf([-1,1,0,-3,3]), "[expected: [0,0,9,0,0]]")
