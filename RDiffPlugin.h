#ifndef RDiffPLUGIN_H
#define RDiffPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class RDiffPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "RDiff";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
