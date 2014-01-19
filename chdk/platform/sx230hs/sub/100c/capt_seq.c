#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"

static long *nrflag = (long*)0x8A6C; // 0x89F4;  // sx220 0x8964 0x896C-8 at FF18D1DC not sure 0xEF44//sx210  0x75B0 ASM1989 08.21.2010 found at FF972F10
#define NR_AUTO (0)                            // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 100          // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) capt_seq_task(){
 
 asm volatile (

                 "STMFD   SP!, {R3-R9,LR}\n"
                 "LDR     R5, =0x3EFA4\n"
                 "LDR     R7, =0x3EF4\n"
                 "MOV     R6, #0\n"
 "loc_FF078BD8:\n"                            
                 "LDR     R0, [R7,#4]\n"
                 "MOV     R2, #0\n"
                 "MOV     R1, SP\n"
                 "BL      sub_FF02B17C\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FF078C04\n"
                 "LDR     R1, =0x47A\n"
                 "LDR     R0, =0xFF0785F4\n"
                 "BL      sub_FF00EC80\n"
                 "BL      sub_FF00EC38\n"
                 "LDMFD   SP!, {R3-R9,PC}\n"
 "loc_FF078C04:\n"                           
                 "LDR     R0, [SP]\n"
                 "LDR     R1, [R0]\n"
                 "CMP     R1, #0x27\n"
                 "ADDCC   PC, PC, R1,LSL#2\n"
                 "B       loc_FF078E84\n"
 "loc_FF078C18:\n"                           
                 "B       loc_FF078CB4\n"
 "loc_FF078C1C:\n"                           
                 "B       loc_FF078CCC\n"
 "loc_FF078C20:\n"                            
                 "B       loc_FF078D04\n"
 "loc_FF078C24:\n"                           
                 "B       loc_FF078D18\n"
 "loc_FF078C28:\n"                           
                 "B       loc_FF078D10\n"
 "loc_FF078C2C:\n"                           
                 "B       loc_FF078D24\n"
 "loc_FF078C30:\n"                            
                 "B       loc_FF078D2C\n"
 "loc_FF078C34:\n"                            
                 "B       loc_FF078D34\n"
 "loc_FF078C38:\n"                           
                 "B       loc_FF078D50\n"
 "loc_FF078C3C:\n"                           
                 "B       loc_FF078D90\n"
 "loc_FF078C40:\n"                           
                 "B       loc_FF078D5C\n"
 "loc_FF078C44:\n"                            
                 "B       loc_FF078D68\n"
 "loc_FF078C48:\n"                           
                 "B       loc_FF078D70\n"
 "loc_FF078C4C:\n"                           
                 "B       loc_FF078D78\n"
 "loc_FF078C50:\n"                           
                 "B       loc_FF078D80\n"
 "loc_FF078C54:\n"                           
                 "B       loc_FF078D88\n"
 "loc_FF078C58:\n"                            
                 "B       loc_FF078D98\n"
 "loc_FF078C5C:\n"                           
                 "B       loc_FF078DA0\n"
 "loc_FF078C60:\n"                           
                 "B       loc_FF078DA8\n"
 "loc_FF078C64:\n"                           
                 "B       loc_FF078DB0\n"
 "loc_FF078C68:\n"                            
                 "B       loc_FF078DB8\n"
 "loc_FF078C6C:\n"                            
                 "B       loc_FF078DC0\n"
 "loc_FF078C70:\n"                            
                 "B       loc_FF078DC8\n"
 "loc_FF078C74:\n"                           
                 "B       loc_FF078DD0\n"
 "loc_FF078C78:\n"                           
                 "B       loc_FF078DD8\n"
 "loc_FF078C7C:\n"                           
                 "B       loc_FF078DE0\n"
 "loc_FF078C80:\n"                           
                 "B       loc_FF078DEC\n"
 "loc_FF078C84:\n"                            
                 "B       loc_FF078DF4\n"
 "loc_FF078C88:\n"                           
                 "B       loc_FF078E00\n"
 "loc_FF078C8C:\n"                           
                 "B       loc_FF078E08\n"
 "loc_FF078C90:\n"                           
                 "B       loc_FF078E10\n"
 "loc_FF078C94:\n"                            
                 "B       loc_FF078E18\n"
 "loc_FF078C98:\n"                           
                 "B       loc_FF078E20\n"
 "loc_FF078C9C:\n"                            
                 "B       loc_FF078E28\n"
 "loc_FF078CA0:\n"                           
                 "B       loc_FF078E30\n"
 "loc_FF078CA4:\n"                          
                 "B       loc_FF078E38\n"
 "loc_FF078CA8:\n"                           
                 "B       loc_FF078E40\n"
 "loc_FF078CAC:\n"                            
                 "B       loc_FF078E4C\n"
 "loc_FF078CB0:\n"                            
                 "B       loc_FF078E90\n"
 "loc_FF078CB4:\n"
				 "BL      shooting_expo_iso_override\n"               // added 
				 "BL      sub_FF0794A4\n"
				 "BL      shooting_expo_param_override\n"
 				 "BL      sub_FF076164\n"
				 "MOV     R0, #0\n"
				 "STR     R0, [R5,#0x28]\n"	
                 "B       loc_FF078E90\n"
 "loc_FF078CCC:\n"                            
                 "LDR     R8, [R0,#0xC]\n"
                 "MOV     R0, R8\n"
				 "BL      sub_FF192CBC_my\n"
				 "BL      capt_seq_hook_raw_here\n"
				 "MOV     R4, R0\n"
                 "MOV     R2, R8\n"
                 "MOV     R1, #1\n"
                 "BL      sub_FF076BEC\n"
                 "TST     R4, #1\n"
                 "BNE     loc_FF078CFC\n"
                 "MOV     R0, R8\n"
                 "BL      sub_FF1926A8\n"
                 "B       loc_FF078E90\n"
 "loc_FF078CFC:\n"                           
                 "BL      sub_FF192678\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D04:\n"                            
                 "MOV     R0, #1\n"
                 "BL      sub_FF079784\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D10:\n"                            
                 "BL      sub_FF0790E0\n"
                 "B       loc_FF078D1C\n"
 "loc_FF078D18:\n"                            
                 "BL      sub_FF079484\n"
 "loc_FF078D1C:\n"                            
                 "STR     R6, [R5,#0x28]\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D24:\n"                           
                 "BL      sub_FF07948C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D2C:\n"                           
                 "BL      sub_FF079678\n"
                 "B       loc_FF078D54\n"
 "loc_FF078D34:\n"                            
                 "LDR     R4, [R0,#0xC]\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF192F34\n"
                 "MOV     R2, R4\n"
                 "MOV     R1, #9\n"
                 "BL      sub_FF076BEC\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D50:\n"                           
                 "BL      sub_FF0796EC\n"
 "loc_FF078D54:\n"                            
                 "BL      sub_FF076164\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D5C:\n"                            
                 "LDR     R0, [R5,#0x58]\n"
                 "BL      sub_FF07A004\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D68:\n"                           
                 "BL      sub_FF07A2D4\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D70:\n"                           
                 "BL      sub_FF07A338\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D78:\n"                            
                 "BL      sub_FF07A52C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D80:\n"                           
                 "BL      sub_FF07A97C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D88:\n"                            
                 "BL      sub_FF07AA2C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D90:\n"                           
                 "BL      sub_FF079484\n"
                 "B       loc_FF078E90\n"
 "loc_FF078D98:\n"                            
                 "BL      sub_FF1917B4\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DA0:\n"                           
                 "BL      sub_FF1919C8\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DA8:\n"                           
                 "BL      sub_FF191A60\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DB0:\n"                            
                 "BL      sub_FF191B4C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DB8:\n"                           
                 "BL      sub_FF191C1C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DC0:\n"                            
                 "MOV     R0, #0\n"
                 "B       loc_FF078DE4\n"
 "loc_FF078DC8:\n"                           
                 "BL      sub_FF1920A4\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DD0:\n"                            
                 "BL      sub_FF19213C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DD8:\n"                           
                 "BL      sub_FF19221C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DE0:\n"                           
                 "MOV     R0, #1\n"
 "loc_FF078DE4:\n"                           
                 "BL      sub_FF191F3C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DEC:\n"                            
                 "BL      sub_FF0799A8\n"
                 "B       loc_FF078E90\n"
 "loc_FF078DF4:\n"                            
                 "BL      sub_FF0799E8\n"
                 "BL      sub_FF193BE8\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E00:\n"                            
                 "BL      sub_FF191DA0\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E08:\n"                           
                 "BL      sub_FF191E6C\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E10:\n"                            
                 "BL      sub_FF193CB4\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E18:\n"                           
                 "BL      sub_FF0282D4\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E20:\n"                           
                 "BL      sub_FF07CE74\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E28:\n"                          
                 "BL      sub_FF07CEF8\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E30:\n"                           
                 "BL      sub_FF192310\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E38:\n"                                                                   
                 "BL      sub_FF192374\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E40:\n"                            
                 "BL      sub_FF07CF54\n"
                 "BL      sub_FF07CF14\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E4C:\n"                           
                 "MOV     R0, #1\n"
                 "BL      sub_FF1936E8\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF1937B8\n"
                 "LDRH    R0, [R5,#0xA0]\n"
                 "CMP     R0, #4\n"
                 "LDRNEH  R0, [R5]\n"
                 "SUBNE   R1, R0, #0x4200\n"
                 "SUBNES  R1, R1, #0x2A\n"
                 "BNE     loc_FF078E90\n"
                 "BL      sub_FF07CEF8\n"
                 "BL      sub_FF07D53C\n"
                 "BL      sub_FF07D378\n"
                 "B       loc_FF078E90\n"
 "loc_FF078E84:\n"                            
                 "LDR     R1, =0x5DB\n"
                 "LDR     R0, =0xFF0785F4\n"
                 "BL      sub_FF00EC80\n"
 "loc_FF078E90:\n"  
                 "LDR     R0, [SP]\n"
                 "LDR     R1, [R0,#4]\n"
                 "LDR     R0, [R7]\n"
                 "BL      sub_FF083C60\n"
                 "LDR     R4, [SP]\n"
                 "LDR     R0, [R4,#8]\n"
                 "CMP     R0, #0\n"
                 "LDREQ   R0, =0xFF0785F4\n"
                 "MOVEQ   R1, #0x118\n"
                 "BLEQ    sub_FF00EC80\n"
                 "STR     R6, [R4,#8]\n"
                 "B       loc_FF078BD8\n"
	);
}		

void __attribute__((naked,noinline))  sub_FF192CBC_my(){

	asm volatile(
                "STMFD   SP!, {R3-R7,LR}\n"
                "LDR     R5, =0x3EFA4\n"
                "MOV     R4, R0\n"
                "LDR     R0, [R5,#0x28]\n"
                "LDR     R6, =0x420C\n"
                "CMP     R0, #0\n"
                "MOV     R7, #0\n"
                "BNE     loc_FF192D4C\n"
                "LDR     R0, [R5,#0xC4]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FF192D34\n"
                "LDRH    R0, [R5]\n"
                "CMP     R0, R6\n"
                "LDRNEH  R0, [R5,#0x9E]\n"
                "CMPNE   R0, #3\n"
                "LDRNE   R0, [R4,#8]\n"
                "CMPNE   R0, #1\n"
                "BLS     loc_FF192D18\n"
                "BL      sub_FF022D90\n"
                "TST     R0, #1\n"
                "BEQ     loc_FF192D4C\n"
                "BL      sub_FF07ECA8\n"
                "B       loc_FF192D44\n"
"loc_FF192D18:\n"
                "MOV     R0, #0xC\n"
                "BL      sub_FF07EC48\n"
                "TST     R0, #1\n"
                "BEQ     loc_FF192D4C\n"
                "BL      sub_FF1935A4\n"
                "BL      sub_FF0768BC\n"
                "B       loc_FF192D44\n"
"loc_FF192D34:\n"
                "MOV     R0, #0xC\n"
                "BL      sub_FF07EC48\n"
                "TST     R0, #1\n"
                "BEQ     loc_FF192D4C\n"
"loc_FF192D44:\n"
                "MOV     R0, #1\n"
                "LDMFD   SP!, {R3-R7,PC}\n"
"loc_FF192D4C:\n"
                "LDRH    R0, [R5]\n"
                "CMP     R0, R6\n"
                "LDRNEH  R0, [R5,#0x9E]\n"
                "CMPNE   R0, #3\n"
                "LDRNE   R0, [R4,#8]\n"
                "CMPNE   R0, #1\n"
                "BLS     loc_FF192D7C\n"
                "LDRH    R0, [R5,#0x9C]\n"
                "CMP     R0, #0\n"
                "LDREQH  R0, [R5,#0x98]\n"
                "CMPEQ   R0, #2\n"
                "BLEQ    sub_FF079AB4\n"
"loc_FF192D7C:\n"
                "LDRH    R1, [R5]\n"
                "LDRH    R0, [R5,#0x9E]\n"
                "CMP     R1, R6\n"
                "BEQ     loc_FF192DBC\n"
                "CMP     R0, #3\n"
                "BEQ     loc_FF192DFC\n"
                "LDR     R0, [R4,#8]\n"
                "CMP     R0, #1\n"
                "BLS     loc_FF192DC4\n"
                "LDRH    R0, [R5,#0x9C]\n"
                "CMP     R0, #0\n"
                "BNE     loc_FF192DFC\n"
                "LDRH    R0, [R5,#0x98]\n"
                "CMP     R0, #2\n"
                "BEQ     loc_FF192DF8\n"
                "B       loc_FF192DD0\n"
"loc_FF192DBC:\n"
                "CMP     R0, #3\n"
                "BEQ     loc_FF192DFC\n"
"loc_FF192DC4:\n"
                "LDRH    R0, [R5,#0x9C]\n"
                "CMP     R0, #0\n"
                "BNE     loc_FF192DFC\n"
"loc_FF192DD0:\n"
                "LDRH    R0, [R5,#0x98]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FF192DFC\n"
                "CMP     R1, R6\n"
                "LDRNE   R0, [R4,#8]\n"
                "CMPNE   R0, #1\n"
                "BLS     loc_FF192DFC\n"
                "LDR     R0, [R4,#0xC]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FF192DFC\n"
"loc_FF192DF8:\n"
                "BL      sub_FF193CEC\n"
"loc_FF192DFC:\n"
                "BL      sub_FF193CB4\n"
                "BL      sub_FF079494\n"
                "LDR     R0, [R5,#0x28]\n"
                "CMP     R0, #0\n"
                "BNE     loc_FF192EC8\n"
                "MOV     R0, R4\n"
                "BL      sub_FF192530\n"
                "TST     R0, #1\n"
                "LDMNEFD SP!, {R3-R7,PC}\n"
                "MOV     R0, R4\n"
                "BL      sub_FF192994\n"
                "BL      sub_FF1934E8\n"
                "LDR     R0, [R5,#0xC4]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FF192E54\n"
                "LDRH    R0, [R5]\n"
                "CMP     R0, R6\n"
                "LDRNEH  R0, [R5,#0x9E]\n"
                "CMPNE   R0, #3\n"
                "LDRNE   R0, [R4,#8]\n"
                "CMPNE   R0, #1\n"
                "BHI     loc_FF192E5C\n"
"loc_FF192E54:\n"
                "MOV     R0, #2\n"
                "BL      sub_FF080584\n"
				"BL      wait_until_remote_button_is_released\n"	
				"BL      capt_seq_hook_set_nr\n"
"loc_FF192E5C:\n"
                "LDRH    R0, [R5]\n"
                "SUB     R1, R0, #0x4200\n"
                "SUBS    R1, R1, #0x2D\n"
                "BNE     loc_FF192EB8\n"
                "MOV     R5, #1\n"
                "MOV     R2, #2\n"
                "MOV     R1, SP\n"
                "ADD     R0, R2, #0x15C\n"
                "STR     R5, [SP]\n"
                "BL      sub_FF08BF58\n"
                "TST     R0, #1\n"
                "MOVNE   R1, #0xBC\n"
                "LDRNE   R0, =0xFF192FE4\n"
                "BLNE    sub_FF00EC80\n"
                "LDRH    R0, [SP]\n"
                "CMP     R0, #1\n"
				"BLS     loc_FF192EB0\n"
                "MOV     R0, R4\n"
                "STR     R5, [R4,#0xE4]\n"
                "BL      sub_FF30FF9C\n"
                "B       loc_FF192EC0\n"
"loc_FF192EB0:\n"
                "MOV     R0, #0\n"
                "STR     R0, [R4,#0xE4]\n"
"loc_FF192EB8:\n"
                "MOV     R0, R4\n"
                "BL      sub_FF30FBDC\n"
"loc_FF192EC0:\n"
                "MOV     R7, R0\n"
                "B       loc_FF192ED8\n"
"loc_FF192EC8:\n"
                "LDR     R0, =0x8A08\n"
                "LDR     R0, [R0]\n"
                "CMP     R0, #0\n"
                "MOVNE   R7, #0x1D\n"
"loc_FF192ED8:\n"
                "MOV     R0, R7\n"
                "LDMFD   SP!, {R3-R7,PC}\n"
	);
}

void __attribute__((naked,noinline)) exp_drv_task(){
	asm volatile(
		"STMFD	SP!, {R4-R9,LR}\n"
		"SUB	SP, SP,	#0x24\n"
		"LDR	R6, =0x5838\n"
		"LDR	R7, =0xBB8\n"
		"LDR	R4, =0x5AA3C\n"
		"MOV	R0, #0\n"
		"ADD	R5, SP,	#0x14\n"
		"STR	R0, [SP,#0x10]\n"
"loc_FF0C5E6C:\n"
		"LDR	R0, [R6,#0x20]\n"
		"MOV	R2, #0\n"
		"ADD	R1, SP,	#0x20\n"
		"BL		sub_FF02B17C\n"
		"LDR	R0, [SP,#0x10]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF0C5EB8\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R0, [R0]\n"
		"CMP	R0, #0x14\n"
		"CMPNE	R0, #0x15\n"
		"CMPNE	R0, #0x16\n"
		"CMPNE	R0, #0x17\n"
		"BEQ	loc_FF0C6018\n"
		"CMP	R0, #0x29\n"
		"BEQ	loc_FF0C5FA0\n"
		"ADD	R1, SP,	#0x10\n"
		"MOV	R0, #0\n"
		"BL		sub_FF0C7744\n"
"loc_FF0C5EB8:\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x2F\n"
		"BNE	loc_FF0C5EE4\n"
		"BL		sub_FF0C7270\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #1\n"
		"BL		sub_FF083C60\n"
		"BL		sub_FF00EC38\n"
		"ADD	SP, SP,	#0x24\n"
		"LDMFD	SP!, {R4-R9,PC}\n"
"loc_FF0C5EE4:\n"
		"CMP	R1, #0x2E\n"
		"BNE	loc_FF0C5F00\n"
		"LDR	R2, [R0,#0x8C]!\n"
		"LDR	R1, [R0,#4]\n"
		"MOV	R0, R1\n"
		"BLX	R2\n"
		"B		loc_FF0C64A8\n"
"loc_FF0C5F00:\n"
		"CMP	R1, #0x27\n"
		"BNE	loc_FF0C5F50\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #0x80\n"
		"BL		sub_FF083C94\n"
		"LDR	R0, =0xFF0C111C\n"
		"MOV	R1, #0x80\n"
		"BL		sub_FF18376C\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R2, R7\n"
		"MOV	R1, #0x80\n"
		"BL		sub_FF083BA0\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0x1756\n"
		"BNE	loc_FF0C600C\n"
"loc_FF0C5F3C:\n"
		"LDR	R1, [SP,#0x20]\n"
		"LDR	R0, [R1,#0x90]\n"
		"LDR	R1, [R1,#0x8C]\n"
		"BLX	R1\n"
		"B		loc_FF0C64A8\n"
"loc_FF0C5F50:\n"
		"CMP	R1, #0x28\n"
		"BNE	loc_FF0C5F98\n"
		"ADD	R1, SP,	#0x10\n"
		"BL		sub_FF0C7744\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #0x100\n"
		"BL		sub_FF083C94\n"
		"LDR	R0, =0xFF0C112C\n"
		"MOV	R1, #0x100\n"
		"BL		sub_FF184094\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R2, R7\n"
		"MOV	R1, #0x100\n"
		"BL		sub_FF083BA0\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF0C5F3C\n"
		"LDR	R1, =0x1760\n"
		"B		loc_FF0C600C\n"
"loc_FF0C5F98:\n"
		"CMP	R1, #0x29\n"
		"BNE	loc_FF0C5FB0\n"
"loc_FF0C5FA0:\n"
		"LDR	R0, [SP,#0x20]\n"
		"ADD	R1, SP,	#0x10\n"
		"BL		sub_FF0C7744\n"
		"B		loc_FF0C5F3C\n"
"loc_FF0C5FB0:\n"
		"CMP	R1, #0x2C\n"
		"BNE	loc_FF0C5FC8\n"
		"BL		sub_FF0B2A64\n"
		"BL		sub_FF0B36D4\n"
		"BL		sub_FF0B31F4\n"
		"B		loc_FF0C5F3C\n"
"loc_FF0C5FC8:\n"
		"CMP	R1, #0x2D\n"
		"BNE	loc_FF0C6018\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #4\n"
		"BL		sub_FF083C94\n"
		"LDR	R1, =0xFF0C114C\n"
		"LDR	R0, =0xFFFFF400\n"
		"MOV	R2, #4\n"
		"BL		sub_FF0B24D8\n"
		"BL		sub_FF0B2768\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R2, R7\n"
		"MOV	R1, #4\n"
		"BL		sub_FF083ABC\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF0C5F3C\n"
		"LDR	R1, =0x1788\n"
"loc_FF0C600C:\n"
		"LDR	R0, =0xFF0C18F0\n"
		"BL		sub_FF00EC80\n"
		"B		loc_FF0C5F3C\n"
"loc_FF0C6018:\n"
		"LDR	R0, [SP,#0x20]\n"
		"MOV	R8, #1\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x12\n"
		"CMPNE	R1, #0x13\n"
		"BNE	loc_FF0C6080\n"
		"LDR	R1, [R0,#0x7C]\n"
		"ADD	R1, R1,	R1,LSL#1\n"
		"ADD	R1, R0,	R1,LSL#2\n"
		"SUB	R1, R1,	#8\n"
		"LDMIA	R1, {R2,R3,R9}\n"
		"STMIA	R5, {R2,R3,R9}\n"
		"BL		sub_FF0C41A4\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x8C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"LDR	R0, [SP,#0x20]\n"
		"BL		sub_FF0C7684\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R2, [R0,#0x98]\n"
		"LDR	R3, [R0,#0x94]\n"
		"B		loc_FF0C6394\n"
"loc_FF0C6080:\n"
		"CMP	R1, #0x14\n"
		"CMPNE	R1, #0x15\n"
		"CMPNE	R1, #0x16\n"
		"CMPNE	R1, #0x17\n"
		"BNE	loc_FF0C6138\n"
		"ADD	R3, SP,	#0x10\n"
		"ADD	R2, SP,	#4\n"
		"ADD	R1, SP,	#0x14\n"
		"BL		sub_FF0C440C\n"
		"CMP	R0, #1\n"
		"MOV	R9, R0\n"
		"CMPNE	R9, #5\n"
		"BNE	loc_FF0C60D4\n"
		"LDR	R0, [SP,#0x20]\n"
		"MOV	R2, R9\n"
		"LDR	R1, [R0,#0x7C]!\n"
		"LDR	R12, [R0,#0x10]!\n"
		"LDR	R3, [R0,#4]\n"
		"ADD	R0, SP,	#4\n"
		"BLX	R12\n"
		"B		loc_FF0C610C\n"
"loc_FF0C60D4:\n"
		"LDR	R0, [SP,#0x20]\n"
		"CMP	R9, #2\n"
		"LDR	R3, [R0,#0x90]\n"
		"CMPNE	R9, #6\n"
		"BNE	loc_FF0C6120\n"
		"LDR	R12, [R0,#0x8C]\n"
		"MOV	R2, R9\n"
		"MOV	R1, #1\n"
		"ADD	R0, SP,	#4\n"
		"BLX	R12\n"
		"LDR	R0, [SP,#0x20]\n"
		"ADD	R2, SP,	#4\n"
		"ADD	R1, SP,	#0x14\n"
		"BL		sub_FF0C5B98\n"
"loc_FF0C610C:\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R2, [SP,#0x10]\n"
		"MOV	R1, R9\n"
		"BL		sub_FF0C5DEC\n"
		"B		loc_FF0C639C\n"
"loc_FF0C6120:\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R12, [R0,#0x8C]\n"
		"MOV	R2, R9\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R12\n"
		"B		loc_FF0C639C\n"
"loc_FF0C6138:\n"
		"CMP	R1, #0x23\n"
		"CMPNE	R1, #0x24\n"
		"BNE	loc_FF0C6184\n"
		"LDR	R1, [R0,#0x7C]\n"
		"ADD	R1, R1,	R1,LSL#1\n"
		"ADD	R1, R0,	R1,LSL#2\n"
		"SUB	R1, R1,	#8\n"
		"LDMIA	R1, {R2,R3,R9}\n"
		"STMIA	R5, {R2,R3,R9}\n"
		"BL		sub_FF0C2F94\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x8C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"LDR	R0, [SP,#0x20]\n"
		"BL		sub_FF0C3480\n"
		"B		loc_FF0C639C\n"
"loc_FF0C6184:\n"
		"ADD	R1, R0,	#4\n"
		"LDMIA	R1, {R2,R3,R9}\n"
		"STMIA	R5, {R2,R3,R9}\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x27\n"
		"ADDCC	PC, PC,	R1,LSL#2\n"
		"B		loc_FF0C6384\n"
"loc_FF0C61A0:\n"
		"B		loc_FF0C623C\n"
"loc_FF0C61A4:\n"
		"B		loc_FF0C623C\n"
"loc_FF0C61A8:\n"
		"B		loc_FF0C6244\n"
"loc_FF0C61AC:\n"
		"B		loc_FF0C624C\n"
"loc_FF0C61B0:\n"
		"B		loc_FF0C624C\n"
"loc_FF0C61B4:\n"
		"B		loc_FF0C624C\n"
"loc_FF0C61B8:\n"
		"B		loc_FF0C623C\n"
"loc_FF0C61BC:\n"
		"B		loc_FF0C6244\n"
"loc_FF0C61C0:\n"
		"B		loc_FF0C624C\n"
"loc_FF0C61C4:\n"
		"B		loc_FF0C624C\n"
"loc_FF0C61C8:\n"
		"B		loc_FF0C6264\n"
"loc_FF0C61CC:\n"
		"B		loc_FF0C6264\n"
"loc_FF0C61D0:\n"
		"B		loc_FF0C6370\n"
"loc_FF0C61D4:\n"
		"B		loc_FF0C6378\n"
"loc_FF0C61D8:\n"
		"B		loc_FF0C6378\n"
"loc_FF0C61DC:\n"
		"B		loc_FF0C6378\n"
"loc_FF0C61E0:\n"
		"B		loc_FF0C6378\n"
"loc_FF0C61E4:\n"
		"B		loc_FF0C6380\n"
"loc_FF0C61E8:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C61EC:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C61F0:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C61F4:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C61F8:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C61FC:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6200:\n"
		"B		loc_FF0C6254\n"
"loc_FF0C6204:\n"
		"B		loc_FF0C625C\n"
"loc_FF0C6208:\n"
		"B		loc_FF0C625C\n"
"loc_FF0C620C:\n"
		"B		loc_FF0C6270\n"
"loc_FF0C6210:\n"
		"B		loc_FF0C6270\n"
"loc_FF0C6214:\n"
		"B		loc_FF0C6278\n"
"loc_FF0C6218:\n"
		"B		loc_FF0C62B0\n"
"loc_FF0C621C:\n"
		"B       loc_FF0C62E8\n"
"loc_FF0C6220:\n"
		"B		loc_FF0C6320\n"
"loc_FF0C6224:\n"
		"B		loc_FF0C6358\n"
"loc_FF0C6228:\n"
		"B		loc_FF0C6358\n"
"loc_FF0C622C:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6230:\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6234:\n"
		"B		loc_FF0C6360\n"
"loc_FF0C6238:\n"
		"B		loc_FF0C6368\n"
"loc_FF0C623C:\n"
		"BL		sub_FF0C171C\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6244:\n"
		"BL		sub_FF0C1A1C\n"
		"B		loc_FF0C6384\n"
"loc_FF0C624C:\n"
		"BL		sub_FF0C1C84\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6254:\n"
		"BL		sub_FF0C1F38\n"
		"B		loc_FF0C6384\n"
"loc_FF0C625C:\n"
		"BL		sub_FF0C2150\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6264:\n"
		"BL		sub_FF0C260C_my\n"
		"MOV	R8, #0\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6270:\n"
		"BL		sub_FF0C27F0\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6278:\n"
		"LDRH	R1, [R0,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R4,#2]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R0,#0xC]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL		sub_FF0C7304\n"
		"B		loc_FF0C6384\n"
"loc_FF0C62B0:\n"
		"LDRH	R1, [R0,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R4,#2]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R4,#8]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL		sub_FF0C7484\n"
		"B		loc_FF0C6384\n"
"loc_FF0C62E8:\n"
		"LDRH	R1, [R4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R0,#6]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R4,#8]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL		sub_FF0C7538\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6320:\n"
		"LDRH	R1, [R4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R4,#2]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R0,#0xC]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL		sub_FF0C75E0\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6358:\n"
		"BL		sub_FF0C2D6C\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6360:\n"
		"BL		sub_FF0C3584\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6368:\n"
		"BL		sub_FF0C3A90\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6370:\n"
		"BL		sub_FF0C3C70\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6378:\n"
		"BL		sub_FF0C3E2C\n"
		"B		loc_FF0C6384\n"
"loc_FF0C6380:\n"
		"BL		sub_FF0C3F9C\n"
"loc_FF0C6384:\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"LDR	R3, [R0,#0x8C]\n"
"loc_FF0C6394:\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
"loc_FF0C639C:\n"
		"LDR	R1, [SP,#0x20]\n"
		"LDR	R0, [R1]\n"
		"CMP	R0, #0x10\n"
		"BEQ	loc_FF0C63D4\n"
		"BGT	loc_FF0C63C4\n"
		"CMP	R0, #1\n"
		"CMPNE	R0, #4\n"
		"CMPNE	R0, #0xE\n"
		"BNE	loc_FF0C63E4\n"
		"B		loc_FF0C63D4\n"
"loc_FF0C63C4:\n"
		"CMP	R0, #0x13\n"
		"CMPNE	R0, #0x17\n"
		"CMPNE	R0, #0x1A\n"
		"BNE	loc_FF0C63E4\n"
"loc_FF0C63D4:\n"
		"LDRH	R0, [R4]\n"
		"STRH	R0, [SP,#0x14]\n"
		"LDRH	R0, [R4,#8]\n"
		"STRH	R0, [SP,#0x1C]\n"
"loc_FF0C63E4:\n"
		"CMP	R8, #1\n"
		"BNE	loc_FF0C6430\n"
		"LDR	R0, [R1,#0x7C]\n"
		"MOV	R2, #0xC\n"
		"ADD	R0, R0,	R0,LSL#1\n"
		"ADD	R0, R1,	R0,LSL#2\n"
		"SUB	R8, R0,	#8\n"
		"LDR	R0, =0x5AA3C\n"
		"ADD	R1, SP,	#0x14\n"
		"BL		sub_FF3B5CA4\n"
		"LDR	R0, =0x5AA48\n"
		"MOV	R2, #0xC\n"
		"ADD	R1, SP,	#0x14\n"
		"BL		sub_FF3B5CA4\n"
		"LDR	R0, =0x5AA54\n"
		"MOV	R2, #0xC\n"
		"MOV	R1, R8\n"
		"BL		sub_FF3B5CA4\n"
		"B		loc_FF0C64A8\n"
"loc_FF0C6430:\n"
		"LDR	R0, [R1]\n"
		"MOV	R3, #1\n"
		"CMP	R0, #0xB\n"
		"BNE	loc_FF0C6474\n"
		"MOV	R2, #0\n"
		"STRD	R2, [SP]\n"
		"MOV	R2, R3\n"
		"MOV	R1, R3\n"
		"MOV	R0, #0\n"
		"BL		sub_FF0C14EC\n"
		"MOV	R3, #1\n"
		"MOV	R2, #0\n"
		"STRD	R2, [SP]\n"
		"MOV	R2, R3\n"
		"MOV	R1, R3\n"
		"MOV	R0, #0\n"
		"B		loc_FF0C64A4\n"
"loc_FF0C6474:\n"
		"MOV	R2, #1\n"
		"STRD	R2, [SP]\n"
		"MOV	R3, R2\n"
		"MOV	R1, R2\n"
		"MOV	R0, R2\n"
		"BL		sub_FF0C14EC\n"
		"MOV	R3, #1\n"
		"MOV	R2, R3\n"
		"MOV	R1, R3\n"
		"MOV	R0, R3\n"
		"STR	R3, [SP]\n"
		"STR	R3, [SP,#4]\n"
"loc_FF0C64A4:\n"
		"BL		sub_FF0C1668\n"
"loc_FF0C64A8:\n"
		"LDR	R0, [SP,#0x20]\n"
		"BL		sub_FF0C7270\n"
		"B		loc_FF0C5E6C\n"
	);
}

void __attribute__((naked,noinline)) sub_FF0C260C_my(){

	asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n"
                "LDR     R7, =0x5838\n"
                "MOV     R4, R0\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R1, #0x3E\n"
                "BL      sub_FF083C94\n"
                "MOV     R2, #0\n"
                "LDRSH   R0, [R4,#4]\n"
                "MOV     R1, R2\n"
                "BL      sub_FF0C11AC\n"
                "MOV     R5, R0\n"
                "LDRSH   R0, [R4,#6]\n"
                "BL      sub_FF0C12FC\n"
                "LDRSH   R0, [R4,#8]\n"
                "BL      sub_FF0C1354\n"
                "LDRSH   R0, [R4,#0xA]\n"
                "BL      sub_FF0C13AC\n"
                "LDRSH   R0, [R4,#0xC]\n"
                "MOV     R1, #0\n"
                "BL      sub_FF0C1404\n"
                "MOV     R6, R0\n"
                "LDRSH   R0, [R4,#0xE]\n"
                "BL      sub_FF0C72A0\n"
                "LDR     R0, [R4]\n"
                "LDR     R8, =0x5AA54\n"
                "CMP     R0, #0xB\n"
                "MOVEQ   R5, #0\n"
                "MOVEQ   R6, R5\n"
                "BEQ     loc_FF0C26A8\n"
                "CMP     R5, #1\n"
                "BNE     loc_FF0C26A8\n"
                "LDRSH   R0, [R4,#4]\n"
                "LDR     R1, =0xFF0C110C\n"
                "MOV     R2, #2\n"
                "BL      sub_FF183A44\n"
                "STRH    R0, [R4,#4]\n"
                "MOV     R0, #0\n"
                "STR     R0, [R7,#0x28]\n"
                "B       loc_FF0C26B0\n"
"loc_FF0C26A8:\n"
                "LDRH    R0, [R8]\n"
                "STRH    R0, [R4,#4]\n"
"loc_FF0C26B0:\n"
                "CMP     R6, #1\n"
                "LDRNEH  R0, [R8,#8]\n"
                "BNE     loc_FF0C26CC\n"
                "LDRSH   R0, [R4,#0xC]\n"
                "LDR     R1, =0xFF0C1190\n"
                "MOV     R2, #0x20\n"
                "BL      sub_FF0C72C0\n"
"loc_FF0C26CC:\n"
                "STRH    R0, [R4,#0xC]\n"
                "LDRSH   R0, [R4,#6]\n"
                "BL      sub_FF0B27D4_my\n"
                "LDRSH   R0, [R4,#8]\n"
                "MOV     R1, #1\n"
                "BL      sub_FF0B2F34\n"
                "MOV     R1, #0\n"
                "ADD     R0, R4, #8\n"
                "BL      sub_FF0B2FBC\n"
                "LDRSH   R0, [R4,#0xE]\n"
                "BL      sub_FF0BBFA0\n"
                "LDR     R4, =0xBB8\n"
                "CMP     R5, #1\n"
                "BNE     loc_FF0C2724\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R2, R4\n"
                "MOV     R1, #2\n"
                "BL      sub_FF083BA0\n"
                "TST     R0, #1\n"
                "LDRNE   R1, =0x7E3\n"
                "LDRNE   R0, =0xFF0C18F0\n"
                "BLNE    sub_FF00EC80\n"
"loc_FF0C2724:\n"
                "CMP     R6, #1\n"
                "LDMNEFD SP!, {R4-R8,PC}\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R2, R4\n"
                "MOV     R1, #0x20\n"
                "BL      sub_FF083BA0\n"
                "TST     R0, #1\n"
                "LDMEQFD SP!, {R4-R8,PC}\n"
                "LDMFD   SP!, {R4-R8,LR}\n"
                "LDR     R1, =0x7E8\n"
                "LDR     R0, =0xFF0C18F0\n"
                "B       sub_FF00EC80\n"
	);
}

void __attribute__((naked,noinline)) sub_FF0B27D4_my(){

	asm volatile(
                "STMFD   SP!, {R4-R6,LR}\n"
                "LDR     R5, =0x54E0\n"
                "MOV     R4, R0\n"
                "LDR     R0, [R5,#4]\n"
                "CMP     R0, #1\n"
                "LDRNE   R1, =0x146\n"
                "LDRNE   R0, =0xFF0B260C\n"
                "BLNE    sub_FF00EC80\n"
                "CMN     R4, #0xC00\n"
                "LDREQSH R4, [R5,#2]\n"
                "CMN     R4, #0xC00\n"
                "MOVEQ   R1, #0x14C\n"
                "LDREQ   R0, =0xFF0B260C\n"
                "STRH    R4, [R5,#2]\n"
                "BLEQ    sub_FF00EC80\n"
                "MOV     R0, R4\n"
                "BL      apex2us\n"
                "MOV     R4, R0\n"
                "BL      sub_FF106D80\n"
                "MOV     R0, R4\n"
                "BL      sub_FF114DA0\n"
                "TST     R0, #1\n"
                "LDMEQFD SP!, {R4-R6,PC}\n"
                "LDMFD   SP!, {R4-R6,LR}\n"
                "LDR     R1, =0x151\n"
                "LDR     R0, =0xFF0B260C\n"
                "B       sub_FF00EC80\n"
	);
}
