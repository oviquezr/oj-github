#!/bin/bash 
#-------------------------------------------------------
#  Part 1: Check for and handle command-line arguments
#-------------------------------------------------------
TIME_WARP=1
JUST_MAKE="no"
HAZARD_FILE="hazards.txt"

SHORE_IP="18.111.35.126"
#SHORE_IP="192.168.1.150"
SHORE_LISTEN="9300"

for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
	printf "%s [SWITCHES] [time_warp]   \n" $0
	printf "  --just_make, -j    \n" 
	printf "  --hazards=file.txt \n" 
	printf "  --help, -h         \n" 
	exit 0;
    elif [ "${ARGI:0:10}" = "--hazards=" ] ; then
        HAZARD_FILE="${ARGI#--hazards=*}"
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$TIME_WARP" = 1 ]; then 
        TIME_WARP=$ARGI
    elif [ "${ARGI}" = "--just_build" -o "${ARGI}" = "-j" ] ; then
	JUST_MAKE="yes"
    else 
	printf "Bad Argument: %s \n" $ARGI
	exit 0
    fi
done

if [ -f $HAZARD_FILE ]; then
  echo "Using Hazard File $HAZARD_FILE"
else
  echo "$HAZARD_FILE not found. Exiting"
  exit 0
fi 

#-------------------------------------------------------
#  Part 2: Create the .moos and .bhv files. 
#-------------------------------------------------------
VNAME1="oviquezr"      # The first  vehicle community
START_POS1="0,0"  

SWATH_WIDTH_1="10"
SENSOR_PD_1="0.85"

#-----------------------------
# CASE 1: Baseline Hazard File
#-----------------------------
#POINTS_1="-200,-130:-90,-420:-57,-402:-170,-120:-129,-104:-22,-388:20,-370:-84,-85:-42,-69:59,-354:100,-339:-2,-53:39,-34:140,-322:175,-311:80,-23:121,-7:216,-290:256,-275:167,3:203,14:296,-260:330,-244:244,6"

#-----------------------------
# CASE 2: Full Area Lawnmower
#-----------------------------
POINTS_1="format=lawnmower,label=survey,x=120,y=-240,width=560,height=340,lane_width=15,rows=north-south,degs=0"

#nsplug meta_shoreside.moos targ_shoreside.moos -f WARP=$TIME_WARP \
#   VNAME="shoreside" HAZARD_FILE=$HAZARD_FILE   

nsplug meta_vehicle.moos targ_$VNAME1.moos -f WARP=$TIME_WARP  \
   VNAME=$VNAME1      START_POS=$START_POS1                    \
   VPORT="9001"       SHARE_LISTEN="9301"                      \
   VTYPE=UUV          SENSOR_PD=$SENSOR_PD_1                   \
   SHORE_IP=$SHORE_IP SHORE_LISTEN=$SHORE_LISTEN               \
   SWATH_WIDTH=$SWATH_WIDTH_1

nsplug meta_vehicle.bhv targ_$VNAME1.bhv -f VNAME=$VNAME1      \
    START_POS=$START_POS1   POINTS=$POINTS_1

if [ ${JUST_MAKE} = "yes" ] ; then
    exit 0
fi

#-------------------------------------------------------
#  Part 3: Launch the processes
#-------------------------------------------------------
printf "Launching $VNAME1 MOOS Community (WARP=%s) \n" $TIME_WARP
pAntler targ_$VNAME1.moos >& /dev/null &
sleep .25
#printf "Launching $SNAME MOOS Community (WARP=%s) \n"  $TIME_WARP
#pAntler targ_shoreside.moos >& /dev/null &
printf "Done \n"

#uMAC targ_shoreside.moos
uMAC targ_oviquezr.moos

printf "Killing all processes ... \n"
kill %1 #%2 
printf "Done killing processes.   \n"


