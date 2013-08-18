# The Z algorithm (linear time pattern matching)


def find(text, pattern):
	S = pattern + '$' + text
	Z = [0] * len(S)

	# Preprocessing step
	left, right = -1, -1
	for i in xrange(1, len(S)):
		if i > right:
			left, right = i, i
			while right < len(S) and S[right - left] == S[right]:
				right += 1
			Z[i] = right - left
			right -= 1
		elif Z[i - left] < (right - i + 1):
			Z[i] = Z[i - left]
		else:
			left = i
			while right < len(S) and S[right - left] == S[right]:
				right += 1
			Z[i] = right - left
			right -= 1

	return max(Z[len(pattern):]) == len(pattern)


print find('vivekviaz', 'viaz')



