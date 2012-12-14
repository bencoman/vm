/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.234 uuid: 66acafd1-cad0-4f20-b786-ab8f48201d82
   from
	JoystickTabletPlugin VMMaker.oscog-eem.234 uuid: 66acafd1-cad0-4f20-b786-ab8f48201d82
 */
static char __buildInfo[] = "JoystickTabletPlugin VMMaker.oscog-eem.234 uuid: 66acafd1-cad0-4f20-b786-ab8f48201d82 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "JoystickTabletPlugin.h"
#include "sqMemoryAccess.h"
#include "sqMemoryAccess.h"


/*** Constants ***/
#define BytesPerWord 4


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
EXPORT(sqInt) initialiseModule(void);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveGetTabletParameters(void);
EXPORT(sqInt) primitiveReadJoystick(void);
EXPORT(sqInt) primitiveReadTablet(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static void sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*classBitmap)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*positive32BitIntegerFor)(sqInt integerValue);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt classBitmap(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt positive32BitIntegerFor(sqInt integerValue);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt success(sqInt aBoolean);

extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"JoystickTabletPlugin VMMaker.oscog-eem.234 (i)"
#else
	"JoystickTabletPlugin VMMaker.oscog-eem.234 (e)"
#endif
;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

static sqInt
halt(void)
{
	;
	return 0;
}

EXPORT(sqInt)
initialiseModule(void)
{
	return joystickInit();
}

static sqInt
msg(char *s)
{
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}


/*	Get information on the pen tablet attached to this machine. Fail if there
	is no tablet. If successful, the result is an array of integers; see the
	Smalltalk call on this primitive for its interpretation.
 */

EXPORT(sqInt)
primitiveGetTabletParameters(void)
{
	sqInt cursorIndex;
	sqInt result;
	int *  resultPtr;
	sqInt resultSize;

	cursorIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = instantiateClassindexableSize(classBitmap(), resultSize);
	resultPtr = ((int *)firstIndexableField(result));
	success(tabletGetParameters(cursorIndex, resultPtr));
	if (failed()) {
		return null;
	}
	popthenPush(2, result);
	return null;
}


/*	Read an input word from the joystick with the given index. */

EXPORT(sqInt)
primitiveReadJoystick(void)
{
	sqInt index;
	sqInt _return_value;

	index = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	_return_value = positive32BitIntegerFor((joystickRead(index)));
	if (failed()) {
		return null;
	}
	popthenPush(2, _return_value);
	return null;
}


/*	Get the current state of the cursor of the pen tablet specified by my
	argument. Fail if there is no tablet. If successful, the result is an
	array of integers; see the Smalltalk call on this primitive for its
	interpretation. 
 */

EXPORT(sqInt)
primitiveReadTablet(void)
{
	sqInt cursorIndex;
	sqInt result;
	int *  resultPtr;
	sqInt resultSize;

	cursorIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = instantiateClassindexableSize(classBitmap(), resultSize);
	resultPtr = ((int *)firstIndexableField(result));
	success(tabletRead(cursorIndex, resultPtr));
	if (failed()) {
		return null;
	}
	popthenPush(2, result);
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		classBitmap = interpreterProxy->classBitmap;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		popthenPush = interpreterProxy->popthenPush;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

EXPORT(sqInt)
shutdownModule(void)
{
	return joystickShutdown();
}

static void
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* JoystickTabletPlugin_exports[][3] = {
	{"JoystickTabletPlugin", "getModuleName", (void*)getModuleName},
	{"JoystickTabletPlugin", "initialiseModule", (void*)initialiseModule},
	{"JoystickTabletPlugin", "primitiveGetTabletParameters", (void*)primitiveGetTabletParameters},
	{"JoystickTabletPlugin", "primitiveReadJoystick", (void*)primitiveReadJoystick},
	{"JoystickTabletPlugin", "primitiveReadTablet", (void*)primitiveReadTablet},
	{"JoystickTabletPlugin", "setInterpreter", (void*)setInterpreter},
	{"JoystickTabletPlugin", "shutdownModule", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#endif /* ifdef SQ_BUILTIN_PLUGIN */
