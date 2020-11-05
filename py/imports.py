import sys
print(sys.modules.get('platform', 'not found'))
import platform
print(sys.modules.get('platform', 'not found'))