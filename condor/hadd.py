import os
import samples
import argparse
import subprocess
import sys

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="hadd output files from condor jobs")
    parser.add_argument('-i' , '--inputPath'    , dest='inPath'  , help='top level directory with all samples'   , type=str,  required=True   )
    parser.add_argument('-o' , '--outputPath'   , dest='outPath' , help='output directory'                       , type=str, required=True   )
    # Argument parser
    args = parser.parse_args()
    
## print sample map we ran submitMetis over
sample_map = samples.QCD_2018
sample_map.update(samples.Vplusjets_2018)
sample_map.update(samples.top_2018)
sample_map.update(samples.diboson_2018)

sample_map.update(samples.lowHT_2018)
#sample_map = samples.sos


#print os.listdir(args.inPath)
to_hadd = os.listdir(args.inPath)

if not os.path.exists(args.outPath):
    os.makedirs(args.outPath)

for d in to_hadd:
    short = d.split("_Run")[0]
    for k in  sample_map.keys():
        if short in str(k):
            print sample_map[k]
            files = os.listdir(args.inPath+d)
            flist = []
            for f in files: flist.append( os.path.join( args.inPath + "/" + d +"/", f))
            
            subprocess.call(["hadd", "-T", sample_map[k]+".root"] + flist)
            subprocess.call(["mv", sample_map[k]+".root", args.outPath])

     
