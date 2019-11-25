#!/bin/bash
set -e
. ./headers.sh
for PROJECT in $PROJECTS; do
    (cd $PROJECT && DESDIR="$SYSROOT" $MAKE install)
done