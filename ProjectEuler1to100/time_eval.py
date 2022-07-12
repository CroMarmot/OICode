#!/usr/bin/env python3
import datetime
import os
import re
import signal
import sys


debug = False
verbose = " >/dev/null" if not debug else ""
timeout = "20m"
result_folder = "../ProjectEulerTimeCost/"
time_suffix = ".time.md"


def signal_handler(sig, frame):
    print('You pressed Ctrl+C!')
    sys.exit(1)


signal.signal(signal.SIGINT, signal_handler)


def timeout_script(script):
    return f"timeout -s SIGKILL {timeout} " + script + verbose


def exec_py3(f):
    return os.system(timeout_script(f"/usr/bin/env python3 {f}"))


def exec_sh(f):
    return os.system(timeout_script(f"sh {f}"))


def exec_cpp17(f):
    os.system(f"clang++ -o a.out {f} -std=gnu++17 -O2" + verbose)
    r = os.system(timeout_script("./a.out"))
    os.system("rm a.out" + verbose)
    return r


def exec_go(f):
    return os.system(f"go run {f}" + verbose)


def exec_rust(f):
    os.system(f"rustc -o a.out {f}" + verbose)
    r = os.system(timeout_script("./a.out"))
    os.system("rm a.out" + verbose)
    return r


def exec_js(f):
    return os.system(timeout_script(f"node {f}"))


def exec_txt(f):
    return 0


def run_file(f):
    start = datetime.datetime.now()
    r = 0
    if f.endswith(".py"):
        r = exec_py3(f)
    elif f.endswith(".cpp"):
        r = exec_cpp17(f)
    elif f.endswith(".go"):
        r = exec_go(f)
    elif f.endswith(".rs"):
        r = exec_rust(f)
    elif f.endswith(".js"):
        r = exec_js(f)
    elif f.endswith(".txt"):
        r = exec_txt(f)
    elif f.endswith(".sh"):
        r = exec_sh(f)
    else:
        return False, 0
    if r != 0:
        print(f"[{f}] Failed with code [{r}]")
        if r == 2:
            # SIGINT
            sys.exit(r)
        else:
            # timeout kill了 记录超大时间
            return True, 1000000
        return False, 0
    end = datetime.datetime.now()
    return True, (end-start).total_seconds()


def eval_time(f):
    t_record = os.path.join(result_folder, f + time_suffix)

    if os.path.isfile(t_record):
        return

    print(f"[{f}] Running")
    ok, t = run_file(f)
    if ok:
        with open(t_record, 'w') as o:
            o.write(str(t))
        print(f"[{f}] Done with {str(t)}")
    else:
        print(f"[{f}] Not Support or No Result")


def gen_readme(file_dir):
    with open(os.path.join(result_folder, "README.md"), "w") as o:
        sIn = """
# In 1 min

|file|time|
|---|---|
"""

        sOver = """
# Over 1 min

|file|time|
|---|---|
"""

        names = []
        for f in os.listdir(result_folder):
            p = os.path.join(result_folder, f)
            if not os.path.isfile(p):
                continue
            if f.endswith(time_suffix):
                names.append(f)
        names.sort()
        for f in names:
            p = os.path.join(result_folder, f)
            with open(p, "r") as o1:
                x = o1.read().strip()
                t = float(x)
                if t > 60:
                    sOver += f"|{f[:-len(time_suffix)]}|{x}|\n"
                else:
                    sIn += f"|{f[:-len(time_suffix)]}|{x}|\n"
        o.write(sIn + sOver)


def scan(file_dir):
    for f in os.listdir(file_dir):
        p = os.path.join(file_dir, f)
        if not os.path.isfile(p):
            continue
        if not re.match("^p[0-9]+$", f.split(".")[0]):
            print("Not code", f)
            continue
        eval_time(p)

    gen_readme(file_dir)
    from draw_time import draw_time
    draw_time()


# run_file("p745.cpp")
scan(".")
