T = int(input())
for t in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    print("YES" if int(sum(a)**0.5)**2 == sum(a) else "NO")