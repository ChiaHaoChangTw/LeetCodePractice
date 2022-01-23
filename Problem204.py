class Solution:
	def countPrimes(self, n):
		if n <= 2:
			return 0
		isPrime = [True] * n
		count = 1
		for i in range(3, n, 2):
			if isPrime[i]:
				count += 1
				for j in range(3, n // i + 1, 2):
					isPrime[i * j] = False
		return count

if __name__ == "__main__":
	solution = Solution()
	print(solution.countPrimes(10), "[expected: 4]")
	print(solution.countPrimes(0), "[expected: 0]")
	print(solution.countPrimes(1), "[expected: 0]")
	print(solution.countPrimes(110), "[expected: 29]")
