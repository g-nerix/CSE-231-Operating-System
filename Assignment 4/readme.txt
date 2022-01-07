------------------------------------------------------------------------------------------------------------------------------
README:
------------------------------------------------------------------------------------------------------------------------------
SYSCALLS made:

->reader	: to dequeue an element form the Queue
->writer	: to enqueue an element into the Queue
->queue_init	: to initialise a Queue in syc.c

------------------------------------------------------------------------------------------------------------------------------
Additional Functions made:

->initialize_queue : makes a Queue in kernel Space using kmalloc
->enqueue	   : helps to enque an element while implementing semaphore to prevent conflict
->dequeue	   : helpes to dequeue an element while implementing semaphore to prevent conflict

------------------------------------------------------------------------------------------------------------------------------
P.c: is the producer process which will read random 8 bytes from "/dev/urandom" and then convert the bytes into long long int.
it uses the "writer" syscall to enqueue the random 8 byte number generated in a queue maintained in the kernel.

C.c: it is the consumer process and uses the "reader" syscall to dequeue the number enqueued by the producer process.

------------------------------------------------------------------------------------------------------------------------------
Synchronization:

3 semaphores ,namely control, empty, and full are declared in global scope in kernel:

->control: controls the procress switching.
->empty  : keeps track of the empty blocks in the queue.
->full   : keeps track of the occupied blocks in the queue.

------------------------------------------------------------------------------------------------------------------------------
How to run test program:
- Apply the pacth to the kernel
- Build and Install the kernel
	sudo make modules_install					
	sudo cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux-new	
	sudo mkinitcpio -k 5.14.6 -g /boot/initramfs-linux-new.img
	sudo grub-mkconfig -o /boot/grub/grub.cfg
	sudo reboot
- make 
- ./c
- ./p
------------------------------------------------------------------------------------------------------------------------------

