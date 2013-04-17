#!/bin/bash 
#-------------------------------------------------------
#  Part 1: Check for and handle command-line arguments
#-------------------------------------------------------
TIME_WARP=1
JUST_MAKE="no"
VNAME="archie"
for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
	printf "%s [SWITCHES] [time_warp]   \n" $0
	printf "  --just_make, -j    \n" 
	printf "  --vname=VNAME      \n" 
	printf "  --help, -h         \n" 
	exit 0;
    elif [ "${ARGI:0:8}" = "--vname=" ] ; then
        VNAME="${ARGI#--vname=*}"
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$TIME_WARP" = 1 ]; then 
        TIME_WARP=$ARGI
    elif [ "${ARGI}" = "--just_build" -o "${ARGI}" = "-j" ] ; then
	JUST_MAKE="yes"
    else 
	printf "Bad Argument: %s \n" $ARGI
	exit 0
    fi
done

#-------------------------------------------------------
#  Part 2: Create the .moos and .bhv files. 
#-------------------------------------------------------
START_POS1="0,0"  

SWATH_WIDTH_1="25"
SENSOR_PD_1="0.90"

#-----------------------------
# CASE 1: Baseline Hazard File
#-----------------------------
#POINTS_1="-200,-130:-90,-420:-57,-402:-170,-120:-129,-104:-22,-388:20,-370:-84,-85:-42,-69:59,-354:100,-339:-2,-53:39,-34:140,-322:175,-311:80,-23:121,-7:216,-290:256,-275:167,3:203,14:296,-260:330,-244:244,6"

#-----------------------------
# CASE 2: Full Area Lawnmower
#-----------------------------
POINTS_1="format=lawnmower,label=survey,x=125,y=-240,width=550,height=330,lane_width=25,rows=north-south,degs=0"

nsplug meta_vehicle.moos targ_$VNAME.moos -f WARP=$TIME_WARP  \
   VNAME=$VNAME       START_POS=$START_POS1                   \
   VPORT="9002"       SHARE_LISTEN="9302"                     \
   VTYPE=UUV          SENSOR_PD=$SENSOR_PD_1                  \
   SHORE_IP=$SHORE_IP SHORE_LISTEN=$SHORE_LISTEN              \
   SWATH_WIDTH=$SWATH_WIDTH_1    

nsplug meta_vehicle.bhv targ_$VNAME.bhv -f VNAME=$VNAME       \
    START_POS=$START_POS1   POINTS=$POINTS_1


if [ ${JUST_MAKE} = "yes" ] ; then
    exit 0
fi

#-------------------------------------------------------
#  Part 3: Launch the processes
#-------------------------------------------------------
printf "Launching $VNAME MOOS Community (WARP=%s) \n" $TIME_WARP
pAntler targ_$VNAME.moos >& /dev/null &

uMAC targ_$VNAME.moos

kill %1 
printf "Done.   \n"


