# CS 232 Spring 2023 - Week 14 Lab
# Peter Ramos & Dakota Donner

import numpy as np
import pandas as pd
import os

os.chdir('/home/runner/Lab14/airline_data')  
os.listdir('/home/runner/Lab14/airline_data')

# 1.1 Load in Single File

#
# complete the code snippet below
#

def process_file(filepath):
    df = pd.read_csv(filepath)
    # Add code to extract airline name and save it to a name variable
    name = filepath.split('/')[-1].split('.')[0]
    df['airline'] = name
    return(df)
    
# 1.2 Load in Multiple Files

#
# complete the code snippet below
#

directory = '/home/runner/Lab14/airline_data'
for file in os.listdir(directory):
    if file.split(".")[-1] == "csv": # Fill in the blank to filter for files ending with `.csv`
        process_file(file)

#
# complete the code snippet below (concatenating dataframes)
#

# Solution
dflist = []
directory = '/home/runner/Lab14/airline_data'
df = []

# YOUR CODE HERE
for file in os.listdir(directory):
  dflist.append(process_file(file))
 
df = pd.concat(dflist)



# Command that will display the number of rows/columns in df dataframe
print(df.index)

# Command that will display the number of unique airlines in dataset
print(df['airline'].index)

df.head()

# 2.1 Nulls


# correct the code snippet below
#

# modify the argument(s) to .sum() below so that it produces the desired output
df.isnull().sum(axis=1)

#
# complete the code snippet below (dropping columns with nulls)

#
columns_to_drop = [
    'Unnamed: 0',
    'tweet_coord',
    'tweet_id',
    'user_timezone',
    'tweet_created',
    'tweet_location',
    'negativereason_gold',
    'airline_sentiment_gold']

# YOUR CODE HERE
df.drop(columns_to_drop, axis=1, inplace = True)

df.head(3)
# 2.2 Feature Extraction

#
# coomplete the code snippet below
#

# YOUR CODE HERE
df['word_count'] = df['text'].str.split().str.len()
df['mentions'] = df['text'].str.count('@')

# 2.3 Subset Tweets

#
# complete the code snippet below
#

# YOUR CODE HERE
pos_neg_df = df.loc[df['airline_sentiment']!= 'neutral',:]

new_label = {"airline_sentiment": {"positive": 1, "negative": 0}}
pos_neg_df.replace(new_label , inplace = True)
#will cause warning message
print(pos_neg_df)

# 3.1 Most Common Users, Most Frequent Airlines

#
# coomplete the code snippet below
#

# YOUR CODE HERE

# Command to display number of unique users in dataset
print(len(pos_neg_df['name'].unique()))
      
# Commands to allow you to visually identify the user who has tweeted the most
print(pos_neg_df.value_counts('name'))

df['name'].value_counts().plot(kind='hist', bins=100)

# 3.2 Visualization

# SKIPPED AS PER INSTRUCTOR REQUEST