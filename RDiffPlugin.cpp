#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "RDiffPlugin.h"

void RDiffPlugin::input(std::string file) {
   readParameterFile(file);
}

void RDiffPlugin::run() {}

void RDiffPlugin::output(std::string file) {
//rdiff -o results -d data/ -a example_condition_A_replicate_1.bam,example_condition_A_replicate_2.bam -b example_condition_B_replicate_1.bam,example_condition_B_replicate_2.bam -g data/genes_example.gff3 -m poisson
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "rdiff -o "+file+" -d "+PluginManager::addPrefix(myParameters["data"])+" -a "+PluginManager::addPrefix(myParameters["a1"])+","+PluginManager::addPrefix(myParameters["a2"])+" -b "+PluginManager::addPrefix(myParameters["b1"])+","+PluginManager::addPrefix(myParameters["b2"])+" -g "+PluginManager::addPrefix(myParameters["gff"])+" -m "+myParameters["method"];
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<RDiffPlugin> RDiffPluginProxy = PluginProxy<RDiffPlugin>("RDiff", PluginManager::getInstance());
