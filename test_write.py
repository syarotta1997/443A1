import subprocess
import sys

sys.stdout = open('test_read_results.txt','w')

make_process = subprocess.Popen("make clean all")
if (make_process != None):
    #creating a file with fixed total bytes worth 5MB
    subprocess.call("./create_random_file file_5MB 100")
else:
    print ("Makefile has failed to compile project...\n")
