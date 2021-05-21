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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/mcc.c mcc_generated_files/reset.c mcc_generated_files/pin_manager.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/traps.c mcc_generated_files/slave1.c mcc_generated_files/interrupt_manager.c main.c /home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}/slave.s 

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/slave1.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/main.o ${OBJECTDIR}/slave.o 
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/reset.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/slave1.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/slave1.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/main.o ${OBJECTDIR}/slave.o 

# Source Files
SOURCEFILES=mcc_generated_files/mcc.c mcc_generated_files/reset.c mcc_generated_files/pin_manager.c mcc_generated_files/system.c mcc_generated_files/clock.c mcc_generated_files/traps.c mcc_generated_files/slave1.c mcc_generated_files/interrupt_manager.c main.c /home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}/slave.s 



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CH512MP508
MP_LINKER_FILE_OPTION=,--script=p33CH512MP508.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/8d0eae386d0076ab9d51a7229c19e88bbd1025c4.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/55dd8d9a73670779aafbf22cb72411006be3e5b4.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/ac04eee412f73b724c178e9207b185fdc533aaeb.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/af14ea264d63183e21e21222f2d973355608ab1a.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/ffab6e90588ab410b07435033ba96c995fd49631.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/468527208e55eb3a89a24825934d1473616802c5.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/slave1.o: mcc_generated_files/slave1.c  .generated_files/30cab8fc559cdf79c3e4fc495613c5e635923bc.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/slave1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/slave1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/slave1.c  -o ${OBJECTDIR}/mcc_generated_files/slave1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/slave1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/92e140d9d8672a12cbd9f1c8d425887e48e9247c.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/c662af756f0e57b528cb842161b9fa8392252fc7.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/69f33a9259ddd7d05b8cd820da6ac02272280bc7.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/a16f121b3976a0d81311d4765f6d6a1a6e274cae.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/f69f81e48c66f2bb48e00ecf074feac271e98bf7.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/21f7165c6161e38774b26ac4bb9f28b1bbdeab39.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/7d0a46820df2fb47f4a51ea356feb1e6204097ed.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/adad4f8857a7f992b6740d9da1f7471260168f5a.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/slave1.o: mcc_generated_files/slave1.c  .generated_files/86b2f094c2580cb7afaedb62b5c4dab781973484.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/slave1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/slave1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/slave1.c  -o ${OBJECTDIR}/mcc_generated_files/slave1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/slave1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/e03e7fd67e9ba2c038b6f3b04605d28bd60762bd.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/46e9de245b63af648c483cb049ad760c29b88835.flag .generated_files/ccbd08de599db581e2f5ac0b232fcd696c760de2.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${OBJECTDIR}/slave.o: /home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}/slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)   -mdfp="${DFP_DIR}/xc16"  /home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}/slave.s  -o ${OBJECTDIR}/slave.o
else
${OBJECTDIR}/slave.o: /home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}/slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)   -mdfp="${DFP_DIR}/xc16"  /home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}/slave.s  -o ${OBJECTDIR}/slave.o
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -I"/home/max/University/DigitalControl/Curosity/git/buck-boost/feedback-loop-tests/slave.X/dist/default/${IMAGE_TYPE}"  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/fbl-1-master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
