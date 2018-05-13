#!/usr/bin/python
import matplotlib.pyplot as plt
import numpy as np
import sys

if len(sys.argv) < 2:
    raise Exception("./plot.py input_filename output_filename title ylabel")

filename = sys.argv[1]
output = sys.argv[2]
title = sys.argv[3]
ylabel = sys.argv[4]

data = np.genfromtxt(filename, delimiter=',', names=['N', 'Brute', 'Quick'])

plt.figure(num=None, figsize=(8, 6), dpi=300, facecolor='w', edgecolor='k')
plt.plot(data['N'], data['Brute'], 'b.')
plt.plot(data['N'], data['Quick'], 'r.')
plt.xlabel('Input size')
plt.ylabel(ylabel)
plt.title(title)
plt.savefig(output)
