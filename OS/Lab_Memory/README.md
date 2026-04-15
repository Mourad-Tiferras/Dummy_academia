# Lab: Virtual vs Physical Memory


##  Exercice 1: View Virtual Memory of a Process

###  Process Information
- Command used: `sleep 1000 & ps -e | grep sleep`
- PID: **967510**

###  Observations
- The memory map contains **multiple regions**
- Addresses are in **hexadecimal format**

### Answers
- **Are these addresses large or small?**  
  → Very large (64-bit hexadecimal addresses)

- **Are they contiguous?**  
  → No, they are divided into multiple regions

---

##  Exercice 2: View Physical Memory Usage

###  Commands Used
- `free -h`
- `cat /proc/meminfo`

###  Observations
- Total physical memory: **~15 GB (16043600 kB)**

###  Answers
- **Is physical memory smaller than virtual space?**  
  → Yes, physical memory is much smaller than virtual memory space

---

##  Exercice 3: Virtual vs Physical Insight

###  Command Used
- `cat /proc/iomem`

###  Answers
- **Are the addresses similar?**  
  → No

- **What does this indicate?**  
  → Virtual addresses and physical addresses are different and belong to separate spaces

---

##  Exercice 4: Demonstrating Isolation

###  Commands Used
- `sleep 1000 & ps -e | grep sleep`
- `cat /proc/968237/maps`

###  Answers
- **Do both processes have similar address ranges?**  
  → Yes, they have similar layout structures

- **Are they using the same physical memory?**  
  → No, each process has its own isolated memory space

---

##  Exercice 5: Observing Address Space Size

###  Command Used
- `uname -m`

###  Architecture
- **x86_64**

###  Answers
- **Why is virtual memory space very large?**  
  → Because the system uses 64-bit addressing

- **Does it reflect actual RAM size?**  
  → No, virtual memory size is independent of physical RAM

---

##  Exercice 6: Conclusion

### Main Differences
- **Virtual Memory:** Used by processes, large and abstract
- **Physical Memory:** Actual RAM available on the machine

### Key Points
- **Why are virtual addresses larger?**  
  → To provide each process with a large, isolated address space

- **How does the OS map virtual to physical memory?**  
  → Using page tables managed by the Memory Management Unit (MMU)

---

## Summary:
- Virtual memory allows process isolation and flexibility
- Physical memory is limited and shared
- The OS handles translation between both using hardware and kernel mechanisms
