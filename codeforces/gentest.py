from random import randint

print 10, randint(2, 5)
print ' '.join(str(randint(1, 100)) for i in xrange(10))
