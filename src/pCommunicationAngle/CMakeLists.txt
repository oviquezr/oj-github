#--------------------------------------------------------
# The CMakeLists.txt for:             pCommunicationAngle
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
   CommObj.cpp  
   CommunicationAngle.cpp  
   CommunicationAngle_Info.cpp  
   main.cpp
)  

ADD_EXECUTABLE(pCommunicationAngle ${SRC})

TARGET_LINK_LIBRARIES(pCommunicationAngle
   ${MOOS_LIBRARIES}
   mbutil
   ${SYSTEM_LIBS} )
