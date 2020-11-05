import sys
print('Before import: {}'.format(sys.path))
import pths
print('After import: {}'.format(sys.path))
sys.path.append('/home/zhiwei/projects/design_pattern_notes/py/pths')
print('After append: {}'.format(sys.path))
import site
site.addsitedir('/home/zhiwei/projects/design_pattern_notes/py/pths')
print('After site append: {}'.format(sys.path))