import pandas as pd
from matplotlib import pyplot as plt

df = pd.read_csv('english.csv',usecols=['algorithm','length','time'])

grouped_data = {'algorithm':[],'length':[],'time':[]}
for group_name, g_df in df.groupby(['algorithm','length']):
    grouped_data['algorithm'].append(group_name[0])
    grouped_data['length'].append(group_name[1])
    grouped_data['time'].append(g_df['time'].mean())

median_df = pd.DataFrame(grouped_data)

plt.figure(figsize=(8,6))
for group_name, g_df in median_df.groupby('algorithm'):
    plt.plot(g_df[['length']], g_df[['time']], label=group_name) 

plt.legend()
plt.grid()
plt.xlabel('Pattern Length')
plt.ylabel('Time (ms)')
plt.show()