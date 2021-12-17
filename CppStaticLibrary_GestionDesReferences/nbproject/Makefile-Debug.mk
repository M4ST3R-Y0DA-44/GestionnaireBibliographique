#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++-10
CXX=g++-10
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Bibliographie.o \
	${OBJECTDIR}/ContratException.o \
	${OBJECTDIR}/Journal.o \
	${OBJECTDIR}/Ouvrage.o \
	${OBJECTDIR}/Reference.o \
	${OBJECTDIR}/ReferenceException.o \
	${OBJECTDIR}/validationFormat.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/BibliographieTesteur.o \
	${TESTDIR}/tests/JournalTesteur.o \
	${TESTDIR}/tests/OuvrageTesteur.o \
	${TESTDIR}/tests/ReferenceTesteur.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppstaticlibrary_gestiondesreferences.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppstaticlibrary_gestiondesreferences.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppstaticlibrary_gestiondesreferences.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppstaticlibrary_gestiondesreferences.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppstaticlibrary_gestiondesreferences.a

${OBJECTDIR}/Bibliographie.o: Bibliographie.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bibliographie.o Bibliographie.cpp

${OBJECTDIR}/ContratException.o: ContratException.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContratException.o ContratException.cpp

${OBJECTDIR}/Journal.o: Journal.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Journal.o Journal.cpp

${OBJECTDIR}/Ouvrage.o: Ouvrage.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ouvrage.o Ouvrage.cpp

${OBJECTDIR}/Reference.o: Reference.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reference.o Reference.cpp

${OBJECTDIR}/ReferenceException.o: ReferenceException.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReferenceException.o ReferenceException.cpp

${OBJECTDIR}/validationFormat.o: validationFormat.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/validationFormat.o validationFormat.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/BibliographieTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/JournalTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/OuvrageTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/ReferenceTesteur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 


${TESTDIR}/tests/BibliographieTesteur.o: tests/BibliographieTesteur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/BibliographieTesteur.o tests/BibliographieTesteur.cpp


${TESTDIR}/tests/JournalTesteur.o: tests/JournalTesteur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/JournalTesteur.o tests/JournalTesteur.cpp


${TESTDIR}/tests/OuvrageTesteur.o: tests/OuvrageTesteur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OuvrageTesteur.o tests/OuvrageTesteur.cpp


${TESTDIR}/tests/ReferenceTesteur.o: tests/ReferenceTesteur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ReferenceTesteur.o tests/ReferenceTesteur.cpp


${OBJECTDIR}/Bibliographie_nomain.o: ${OBJECTDIR}/Bibliographie.o Bibliographie.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Bibliographie.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bibliographie_nomain.o Bibliographie.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Bibliographie.o ${OBJECTDIR}/Bibliographie_nomain.o;\
	fi

${OBJECTDIR}/ContratException_nomain.o: ${OBJECTDIR}/ContratException.o ContratException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ContratException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContratException_nomain.o ContratException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ContratException.o ${OBJECTDIR}/ContratException_nomain.o;\
	fi

${OBJECTDIR}/Journal_nomain.o: ${OBJECTDIR}/Journal.o Journal.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Journal.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Journal_nomain.o Journal.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Journal.o ${OBJECTDIR}/Journal_nomain.o;\
	fi

${OBJECTDIR}/Ouvrage_nomain.o: ${OBJECTDIR}/Ouvrage.o Ouvrage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Ouvrage.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ouvrage_nomain.o Ouvrage.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Ouvrage.o ${OBJECTDIR}/Ouvrage_nomain.o;\
	fi

${OBJECTDIR}/Reference_nomain.o: ${OBJECTDIR}/Reference.o Reference.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Reference.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reference_nomain.o Reference.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Reference.o ${OBJECTDIR}/Reference_nomain.o;\
	fi

${OBJECTDIR}/ReferenceException_nomain.o: ${OBJECTDIR}/ReferenceException.o ReferenceException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ReferenceException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReferenceException_nomain.o ReferenceException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ReferenceException.o ${OBJECTDIR}/ReferenceException_nomain.o;\
	fi

${OBJECTDIR}/validationFormat_nomain.o: ${OBJECTDIR}/validationFormat.o validationFormat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/validationFormat.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/validationFormat_nomain.o validationFormat.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/validationFormat.o ${OBJECTDIR}/validationFormat_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
