#%%

import sys
import pandas as pd
import seaborn as sb
import matplotlib.pyplot as plt

from numpy import NaN
from csv import reader


with open('AirlineData.csv', 'r') as csv_file:
    my_list = []
    csv_reader = reader(csv_file)

    for line in csv_reader: # for line in reader(sys.stdin):

        sentiment = line[0].strip()
        negative_reason = line[1].strip()
        airline = line[2].strip()
        text = line[3].strip()

        # exclude column headers
        if ( 
            not sentiment or sentiment == 'airline_sentiment' or 
            negative_reason == 'negativereason' or 
            not airline or airline == 'airline' or  
            not text or text == 'text'
            ): continue 
        
        # use dataframe-friendly empty values
        if not negative_reason:
            negative_reason = NaN

        # remove @'s, new lines, and carriage returns
        text = text.replace('@', '', -1)
        text = text.replace('\n', '', -1)
        text = text.replace('\r', '', -1)

        #   print(
        #         f'{sentiment}\t'
        #         f'{neg_reason}\t'
        #         f'{airline}\t'
        #         f'{text}'
        #        )
               
        my_list.append(f'{sentiment}\t'
        f'{negative_reason}\t'
        f'{airline}\t'
        f'{text}')

# init dataframe with columns
df = pd.DataFrame(columns=['Sentiment', 'NegativeReason', 'Airline', 'Text'])

for line in my_list:
    line.strip()

    # split line into respective vars
    sentiment, negative_reason, airline, text = line.split('\t')

    # build dataframe
    df.loc[len(df.index)] = [sentiment, negative_reason, airline, text]


# sentiment count per airline
ax = sb.countplot(data=df, y='Airline', order=df.Airline.value_counts().index)
ax.bar_label(ax.containers[0])
ax.set_title('Sentiment Count per Airline')
plt.show()


# percentage of each sentiment for all airlines
x = df.Sentiment.value_counts().sort_values()
plt.figure(figsize=(5,5))
ax = plt.pie(x=x, labels=x.index, autopct='%1.1f%%', explode=[0.03, 0.03, 0.08])
plt.title('Proportion of Sentiment for all Airlines')
plt.show()


# percentage of sentiment per airline
a = df.groupby(['Airline', 'Sentiment'])['Sentiment'].count().unstack()
fig, axes = plt.subplots(2, 3, figsize=(15, 8))
axes = axes.flatten()

for i, ax in zip(range(0,6), axes):
    temp = a.iloc[i]
    ax.pie(x=temp, labels=temp.index, autopct='%1.1f%%', explode=[0.08, 0.03, 0.03])
    ax.set_title(f"{a.index[i]}:{format(a.values[i].sum(), ',')}")
    
plt.suptitle("Proportion of Sentiment per Airline", fontsize=20)
plt.show()

    
# count of negative reason for all airlines
df_neg_reason = df[df.Sentiment == 'negative']
plt.figure(figsize=(8,5))
ax = sb.countplot(data=df_neg_reason, y='NegativeReason', palette='Set2', order=df_neg_reason.NegativeReason.value_counts().index)
ax.bar_label(ax.containers[0])
ax.set_title('Count per Negative Reason for all Airlines')
plt.show()


# count of negative reason per airline
fig, axes = plt.subplots(6, 1, figsize=(8,25), sharex=True)
axes = axes.flatten()
airline_names = df_neg_reason['Airline'].unique()

for airline_name, n in zip(airline_names, axes):
    ax = sb.countplot(data=df_neg_reason[df_neg_reason.Airline == airline_name], y='NegativeReason', palette='Set2', order=df_neg_reason[df_neg_reason.Airline == airline_name].NegativeReason.value_counts().index, ax=n)
    ax.set_title(f"{airline_name}: {format(len(df_neg_reason[df_neg_reason.Airline == airline_name]), ',')}")
    ax.set_xlabel('')
    ax.set_ylabel('')

plt.suptitle("Count per Negative Reason per Airline", fontsize=20)
plt.show()
