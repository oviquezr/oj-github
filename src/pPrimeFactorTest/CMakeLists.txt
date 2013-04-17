#--------------------------------------------------------
# The CMakeLists.txt for:                pPrimeFactorTest
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
   PrimeFactorTest.cpp  
   PrimeFactorTest_Info.cpp  
   main.cpp
)  

ADD_EXECUTABLE(pPrimeFactorTest ${SRC})

TARGET_LINK_LIBRARIES(pPrimeFactorTest
   ${MOOS_LIBRARIES}
   mbutil
   ${SYSTEM_LIBS} )
