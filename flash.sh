#!/bin/bash
KEYMAP=$1
qmk --version || nix-shell -p qmk
qmk compile -kb ferris/sweep -km $KEYMAP -e CONVERT_TO=liatris || exit 1
echo "Firmware compiled."
echo "Please enter password for sudo."
sudo -v
echo "Connect first part of keyboard and set it in boot/flash mode."
# Verify that the label is the same as what is used by the micro controller.
# Check the label name in /dev/disk/by-label - it should be "RPI-RP2" or the
# code below used when mounting should be updated where the label is specified

FILE=$(ls -1rt|grep ".uf2")
echo "Using firmware $FILE"

# Flash first half
until sudo mount --source LABEL=RPI-RP2 --target /mnt --type vfat --onlyonce --options defaults,noatime,users
do
  sleep 5
  echo "Failed to mount device, please connect it"
done

sudo cp -v $FILE /mnt &&
sleep 3 &&
echo "First half of keyboard successfully flashed"
sudo umount /mnt || exit 2

# Flash second half
echo "Please connect second half and set it in boot/flash mode."
sleep 5

until sudo mount --source LABEL=RPI-RP2 --target /mnt --type vfat --onlyonce --options defaults,noatime,users
do
  sleep 5
  echo "Failed to mount device, please connect it"
done
sudo cp -v $FILE /mnt &&
sleep 3 &&
echo "Second half of keyboard successfully flashed"
sudo umount /mnt

echo "Firmware update completed"
