# **ARM Cortex-M Architecture Course**

This folder contains my work and Labs focusing on ARM Cortex-M3/4. I have explored various fundamental and advanced concepts critical to embedded systems design and development.

## 📌**Concepts Learned**
- **ARM Operating Modes and Access Levels:**
    - Switching Operating Modes between **Thread** Mode and **Handler** Mode.
    - Switching Access Levels between **Privileged** and **Unprivileged**.

- **ARM Cortex-M Registers** 

- **ARM Cortex-M STACK:** <br />&ensp;&ensp; Understanding the switch between the Main Stack Pointer **(MSP)** and the Process Stack Pointer **(PSP)**.

- **Inline Assembly in C** 

- **ARM Exceptions and Interrupts:** 

- **SVC/PendSV Exceptions:** 

## 📌**LABS**

- ### Simple OS 
    - This LAB is a Simple OS where the Scheduler has a Specific Stack Region and uses **MSP** , the Scheduler runs on Privileged access level managing task switching between two tasks, `TaskA` and `TaskB`, each with its specific stack region and uses **PSP**, running on Unprivileged (User) access level.
    - Initially, an **external interrupt (EXTI)** was used as scheduling point between Tasks. Then, I improved this LAB by adding **Systick Timer** to set an interval time for Periodic Scheduling.
    - for more details, here's the Code: 
        - [Simple_OS_EXTI](https://github.com/YoussefSamy21/Embedded-Systems-K.S/tree/main/Unit_14_ARM_Architecture/Session_5_CortexM_STACK/1-Simple_OS_EXTI) 
        - [Simple_OS_Systick](https://github.com/YoussefSamy21/Embedded-Systems-K.S/tree/main/Unit_14_ARM_Architecture/Session_5_CortexM_STACK/2-Simple_OS_Systick)  

- ### **SVC for OS Services**
    - This LAB implements a simple Supervisor call (SVC) to perform 3 services which are basic arithmetic operations (addition, subtraction, multiplication) based on SVC requests. Each operation has its own SVC_ID.<br />for more details, here's the Code: [SVC_OS_Services](https://github.com/YoussefSamy21/Embedded-Systems-K.S/blob/main/Unit_14_ARM_Architecture/Session_6_SVC_%26_PendSV/main.c)   
    - *LAB APIs*:

        - **`OS_SVC_Set`:** Sends an SVC request by using the SVC intruction, triggering an SVC exception based on the provided ID.
        
        - **`SVC_Handler`:** Determines the stack pointer used (MSP or PSP) and forwards the handling to the `OS_SVC` function.
        
        - **`OS_SVC`:** Extracts the SVC number from the SVC instruction and performs the requested operation on the operands.The result is then stored to be accessible after the SVC call.
```c
uint32_t OS_SVC_Set(uint32_t a, uint32_t b, uint32_t SVC_ID);
void SVC_Handler(void);
void OS_SVC(uint32_t *StackFrame_ptr);
