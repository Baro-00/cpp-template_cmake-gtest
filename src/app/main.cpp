// main.cpp
#include "Config.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    int ret = 0; // return code

    // Parse command line arguments
    Config config = Config::parseCommandLine(argc, argv);

    // Check for errors in command line arguments
    if (config.isShowHelp()) { // - show help if requested
        config.printHelp(argv[0]);
    } else if (config.isShowVersion()) { // - show version if requested
        config.printVersion();
    } else if (config.getInputFile().empty()) { // - input file is required
        std::cerr << "Error: No input file provided.\n" << std::endl; 
        ret = 1;
    } else {
        // - print summary of the configuration
        config.printSummary(config);
            
        // * USER CODE START
        
        // TODO: Add your application logic here *

        // * USER CODE END
    }

    std::cerr << "[DEBUG] Final return code: " << ret << std::endl;

    // - return code
    if (ret != 0) {
        std::cerr << "Error: Exit code: " << ret << std::endl;
    } 
    return ret;
}