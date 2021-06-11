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
SOURCEFILES_QUOTED_IF_SPACED=adc.c buttons.c leds.c timer_1ms.c system.c leds_rgb.c sccp.c uart1.c uart_printf.c main.c debounce.c msi.c /home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}/slave.s 

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/adc.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/timer_1ms.o ${OBJECTDIR}/system.o ${OBJECTDIR}/leds_rgb.o ${OBJECTDIR}/sccp.o ${OBJECTDIR}/uart1.o ${OBJECTDIR}/uart_printf.o ${OBJECTDIR}/main.o ${OBJECTDIR}/debounce.o ${OBJECTDIR}/msi.o ${OBJECTDIR}/slave.o 
POSSIBLE_DEPFILES=${OBJECTDIR}/adc.o.d ${OBJECTDIR}/buttons.o.d ${OBJECTDIR}/leds.o.d ${OBJECTDIR}/timer_1ms.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/leds_rgb.o.d ${OBJECTDIR}/sccp.o.d ${OBJECTDIR}/uart1.o.d ${OBJECTDIR}/uart_printf.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/debounce.o.d ${OBJECTDIR}/msi.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/adc.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/timer_1ms.o ${OBJECTDIR}/system.o ${OBJECTDIR}/leds_rgb.o ${OBJECTDIR}/sccp.o ${OBJECTDIR}/uart1.o ${OBJECTDIR}/uart_printf.o ${OBJECTDIR}/main.o ${OBJECTDIR}/debounce.o ${OBJECTDIR}/msi.o ${OBJECTDIR}/slave.o 

# Source Files
SOURCEFILES=adc.c buttons.c leds.c timer_1ms.c system.c leds_rgb.c sccp.c uart1.c uart_printf.c main.c debounce.c msi.c /home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}/slave.s 



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
${OBJECTDIR}/adc.o: adc.c  .generated_files/267c5ceae960694a89bc9f1b6b6e608622b6fdff.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/d4b95cba44cbf9efbb50c3882a1661d5aee91d9c.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  buttons.c  -o ${OBJECTDIR}/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/buttons.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/2a9315938b76845fcaf34b98fabaabfe7b204939.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds.c  -o ${OBJECTDIR}/leds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer_1ms.o: timer_1ms.c  .generated_files/890bf10d65f3826a926405114fea0ca82952e5dc.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer_1ms.c  -o ${OBJECTDIR}/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer_1ms.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/fd8d102ca957c97a57903099caf9d9f84f057590.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds_rgb.o: leds_rgb.c  .generated_files/5ef0a05c4ae325346000133e639664ad6a265a18.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/leds_rgb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds_rgb.c  -o ${OBJECTDIR}/leds_rgb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds_rgb.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sccp.o: sccp.c  .generated_files/f7338c6d447a4c40fb5e7422b411dc9dd987148b.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sccp.o.d 
	@${RM} ${OBJECTDIR}/sccp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sccp.c  -o ${OBJECTDIR}/sccp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sccp.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart1.o: uart1.c  .generated_files/225bec9c7c86b7af3387296a3ec64d93006cddad.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart1.o.d 
	@${RM} ${OBJECTDIR}/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart1.c  -o ${OBJECTDIR}/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart_printf.o: uart_printf.c  .generated_files/71b95684ca88dbb66252f4b9736d017d74c9610e.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart_printf.o.d 
	@${RM} ${OBJECTDIR}/uart_printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_printf.c  -o ${OBJECTDIR}/uart_printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart_printf.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/826b30df63726705e4265c4f848b2f5622c09216.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/debounce.o: debounce.c  .generated_files/3f76a3b777bd3d27eec9268666c939daf0c22928.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/debounce.o.d 
	@${RM} ${OBJECTDIR}/debounce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  debounce.c  -o ${OBJECTDIR}/debounce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/debounce.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/msi.o: msi.c  .generated_files/3c6b29ff6dd0407c7ea82225499611773ea16fbc.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/msi.o.d 
	@${RM} ${OBJECTDIR}/msi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  msi.c  -o ${OBJECTDIR}/msi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/msi.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/adc.o: adc.c  .generated_files/1232b4b3b4673998cc3cfc1d5e1d5416cf8ad73f.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/c5616b12606e5329c85e2d839754aafc73d61779.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  buttons.c  -o ${OBJECTDIR}/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/buttons.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/878125e42f3607155a2a8e4bc0cd856b6e95b165.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds.c  -o ${OBJECTDIR}/leds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/timer_1ms.o: timer_1ms.c  .generated_files/2c97363f226e4c49a936c567c292e1c751ee6b85.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer_1ms.c  -o ${OBJECTDIR}/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer_1ms.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/b5d42d099d851efedc249c71e54deffceac83c3f.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/leds_rgb.o: leds_rgb.c  .generated_files/691f8307493d6e399dff29e78b72655cff89dea1.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds_rgb.o.d 
	@${RM} ${OBJECTDIR}/leds_rgb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  leds_rgb.c  -o ${OBJECTDIR}/leds_rgb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/leds_rgb.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/sccp.o: sccp.c  .generated_files/ddf75d7b8f8f997db60f9742c951c040ba5038b5.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sccp.o.d 
	@${RM} ${OBJECTDIR}/sccp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sccp.c  -o ${OBJECTDIR}/sccp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/sccp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart1.o: uart1.c  .generated_files/32f08d7952148fa24bdcc85092161808eb83d224.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart1.o.d 
	@${RM} ${OBJECTDIR}/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart1.c  -o ${OBJECTDIR}/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart_printf.o: uart_printf.c  .generated_files/910a4b4de38a9b14553fb1cfac78274cafb6a2fd.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart_printf.o.d 
	@${RM} ${OBJECTDIR}/uart_printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_printf.c  -o ${OBJECTDIR}/uart_printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart_printf.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/8f2623cfe1782cfb147ac2b6291ca7e33728191a.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/debounce.o: debounce.c  .generated_files/9a1c88e86440e9f24f414ead1e844b7c32d00a28.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/debounce.o.d 
	@${RM} ${OBJECTDIR}/debounce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  debounce.c  -o ${OBJECTDIR}/debounce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/debounce.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/msi.o: msi.c  .generated_files/4ac3d2e733a06da51f1acdec788e6ad8748e636f.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/msi.o.d 
	@${RM} ${OBJECTDIR}/msi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  msi.c  -o ${OBJECTDIR}/msi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/msi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -DFCY=80000000UL -DUART1_BAUD=230400UL -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${OBJECTDIR}/slave.o: /home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}/slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)   -mdfp="${DFP_DIR}/xc16"  /home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}/slave.s  -o ${OBJECTDIR}/slave.o
else
${OBJECTDIR}/slave.o: /home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}/slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)   -mdfp="${DFP_DIR}/xc16"  /home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}/slave.s  -o ${OBJECTDIR}/slave.o
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/git/buck-boost/MPLAB/slave.X/dist/default/${IMAGE_TYPE}"  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
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
