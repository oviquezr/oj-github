#!/bin/bash 
#-------------------------------------------------------
#  Part 1: Check for and handle command-line arguments
#-------------------------------------------------------
TIME_WARP=1
JUST_MAKE="no"
#SHORE_IP="localhost"
#SHORE_IP="18.111.124.135"
#SHORE_IP="18.111.111.60"
SHORE_IP="18.111.105.226"

VERTICES="x=-150,y=-75:x=-150,y=-400:x=400,y=-150:x=400,y=-75"
SWATH_WIDTH="25"
SENSOR_PD="0.90"

for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
	printf "%s [SWITCHES] [time_warp]   \n" $0
	printf "  --just_make, -j    \n" 
	printf "  --help, -h         \n" 
	exit 0;
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$TIME_WARP" = 1 ]; then 
        TIME_WARP=$ARGI
    elif [ "${ARGI}" = "--just_build" -o "${ARGI}" = "-j" ] ; then
	JUST_MAKE="yes"
    elif [ "${ARGI:0:9}" = "--shore_ip" -o "${ARGI}" = "-ip" ] ; then
	JUST_MAKE="yes"
    else 
	printf "Bad Argument: %s \n" $ARGI
	exit 0
    fi
done

#-------------------------------------------------------
#  Part 2: Create the .moos and .bhv files. 
#-------------------------------------------------------
VNAME1="oviquezr"    # The first  vehicle community
START_POS1="0,0"  
SHORE_LISTEN="9300"

nsplug meta_archie.moos targ_oviquezr.moos -f WARP=$TIME_WARP  \
   VNAME=$VNAME1        START_POS=$START_POS1                  \
   VPORT="9002"         SHARE_LISTEN="9302"                    \
   VTYPE=UUV            SHORE_LISTEN=$SHORE_LISTEN             \
   SHORE_IP=$SHORE_IP   VERTICES=$VERTICES                     \
   SENSOR_PD=$SENSOR_PD SWATH_WIDTH=$SWATH_WIDTH 

#nsplug meta_shoreside.moos targ_shoreside.moos -f WARP=$TIME_WARP \
#   VNAME="shoreside"  SHARE_LISTEN=$SHORE_LISTEN                  \
#   VPORT="9000"       

nsplug meta_archie.bhv targ_oviquezr.bhv -f VNAME=$VNAME1      \
    START_POS=$START_POS1 

if [ ${JUST_MAKE} = "yes" ] ; then
    exit 0
fi

#-------------------------------------------------------
#  Part 3: Launch the processes
#-------------------------------------------------------
printf "Launching $VNAME1 MOOS Community (WARP=%s) \n" $TIME_WARP
pAntler targ_oviquezr.moos >& /dev/null &
#sleep .25
#printf "Launching $SNAME MOOS Community (WARP=%s) \n"  $TIME_WARP
#pAntler targ_shoreside.moos >& /dev/null &
printf "Done \n"

#uMAC targ_shoreside.moos
uMAC targ_oviquezr.moos

printf "Killing all processes ... \n"
kill %1 #%2 
printf "Done killing processes.   \n"


