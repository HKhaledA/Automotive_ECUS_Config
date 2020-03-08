    #*************************************************************************/              
    #* FILE NAME: ctr0.s                       COPYRIGHT (c) Freescale 2008  */              
    #*                                                All Rights Reserved    */             
    #* This initializes stack pointer, SDA_BASE and SDA2_BASE	register     */             
    #*                                                                       */
    #*************************************************************************/
             
	.section .text_vle             
	.globl   _start             
	.align   2             

		e_add2i.   r0,0         # Debuggers may object to starting at 0.             
       
	_start:
        .include ".\src\ecc_init.s"              
                  
		e_lis      r1, __SP_INIT@h     # Initialize stack pointer r1 to             
		e_or2i     r1, __SP_INIT@l     # value in linker command file.              
		e_lis      r13, _SDA_BASE_@h   # Initialize r13 to sdata base             
		e_or2i     r13, _SDA_BASE_@l   #               

		e_lis      r2, _SDA2_BASE_@h   # Initialize r2 to sdata2 base              
		e_or2i     r2, _SDA2_BASE_@l   # (provided by linker).             
		e_addi     r0,r0,0             # Clear r0.             
		e_stwu     r1,-64(r1)          # Terminate stack.             

#------------------------------------------------------------------------------             
# Start of code              

		e_bl      romcopy                                                      
		#e_b       exit      	# Never returns.             

###############################################################################
#                           	End of File                        
###############################################################################
