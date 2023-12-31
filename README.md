# A demo of Handle with streaming data

Base on QT network module 

Streaming data is like data during the process of downloading files.

In my work, I need handle with a API generating streaming data.

be like:

```json
data: {"name":"LHB-91C8AD4E","evt_type":0,"rssi":-71,"adData":"0201060AFF5D05000201010B06010D094C48422D3931433841443445","bdaddrs":[{"bdaddr":"C7:88:AD:69:44:4E","bdaddrType":"random"}]}

data: {"name":"unknown)","evt_type":3,"rssi":-64,"adData":"1EFF060001092002159698BD8297407BF922E9A71BA9529768DCDE036D2650","bdaddrs":[{"bdaddr":"04:1F:41:80:F0:11","bdaddrType":"random"}]}

data: {"name":"unknown)","evt_type":0,"rssi":-59,"adData":"02010217FF8F032D1134667065101D4122152629098457010304830303AAFD","bdaddrs":[{"bdaddr":"50:DB:F1:67:88:EC","bdaddrType":"random"}]}

...
```



handle with python

```python
req = requests.get("www.example.com/node?&filter_mac='C7:88:AD:69:44:4E'", stream=True)
# rel = req.raw.read(1024).decode('utf-8')
rel = req.raw.read(1024)
print(rel)
# todo anything
```

Only three line with python!!!





## Run

put it in your Qt creator

build & run