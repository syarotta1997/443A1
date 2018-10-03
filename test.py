import subprocess

#opening a file to record the results
blocks = [100,500, 1000, 2500,5000, 7500,10000, 25000,50000,75000,100000,250000,500000,750000,1000000,2000000,3000000]

subprocess.call(["make","clean","all"])
print("NOW TESTING DISK WRITE ......\n")
for i in range (0, len(blocks)):
    #calling create_random_file with fixed 5MB file size using different
    #block sizes defined in list
    subprocess.call(["create_random_file", "file"+str(i) ,"5000000",str(blocks[i])])
print ("\nNOW TESTING DISK READ ......\n")
for i in range (0, len(blocks)):
    #calling create_random_file with fixed 5MB file size using different
    #bloci sizes defined in list
    subprocess.call(["get_histogram", "file"+str(i) , str(blocks[i])])
    print("\n")
print("\n END OF TEST")
