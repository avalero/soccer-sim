#!/bin/bash

cd player && make && cd ..
sleep 3;

for i in {0..10}
do
  gnome-terminal -- bash -c "/home/avalero/workspace/soccer-sim/player/player Valeros 555$i" &
  sleep 1
done
