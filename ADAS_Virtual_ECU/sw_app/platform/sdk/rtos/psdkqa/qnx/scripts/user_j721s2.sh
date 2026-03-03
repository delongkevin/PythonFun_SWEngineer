echo "user.sh called..."

echo Setting additional environment variables...
export PS1='J721S2-FCA@QNX:$(pwd)# '
export PATH=:/proc/boot:/bin:/sbin:/usr/bin:/usr/sbin:/opt/bin:/ti_fs:/ti_fs/bin:/ti_fs/sbin:/ti_fs/usr/bin:/ti_fs/usr/sbin:/ti_fs/tibin:/ti_fs/vision_apps:/ti_fs/scripts
export LD_LIBRARY_PATH=:/proc/boot:/lib:/usr/lib:/lib/dll:/opt/lib:/ti_fs/lib:/ti_fs/usr/lib:/ti_fs/lib/dll/mmedia:/ti_fs/lib/dll:/ti_fs/tilib:/ti_fs/vision_apps
export GRAPHICS_ROOT=/ti_fs/usr/lib/graphics/j721s2
export OMXIL_COMPONENT_PATH=/ti_fs/tilib
export GRAPHICS_ROOT=/ti_fs/usr/lib/graphics/j721s2

echo "Starting ti-vpu-codec-mgr"
ti-vpu-codec-mgr

echo "Starting screen.."
screen -c $GRAPHICS_ROOT/graphics.conf
