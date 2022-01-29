Docker
- platform as a service
- use OS-level virtualisation
- build, share, and run applications with containers


Why Containerisation?
- Flexible- complexity of application is not a concern
- Lightweight- Containers leverage and share the host kernel, making them much more efficient in terms of system resources than virtual machines
- Portable
- Loosely coupled
- Scalable
- Secure- Containers apply aggressive constraints and isolations to processes without any configuration required on the part of the user.

Containers
- is a standardised unit which can be created on the fly to deploy a particular application or environment
- nothing but a running process, with some added encapsulation features applied to it in order to keep it isolated from the host and from other containers
- private filesystem; this filesystem is provided by a Docker image
- bundle their own software, libraries and configuration files
- they can communicate with each other through well-defined channels

Containers vs virtual machines
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

Benefits of using Containers over Virtual Machines
- Unlike VMs( Virtual Machines ) that run on a Guest OS, using a hypervisor, Docker containers run directly on a host server (for Linux), using a Docker engine, making it faster and lightweight.
    - ![image](https://user-images.githubusercontent.com/15718435/151669127-05caf40b-15e6-4502-8af7-576c65f63a20.png)
- Docker containers can be easily integrated compared to VMs.
- With a fully virtualized system, you get more isolation. However, it requires more resources. With Docker, you get less isolation. However, as it requires fewer resources, you can run thousands of container on a host.
- A VM can take a minimum of one minute to start, while a Docker container usually starts in a fraction of seconds.
- Unlike VMs there is no need to preallocate the RAM. Hence docker containers utilize less RAM compared to VMs. So only the amount of RAM that is required is used.
    - ![image](https://user-images.githubusercontent.com/15718435/151669134-105c1185-403c-4d16-a059-af579f68fa5f.png)



