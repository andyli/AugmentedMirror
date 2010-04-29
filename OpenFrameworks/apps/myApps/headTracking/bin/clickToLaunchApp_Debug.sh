#!/bin/sh

echo $(pwd)
export LD_LIBRARY_PATH=$(pwd)/libs/
./advancedEventsExample_debug

