#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=adc.c buttons.c leds.c timer_1ms.c system.c leds_rgb.c sccp.c uart1.c uart_printf.c main.c debounce.c msi.c /home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}/slave.s 

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/adc.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/timer_1ms.o ${OBJECTDIR}/system.o ${OBJECTDIR}/leds_rgb.o ${OBJECTDIR}/sccp.o ${OBJECTDIR}/uart1.o ${OBJECTDIR}/uart_printf.o ${OBJECTDIR}/main.o ${OBJECTDIR}/debounce.o ${OBJECTDIR}/msi.o ${OBJECTDIR}/slave.o 
POSSIBLE_DEPFILES=${OBJECTDIR}/adc.o.d ${OBJECTDIR}/buttons.o.d ${OBJECTDIR}/leds.o.d ${OBJECTDIR}/timer_1ms.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/leds_rgb.o.d ${OBJECTDIR}/sccp.o.d ${OBJECTDIR}/uart1.o.d ${OBJECTDIR}/uart_printf.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/debounce.o.d ${OBJECTDIR}/msi.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/adc.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/timer_1ms.o ${OBJECTDIR}/system.o ${OBJECTDIR}/leds_rgb.o ${OBJECTDIR}/sccp.o ${OBJECTDIR}/uart1.o ${OBJECTDIR}/uart_printf.o ${OBJECTDIR}/main.o ${OBJECTDIR}/debounce.o ${OBJECTDIR}/msi.o ${OBJECTDIR}/slave.o 

# Source Files
SOURCEFILES=adc.c buttons.c leds.c timer_1ms.c system.c leds_rgb.c sccp.c uart1.c uart_printf.c main.c debounce.c msi.c /home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}/slave.s 



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CH512MP508
MP_LINKER_FILE_OPTION=,--script=p33CH512MP508.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/adc.o: adc.c  .generated_files/65f89f75d2e445639723faf25bf6455eae033457.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/e9447ce433e726c0af926c9c633182fffc128f46.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  buttons.c  -o ${OBJECTDIR}/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/buttons.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/e054b470c5c888682a588e2262124c324cb22524.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds.c  -o ${OBJECTDIR}/leds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer_1ms.o: timer_1ms.c  .generated_files/de1d366f3af50c3b032949905c7a1a1544b27c24.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer_1ms.c  -o ${OBJECTDIR}/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer_1ms.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/c0cdfc00b4676958e47044e10821e3574d5367e8.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds_rgb.o: leds_rgb.c  .generated_files/65b91040be194e099ab4b4887aa738fc1a95919b.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/leds_rgb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds_rgb.c  -o ${OBJECTDIR}/leds_rgb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds_rgb.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sccp.o: sccp.c  .generated_files/5a8af705018a913d5063d0516e88946362ff6bef.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sccp.o.d 
	@${RM} ${OBJECTDIR}/sccp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sccp.c  -o ${OBJECTDIR}/sccp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sccp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart1.o: uart1.c  .generated_files/95f92b2b885a4ceae13998d29e354086bbac2a79.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart1.o.d 
	@${RM} ${OBJECTDIR}/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart1.c  -o ${OBJECTDIR}/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart_printf.o: uart_printf.c  .generated_files/dc965f241244a2377fc02d8ab7c8c6a02eed5951.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart_printf.o.d 
	@${RM} ${OBJECTDIR}/uart_printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_printf.c  -o ${OBJECTDIR}/uart_printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart_printf.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/e8ec08c368cada3f12dd5b693f36ce77064d579.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/debounce.o: debounce.c  .generated_files/6843061704b95e9654b1fda054e28ed287c06c1.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/debounce.o.d 
	@${RM} ${OBJECTDIR}/debounce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  debounce.c  -o ${OBJECTDIR}/debounce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/debounce.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/msi.o: msi.c  .generated_files/ef566c43489e359a9867e6160b602c13e2eb528a.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/msi.o.d 
	@${RM} ${OBJECTDIR}/msi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  msi.c  -o ${OBJECTDIR}/msi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/msi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/adc.o: adc.c  .generated_files/6a571c172600fca2100853e181763526e09dda34.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/c76e8ede103709e5ab0788e43392247b398206e0.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  buttons.c  -o ${OBJECTDIR}/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/buttons.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/e1e7b44a6b76b7727cbe3236c90034e0867b0617.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds.c  -o ${OBJECTDIR}/leds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer_1ms.o: timer_1ms.c  .generated_files/394e864ef2e54a56e7c5cf90988f7fd8015b8873.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer_1ms.c  -o ${OBJECTDIR}/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer_1ms.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/245d48fada8411ebf2a870972d5e4fd4af2983bf.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds_rgb.o: leds_rgb.c  .generated_files/8ce79d142187b6d1a510e4330ef9707145281ded.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/leds_rgb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds_rgb.c  -o ${OBJECTDIR}/leds_rgb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds_rgb.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sccp.o: sccp.c  .generated_files/f2e77a98320d37269f6ed9c22354cd2d4adece39.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sccp.o.d 
	@${RM} ${OBJECTDIR}/sccp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sccp.c  -o ${OBJECTDIR}/sccp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sccp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart1.o: uart1.c  .generated_files/7e861f5736186c0533c3797a792ac98816302b70.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart1.o.d 
	@${RM} ${OBJECTDIR}/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart1.c  -o ${OBJECTDIR}/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart_printf.o: uart_printf.c  .generated_files/ab9384eec8ea889cad0ecdbadb1a308c6278ac2e.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart_printf.o.d 
	@${RM} ${OBJECTDIR}/uart_printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_printf.c  -o ${OBJECTDIR}/uart_printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart_printf.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/d118ffa96b0aef58cc9f247028739cf052203c07.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/debounce.o: debounce.c  .generated_files/dad11632180346187339728f6c075499351a1520.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/debounce.o.d 
	@${RM} ${OBJECTDIR}/debounce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  debounce.c  -o ${OBJECTDIR}/debounce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/debounce.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/msi.o: msi.c  .generated_files/1527bd6479f0061f0ae6c56b02d04034deda7beb.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/msi.o.d 
	@${RM} ${OBJECTDIR}/msi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  msi.c  -o ${OBJECTDIR}/msi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/msi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble_subordinate
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/slave.o: /home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}/slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)   -mdfp="${DFP_DIR}/xc16"  /home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}/slave.s  -o ${OBJECTDIR}/slave.o
else
${OBJECTDIR}/slave.o: /home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}/slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)   -mdfp="${DFP_DIR}/xc16"  /home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}/slave.s  -o ${OBJECTDIR}/slave.o
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=__S1DEBUG=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/buck-test-3/slave.X/dist/default/${IMAGE_TYPE}"  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
	cd ../slave.X && ${MAKE}  -f Makefile CONF=default TYPE_IMAGE=DEBUG_RUN
	cd ../slave.X && ${MAKE}  -f Makefile CONF=default TYPE_IMAGE=DEBUG_RUN SUB_IMAGE_NAME=slave .build-sub-images-impl
else
	cd ../slave.X && ${MAKE}  -f Makefile CONF=default
	cd ../slave.X && ${MAKE}  -f Makefile CONF=default SUB_IMAGE_NAME=slave .build-sub-images-impl
endif


# Subprojects
.clean-subprojects:
	cd ../slave.X && rm -rf "build/default" "dist/default"

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
