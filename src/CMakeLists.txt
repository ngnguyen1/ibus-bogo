add_library (ibus_bogo
            IBusBoGo.hpp
            IBusBoGo.cpp
)
add_executable (ibus_bogo_engine BoGomain)
target_link_libraries (ibus_bogo_engine
                      ibus_bogo
                      ibus)
