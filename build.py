import os
import sys
import shutil

vulkan_lib = "vulkan"

o_name = "yzhr.dll"
hh = " -ldl"
a = ""
o1 = ".o"
oa = "lib"
ob = ".a"
platform = sys.platform
ww = ""
lll = "lib"
if platform == "linux":
    o_name = "libengine.so"
    a = " -fPIC"
elif platform == "win32" or platform == "win64":
    o_name = "engine.dll"
    o1 = ".obj"
    oa = ""
    ob = ".lib"
    hh = ""
    ww = "C:"
    vulkan_lib = "vulkan-1"
    lll = "Lib"

vulkan_path = f"{ww}/VulkanSDK/1.3.290.0"

inc = f" -I./include -I{vulkan_path}/include"
L = f" -L{vulkan_path}/{lll} -l{vulkan_lib}"

r = os.system(f"clang{a} -shared -o build/{o_name}{inc}{L} src/Engine.c -std=c17")

if r == 0:
    r = os.system(f"clang -c interface/interface.c -I./include -o build/interface{o1} -std=c17")
    if r == 0:
        r = os.system(f"ar rcs build/{oa}interface{ob} build/interface{o1}{hh}")