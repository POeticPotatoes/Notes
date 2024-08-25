import pandas as pd

col_names = ["TYPE", "SFLOW_AGENT_ADDRESS", "INPUT_PORT", "OUTPUT_PORT", "SRC_MAC",
    "DST_MAC", "ETHERNET_TYPE", "IN_VLAN", "OUT_VLAN", "SRC_IP", "DST_IP", "IP_PROTOCOL",
    "IP_TOS", "IP_TTL", "SRC_PORT", "DST_PORT", "TCP_FLAGS", "PACKET_SIZE", "IP_PACKET_SIZE",
    "SAMPLING_RATE", ""]

data = pd.read_csv(
    "./Lab 4 sample data for practice only, not for grading.csv", header=None, names=col_names)

n = len(data)

# Top 5 Talkers
top_talkers = data["SRC_IP"].value_counts().iloc[:5]
print("Top 5 Talkers:")
print(top_talkers, "\n")

top_listeners = data["DST_IP"].value_counts().iloc[:5]
print("Top 5 Listeners:")
print(top_listeners, "\n")

top_ports = data["DST_PORT"].value_counts().iloc[:5]
print("Top 5 Destination Ports:")
print(top_ports, "\n")

total_packet_size = data["IP_PACKET_SIZE"].sum()
mb = 2**20
print("Total Packet Size:", total_packet_size, f"({total_packet_size/mb}mb)\n")

protocols = data["IP_PROTOCOL"].value_counts()
vals = dict(zip(protocols.index, protocols.values))

print(f"TCP was called {vals[6]} times ({vals[6]*100//n}%)")
print(f"UDP was called {vals[17]} times ({vals[17]*100//n}%)\n")

data.insert(0, "PAIRS", [(data["SRC_IP"][i], data["DST_IP"][i]) for i in range(n)])

top_pairs = data["PAIRS"].value_counts().iloc[:5]
print("Top 5 Communication Pairs:")
print(top_pairs, "\n")
