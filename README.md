# seL4-Atlas
An seL4 kernel as an Atlas project. The following project is constructed by manually building the seL4 kernel following the instructions of [Stand-alone seL4 builds](https://docs.sel4.systems/Developing/Building/seL4Standalone). This build process generates a kernel_all.c file containing the whole kernel in a single C file. kernel_all.c references many header files which can be either found in the "include" directory of seL4 or automatically generated through the build process. Therefore, some manual work is needed to re-organize the header files to be correctly included within the kernel_all.c.

####Indexing Instructions
seL4 builds typically use a cross-compiler. Make sure to set your toolchain in Project Settings to "Cross Compiler Toolchain" before you index the project in Atlas.
