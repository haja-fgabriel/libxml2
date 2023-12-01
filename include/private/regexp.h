#ifndef XML_REGEXP_H_PRIVATE__
#define XML_REGEXP_H_PRIVATE__

#include <libxml/xmlautomata.h>

XML_HIDDEN void
xmlAutomataSetFlags(xmlAutomataPtr am, int flags);

XML_HIDDEN int
xmlRegexpGetNbStrings(xmlRegexpPtr reg);

XML_HIDDEN int
xmlRegexpGetNbStates(xmlRegexpPtr reg);

XML_HIDDEN char*
xmlRegexpGetString(xmlRegexpPtr reg, int index);

XML_HIDDEN int
xmlRegexpHasPath(xmlRegexpPtr reg, int index, int atom);

XML_HIDDEN int
xmlRegExecHasPath(xmlRegExecCtxtPtr ctxt, const xmlChar* name);

XML_HIDDEN int
xmlRegExecGetState(xmlRegExecCtxtPtr ctxt);

XML_HIDDEN void
xmlRegExecSetState(xmlRegExecCtxtPtr ctxt, int state);

XML_HIDDEN int
xmlRegExecIsInFinalState(xmlRegExecCtxtPtr ctxt);

XML_HIDDEN xmlRegExecCtxtPtr
xmlRegCopyExecCtxt(xmlRegExecCtxtPtr exec);



#endif /* XML_REGEXP_H_PRIVATE__ */
