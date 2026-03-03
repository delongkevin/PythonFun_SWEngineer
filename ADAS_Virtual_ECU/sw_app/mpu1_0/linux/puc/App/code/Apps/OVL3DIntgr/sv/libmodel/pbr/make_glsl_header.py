import sys
import re
import copy

def file_to_text(path):
    try:
        f = open(path, "r")
        s = f.read()
        f.close()
        return s
    except:
        print("cannot open file " + path)
    
    return []

files_map = {}
files = []


def process_file(name, text):
    global files_map
    global files
    crop = max(name.rfind('/'), name.rfind('\\'))

    if crop >= 0:
        name = name[crop+1:len(name)]

    files_map[name] = len(files)
    files.append([name, text])


def main_py(argv):
    global files_map
    global files

    for i in range(1, len(argv)-1):
        s = file_to_text(argv[i])
        if len(s) > 0:
            process_file(argv[i], s)

    p = re.compile('(#include[^"<\n]*["<]([^">\n]+)[">])', re.M)

    for iter in range(8):
        for f_i in range(len(files)):
            f = files[f_i][1]
            repl = p.findall(f)
            for r in repl:
                to = files_map.get(r[1])
                if to != None:
                    files[f_i][1] = f.replace(r[0], files[to][1])

    out = ""
    for f_i in range(len(files)):
        f = files[f_i][1]
        nm = files[f_i][0]
        out+="\nstatic const char *%s =\n" % (nm.replace('.','_'))
        s = f.split("\n")
        for l in s:
            out+= '    "%s\\n"\n' % (l.replace('"', '\\"'))
        out+=";\n"
    
    f = open(argv[-1], "w")
    f.write(out)
    f.close()

main_py(sys.argv)
