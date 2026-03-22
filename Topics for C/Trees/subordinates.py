import sys

sys.setrecursionlimit(10**7)

def dfs(parent : int ,adjList: list[list] , ans: list) -> int:
    s = len(adjList[parent])
    for i in range(len(adjList[parent])):
        s+=dfs(adjList[parent][i] ,adjList ,ans)
    ans[parent]=s
    return s


n = int(input())

adjList,ans = [[] for _ in range(n+1)] , [0]*(n+1)

ls = [int(i) for i in input().split()]

for i in range(len(ls)) :
    child = i+2
    parent = ls[i]
    adjList[parent].append(child)

dfs(1 , adjList , ans)

for i in range(1 , len(ans)) :
    print(ans[i] , end = " ")
