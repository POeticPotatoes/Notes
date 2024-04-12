# %%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import networkx as nx


# %%
# Read csv file
sflow_data = pd.read_csv(
    "./Lab 4 sample data for practice only, not for grading.csv", header=None
)

# %%
TYPE = 0
SFLOW_AGENT_ADDRESS = 1
INPUT_PORT = 2
OUTPUT_PORT = 3
SRC_MAC = 4
DST_MAC = 5
ETHERNET_TYPE = 6
IN_VLAN = 7
OUT_VLAN = 8
SRC_IP = 9
DST_IP = 10
IP_PROTOCOL = 11
IP_TOS = 12
IP_TTL = 13
SRC_PORT = 14
DST_PORT = 15
TCP_FLAGS = 16
PACKET_SIZE = 17
IP_PACKET_SIZE = 18
SAMPLING_RATE = 19

# %%
# Top 5 Talkers
top_5_talkers = sflow_data[SRC_IP].value_counts()[:5]
top_5_talkers = list(zip(top_5_talkers.index, top_5_talkers.values))
print("Top 5 Talkers:")
print(f"{'IP':<20}No. of Packets")
for x, y in top_5_talkers:
    print(f"{x:<20}{y}")

print("")

# %%
# Top 5 Listeners
top_5_listeners = sflow_data[DST_IP].value_counts()[:5]
top_5_listeners = list(zip(top_5_listeners.index, top_5_listeners.values))
print("Top 5 Listeners:")
print(f"{'IP':<20}No. of Packets")
for x, y in top_5_listeners:
    print(f"{x:<20}{y}")

print("")

# %%
# Top 5 destination ip port number
top_5_dst_ip_port_no = sflow_data[DST_PORT].value_counts()[:5]
top_5_dst_ip_port_no = list(
    zip(top_5_dst_ip_port_no.index, top_5_dst_ip_port_no.values)
)
print("Top 5 Destination Port Number:")
print(f"{'Dest. Port Number':<20}No. of Packets")
for x, y in top_5_dst_ip_port_no:
    print(f"{x:<20}{y}")

print("")

# %%
# Total packet size / total traffic
total_packet_size = sflow_data[IP_PACKET_SIZE].sum()
print(f"Total Packet Size (B)   : {total_packet_size}")
print(f"Total Packet Size (MB)  : {total_packet_size / 1024 / 1024}")

print("")

# %%
# TCP vs UDP vs the other protocols
tcp_vs_udp = sflow_data[IP_PROTOCOL].value_counts()
total_packets = tcp_vs_udp.sum()
tcp_vs_udp = [
    x for x in list(zip(tcp_vs_udp.index, tcp_vs_udp.values)) if x[0] == 6 or x[0] == 17
]
print(
    f"TCP: {tcp_vs_udp[0][1]:4d} times, {tcp_vs_udp[0][1] / total_packets * 100:.2f}%"
)
print(
    f"UDP: {tcp_vs_udp[1][1]:4d} times, {tcp_vs_udp[1][1] / total_packets * 100:.2f}%"
)

print("")

# %%
# Top 5 Communication Pairs
top_5_comm_pairs = (
    sflow_data.groupby([SRC_IP, DST_IP]).size().sort_values(ascending=False)[:5]
)
print(f"{'Source':<18}{'Destination':<18}Number of Communication Pairs")
for (a, b), y in top_5_comm_pairs.items():
    print(f"{a:<18}{b:<18}{y}")

print("")

# %%
# comm_dataset = sflow_data.groupby([SRC_IP, DST_IP]).size().sort_values(ascending=False)

# comm_dataframe = pd.DataFrame()
# froms = []
# tos = []
# for (a, b), y in comm_dataset.items():
#     froms.append(a)
#     tos.append(b)

# comm_dataframe["from"] = froms
# comm_dataframe["to"] = tos

# G = nx.from_pandas_edgelist(comm_dataframe, "from", "to")

# plt.figure(figsize=(60, 60))
# gp = nx.spring_layout(G)
# nx.draw_networkx_nodes(G, gp, node_color="red")
# nx.draw_networkx_edges(G, gp)
# nx.draw_networkx_labels(G, gp, font_size=8)

# plt.show()
