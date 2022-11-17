class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        PLUS, MINUS, PRODUCT = -1, -2, -3

        def getPriority(opt):
            return 1 if opt == PRODUCT else 0

        def calc(a, b, opt):
            if opt == PLUS: return a + b
            if opt == MINUS: return a - b
            return a * b

        def toString(arr):
            ans = ""
            for x in arr:
                if x == PLUS: ans += "+"
                elif x == MINUS: ans += "-"
                elif x == PRODUCT: ans += "*"
                else: ans += str(x)
            return ans

        def evaluate(arr):
            if len(arr) == 0: return None
            numStack = []
            optStack = []
            for x in arr:
                if x == PRODUCT or x == PLUS or x == MINUS:
                    while len(optStack) > 0 and getPriority(x) <= getPriority(optStack[-1]):
                        a = numStack.pop()
                        b = numStack.pop()
                        c = calc(b, a, optStack.pop())
                        numStack.append(c)
                    optStack.append(x)
                else:
                    numStack.append(x)
            while len(optStack) > 0:
                a = numStack.pop()
                b = numStack.pop()
                c = calc(b, a, optStack.pop())
                numStack.append(c)
            return numStack[-1]

        def backtrack(i, curr, result, canOpt, size):
            if i == len(num):
                result = result + [curr]
                if evaluate(result) == target:
                    ans.append(toString(result))
                return

            if size == 0 or curr > 0:
                backtrack(i + 1, curr * 10 + int(num[i]), result, True, 1)
            if canOpt:
                backtrack(i, 0, result + [curr, PLUS], False, 0)
                backtrack(i, 0, result + [curr, MINUS], False, 0) 
                backtrack(i, 0, result + [curr, PRODUCT], False, 0) 

        ans = []
        backtrack(0, 0, [], False, 0)
        return ans