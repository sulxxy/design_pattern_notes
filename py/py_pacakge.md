# Python中的模块和包
# Python项目结构
# Python包搜索/导入顺序
1. 优先在内建的模块中搜索（`sys.builtin_module_name`）。
    ```python
    import sys
    print(sys.builtin_module_names)
    ('_ast', '_bisect', '_blake2', '_codecs', '_collections', '_datetime', '_elementtree', '_functools', '_heapq', '_imp', '_io', '_locale', '_md5', '_operator', '_pickle', '_posixsubprocess', '_random', '_sha1', '_sha256', '_sha3', '_sha512', '_signal', '_socket', '_sre', '_stat', '_string', '_struct', '_symtable', '_thread', '_tracemalloc', '_warnings', '_weakref', 'array', 'atexit', 'binascii', 'builtins', 'cmath', 'errno', 'faulthandler', 'fcntl', 'gc', 'grp', 'itertools', 'marshal', 'math', 'posix', 'pwd', 'pyexpat', 'select', 'spwd', 'sys', 'syslog', 'time', 'unicodedata', 'xxsubtype', 'zipimport', 'zlib')
    ```
2. 同时需要注意，解释器启动时会默认加载一些内建模块，还会加载其他一些标准库，都存放在`sys.modules`字典中，这会导致遮蔽，[example](./import_orders/import_order.py)。
   ```sh
   $ tree import_orders
    .
    ├── __pycache__
    │   └── platform.cpython-36.pyc
    ├── import_order.py
    ├── math.py
    ├── os.py
    └── platform.py
   $ cat import_order.py

    import sys
    print('Built in modules: ')
    print(sys.builtin_module_names)
    print('Automatically imported modules: ')
    print(sys.modules)
    import math
    import os
    import platform

   $ python3 import_order.py

    Built in modules: 
    ('_ast', '_bisect', '_blake2', '_codecs', '_collections', '_datetime', '_elementtree', '_functools', '_heapq', '_imp', '_io', '_locale', '_md5', '_operator', '_pickle', '_posixsubprocess', '_random', '_sha1', '_sha256', '_sha3', '_sha512', '_signal', '_socket', '_sre', '_stat', '_string', '_struct', '_symtable', '_thread', '_tracemalloc', '_warnings', '_weakref', 'array', 'atexit', 'binascii', 'builtins', 'cmath', 'errno', 'faulthandler', 'fcntl', 'gc', 'grp', 'itertools', 'marshal', 'math', 'posix', 'pwd', 'pyexpat', 'select', 'spwd', 'sys', 'syslog', 'time', 'unicodedata', 'xxsubtype', 'zipimport', 'zlib')
    Automatically imported modules: 
    {'builtins': <module 'builtins' (built-in)>, 'sys': <module 'sys' (built-in)>, '_frozen_importlib': <module 'importlib._bootstrap' (frozen)>, '_imp': <module '_imp' (built-in)>, '_warnings': <module '_warnings' (built-in)>, '_thread': <module '_thread' (built-in)>, '_weakref': <module '_weakref' (built-in)>, '_frozen_importlib_external': <module 'importlib._bootstrap_external' (frozen)>, '_io': <module 'io' (built-in)>, 'marshal': <module 'marshal' (built-in)>, 'posix': <module 'posix' (built-in)>, 'zipimport': <module 'zipimport' (built-in)>, 'encodings': <module 'encodings' from '/usr/lib/python3.6/encodings/__init__.py'>, 'codecs': <module 'codecs' from '/usr/lib/python3.6/codecs.py'>, '_codecs': <module '_codecs' (built-in)>, 'encodings.aliases': <module 'encodings.aliases' from '/usr/lib/python3.6/encodings/aliases.py'>, 'encodings.utf_8': <module 'encodings.utf_8' from '/usr/lib/python3.6/encodings/utf_8.py'>, '_signal': <module '_signal' (built-in)>, '__main__': <module '__main__' from 'import_order.py'>, 'encodings.latin_1': <module 'encodings.latin_1' from '/usr/lib/python3.6/encodings/latin_1.py'>, 'io': <module 'io' from '/usr/lib/python3.6/io.py'>, 'abc': <module 'abc' from '/usr/lib/python3.6/abc.py'>, '_weakrefset': <module '_weakrefset' from '/usr/lib/python3.6/_weakrefset.py'>, 'site': <module 'site' from '/usr/lib/python3.6/site.py'>, 'os': <module 'os' from '/usr/lib/python3.6/os.py'>, 'errno': <module 'errno' (built-in)>, 'stat': <module 'stat' from '/usr/lib/python3.6/stat.py'>, '_stat': <module '_stat' (built-in)>, 'posixpath': <module 'posixpath' from '/usr/lib/python3.6/posixpath.py'>, 'genericpath': <module 'genericpath' from '/usr/lib/python3.6/genericpath.py'>, 'os.path': <module 'posixpath' from '/usr/lib/python3.6/posixpath.py'>, '_collections_abc': <module '_collections_abc' from '/usr/lib/python3.6/_collections_abc.py'>, '_sitebuiltins': <module '_sitebuiltins' from '/usr/lib/python3.6/_sitebuiltins.py'>, 'sysconfig': <module 'sysconfig' from '/usr/lib/python3.6/sysconfig.py'>, '_sysconfigdata_m_linux_x86_64-linux-gnu': <module '_sysconfigdata_m_linux_x86_64-linux-gnu' from '/usr/lib/python3.6/_sysconfigdata_m_linux_x86_64-linux-gnu.py'>, '_bootlocale': <module '_bootlocale' from '/usr/lib/python3.6/_bootlocale.py'>, '_locale': <module '_locale' (built-in)>, 'types': <module 'types' from '/usr/lib/python3.6/types.py'>, 'functools': <module 'functools' from '/usr/lib/python3.6/functools.py'>, '_functools': <module '_functools' (built-in)>, 'collections': <module 'collections' from '/usr/lib/python3.6/collections/__init__.py'>, 'operator': <module 'operator' from '/usr/lib/python3.6/operator.py'>, '_operator': <module '_operator' (built-in)>, 'keyword': <module 'keyword' from '/usr/lib/python3.6/keyword.py'>, 'heapq': <module 'heapq' from '/usr/lib/python3.6/heapq.py'>, '_heapq': <module '_heapq' (built-in)>, 'itertools': <module 'itertools' (built-in)>, 'reprlib': <module 'reprlib' from '/usr/lib/python3.6/reprlib.py'>, '_collections': <module '_collections' (built-in)>, 'weakref': <module 'weakref' from '/usr/lib/python3.6/weakref.py'>, 'collections.abc': <module 'collections.abc' from '/usr/lib/python3.6/collections/abc.py'>, 'importlib': <module 'importlib' from '/usr/lib/python3.6/importlib/__init__.py'>, 'importlib._bootstrap': <module 'importlib._bootstrap' (frozen)>, 'importlib._bootstrap_external': <module 'importlib._bootstrap_external' (frozen)>, 'warnings': <module 'warnings' from '/usr/lib/python3.6/warnings.py'>, 'importlib.util': <module 'importlib.util' from '/usr/lib/python3.6/importlib/util.py'>, 'importlib.abc': <module 'importlib.abc' from '/usr/lib/python3.6/importlib/abc.py'>, 'importlib.machinery': <module 'importlib.machinery' from '/usr/lib/python3.6/importlib/machinery.py'>, 'contextlib': <module 'contextlib' from '/usr/lib/python3.6/contextlib.py'>, 'zope': <module 'zope' from '/usr/lib/python3/dist-packages/zope/__init__.py'>, 'sitecustomize': <module 'sitecustomize' from '/usr/lib/python3.6/sitecustomize.py'>, 'apport_python_hook': <module 'apport_python_hook' from '/usr/lib/python3/dist-packages/apport_python_hook.py'>}
    this is my platform.py
   ```
   在上例中，`os`模块并非builtin模块，但仍然没有导入自定义的模块，是因为python解释器启动时自动缓存了`os`模块到`sys.modules`中，由于每个模块只会被导入一次，因此当前目录的`os`模块不再被导入。验证：
   ```sh
   $ cat remove_os.py
    import sys
    sys.modules.pop('os')
    import os
   $ python3 remove_os.py
    this is my os.py 
   $ ls __pycache__ 
   os.cpython-36.pyc
   ```

3. 然后就是搜索`sys.path`路径下的模块了，[example](./cwd.py)。
   ```sh
   import os, sys
   print('sys path: {}'.format(sys.path))
   print('Current working dir: {}'.format(os.getcwd()))

   sys path: ['/home/zhiwei/projects/design_pattern_notes/py', '/usr/lib/python36.zip', '/usr/lib/python3.6', '/usr/lib/python3.6/lib-dynload', '/home/zhiwei/.local/lib/python3.6/site-packages', '/usr/local/lib/python3.6/dist-packages', '/usr/lib/python3/dist-packages']
   Current working dir: /home/zhiwei/projects/design_pattern_notes/py
   ```

   pth文件：Python在遍历已知的库文件目录过程中，如果见到一个`.pth`文件，就会将文件中所记录的路径加入到 sys.path 设置中，于是`.pth`文件说指明的库也就可以被Python运行环境找到了。将`xxx.pth`文件放在特定位置，则可以让Python在加载模块时，读取`xxx.pth`中指定的路径，[example](./test_pth.py)。
   https://blog.csdn.net/kypfos/article/details/84559665
   
   virtualenv: https://www.kawabangga.com/posts/3543
   https://blog.csdn.net/Jacketinsysu/article/details/54944842

https://sanyuesha.com/2016/05/28/python-module-path-find/
https://michael728.github.io/2018/12/15/python-package-import-order/
# import与C/C++的include的区别
1. import只导入一次，第一次导入时会编译生成pyc；
2. 下次再被导入时，直接复用pyc即可；
3. import的本质: 放入`sys.modules`中， [example](./imports.py)。
https://www.cnblogs.com/yuandonghua/p/11771055.html
http://net-informations.com/python/iq/pyc.htm#:~:text=pyc%20contain%20the%20compiled%20bytecode,interpreter%20compiles%20the%20source%20to.&text=But%20interpreters%20take%20human%20readable,this%20with%20an%20intermediate%20stage%20.
