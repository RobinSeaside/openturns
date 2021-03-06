#! /usr/bin/env python

from __future__ import print_function
import openturns as ot

# Database construction
dimension = 2

inputSample = ot.NumericalSample(0, dimension)
inputSample.add(ot.NumericalPoint(dimension, 1.0))
inputSample.add(ot.NumericalPoint(dimension, 2.0))
inputSample.setDescription(['x0', 'x1'])
outputSample = ot.NumericalSample(0, 1)
outputSample.add(ot.NumericalPoint(1, 4.0))
outputSample.add(ot.NumericalPoint(1, 5.0))
outputSample.setDescription(['y0'])
database = ot.DatabaseFunction(inputSample, outputSample)

print('database=', database)

# Does it work?
x = ot.NumericalPoint(dimension, 1.8)
print('x=', x)
print('database(x)=', database(x))
