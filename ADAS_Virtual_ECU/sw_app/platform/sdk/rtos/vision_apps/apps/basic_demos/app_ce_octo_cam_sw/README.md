# Cogent Camera App

## Running

Ensure RAID0 on SSDs is set-up for uncompressed stream dump

non-interactive:

```sh
cd /opt/vision_apps/
source ./vision_apps_init.sh
./vx_app_cogent_octo_cam.out --cfg app_cogent_octo.cfg
```

## RAID0 setup

```sh
mdadm --create --verbose /dev/md0 --level=0  --raid-devices=2 /dev/nvme0n1 /dev/nvme1n1
mkfs.ext4 /dev/md0

echo '/dev/md0             /mnt                 auto       defaults,noatime,discard  0   0' >> /etc/fstab

reboot
```

## Replay raw stream:

```sh
scp 192.168.2.111:/mnt/stream_0.nv12

ffplay -f rawvideo -video_size 1280x1080 -pixel_format nv12 -framerate 30 -i stream_0.nv12
```
