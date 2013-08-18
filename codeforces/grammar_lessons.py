def is_masc(word):
	return word[-4:] == "lios" or word[-3:] == "etr" or word[-6:] == "initis"
def is_fem(word):
	return word[-5:] == "liala" or word[-4:] == "etra" or word[-6:] == "inites"


words = raw_input().strip().split()
print "YES" if (all(map(is_fem, words)) or all(map(is_masc, words))) else "NO"