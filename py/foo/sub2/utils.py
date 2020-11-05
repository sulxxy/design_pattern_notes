print('foo.sub2.utils: name: {}, pakcage: {}'.format(__name__, __package__))
import os
dir_path = os.path.dirname(os.path.realpath(__file__))
cwd = os.getcwd()
print('foo.sub2.utils: dir: {}, name: {}, current working dir: {}'.format(dir_path, __name__, cwd))