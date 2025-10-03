def solve(Q,Queries):
    N = 0

    for i in range(Q):
        N = max(N,int(Queries[i][1]))

    answers=  []
    pre = [0]
    sum = 0

    for i in range(1,N+1):
        temp = i
        cnt  =0 
        while((temp)):
            temp//=4
            cnt+=1
        sum+= cnt
        pre.append(sum)


    for i in range(Q):
        arr = Queries[i]
        left = int(arr[0])
        right = int(arr[1])
        ans = 2*(pre[left]-pre[left-1]) + pre[right] - pre[left]
        answers.append(ans)
    return answers

Q = int(input())
inps = []
for i in range(Q):
    r = input()
    val = r.split(" ")
    inps.append(val)
print(solve(Q,inps))


