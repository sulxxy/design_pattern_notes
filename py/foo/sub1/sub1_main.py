print('sub1_main: name: {}, pacakge: {}'.format(__name__, __package__))
import sys
print(sys.path)
# from ..sub2 import utils as utils2
import foo.sub1.utils