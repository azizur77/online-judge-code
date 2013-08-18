from random import choice, randint, shuffle

alphabet = 'abcdefghijklmnopqrstuvwxyz'

def word(n):
	return ([choice(alphabet) for i in range(n)])

def board(n, m):
	ele = '.X'

l = [word(5) for i in range(20)]
m = l[:]
for i in range(len(m)):
	shuffle(m[i])
l += m
print [''.join(x) for x in l]