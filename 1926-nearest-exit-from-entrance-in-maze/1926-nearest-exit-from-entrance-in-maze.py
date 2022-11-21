class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        dirs = [(0,1),(0,-1),(1,0),(-1,0)]
        entrance = (entrance[0],entrance[1])
        q = deque([entrance])
        visited = set()
        visited.add(entrance)
        step = 0
        while q:
            stepLength = len(q)
            for i in range(stepLength):
                node = q.popleft()
                if node[0] == 0 or node[0] == len(maze) -1 or node[1] == 0 or node[1] == len(maze[0]) -1 :
                    if maze[node[0]][node[1]] == '.' and (node[0],node[1]) != entrance:
                        return step
                for d in dirs:
                    newD = (node[0] + d[0], node[1] + d[1])
                    if newD not in visited and 0<=newD[0]<len(maze) and 0<=newD[1]<len(maze[0]) and maze[newD[0]][newD[1]] == '.':
                        visited.add(newD)
                        q.append(newD)
            step += 1
        return -1