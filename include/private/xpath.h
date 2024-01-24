#ifndef XML_XPATH_H_PRIVATE__
#define XML_XPATH_H_PRIVATE__


typedef struct _todo_xmlXPathSatisfiabilityExecCtxt todo_xmlXPathSatisfiabilityExecCtxt XML_HIDDEN;
typedef todo_xmlXPathSatisfiabilityExecCtxt* todo_xmlXPathSatisfiabilityExecCtxtPtr XML_HIDDEN;

XML_HIDDEN void
xmlInitXPathInternal(void);

XML_HIDDEN int
xmlXPathIsSatisfiableOnSchema(xmlXPathContextPtr ctx,
    const xmlChar* str,
    const xmlRegexpPtr verticalModel,
    const xmlRegexpPtr closure);

#endif /* XML_XPATH_H_PRIVATE__ */
