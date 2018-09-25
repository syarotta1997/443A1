import subprocess
import sys
#opening a file to record the results
blocks = [100,500,1000,5000,10000,50000,100000,500000,1000000,3000000]
sys.stdout = open('test_results.txt','w')
subprocess.call(["make","clean","all"])
for i in range (0,10):
    #calling create_random_file with fixed 5MB file size using different
    #bloci sizes defined in list
    subprocess.call(["create_random_file", "file"+ str(i+1) ,"5000000",str(blocks[i])])
    
