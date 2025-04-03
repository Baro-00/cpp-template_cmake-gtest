// Config.hpp
#pragma once
#include <string>

class Config {

public:
    Config()
        : inputFile("")
        , outputFile("")
        , showVersion(false)
        , showHelp(false)
    {}

    static Config parseCommandLine(int argc, char* argv[]);

    void printHelp(const char* programName);

    void printVersion(void);

    void printSummary(const Config config);

    bool isShowVersion() const { return showVersion; }
    
    bool isShowHelp() const { return showHelp; }
    
    const std::string& getInputFile() const { return inputFile; }
    
    const std::string& getOutputFile() const { return outputFile; }
    
    void setInputFile(const std::string& file) { inputFile = file; }
    
    void setOutputFile(const std::string& file) { outputFile = file; }

private:
    const std::string APP_NAME = "USR_PROJECT_NAME";
    const std::string VERSION = "1.0.0";

    std::string inputFile;
    std::string outputFile;
    bool showVersion;
    bool showHelp;
};