import os
import sys
import shutil

o_name = "yzhr.dll"
hh = " -ldl"
a = ""
o1 = ".o"
oa = "lib"
ob = ".a"
platform = sys.platform
if platform == "linux":
    o_name = "libyzhr.so"
    a = " -fPIC"
elif platform == "win32" or platform == "win64":
    o_name = "yzhr.dll"
    o1 = ".obj"
    oa = ""
    ob = ".lib"
    hh = ""
elif platform == "darwin":
    o_name = "libyzhr.dylib"
    a = " -fPIC"

inc = " -I./include"
L = ""

r = os.system(f"clang{a} -shared -o build/{o_name}{inc}{L} src/yzhr.c -std=c17")

if r == 0:
    r = os.system(f"clang -c yzhrInterface/yzhrInterface.c -I./include -o build/yzhrInterface{o1}{hh}")
    if r == 0:
        r = os.system(f"ar rcs build/{oa}yzhrInterface{ob} build/yzhrInterface{o1}")