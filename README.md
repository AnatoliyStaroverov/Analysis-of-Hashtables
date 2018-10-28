
# *Hash Table Report*
written by Anatoliy Staroverov

### Section 1: Problem Statement
The goal of this exercise is to implement three different hash table and record the insert and search operations of the hash table. Also, we record the collisions that happen during insertion.

### Section 2: Experiment setup
The code was written and tested in a Linux environment inside Oracles virtual box. I used adobes text editor “Brackets”. Some debugging was performed using Gdb. Below, I listed the specifications of the laptop used to perform these operations.

- **RAM:**  12 Gaga bytes
- **CPU:** 1.60GHz
- **Processor:** Intel® core™ i5-82500  
- **Storage:** 1 terabyte of storage.
- **System Type:** 64-bit operating system, x64-based processor

### Section 3: Experimental setup
This experiment resulted in the following conclusions. The tables that support my conclusion are provided on the second page.

#### 1. Separate chaining: 
Has the fastest insert time with the most collisions and slowest search time but do note that the search time for all three implementations are within a one tenth of a second.  Theoretically this makes sense because search time will be the slowest because you create a linked list for every collision and you must search the linked list for the element.
#### 2. Linear probing: 
Had the second fastest insert time and the second least amount of collisions and had a search time that was faster than separate chaining which theoretically makes sense that the insertion will be slower because you may need several attempts to find an empty slot.

#### 3. Quadratic Probing
Quadratic probing resulted in the slowest insert time from the three implementations conducted and had the least amount of collisions. Theoretically this makes sense for two reasons. First, this implementation will take the longest to insert because it must find the next available slot and the way that quadratic probing inserts makes sense why it takes longer. Second, the number of collision is the lowest because quadratic probing avoids primary clustering.
#### 4. Simple, Pre, Full hash functions.
The results show that the simple hash function had the most collisions and had the slowest search time. Theoretically this makes sense because the hash function is bad and increases the chances for collisions. Here are the following table from the experiments

	
| Hash Function |	Insert	Total time | 	Insert	Average time |	Total number of collisions |	Search Total time | Search Average time |
| :---: | :---:|:---:| :---: |:---: |:---: |
| `Simple` |	1.14(SEC)|	0.11(ms)|	39001|	0.2365(ms)|	0.0227(ms)|
|`Prefix` |	1.21(sec)|	0.11669(ms)|	5159|	0.1822(sec)|	0.017(ms)|
|`Full-length`|	0.4382(sec)|	0.0422(ms)|	4638|	0.0684(Sec)|	0.00659(ms)|



		
| Hash Function |	Insert	Total time |	Insert	Average time|	Total number of collisions|	Search Total time|	Search Average time|
| :---: | :---:|:---:| :---: |:---: |:---: |
|`Chaining`|	0.406(sec)|	0.039125(ms)|	5714|	0.0736(sec)|	0.00709(ms)|
|`Linear Probing`|	0.4112(sec)|	0.0396(ms)|	5165|	0.0699(sec)|	0.00673(ms)|
|`Quadratic`|	0.4382(sec)|	0.0422(ms)|	4638|	0.0684(Sec)|	0.00659(ms)|






