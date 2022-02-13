# Distributed caches
## Redis
- CP
- in memory database
- single threaded, less useful when data is huge
- is faster than Cassandra in form of big data fetching and storing especially in the case of live streaming.
- maintained a disk backed in-memory database
- master-slave architecture
- utility script is needed for updating nodes
- more nodes are needed for master-slave architecture
- use sentinel to detect member failure, which makes it slow
- runs in remote server

## Hazelcast
- multi-threaded, scales when data is large
- better performance than redis
- less number of physical machines, all nodes can have primary data and backup
- easy to add mode nodes
- use peers to detect member failure, recovery is made automatically for data loss
- hazelcast can run in embedded mode

## Cassandra
- AP
- business requirement to write or store more data into the system rather read data
- Cassandra is too popular with some specific industries like banking or financial where the normal attitude to writing more than reading (considering entire data including transaction data).

## Memcached
- key value store
- faster than redis, but for smaller data
- more beneficial when storing relatively small and static data
- Memcached can handle high-traffic websites well.
- With this program you can simultaneously read a lot of information and get a great response time.