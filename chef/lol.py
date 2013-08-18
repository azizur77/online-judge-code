T = input()
for i in xrange(T):
	s = set(list(raw_input().strip().lower()))
	flag = False
	for char in xrange(97, 123):
		if chr(char) not in s:
			print chr(char)
			flag = True
			break
	if not flag:
		print '~'