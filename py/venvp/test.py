import sys
print(sys.prefix)
print(sys.path)

import os
print('os path: {}'.format(os.__file__))

import numpy
print('numpy path: {}'.format(numpy.__file__))

print(sys.modules)