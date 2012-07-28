add_library (ibus_bogo
            IBusBoGo.hpp
            IBusBoGo.cpp)
target_link_libraries (ibus_bogo ${GLIBMM_LIBRARIES} ${IBUS_LIBRARIES} ${GLIB_LIBRARIES})
add_executable (ibus_bogo_engine BoGomain)
target_link_libraries (ibus_bogo_engine
                      ibus_bogo  ${IBUS_LIBRARIES}) 
