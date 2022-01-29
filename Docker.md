## Docker
- platform as a service
- use OS-level virtualisation
- build, share, and run applications with containers

## Containers
- is a standardised unit which can be created on the fly to deploy a particular application or environment
- nothing but a running process, with some added encapsulation features applied to it in order to keep it isolated from the host and from other containers
- private filesystem; this filesystem is provided by a Docker image
- bundle their own software, libraries and configuration files
- they can communicate with each other through well-defined channels

## Why Containerisation?
- Portable
- Standard
- Loosely coupled
- Scalable
- Flexible- complexity of application is not a concern
- Lightweight- Containers leverage and share the host kernel, making them much more efficient in terms of system resources than virtual machines
- Secure- Containers apply aggressive constraints and isolations to processes without any configuration required on the part of the user.

## Containers vs virtual machines
### VIRTUAL MACHINES
Virtual machines (VMs) are an abstraction of physical hardware turning one server into many servers. The hypervisor allows multiple VMs to run on a single machine. Each VM includes a full copy of an operating system, the application, necessary binaries and libraries - taking up tens of GBs. VMs can also be slow to boot.

### CONTAINERS
Containers are an abstraction at the app layer that packages code and dependencies together. Multiple containers can run on the same machine and share the OS kernel with other containers, each running as isolated processes in user space. Containers take up less space than VMs (container images are typically tens of MBs in size), can handle more applications and require fewer VMs and Operating systems.

- Kernel
    - A container runs natively on Linux and shares the kernel of the host machine with other containers. It runs a discrete process, taking no more memory than any other executable, making it lightweight.
    - By contrast, a virtual machine (VM) runs a full-blown “guest” operating system with virtual access to host resources through a hypervisor. In general, VMs incur a lot of overhead beyond what is being consumed by your application logic.
- Time to boot
    - Containers are fast and boots quickly as it uses host operating system and shares the relevant libraries.
    - Virtual Machines are slow and take a lot of time to boot.
- Resources
    - Containers do not waste or block host resources unlike virtual machines.
- Libraries
    - Containers have isolated libraries and binaries specific to the application they are running.
- Dependency
    - Docker solves the dependency problem by keeping the dependency contained inside the containers. It unites developers against dependency of their project.

![image](https://user-images.githubusercontent.com/15718435/151669113-56d7bcbf-d533-4701-9ba0-5522e3cde4f9.png)

## Benefits of using Containers over Virtual Machines
- Unlike VMs( Virtual Machines ) that run on a Guest OS, using a hypervisor, Docker containers run directly on a host server (for Linux), using a Docker engine, making it faster and lightweight.
    - ![image](https://user-images.githubusercontent.com/15718435/151669127-05caf40b-15e6-4502-8af7-576c65f63a20.png)
- Docker containers can be easily integrated compared to VMs.
- With a fully virtualized system, you get more isolation. However, it requires more resources. With Docker, you get less isolation. However, as it requires fewer resources, you can run thousands of container on a host.
- A VM can take a minimum of one minute to start, while a Docker container usually starts in a fraction of seconds.
- Unlike VMs there is no need to preallocate the RAM. Hence docker containers utilize less RAM compared to VMs. So only the amount of RAM that is required is used.
    - ![image](https://user-images.githubusercontent.com/15718435/151669134-105c1185-403c-4d16-a059-af579f68fa5f.png)


## How does Docker work?
Docker has a docker engine, which is the heart of Docker system. It is a client-server application. It has three main components:
- A server which is a type of long-running process called a daemon process.
- A client which is Docker CLI( Command Line Interface), and
- A REST API which is used to communicate between the client( Docker CLI ) and the server ( Docker Daemon )
The Docker daemon receives the command from the client and manages Docker objects, such as images, containers, networks, and volumes. The Docker client and daemon can either run on the same system, or you can connect a Docker client to a remote Docker daemon. They can communicate using a REST API, over UNIX sockets or a network interface.

Docker which runs in the same operating system as its host. This allows it to share a lot of the host operating system resources. Also, it uses a layered filesystem (AuFS) and manages networking.

#### AuFs
- layered file system
- have a read only part and a write part which are merged together.
- One could have the common parts of the operating system as read only (and shared amongst all of your containers) and then give each container its own mount for writing.

## Technology Used in Docker
Docker takes advantage of various features of Linux kernel like namespaces and cgroups.
### namespaces
    - real magic behind containers
    - to provide isolated workspace called containers
    - Each aspect of a container runs in a separate namespace and its access is limited to that namespace
    - kinds of namespace
        - pid
            - Each pid namespace has its own process numbering.
            - Different pid namespaces form a hierarchy
            - the kernel keeps track of which namespace created which other
            - A “parent” namespace can see its children namespaces, and it can affect them (for instance, with signals); but a child namespace cannot do anything to its parent namespace. As a consequence:
                - each pid namespace has its own “PID 1” init-like process;
                - processes living in a namespace cannot affect processes living in parent or sibling namespaces with system calls like kill or ptrace, since process ids are meaningful only inside a given namespace;
                - if a pseudo-filesystem like proc is mounted by a process within a pid namespace, it will only show the processes belonging to the namespace;
                - since the numbering is different in each namespace, it means that a process in a child namespace will have multiple PIDs: one in its own namespace, and a different PID in its parent namespace.
                    - the top-level pid namespace, you will be able to see all processes running in all namespaces, but with different PIDs. Of course, a process can have more than 2 PIDs if there are more than two levels of hierarchy in the namespaces.
        - net
            - if you want to run e.g. a different Apache in each container, you will have a problem: there can be only one process listening to port 80/tcp at a time. You could configure your instances of Apache to listen on different ports… or you could use the net namespace.
            - net namespace is about networking
            - Each different net namespace can have different network interfaces
            - Even lo, the loopback interface supporting 127.0.0.1, will be different in each different net namespace.
            - It is possible to create pairs of special interfaces, which will appear in two different net namespaces, and allow a net namespace to talk to the outside world.
            - A typical container will have its own loopback interface (lo), as well as one end of such a special interface, generally named eth0. The other end of the special interface will be in the “original” namespace, and will bear a poetic name like veth42xyz0. It is then possible to put those special interfaces together within an Ethernet bridge (to achieve switching between containers), or route packets between them, etc. (If you are familiar with the Xen networking model, this is probably no news to you!)
            - Note that each net namespace has its own meaning for INADDR_ANY, a.k.a. 0.0.0.0; so when your Apache process binds to *:80 within its namespace, it will only receive connections directed to the IP addresses and interfaces of its namespace – thus allowing you, at the end of the day, to run multiple Apache instances, with their default configuration listening on port 80.
            - In case you were wondering: each net namespace has its own routing table, but also its own iptables chains and rules.
        - ipc
            - IPC provides semaphores, message queues, and shared memory segments.
            - While still supported by virtually all UNIX flavors, those features are considered by many people as obsolete, and superseded by POSIX semaphores, POSIX message queues, and mmap. Nonetheless, some programs – including PostgreSQL – still use IPC.
            - each IPC resources are accessed through a unique 32-bits ID. IPC implement permissions on resources, but nonetheless, one application could be surprised if it failed to access a given resource because it has already been claimed by another process in a different container.
            - Introduce the ipc namespace: processes within a given ipc namespace cannot access (or even see at all) IPC resources living in other ipc namespaces. And now you can safely run a PostgreSQL instance in each container without fearing IPC key collisions!
        - mnt
            - chroot, a mechanism allowing to sandbox a process (and its children) within a given directory.
            - The mnt namespace takes that concept one step further.
            - the mnt namespace deals with mountpoints
            - Processes living in different mnt namespaces can see different sets of mounted filesystems – and different root directories. If a filesystem is mounted in a mnt namespace, it will be accessible only to those processes within that namespace; it will remain invisible for processes in other namespaces
            - it allows to sandbox each container within its own directory, hiding other containers.
            - Inspecting /proc/mounts in a container will show the mountpoints of all containers. Also, those mountpoints will be relative to the original namespace, which can give some hints about the layout of your system – and maybe confuse some applications which would rely on the paths in /proc/mounts.The mnt namespace makes the situation much cleaner, allowing each container to have its own mountpoints, and see only those mountpoints, with their path correctly translated to the actual root of the namespace.
        - uts
            - uts namespace deals with one little detail: the hostname that will be “seen” by a group of processes.
            - Each uts namespace will hold a different hostname, and changing the hostname (through the sethostname system call) will only change it for processes running in the same namespace.

### cgroups( control groups )
    - are used to limit and isolate the resource usage( CPU, memory, Disk I/O, network etc ) of a collection of processes.
    - allow Docker engine to share the available hardware resources to containers and optionally enforce limit and constraints.

### UnionFS( Union file systems )
    - are file systems that operate by creating layers, making them very lightweight and fast
Docker Engine combines the namespaces, cgroups, and UnionFS into a wrapper called a container format. The default container format is libcontainer

## Creating Our First Docker Application
#### OS snapshot
You start with a base image, and then make your changes, and commit those changes using docker, and it creates an image. This image contains only the differences from the base. When you want to run your image, you also need the base, and it layers your image on top of the base using a layered file system: as mentioned above, Docker uses AuFS. AuFS merges the different layers together and you get what you want; you just need to run it. You can keep adding more and more images (layers) and it will continue to only save the diffs. Since Docker typically builds on top of ready-made images from a registry, you rarely have to "snapshot" the whole OS yourself.
- Create a Dockerfile in your application
    ```
    FROM python:3.8-alpine3.11

    # update apk repo
    RUN echo "http://dl-4.alpinelinux.org/alpine/v3.11/main" >> /etc/apk/repositories && \
        echo "http://dl-4.alpinelinux.org/alpine/v3.11/community" >> /etc/apk/repositories

    # install chromedriver
    RUN apk --no-cache add chromium chromium-chromedriver

    # install selenium
    RUN pip install selenium pytest
    ```
- Deploying Your Application
    - create a docker image.
        ```
        docker build -t <name to give to your image>
        ```
    - Convert Docker image of the Application into a Running container.
        ```
        docker run -p 9090:80 <name to give to your container>
        ```

## Docker command
Below are some useful Docker commands
- Stopping a running image
    ```
    docker stop <id-of-image>
    ```
- Starting an image which is not running
    ```
    docker start <id-of-image>
    ```
- Removing an image from docker
    ```
    docker rmi <id-of-image>
    ```
- Removing a container from docker
    ```
    docker rm <id-of-container>
    ```

## How does virtualization work at a low level?
- VM manager takes over the CPU ring 0 (or the "root mode" in newer CPUs) and intercepts all privileged calls made by the guest OS to create the illusion that the guest OS has its own hardware.
- The net effect is that virtualization allows you to run two completely different OSes on the same hardware. Each guest OS goes through all the processes of bootstrapping, loading kernel, etc. You can have very tight security.
- For example, a guest OS can't get full access to the host OS or other guests and mess things up.

## How do containers work at a low level?
- Around 2006, people including some of the employees at Google implemented a new kernel level feature called namespaces
- One function of the OS is to allow sharing of global resources like network and disks among processes. What if these global resources were wrapped in namespaces so that they are visible only to those processes that run in the same namespace?
- This provides a kind of virtualization and isolation for global resources.
- Each container runs in its own namespace but uses exactly the same kernel as all other containers. The isolation happens because the kernel knows the namespace that was assigned to the process and during API calls it makes sure that the process can only access resources in its own namespace.


Ref:
https://medium.com/@kmdkhadeer/docker-get-started-9aa7ee662cea
https://stackoverflow.com/questions/16047306/how-is-docker-different-from-a-virtual-machine/16048358#16048358
https://www.docker.com/resources/what-container#/package_software
http://web.archive.org/web/20150326185901/http://blog.dotcloud.com/under-the-hood-linux-kernels-on-dotcloud-part