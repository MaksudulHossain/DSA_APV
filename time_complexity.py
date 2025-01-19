import time 

n = 100000

# O(n^2) is a big no-no!
start = time.time()
for i in range(n):
    for i in range(n):
        print(i)

endtime = time.time() 

print(f"time taken {endtime - start}")