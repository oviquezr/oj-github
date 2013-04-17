#--------------------------------------------------------
# The CMakeLists.txt for:                pPrimeFactor_new
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
   PrimeObj.cpp  
   PrimeFactor_Info.cpp  
   main.cpp
)  

ADD_EXECUTABLE(pPrimeFactor_new ${SRC})

TARGET_LINK_LIBRARIES(pPrimeFactor_new
   ${MOOS_LIBRARIES}
   mbutil
   ${SYSTEM_LIBS} )
