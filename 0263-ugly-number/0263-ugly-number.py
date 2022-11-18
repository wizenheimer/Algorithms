class Solution:
    def isUgly(self, n: int) -> bool:
        return n > 0 and (2**30)*(3**20)*(5**13) % n == 0