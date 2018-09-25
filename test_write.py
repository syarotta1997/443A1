import subprocess
import sys

sys.stdout = open('test_read_results.txt','w')
cmd = "library.c"
subprocess.call(["gcc",cmd])

