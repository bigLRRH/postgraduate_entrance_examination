# 计算机组成原理

## 1 计算机系统概述

### 1.1 计算机系统层次结构

#### 1.1.1 计算机系统的基本组成

**计算机系统**由**硬件**与**软件**两部分组成。  
**硬件**使具体物理装置的总称。  
**软件**包括在硬件上的**程序**、**数据**以及**相关的文档**。  
**程序**是指挥计算机如何操作的一个指令序列。  
**数据**是指令操作的对象。

#### 1.1.2 计算机硬件的基本结构

冯·诺伊曼机的基本思想：  
（1） 采用“**存储程序**”的工作方式。  
（2） 计算机硬件系统有**运算器**、**存储器**、**控制器**、**输入设备**和**输出设备**5大基本部件组成。  
（3） **指令**和**数据**以**同等地位**存储在**存储器**中，形式上没有区别，但计算机应能区分它们。  
（4） 计算机内部以**二进制形式**表示**指令**和**数据**。  
（5） **指令**由**操作码**和**地址码**组成，操作码指出操作的类型，地址码指出操作数的地址；由一串指令组成程序。  
“存储程序”的基本思想是：将实现编制好的程序和原始数据送入主存储器后才能执行，一旦程序被启动执行，就无需操作人员的干预，计算机会自动逐条执行指令，直至程序执行结束。

##### 1.1.2.2 计算机的基本部件

**（1）中央处理器**  
中央处理器（简称CPU或处理器）是整个计算机的核心部件，主要用于指令的执行。  
CPU主要包含两种基本部件：**数据通路**和**控制器**。  
**数据通路**主要包含**算术逻辑部件**（arithmetic and logic unit, ALU）和**通用寄存器**等。  
ALU用来执行算数运算和逻辑运算。  
通用寄存器用来暂存指令所用的操作数或执行结果。  
**控制器**用来对指令进行译码，生成相应的控制信号，以控制数据通路进行正确的操作。  
**（2）存储器**  
存储器分为**内存**和**外存**（也称**辅助存储器**或**外存储器**）。  
内存包括**主存储器**（也称**主存**或**内存储器**）和**高速缓存**（cache）。  
CPU能直接访问的存储器是主存储器。  
辅助存储器用于帮助主存储器记忆更多的信息，辅助存储器中的信息必须调入主存储器。  
主存储器的工作方式是按存储单元的地址进行存取，这种存取方式称为**按地址存取方式**。  
**（3）外部设备和设备控制器**  
外部设备简称外设，也称为I/O设备，其中，I/O是输入/输出（input/output）的缩写。外设通常由**机械部分**和**电子部分**组成，这两部分通常是可以分开的，机械部分是外部设备本身，电子部分是控制外部设备的设备控制器。  
**输入设备**的主要功能是将程序和数据以机器所能识别和接受的信息形式输入计算机。  
**输出设备**的任务是将计算机处理的结果以人们所能接受的形式或其它系统所要求的形式输出。  

#### 1.1.3 计算机软件和硬件的关系

#### 1.1.4 计算机系统的工作原理

##### 1.1.4.1 “存储程序”工作方式

##### 1.1.4.2 高级语言程序与机器语言程序之间的转换

(1) 通过程序编辑软件得到hello.c文件（源程序）。hello.c在计算机中以ASCII字符方式存放。  
(2) 将hello.c进行预处理、编译、汇编和链接，最终生成可执行目标文件。  
**预处理：** 预处理器（cpp）队源程序中以字符#开头的命令进行处理。例如将#include命令后面的.h文件插入程序文件。输出结果还是一个源程序文件，以.i为扩展名。  
编译：编译器（ccl）队预处理后的源程序进行编译

##### 1.1.4.3 程序和指令的执行过程

### 1.2 计算机性能指标

## 2 数据的表示和运算

## 3 存储器层次结构

## 4 指令系统

## 5 中央处理器（CPU）

## 6 总线和输入/输出系统