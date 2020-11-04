import os
dir_path = os.path.dirname(os.path.realpath(__file__))
cwd = os.getcwd()
print('foo.utils: dir: {}, cwd: {}'.format(dir_path, cwd))

import sub1.utils