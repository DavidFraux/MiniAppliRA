# Install script for directory: C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/Aruco")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xmainx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/Debug/aruco3112.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/Release/aruco3112.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/MinSizeRel/aruco3112.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/RelWithDebInfo/aruco3112.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xmainx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/Debug/aruco3112.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/Release/aruco3112.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/MinSizeRel/aruco3112.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/build/bin/RelWithDebInfo/aruco3112.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aruco" TYPE FILE FILES
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/aruco_cvversioning.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/cameraparameters.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/dictionary_based.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/ippe.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/markerdetector_impl.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/markermap.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/timers.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/aruco_export.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/cvdrawingutils.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/dictionary.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/levmarq.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/marker.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/picoflann.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/aruco.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/debug.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/markerdetector.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/markerlabeler.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/posetracker.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/fractaldetector.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aruco/fractallabelers" TYPE FILE FILES
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/fractallabelers/fractalposetracker.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/fractallabelers/fractalmarkerset.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/fractallabelers/fractalmarker.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/fractallabelers/fractallabeler.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aruco/dcf" TYPE FILE FILES
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/dcf/dcfmarkermaptracker.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/dcf/dcfmarkertracker.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/dcf/dcf_utils.h"
    "C:/Users/Eleve/Downloads/aruco/aruco-3.1.12/src/dcf/trackerimpl.h"
    )
endif()

