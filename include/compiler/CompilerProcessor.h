#ifndef COMPILER_PROCESSOR_H
#define COMPILER_PROCESSOR_H

#include "processor/AimlProcessor.h"
#include "Kernel.h"
#include "Utils.h"

#include <string>
#include "CompilerHandler.h"

using namespace std;

class CompilerProcessor : public AimlProcessor
{
public:
	~CompilerProcessor() { }

	string process(Match *m, PElement e, Responder *r, const string &id) {
        Player *p = sObjectMgr.GetPlayer(id.c_str());
		string func = e->getAttribute("func");
		string value = "",  name;
		velement param;
		e->getChildren("param", &param);
		map<string, string> argMap;
        for (velement_it px = param.begin(); px != param.end(); ++px) {
                name = (*px)->getAttribute("name");
                value = Kernel::process(m, *px, r, id);
                argMap[name] = value;
            }
        string response = AimlCompiler::process(func, argMap, p);
        return response;
	}
};

#endif
