# CS 232 Spring 2023 - Week 14 Lab
# _____ & _____

# 1.1 Load in Single File

#
# complete the code snippet below
#

def process_file(filepath):
    df = pd.read_csv(filepath)
    # Add code to extract airline name and save it to a name variable
    name = ___
    df['airline'] = name
    return(df)
    
# 1.2 Load in Multiple Files

#
# complete the code snippet below
#

directory = 'airline_data'
for file in os.listdir(directory):
    if _____: # Fill in the blank to filter for files ending with `.csv`
        process_file(_____)

#
# complete the code snippet below (concatenating dataframes)
#

# Solution
dflist = []
directory = 'airline_data'

# YOUR CODE HERE

df = ___.____(dflist)

# Command that will display the number of rows/columns in df dataframe
print(df.____)

# Command that will display the number of unique airlines in dataset
print(df[____]._____)

# 2.1 Nulls

#
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
df.drop(____)

# 2.2 Feature Extraction

#
# coomplete the code snippet below
#

# YOUR CODE HERE
df['word_count'] = ...
df['mentions'] = ...

# 2.3 Subset Tweets

#
# coomplete the code snippet below
#

# YOUR CODE HERE
pos_neg_df = df.loc[____]

# 3.1 Most Common Users, Most Frequent Airlines

#
# coomplete the code snippet below
#

# YOUR CODE HERE

# Command to display number of unique users in dataset
print(pos_neg_df[____].____)
      
# Commands to allow you to visually identify the user who has tweeted the most
print(pos_neg_df.____(____))

# 3.2 Visualization

#
# coomplete the code snippet below
#

# YOUR CODE HERE

# histogram for negative tweets
pos_neg_df.loc[pos_neg_df[____,'word_count'].plot(kind='hist')

# histogram for positive tweets
pos_neg_df.loc[pos_neg_df[____,'word_count'].plot(kind='hist')
