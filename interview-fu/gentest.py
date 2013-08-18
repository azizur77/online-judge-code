from random import randint
print 100
print ' '.join(map(str, (randint(1, 3) for i in xrange(100))))