Round robin: in this case, each server receives requests in sequential order similar in spirit to First In First Out (FIFO).
Least number of connections: the server with the lowest number of connections will be directed to the request.
Fastest response time: the server that has the fastest response time (either recently or frequently) will be directed to the request.
Weighted: the more powerful servers will receive more requests than the weaker ones underweighted strategy.
IP Hash: in this case, a hash of the IP address of the client is calculated to redirect the request to a server.


Software load balancing is a cheap alternative to hardware load balancers. It operates at layer 4 (network layer) and layer 7 (application layer).
Layer 4: the load balancer uses the information provided by TCP at the network layer. At this layer, it usually selects a server without looking at the content of the request.
Layer 7: the requests can be balanced based on information in the query string, cookies, or any header we choose as well as the regular layer information including source and destination addresses.