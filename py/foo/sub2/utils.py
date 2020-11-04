import os
dir_path = os.path.dirname(os.path.realpath(__file__))
cwd = os.getcwd()
print('foo.sub2.utils: dir: {}, cwd: {}'.format(dir_path, cwd))