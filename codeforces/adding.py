from collections import deque
from math import log, ceil

def readint():
	return map(int, raw_input().strip().split())
a, b, n = readint()
size = n + len(str(a))
Q = deque()
if ((a*10) % b == 0) and ((b % 5 == 0) or (b % 2 == 0)):
	print str(a) + '0' * n
else:
	Q.append((a, len(str(a))))
	last = b % 10
	check = set((last * i) % 10 for i in xrange(10))
	x = 0
	flag = True
	while Q:
		curr, l = Q.popleft()
		if  l == size :
			flag = False
			print curr
			break
		for i in check:
			if (curr * 10 + i) % b == 0:
				Q.append((curr*10 + i, l+1))

	if flag:
		print -1
