Docker
- platform as a service
- use OS-level virtualisation
- build, share, and run applications with containers

Containerisation
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

![image](https://user-images.githubusercontent.com/15718435/151668943-67df5209-0f07-439e-b984-2da527335bf2.png)
![image](https://user-images.githubusercontent.com/15718435/151668946-29a55a30-ab43-4f72-bafb-8a8a4d4d34e0.png)
