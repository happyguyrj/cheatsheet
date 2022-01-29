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
- Loosely coupled
- Scalable
- Flexible- complexity of application is not a concern
- Lightweight- Containers leverage and share the host kernel, making them much more efficient in terms of system resources than virtual machines
- Secure- Containers apply aggressive constraints and isolations to processes without any configuration required on the part of the user.

## Containers vs virtual machines
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

## Technology Used in Docker
- programming language used in Docker is GO
- Docker takes advantage of various features of Linux kernel like namespaces and cgroups.
- namespaces
    - to provide isolated workspace called containers
    - Each aspect of a container runs in a separate namespace and its access is limited to that namespace
- cgroups( control groups )
    - are used to limit and isolate the resource usage( CPU, memory, Disk I/O, network etc ) of a collection of processes.
    - allow Docker engine to share the available hardware resources to containers and optionally enforce limit and constraints.
- UnionFS( Union file systems )
    - are file systems that operate by creating layers, making them very lightweight and fast
Docker Engine combines the namespaces, cgroups, and UnionFS into a wrapper called a container format. The default container format is libcontainer

## Creating Our First Docker Application
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