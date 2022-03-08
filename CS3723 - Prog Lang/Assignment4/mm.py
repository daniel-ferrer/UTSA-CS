# python mm.py 4 8 -5 0 20
# prints: mm9: min=-5 max=20

import sys

def mm(args):
  x = 1000
  y = -1000
  
  for i in range(0, len(args)):
    args[i] = int(args[i])
  
  x = min(args)
  y = max(args)

  return (x, y)

(x,y) = mm(sys.argv[1:])
print("mm9: min=%d max=%d" % (x, y))
