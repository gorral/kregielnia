#include <boost/program_options.hpp>
#include <iostream>
#include <stdexcept>
#include "TenPinBowling.hpp"

using namespace boost::program_options;

int main(int argc, const char *argv[])
{
    if(argc < 2) {
        std::cerr << "You need to pass at least 1 argument" << std::endl;
        exit(-1);
    }
    std::unique_ptr<TenPinBowling> ptrBowling;
    try {
        options_description desc{"Ten-Pin Bowling Options"};
        desc.add_options()
          ("help,h", "Help Ten-Pin Bowling Game!")
          ("in_dir", value<std::string>(), "Input directory")
          ("out_result", value<std::string>()->default_value("result.txt"), "Output result file");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help")) {
            std::cout << desc << '\n';
        } else {
            ptrBowling = std::unique_ptr<TenPinBowling>(new TenPinBowling("My Bowling Game!", {},
                                                                    vm["in_dir"].as<std::string>(),
                                                                    vm["out_result"].as<std::string>()));
        }
        ptrBowling->loadInputFiles();

        ptrBowling->outputResults(argc == 3);
    }
    catch (std::logic_error & e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
