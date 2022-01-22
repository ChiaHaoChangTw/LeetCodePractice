#solution for LeetCode problem 202
class Solution:
    def isHappy(self, n: int) -> bool:
        def getNext(number):
            result = 0
            while number > 0:
                number, digit = divmod(number, 10)
                result += digit ** 2
            return result
        walk = n
        run = getNext(n)
        while run != 1:
            if walk == run:
                return False
            run = getNext(getNext(run))
            walk = getNext(walk)
        return True

if __name__ == "__main__":
	solution = Solution()
	print(solution.isHappy(19), "[expected: True]") #should return True
	print(solution.isHappy(2), "[expected: False]") #should return False
