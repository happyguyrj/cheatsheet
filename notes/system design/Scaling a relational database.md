There are many techniques to scale a relational database: master-slave replication, master-master replication, federation, sharding, denormalization, and SQL tuning.
Replication usually refers to a technique that allows us to have multiple copies of the same data stored on different machines.
Federation (or functional partitioning) splits up databases by function.
Sharding is a database architecture pattern related to partitioning by putting different parts of the data onto different servers and the different user will access different parts of the dataset
Denormalization attempts to improve read performance at the expense of some write performance by coping of the data are written in multiple tables to avoid expensive joins..
SQL tuning.


## Master-slave replication
- enables data from one database server (the master) to be replicated to one or more other database servers (the slaves)
- A client would connect to the master and update data.
- The data would then ripple through the slaves until all of the data is consistent across the servers.
- algorithm to promote a slave to a master
    - Synchronous solutions: the data modifying transaction is not committed until accepted by all servers (distributed transaction), so no data lost on failover.
    - Asynchronous solutions: commit -> delay -> propagation to other servers in the cluster, so some data updates may be lost on failover.

## Master-master replication
- Each database server can act as the master at the same time as other servers are being treated as masters. At some point in time, all of the masters sync up to make sure that they all have correct and up-to-date data.
- If one master fails, the other database servers can operate normally and pick up the slack. When the database server is back online, it will catch up using replication.
- Masters can be located in several physical sites and can be distributed across the network.
- Limited by the ability of the master to process updates.

## Federation
- splits up databases by function
- example: forums, users, and products, resulting in less read and write traffic to each database and therefore less replication lag

## Sharding
- also known as data partitioning
- each database can only manage a subset of the data
- Types of partitioning
    - Horizontal partitioning
        - different rows into different tables
    - Vertical partitioning
        - store tables related to a specific feature in their own server.
        - we can decide to place user profile information on one DB server, friend lists on another, and photos on a third server.
    - Directory based partitioning
        - create a lookup service that knows your current partitioning schema and keeps a map of each entity and which database shard it is stored on.
        - use this method when a data store is likely to need to scale beyond the resources available to a single storage node or to improve performance by reducing contention in a data store
- some common problems with Sharding techniques as follows.
    - Database joins become more expensive and not feasible in certain cases.
    - Sharding can compromise database referential integrity.
    - Database schema changes can become extremely expensive.
    - The data distribution is not uniform and there is a lot of load on a shard.

## Denormalization
- attempts to improve read performance at the expense of some write performance
- copies of the data are written in multiple tables to avoid expensive joins

https://levelup.gitconnected.com/how-to-design-a-system-to-scale-to-your-first-100-million-users-4450a2f9703d