# Python中的模块和包
## Python基本概念
1. module
   
   模块， 一个 py 文件或以其他文件形式存在的可被导入的就是一个模块
2. package
   
   包，包含有 __init__ 文件的文件夹
3. relative path
   
   相对路径，相对于某个目录的路径
4. absolute path
   
   绝对路径，全路径

## Python包搜索/导入顺序
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
   
### virtualenv原理
基于搜索顺序，可以大致了解到virtualenv的原理：
启动过程：
```sh
virtualenv ENV
source bin/activate
```
查看bin/activate可以发现如下内容：
```sh
# unset irrelevant variables
deactivate nondestructive

VIRTUAL_ENV='/home/zhiwei/projects/design_pattern_notes/py/venvp/venvs'
if ([ "$OSTYPE" = "cygwin" ] || [ "$OSTYPE" = "msys" ]) && $(command -v cygpath &> /dev/null) ; then
    VIRTUAL_ENV=$(cygpath -u "$VIRTUAL_ENV")
fi
export VIRTUAL_ENV

_OLD_VIRTUAL_PATH="$PATH"
PATH="$VIRTUAL_ENV/bin:$PATH"
export PATH
```
可以看到，执行activate时，实际上是在当前Path最开始插入了virtual env的路径，这样就会被python优先查找到。

通过python解释器检查环境变量：
```python
import sys
print(sys.prefix)
print(sys.path)
/home/zhiwei/projects/design_pattern_notes/py/venvp/venvs
['/home/zhiwei/projects/design_pattern_notes/py/venvp', '/usr/lib/python36.zip', '/usr/lib/python3.6', '/usr/lib/python3.6/lib-dynload', '/home/zhiwei/projects/design_pattern_notes/py/venvp/venvs/lib/python3.6/site-packages']
```


Python安装包时，会优先安装到sys.prefix/lib/python$ver/site-packages.
```sh
python3 -m site

sys.path = [
    '/home/zhiwei/projects/design_pattern_notes/py/venvp',
    '/usr/lib/python36.zip',
    '/usr/lib/python3.6',
    '/usr/lib/python3.6/lib-dynload',
    '/home/zhiwei/projects/design_pattern_notes/py/venvp/venvs/lib/python3.6/site-packages',
]
USER_BASE: '/home/zhiwei/.local' (exists)
USER_SITE: '/home/zhiwei/.local/lib/python3.6/site-packages' (exists)
ENABLE_USER_SITE: False
```
virtual env并不会把所有的python包都拷贝到当前目录。
```python
import os
print('os path: {}'.format(os.__file__))
import numpy
print('numpy path: {}'.format(numpy.__file__))

os path: /usr/lib/python3.6/os.py
numpy path: /home/zhiwei/projects/design_pattern_notes/py/venvp/venvs/lib/python3.6/site-packages/numpy/__init__.py
```

## import与C/C++的include的区别
1. import只导入一次，第一次导入时会编译生成pyc；
2. 下次再被导入时，直接复用pyc即可；
3. import的本质: 放入`sys.modules`中， [example](./imports.py)。

# Python项目结构
三种方法：
1. 相对路径: 见foo
   > PEP 328
   
   >Relative imports use a module’s `__name__`attribute to determine that module’s position in the package hierarchy. If the module’s name does not contain any package information (e.g. it is set to`__main__`) then relative imports are resolved as if the module were a top level module, regardless of where the module is actually located on the file system.
   相对导入通过使用模块的 `__name__`属性来确定模块在包层次结构中的位置。如果该模块的名称不包含任何包信息（例如，它被设置为`__main__`），那么相对引用会认为这个模块就是顶级模块，而不管模块在文件系统上的实际位置。
   换句话说，解决模块的算法是基于`__name__`和`__package__`变量的值。大部分时候，这些变量不包含任何包信息 ---- 比如：当 `__name__ = __main__` 和 `__package__ = None` 时，python解释器不知道模块所属的包。在这种情况下，相对引用会认为这个模块就是顶级模块，而不管模块在文件系统上的实际位置。
2. 绝对路径:直接看Triton代码
3. 直接强行修改sys.path

# 参考链接
* https://www.kawabangga.com/posts/3543
* https://sanyuesha.com/2016/05/28/python-module-path-find/
* https://michael728.github.io/2018/12/15/python-package-import-order/
* https://www.cnblogs.com/yuandonghua/p/11771055.html
* http://net-informations.com/python/iq/pyc.htm#:~:text=pyc%20contain%20the%20compiled%20bytecode,interpreter%20compiles%20the%20source%20to.&text=But%20interpreters%20take%20human%20readable,this%20with%20an%20intermediate%20stage%20.
* 关于attempted relative import beyond top-level package的解释：https://blog.csdn.net/qiusuoxiaozi/article/details/79061885