LOGIC BEHIND THE CODE:
    This has 5 files test1.c patch.txt patch1.txt patch_sys.txt patch_syscall_64.txt .

    test1.c:
	contains a simple c program which generates load and generates timestamp of the run. before and after  

    patch1.txt:
	contains the list of changes in both the folders after compilation file by file
	[GENERATED USING: diff -bur /home/kern/build/linux-5.14.6 /home/kern/build/build2/linux-5.14.6 >> patch1.txt]

    patch.txt:
	contains a list which stores if there is any change in both the folders.
	[GENERATED USING: diff -rq /home/kern/build/linux-5.14.6 /home/kern/build/build2/linux-5.14.6 >> patch.txt]	

    patch_sys.txt:
	contains a list which stores any change in both the individual file.
	[GENERATED USING: diff -b /home/kern/build/linux-5.14.6/kernel/sys.c /home/kern/build/build2/linux-5.14.6/kernel/sys.c >> patch_sys.txt]

    patch_syscall_64.txt:
	contains a list which stores any change in both the individual file.
	[GENERATED USING: diff -b /home/kern/build/linux-5.14.6/arch/x86/entry/syscalls/syscall_64.tbl /home/kern/build/build2/linux-5.14.6/arch/x86/entry/syscalls/syscall_64.tbl >> patch_syscall_64.txt]

    we first modify the linux-5.14.6/arch/x86/entry/syscalls/syscall_64.tbl file to add the entry of syscall print_vruntime
    then we modify linux-5.14.6/kernel/sys.c file to add the code in the print_vruntime syscall. we enter an argument containing PID and the delay in ms.
    load here is generating a large number of primes. 
     
    After that we run the make command to compile the whole kernel and run the following commands:
  
	sudo make modules_install					// to install
	sudo cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux-new	
	sudo mkinitcpio -k 5.14.3 -g /boot/initramfs-linux-new.img
	sudo grub-mkconfig -o /boot/grub/grub.cfg

   Then we reboot and run our test1.c to check successfull instalation of syscall.
 	sudo dmesg | tail (this is to check kernel logs).
