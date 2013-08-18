def to_decimal(num, base):
	ans = 0
	for i, x in enumerate(num[::-1]):
		x = (ord(x) - ord('A') + 10) if x in "ABCDEF" else int(x)
		ans += x * (int(base)**i)
	return ans

def main():
	inp = raw_input().strip().split()
	
	# Convert to postfix
	stack = []
	postfix = []

	for term in inp:
		if term in '+-' and stack and stack[-1] == '*':
			while stack:
				postfix.append(stack.pop())
		elif term not in '+-*':
			postfix.append(to_decimal(*term.split('_')))

		if term in '+-*':
			stack.append(term)

	while stack:
		postfix.append(stack.pop())

	operands = []


	for term in postfix:
		if term == '+':
			operands[-2] += operands[-1]
		elif term == '-':
			operands[-2] -= operands[-1]
		elif term == '*':
			operands[-2] *= operands[-1]
		else:
			operands.append(term)

		if str(term) in '+-*':
			operands.pop()

	print operands[0]

if __name__ == '__main__':
	main()