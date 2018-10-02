CSC443A1
KELAN LU
1002261269

TO RUN SCRIPT PLEASE COMPILE THE PYTHON CODE "test.py"
USAGE: $python test.py

The script will use subprocess to loop call creat_random_file many times
with fixed file size 5MB, using an array of different block sizes ranging
from 100B - 3MB. It will then print out the time (ms) used to write file
in disk and completes the sequential read part of the experiment.

For the sequential read part, the script will continue loop call 
get_histogram using the files produced by create_random_file with the
same array of different block sizes, then prints out the number of
occurance of letters A-Z along with time (ms), total bytes and
read rate in bps format.

NOTE: This script will call make clean all, which first clears all
pre-existing test files and recompile the whole thing.

NOTE: Since the time will differ for each single run,the experiment 
results and reports are recorded manually without redirecting 
the output to a new file.
