import pandas as pd
import pandasql as ps
from matplotlib import pyplot as plt

df = pd.read_csv('graph_data.csv',usecols=['algorithm','length','time'])

# algorithm, length, data
aggregated_df = ps.sqldf("select algorithm, length, AVG(time) as average_time from df GROUP BY algorithm, length")

plt.figure(figsize=(8,6))
for name, g_df in aggregated_df.groupby(aggregated_df.algorithm):
    plt.plot(g_df[['length']], g_df[['average_time']], label=name) 

plt.legend()
plt.xlabel('Pattern Length')
plt.ylabel('Time (ms)')
plt.show()