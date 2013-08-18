s = raw_input().strip()
while True:
	if s.find('yx') != -1:
		s = s.replace('yx', 'xy')
	elif s.find('xy') != -1:
		s = s.replace('xy', '')
	else:
		break
print s