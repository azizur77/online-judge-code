def rotate(word, k):
	word = list(word)
	n = len(word)
	for i in xrange(k):
		t = word[i]
		idx = i+k
		while idx < n:
			word[idx-k] = word[idx]
			idx += k
		word[idx-k] = t
	return word

print rotate('vivek', 3)
assert rotate('vivek', 3) == 'ekviv'
