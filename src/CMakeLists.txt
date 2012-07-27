add_library (ibus_bogo
            IBusBoGo.cpp
            IBusBoGo.hpp)
add_executable (ibus_bogo_engine BoGomain)
target_link_libraries (ibus_bogo_engine
                      bogoengine
                      ibus_bogo
                      ibus)
