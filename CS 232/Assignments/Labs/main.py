# CS 232 Lab for Week 14
# Peter Ramos & Dakota Donner

import numpy as np
import pandas as pd
import os

os.chdir('/home/runner/Lab14/airline_data')  
os.listdir('/home/runner/Lab14/airline_data')

single_airline = pd.read_csv('Delta.csv')

filename = 'airline_data/Delta.csv'.split('/')[1]

print(filename)

name = filename.split('/')[-1]
print(name)

single_airline['airline'] = name
single_airline.head()

def process_file(filepath):
  df = pd.read_csv(filepath)

  name = filepath.split('/')[-1].split('.')[0]
  df['airline'] = name
  return(df)

directory = 'airline_data'
for file in os.listdir('/home/runner/Lab14/airline_data'):
  print(file)

test_csv = 'delta.csv'
test_text = 'delta.txt'

directory = 'airline_data'
for file in os.listdir('/home/runner/Lab14/airline_data'):
  if file.split(".")[-1] == "csv": 
    print(process_file(file))













