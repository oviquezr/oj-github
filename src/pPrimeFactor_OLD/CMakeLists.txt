#--------------------------------------------------------
# The CMakeLists.txt for:                    pPrimeFactor
# Author(s):                                 Oscar Viquez
#--------------------------------------------------------

# Set System Specific Libraries
if (${WIN32})
  # Windows Libraries
  SET(SYSTEM_LIBS
     wsock32 )
else (${WIN32})
  # Linux and Apple Libraries
  SET(SYSTEM_LIBS
      m
      pthread )
endif (${WIN32})


SET(SRC
   PrimeFactor.cpp  
   PrimeFactor_Info.cpp  
   main.cpp
)  

ADD_EXECUTABLE(pPrimeFactor ${SRC})

TARGET_LINK_LIBRARIES(pPrimeFactor
   ${MOOS_LIBRARIES}
   mbutil
   ${SYSTEM_LIBS} )
