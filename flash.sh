#!/bin/bash
KEYMAP=$1
qmk --version || nix-shell -p qmk
qmk compile -kb ferris/sweep -km $KEYMAP -e CONVERT_TO=liatris || exit 1
echo "Firmware compiled. Connect first part of keyboard and set it in boot/flash mode."
# This requires the following line to be added to fstab
# `LABEL=RPI-RP2           /mnt            vfat            defaults,noatime,users          0 2`
# Verify that the label is the same as what is used by the micro controller.
# Check the label name in /dev/disk/by-label

FILE=$(ls -1rt|grep ".uf2")
echo "Using firmware $FILE"

# Flash first half
until mount LABEL=RPI-RP2
do
  sleep 5
  echo "Failed to mount device, please connect it"
done

cp -v $FILE /mnt &&
sleep 5 &&
echo "First half of keyboard successfully flashed"
umount /mnt || exit 2

# Flash second half
echo "Please connect second half and set it in boot/flash mode."

until mount LABEL=RPI-RP2
do
  sleep 5
  echo "Failed to mount device, please connect it"
done
cp -v $FILE /mnt &&
sleep 3 &&
echo "Second half of keyboard successfully flashed"
umount /mnt

echo "Firmware update completed"
