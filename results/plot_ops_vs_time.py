#!/usr/bin/python3
import matplotlib.pyplot as plt
import numpy as np
import sys

if len(sys.argv) < 2:
    print('Supply an output filename')
    sys.exit()

xfile = './operations_results.csv'
yfile = './time_results.csv'
outfile = sys.argv[1]
xlab = 'Number of operations'
ylab = 'Time (nanoseconds)'

data_x = np.genfromtxt(xfile, delimiter=',', names=['N', 'Brute', 'Quick'])
data_y = np.genfromtxt(yfile, delimiter=',', names=['N', 'Brute', 'Quick'])

plt.figure(num=None, figsize=(8*1.8, 6), dpi=300, facecolor='w', edgecolor='k')
plt.subplot(1, 2, 1)
plt.plot(data_x['Brute'], data_y['Brute'], 'b.')
plt.xlabel(xlab)
plt.ylabel(ylab)
plt.title('Brute Force Median')

plt.subplot(1, 2, 2)
plt.plot(data_x['Quick'], data_y['Quick'], 'r.')
plt.xlabel(xlab)
plt.title('Quick Median')

plt.savefig(outfile)
