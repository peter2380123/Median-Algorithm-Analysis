#!/usr/bin/python
import matplotlib.pyplot as plt
import numpy as np
import sys

if len(sys.argv) < 5:
    raise Exception("./plot.py input_filename output_filename title ylabel")

filename = sys.argv[1]
output = sys.argv[2]
title = sys.argv[3]
ylabel = sys.argv[4]

data = np.genfromtxt(filename, delimiter=',', names=['N', 'Brute', 'Quick'])

plt.figure(num=None, figsize=(16, 9), dpi=300, facecolor='w', edgecolor='k')

# Plot both.

plt.subplot(2, 2, 2)
plt.plot(data['N'], data['Brute'], 'b.')
plt.title('Brute Force Median')

plt.subplot(2, 2, 4)
plt.plot(data['N'], data['Quick'], 'r.')
plt.xlabel('Input size')
plt.title('Quick Median')

plt.subplot(1, 2, 1)
plt.plot(data['N'], data['Brute'], 'b.')
plt.plot(data['N'], data['Quick'], 'r.')
plt.xlabel('Input size')
plt.ylabel(ylabel)
plt.title('Comparitive ' + title)
plt.legend(['Brute Force', 'Quick'])

plt.savefig(output)
