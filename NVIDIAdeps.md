

luis arandas 06-03-2022<br>
ongoing set of useful commands to switch nvidia drivers or cuda installation<br>
here are some useful commands for setup

```
(get kernel)
$ uname -u

(purge everything)
$ todo

(check which drivers can install, go for 470.161.03, cuda 11.4)
$ sudo apt-cache search 'nvidia-driver-' | grep '^nvidia-driver-[[:digit:]]*'
$ sudo apt install nvidia-driver-470

(this should make it, if having problems on 'nvidia-smi', e.g. NVML cannot initialise)
$ sudo ldconfig.real

(make sure installation matches from next two commands)
$ cat /proc/driver/nvidia/version
    [NVRM version: NVIDIA UNIX x86_64 Kernel Module  470.161.03  Wed Oct 19 00:10:36 UTC 2022]
    [GCC version:  gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04)]

$ dkms status
    [nvidia/470.161.03, 5.19.0-35-generic, x86_64: installed]

(check if all version numbers match)
$ dpkg -l | grep '^ii' | grep 'nvidia'
    ii  libnvidia-cfg1-470:amd64                   470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA binary OpenGL/GLX configuration library
    ii  libnvidia-common-470                       470.161.03-0ubuntu0.22.04.1              all          Shared files used by the NVIDIA libraries
    ii  libnvidia-compute-470:amd64                470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA libcompute package
    ii  libnvidia-compute-470:i386                 470.161.03-0ubuntu0.22.04.1              i386         NVIDIA libcompute package
    ii  libnvidia-decode-470:amd64                 470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA Video Decoding runtime libraries
    ii  libnvidia-decode-470:i386                  470.161.03-0ubuntu0.22.04.1              i386         NVIDIA Video Decoding runtime libraries
    ii  libnvidia-egl-wayland1:amd64               1:1.1.9-1.1                              amd64        Wayland EGL External Platform library -- shared library
    ii  libnvidia-encode-470:amd64                 470.161.03-0ubuntu0.22.04.1              amd64        NVENC Video Encoding runtime library
    ii  libnvidia-encode-470:i386                  470.161.03-0ubuntu0.22.04.1              i386         NVENC Video Encoding runtime library
    ii  libnvidia-extra-470:amd64                  470.161.03-0ubuntu0.22.04.1              amd64        Extra libraries for the NVIDIA driver
    ii  libnvidia-fbc1-470:amd64                   470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA OpenGL-based Framebuffer Capture runtime library
    ii  libnvidia-gl-470:amd64                     470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA OpenGL/GLX/EGL/GLES GLVND libraries and Vulkan ICD
    ii  libnvidia-gl-470:i386                      470.161.03-0ubuntu0.22.04.1              i386         NVIDIA OpenGL/GLX/EGL/GLES GLVND libraries and Vulkan ICD
    ii  libnvidia-ifr1-470:amd64                   470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA OpenGL-based Inband Frame Readback runtime library
    ii  nvidia-compute-utils-470                   470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA compute utilities
    ii  nvidia-dkms-470                            470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA DKMS package
    ii  nvidia-driver-470                          470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA driver metapackage
    ii  nvidia-kernel-common-470                   470.161.03-0ubuntu0.22.04.1              amd64        Shared files used with the kernel module
    ii  nvidia-kernel-source-470                   470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA kernel source package
    ii  nvidia-prime                               0.8.17.1                                 all          Tools to enable NVIDIA's Prime
    ii  nvidia-settings                            510.47.03-0ubuntu1                       amd64        Tool for configuring the NVIDIA graphics driver
    ii  nvidia-utils-470                           470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA driver support binaries
    ii  screen-resolution-extra                    0.18.2                                   all          Extension for the nvidia-settings control panel
    ii  xserver-xorg-video-nvidia-470              470.161.03-0ubuntu0.22.04.1              amd64        NVIDIA binary Xorg driver

(check cuda installation)
$ ls -l /usr/lib/x86_64-linux-gnu/libcuda*
    lrwxrwxrwx 1 root root       12 nov 22 17:00 /usr/lib/x86_64-linux-gnu/libcuda.so -> libcuda.so.1
    lrwxrwxrwx 1 root root       21 mar  6 02:31 /usr/lib/x86_64-linux-gnu/libcuda.so.1 -> libcuda.so.470.161.03
    -rw-r--r-- 1 root root 22037736 out 19 01:27 /usr/lib/x86_64-linux-gnu/libcuda.so.470.161.03
```