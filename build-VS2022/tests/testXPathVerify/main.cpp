#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>

#include <libxml/xmlschemas.h>

#define SAFE_ATTRIB(var, expr) do {var = (expr); if (var == nullptr) { goto CleanUp; } } while(0);


using namespace std;

struct Query {
    string name;
    string value;
};

const Query satisfiableQueries[] = {
    {"Q1'", "/site/closed_auctions/closed_auction/annotation/descrition/parlist"},
    {"Q4'", "/site/people/person"},
    {"Q5'", "//person"},
    {"Q7'", "/descendant-or-self::person"},
    {"Q9'", "//*/person"}
};

const Query unsatisfiableQueries[] = {
    {"Q1'", "/site/closed_auctions/closed_auction/annotation/descrition/parlist"},
    {"Q4'", "/site/people/person"},
    {"Q5'", "//person"},
    {"Q7'", "/descendant-or-self::person"},
    {"Q9'", "//*/person"}
};

void handleError()
{
    std::cerr << "An internal libxml2 error has occured\n";
}

void runTest(const std::string& filename, const Query& q, const int expectedValue) 
{
    // TODO pick a different encoding for reading documents
// TODO return -1 for allocation errors
    xmlDocPtr doc = nullptr;
    xmlSchemaParserCtxtPtr schemaParser = nullptr;
    xmlSchemaPtr schema = nullptr;
    xmlSchemaValidCtxtPtr validSchemaCtxt = nullptr;
    xmlSchemaVerifyXPathCtxtPtr verifyCtxt = nullptr;
    const char* encoding = "UTF-8";
    int retVal = 0;
    const char* xpath = q.value.c_str();

    SAFE_ATTRIB(schemaParser, xmlSchemaNewDocParserCtxt(doc));
    SAFE_ATTRIB(schema, xmlSchemaParse(schemaParser));
    SAFE_ATTRIB(validSchemaCtxt, xmlSchemaNewValidCtxt(schema));
    SAFE_ATTRIB(verifyCtxt, xmlSchemaNewVerifyXPathCtxt(validSchemaCtxt, (xmlChar*)xpath));
    xmlSetGenericErrorFunc(stdout, fprintf);

    retVal = xmlSchemaVerifyXPath(verifyCtxt);

    assert(retVal == expectedValue);

CleanUp:

    if (verifyCtxt) xmlSchemaFreeVerifyXPathCtxt(verifyCtxt);
    if (validSchemaCtxt) xmlSchemaFreeValidCtxt(validSchemaCtxt);
    if (schema) xmlSchemaFree(schema);
    if (schemaParser) xmlSchemaFreeParserCtxt(schemaParser);
}

int main(int argc, char** argv) {

    return 0;
}