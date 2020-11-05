print('foo.sub1.utils: name: {}, package: {}'.format(__name__, __package__))
import os
dir_path = os.path.dirname(os.path.realpath(__file__))
cwd = os.getcwd()
print('foo.sub1.utils: dir: {}, name: {}, current working dir: {}'.format(dir_path,__name__, cwd))

from ..sub2 import utils as utils2
# from foo.sub2 import utils as utils2